var http = require("http");
const PORT = 3000;

const server = http.createServer(function(req, res){
    res.writeHead(200,{"Content-Type":"application/json"});
    res.write("server is up on port " + PORT);
    res.end(JSON.stringify({id:1, name:"Manish"}));
});

server.listen(PORT,() => {
    console.log("go to https://localhost:3000/");
});

