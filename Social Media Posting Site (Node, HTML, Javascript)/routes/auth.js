const express = require('express');
const cookieParser = require('cookie-parser');
const authController = require('../controllers/auth');

const router = express.Router();
router.use(cookieParser());

router.post('/register', authController.register);
router.post('/login', authController.login);
router.post('/post', authController.post);
router.get('/logout', authController.logout);

module.exports = router;
