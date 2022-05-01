const express = require("express");
const app = express();
const port = 3000;
const bodyParser = require("body-parser");

const fs = require("fs");

app.use(bodyParser.urlencoded({extended: false}));

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
    fs.readFile(__dirname+'/../pages/about.html',(err,data)=>{
        if(err){
            res.writeHead(404,{"Content-Type":"application/json"});
            res.end(JSON.stringify({message:err}));
        }
        else{
            res.writeHead(200,{"Content-Type":"text/html"});
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

app.get('/createuser',(req,res)=>{
    fs.readFile(__dirname+"/../pages/createUserForm.html",(err,data) => {
        if(err){
            res.writeHead(404,{"Content-type":"application/json"});
            res.end(JSON.stringify({message:err}));
        }
        else{
            res.writeHead(200,{"Content-type":"text/html"})
            res.write(data);
            res.end();
        };
    });
});

app.post('/createuser', (req,res) => {
    console.log(req.body.name);
    console.log(req.body.movie);
    const createUser = require("./dbManip/dbOps/createUser").createUser;
    createUser(req.body.name,req.body.movie);
    res.writeHead(200,{"Content-type":"application/json"});
    res.end(JSON.stringify({message:"logged to console"}));
})

app.listen(port, () => {
    console.log("listening on port " + port);
})
