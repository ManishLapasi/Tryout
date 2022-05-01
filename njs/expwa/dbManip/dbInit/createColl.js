const {MongoClient} = require('mongodb');
const uri = require("../dbConnect/dbConnect").uri;
const config = require("../dbConnect/readCreds").config;

console.log(uri);

MongoClient.connect(uri,(err,db) => {
    if (err) throw err;
    var dbObject = db.db(config.dbName);
    dbObject.createCollection("users",(err,res) => {
        if (err) throw err;
        console.log("collection created");
        db.close();
    })
})