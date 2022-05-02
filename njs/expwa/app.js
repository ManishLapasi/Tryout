const express = require("express");
const app = express();
const port = 3000;
const bodyParser = require("body-parser");

const fs = require("fs");
const { create } = require("domain");

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

app.get('/getrandomrecord', async (req,res) => {
    const getRandom = await require("./dbManip/dbOps/getRandomUser").findOne("Manish");
    res.writeHead(200,{"Content-Type":"application/json"});
    res.end(JSON.stringify(getRandom));
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

app.post('/createuser', async (req,res) => {
    const createUser = await require("./dbManip/dbOps/createUser").createUser(req.body.name,req.body.movie);
    res.writeHead(200,{"Content-type":"application/json"});
    res.end(JSON.stringify(createUser));
})

app.get('/findusers', (req,res) => {
    fs.readFile(__dirname+"/../pages/findUser.html",(err,data) => {
        if(err){
            res.writeHead(400,{"Content-type":"application/json"});
            res.end(JSON.stringify({message:err}));
        }
        else{
            res.writeHead(200,{"Content-type":"text/html"});
            res.write(data);
            res.end();
        }
    })
})

app.post('/findusers', async (req,res) => {
    const Users = await require("./dbManip/dbOps/findUsers").findUsers(req.body.name,req.body.movie);
    res.writeHead(200,{"Content-type":"application/json"})
    res.end(JSON.stringify(Users));
})

app.listen(port, () => {
    console.log("listening on port " + port);
})
