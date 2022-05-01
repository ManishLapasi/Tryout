const {MongoClient} = require("mongodb");
const config = require("../dbConnect/readCreds").config;

const uri = require("../dbConnect/readCreds").uri;

var createUser = function(Name, Movie) {
    MongoClient.connect(uri, (err,db) => {
        if (err) throw err;
        var dbObject = db.db(config.dbName);
        var myObj = { name : Name, favMovie: Movie};
        dbObject.collection("users").insertOne(myObj, (err,res) => {
            if(err) throw err;
            console.log("record inserted");
            db.close();
        });
    });
}

exports.createUser = createUser;


