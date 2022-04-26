var http = require("http");
var dt = require("./module1");
var url = require("url");
var fs = require("fs");

http.createServer(function (req,res) {
    var parsedUrl = url.parse(req.url,true);
    var siteRequested = parsedUrl.pathname;
    console.log(siteRequested);
    var fileName = "./pages" + siteRequested + ".html";
    fs.readFile(fileName, function(err,data){
        if(err){
            res.writeHead(404,{"Content-Type": "text/html"});
            return res.end("404 Not Found");
        }
        res.writeHead(200, {"Content-Type": "text/html"});
        res.write(data);
        return res.end();
    });
}).listen(8080);

http.createServer(function (req,res) {
    var q = url.parse(req.url,true);
    var queryReq = q.query;
    var str = "";
    if(queryReq.year){
        str = str + " year: " + queryReq.year;
    }
    if(queryReq.month){
        str = str + " month: " + queryReq.month;
    }
    res.writeHead(200,{"Content-Type": "text/html"});
    res.write(str);
    res.write(dt.getDate());
    return res.end();  
}).listen(8090);