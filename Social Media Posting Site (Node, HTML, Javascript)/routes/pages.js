const express = require('express');
const authController = require('../controllers/auth');

const router = express.Router();
  
router.get('/', authController.isLoggedIn, (req, res) => {
  if(req.user) {
  res.status(200).redirect('/loggedin');
  } else {
    res.render('main'), {
      layout:'loggedin'
    }
  }
});
  router.get('/loggedin', authController.isLoggedIn, (req, res) => {
    if( req.user ) {
      res.render('loggedin', {
        layout: 'loggedin',
        user: req.user
      });
    } else {
      res.redirect('/');
    }
    authController.viewposts, (req, res) => {
      if(req.data ) {
        res.render('loggedin', {
          layout: 'loggedin',
          data: req.data
        });
      }
      console.log('test');
    }
    
  })
  
module.exports = router;
