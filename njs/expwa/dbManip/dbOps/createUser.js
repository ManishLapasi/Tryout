const {MongoClient} = require("mongodb");
const config = require("../dbConnect/readCreds").config;
const uri = require("../dbConnect/readCreds").uri;

async function createUser(Name, Movie) {
    const client = await MongoClient.connect(uri, { useNewUrlParser: true })
    .catch((err)=>{console.log(err);})
    if(!client){
        return;
    }
    try{
        const db = client.db(config.dbName);
        let coll = db.collection("users");
        let obj = {name:Name,movie:Movie}
        let res = await coll.insertOne(obj);
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

exports.createUser = createUser;

