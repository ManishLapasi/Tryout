var fs = require("fs"), ini = require("ini");

var config = ini.parse(fs.readFileSync(__dirname+"/creds.ini","utf-8"));
const uri = "mongodb+srv://"+config.username+":"+config.password+"@manishdb.kao8o.mongodb.net/myFirstDatabase?retryWrites=true&w=majority";

exports.config = config;
exports.uri = uri;