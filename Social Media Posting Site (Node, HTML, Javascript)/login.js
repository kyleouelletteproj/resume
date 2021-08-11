const express = require("express");
const mysql = require("mysql");

const login = express();

const db = mysql.createConnection({
    host: "joecool.highpoint.edu",
    user: "kouelletteweb",
    password: "!%!%@%!"
})
login.listen(5000, () => {
    console.log("Waiting for log in");
})