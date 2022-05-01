const config = require("../dbConnect/readCreds").config;
const uri = require("../dbConnect/readCreds").uri;
const {MongoClient} = require("mongodb");

var findOne = function(db, callback) {
    var coll = db.db(config.dbName).collection("users");
    coll.findOne({},(err,res) => {
        if(err) throw err;
        console.log(res);
        callback(res);
    });
}

MongoClient.connect(uri, (err,db) => {
    if(err) throw err;
    console.log("connected to db");
    findOne(db,function(res) {
        exports.getRandom = res;
        db.close();
    });
});