var myDBConfig = require("./readCreds");
const {MongoClient} = require('mongodb');

var config = myDBConfig.config;

const uri = "mongodb+srv://"+config.username+":"+config.password+"@manishdb.kao8o.mongodb.net/myFirstDatabase?retryWrites=true&w=majority";

MongoClient.connect(uri,(err,db)=>{
    if(err){
        throw err;
    }
    console.log("db connected");
    //console.log(db);
    db.close();
})

exports.uri = uri;