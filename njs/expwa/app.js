const express = require("express");
const app = express();
const port = 3000;
const bodyParser = require("body-parser");
const swaggerUi = require('swagger-ui-express');
const YAML = require("yamljs");
const swaggerDocument = YAML.load("./pages/swg-docs.yml");
const fs = require("fs");
const logger = require("./middleware/logger").logger; 
const authenticate = require("./middleware/auth").authenticate;


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.use(logger);
app.use(authenticate);

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
    fs.readFile(__dirname+'./pages/about.html',(err,data)=>{
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

app.get('/users/createUser',(req,res)=>{
    fs.readFile(__dirname+"./pages/createUserForm.html",(err,data) => {
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

app.post('/users/createUser', async (req,res) => {
    const createUser = await require("./dbManip/dbOps/createUser").createUser(req.body.name,req.body.movie);
    res.writeHead(200,{"Content-type":"application/json"});
    res.end(JSON.stringify(createUser));
    //res.end();
})

app.get('/users/findUsersByName', (req,res) => {
    fs.readFile(__dirname+"./pages/findUser.html",(err,data) => {
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

app.post('/users/findUsersByName', async (req,res) => {
    const Users = await require("./dbManip/dbOps/findUsers").findUsers(req.body.name);
    res.writeHead(200,{"Content-type":"application/json"})
    res.end(JSON.stringify(Users));
})

app.post("/users/deleteUser", async (req,res) => {
    const deletedUsers = await require("./dbManip/dbOps/deleteUser").deleteUser(req.body.Id);
    res.writeHead(200,{"Content-Type":"application/json"});
    res.end(JSON.stringify(deletedUsers));
})

app.listen(port, () => {
    console.log("listening on port " + port);
})
