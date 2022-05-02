const config = require("../dbConnect/readCreds").config;
const uri = require("../dbConnect/readCreds").uri;
const {MongoClient} = require("mongodb");

async function findOne(Name) {
    const client = await MongoClient.connect(uri, { useNewUrlParser: true })
    .catch(err => {console.log(err);})
    if(!client){
        return;
    }
    try{
        const db = client.db(config.dbName);
        let coll = db.collection("users");
        let query = {name:Name}
        let res = await coll.findOne(query);
        console.log(res);
        return res;
    }
    catch(err){
        console.log(err);
    }
    finally{
        client.close();
    }
}

exports.findOne = findOne;
