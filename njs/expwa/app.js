const express = require("express");
const app = express();
const port = 3000;

var fs = require("fs");

app.get('/',(req,res) => {
    res.writeHead(200,{"Content-Type":"application/json"});
    res.write(JSON.stringify({name:"You've hit the base page"}));
    res.end();
});

app.get('/hi',(req,res) => {
    res.writeHead(200,{"Content-Type":"application/json"});
    res.write(JSON.stringify({message:"Hi"}));
    res.end();
});

app.get('/about', (req,res) => {
    fs.readFile('../pages/about.html',(err,data)=>{
        if(err){
            res.writeHead(404,{"Content-Type":"application/json"});
            res.end(JSON.stringify({message:"Error while getting page"}));
        }
        else{
            res.writeHead(200,{"Content-Type":"application/json"});
            res.write(data);
            res.end();
        }
    });
});

app.get('/getrandom', (req,res) => {
    const getRandom = require("./dbManip/dbOps/getRandomUser").getRandom;
    res.writeHead(200,{"Content-Type":"application/json"});
    res.end(JSON.stringify(getRandom));
});

app.get('/getone', (req,res) => {
    const getOne = require("./dbManip/dbOps/getOneUser").getOne;
    res.writeHead(200,{"Content-Type":"application/json"});
    res.end(JSON.stringify(getOne));
});

app.listen(port, () => {
    console.log("listening on port " + port);
})
