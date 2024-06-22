const express = require('express');
const bodyParser = require('body-parser');
const addon = require('./build/Release/addon');
const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

app.post('/check', (req, res) => {
    const username = req.body.username;
    const result = addon.checkPrivilege(username);
    res.send(`
        <html>
            <head>
                <title>Privilege Check</title>
            </head>
            <body>
                <h1>User ${username} has privilege ${result}</h1>
                <button onclick="window.location.href='/'">Back</button>
            </body>
        </html>
    `);
});

app.listen(3000, () => {
    console.log('Server started on port 3000');
});