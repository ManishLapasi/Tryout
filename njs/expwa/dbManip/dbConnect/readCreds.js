var fs = require("fs"), ini = require("ini");

var config = ini.parse(fs.readFileSync(__dirname+"/creds.ini","utf-8"));
const uri = config.uri;

exports.config = config;
exports.uri = uri;