const authenticate = function(req, res, next){
    const authvar = req.headers["bearer"];
    if(!authvar){
        res.writeHead(401,{"Content-Type":"application/json"});
        res.end(JSON.stringify({message:"No header"}));
        return;
    }    
    const text = Buffer.from(authvar,"base64").toString("ascii");
    const userpass = text.split(":")
    if(userpass[0]=="hi" && userpass[1]=="hello"){
        return next();
    }
    res.writeHead(401,{"Content-Type":"application/json"});
    res.end(JSON.stringify({message:"Access denied"}));
}

exports.authenticate = authenticate;