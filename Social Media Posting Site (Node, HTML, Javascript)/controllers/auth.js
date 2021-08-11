const mysql = require('mysql');
const dotenv = require('dotenv');
const alert = require('alert');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');
const window = require('window');
const { promisify } = require('util');
var posts = 0;
var accounts = 0;

dotenv.config({ path: ".env"});
const db = mysql.createConnection({
  host: process.env.DATABASE_HOST,
  user: process.env.DATABASE_USER,
  password: process.env.DATABASE_PASSWORD,
  database: process.env.DATABASE,
  "socketPath": process.env.DATABASE_PATH
})
        exports.login = async (req, res) => {
          try {
            const name = req.body.uname;
            const password = req.body.psw;
            db.query('SELECT * FROM ACCOUNT WHERE userName = ?', [name], async (error,results) => {
                if(!results || !(await bcrypt.compare(password, results[0].password))) {
                  return res.render('main', {
                    message: 'Invalid username or password'
                  })
                } else {
                    const id = results[0].userID;
                    const token = jwt.sign({id: id}, process.env.JWT_SECRET, {
                        expiresIn: process.env.JWT_EXPIRES_IN
                    })
                    const cookieOptions = {
                        expires: new Date(
                            Date.now() + process.env.JWT_COOKIE_EXPIRES * 24 * 60 * 60 * 1000
                        ),
                        httpOnly: true
                    }
                    res.cookie('jwt', token, cookieOptions);
                    res.status(200).redirect("/loggedin");
                }
            })
          } catch (error) {
            console.log(error);
          }
        }
        exports.register = (req, res) => {
            const name = req.body.uname;
            const password = req.body.psw;
            const confpass = req.body.confpsw;
            db.query('SELECT userName FROM ACCOUNT WHERE userName = ?', [name], async (error, results) => {
                if(error) {
                   console.log(error); 
                }
                if(results.length > 0) {
                        return res.render('main', {
                          message: 'Username is already in use'
                        })
                    } else if(password !== confpass) {
                      return res.render('main', {
                        message: 'Passwords do not match'
                      })
                    }
                    let hashedPassword = await bcrypt.hash(password, 8);
                    if(results.length == 0) {
                        var uid = db.query('SELECT COUNT(*) FROM ACCOUNT');
                        db.query('INSERT INTO ACCOUNT SET ?', {userID: accounts, userName: name, password: hashedPassword}, (error, results) => {
                            if(error) {
                                console.log(error);
                            } else {
                              accounts++;
                              return res.render('main', {
                                message: 'Account created'
                              })
                                accounts++;
                                    res.render('main', {layout : 'main'});
                                }
                            })
                        }
                })
                }

                exports.isLoggedIn = async (req, res, next) => {
                  if(req.cookies.jwt) {
                    try {
                      const decoded = await promisify(jwt.verify)(req.cookies.jwt,
                      process.env.JWT_SECRET
                      );
                      db.query('SELECT * FROM ACCOUNT WHERE userID = ?', [decoded.id], (error, result) => {
                        if(!result) {
                          return next();
                        }
                        req.user = result[0];
                        console.log(req.user.userName, "logged in.")
                        return next();
                
                      });
                    } catch (error) {
                      console.log(error);
                      return next();
                    }
                  } else {
                    next();
                  }
                }
                exports.post = async (req,res, next) => {
                  const postmsg = req.body.postmsg;
                  const recentposts = [];
                  console.log(req.body);
                  if(req.cookies.jwt) {
                    try {
                      const decoded = await promisify(jwt.verify)(req.cookies.jwt,
                      process.env.JWT_SECRET
                      );
                      db.query('INSERT INTO POST SET ?', {postID: posts, userID: [decoded.id], postMSG: postmsg}, (error, result) => {
                          return res.status(200).redirect('/');
                  })
                } catch(error) {
                  console.log(error);
                }
              }
              posts++;
            }
                exports.logout = async (req, res) => {
                  res.cookie('jwt', 'logout', {
                    expires: new Date(Date.now() + 2*1000),
                    httpOnly: true
                  });
                  res.status(200).redirect('/');
                }