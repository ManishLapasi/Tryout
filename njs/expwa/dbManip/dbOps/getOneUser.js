const config = require("../dbConnect/readCreds").config, uri = require("../dbConnect/readCreds").uri;
const {MongoClient} = require("mongodb");

var findOne = function(db, callback) {
    var coll = db.db(config.dbName).collection("users");
    coll.find({favMovie:"Jojo Rabbit"}).toArray(function(err,records){
        if(err) throw err;
        console.log(records);
        callback(records);
    });
}

MongoClient.connect(uri, (err,db) => {
    if(err) throw err;
    console.log("connected to db");
    findOne(db,function(res) {
        exports.getOne = res;
        db.close();
    });
});