const config = require("../dbConnect/readCreds").config;
const uri = require("../dbConnect/readCreds").uri;
const {MongoClient} = require("mongodb");

async function findUsers(Name, Movie) {
    const client = await MongoClient.connect(uri, { useNewUrlParser: true })
    .catch((err) => {
        console.log(err);
    })
    if(!client){
        return;
    }
    try{
        const db = client.db(config.dbName);
        let coll = db.collection("users");
        let query = {name:Name,favMovie:Movie};
        let data =  await coll.find(query).toArray();
        console.log(data);
        return data;
    }
    catch(err){
        console.log(err);
    }
    finally{
        client.close();
    }
}

exports.findUsers = findUsers;