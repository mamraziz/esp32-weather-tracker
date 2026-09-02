const express = require('express');
const app = express();
app.use(express.json());

const Database = require('better-sqlite3');
const db = new Database('data.db');
db.exec(`
  CREATE TABLE IF NOT EXISTS data (
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    ldr INTEGER,
    temp INTEGER,
    hum INTEGER
  )
`);

app.listen(3000, () => {
  console.log('Server running on port 3000');
});

app.post('/readings' , (req, res) => {
    const ldr = req.body.ldr;
    const temp = req.body.temp;
    const hum = req.body.hum;
    db.prepare('INSERT INTO data (ldr, temp, hum) VALUES (?, ?, ?)').run(ldr, temp, hum);
    res.send("Recieved reading");
    console.log('recieved');
});