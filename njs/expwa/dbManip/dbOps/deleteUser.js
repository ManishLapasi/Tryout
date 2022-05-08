const config = require("../dbConnect/readCreds").config;
const uri = require("../dbConnect/readCreds").uri;
const {MongoClient} = require("mongodb");
var ObjectID = require("mongodb").ObjectId;

async function deleteUser(Id) {
    const client = await MongoClient.connect(uri, { useNewUrlParser: true })
    .catch((err) => {console.log(err)})

    if(!client){
        return;
    }
    try{
        const db = client.db(config.dbName);
        const coll = db.collection("users");
        const query = {"_id": ObjectID("626e414f43ccbd7602530f6a")};
        console.log(query);
        let findres = await coll.find(query).toArray();
        console.log(findres);
        let res = await coll.deleteOne(query);
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

exports.deleteUser = deleteUser;