const io = require('socket.io')(3000);
const express = require("express");
const path = require('path');
const http = require('http');
const handlebars = require('express-handlebars');
const mysql = require("mysql");
const dotenv = require('dotenv');
const cookieParser = require('cookie-parser');
const { response } = require('express');
const port = 80;

const users = {}

const app = express();
app.use(express.urlencoded({extended: false}));
app.use(express.json());
app.use(cookieParser());
app.use(express.static('public'));
//routes
app.use('/auth', require('./routes/auth'));
app.use('/', require('./routes/pages'));

app.set('view engine', 'handlebars');
app.engine('handlebars', handlebars({
  layoutsDir: __dirname + '/views'
  }));

dotenv.config({ path: ".env"});
const db = mysql.createConnection({
  host: process.env.DATABASE_HOST,
  user: process.env.DATABASE_USER,
  password: process.env.DATABASE_PASSWORD,
  database: process.env.DATABASE,
  "socketPath": process.env.DATABASE_PATH
})

db.connect( (error) => {
  if(error) {
    console.log(error)
  } else {
    console.log("Connected to MYSQL Database")
  }
})
app.get('/showposts', (request, response) => {
  db.query('SELECT userName, postMSG FROM POST JOIN ACCOUNT WHERE ACCOUNT.userID = POST.userID ORDER BY postID DESC LIMIT 10', (err,data) => {
    if(err) {
      response.end();
    }
    response.json(data);
  })
});
app.listen(port, () => console.log(`App listening to port ${port}`));
