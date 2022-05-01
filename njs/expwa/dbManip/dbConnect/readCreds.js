var fs = require("fs"), ini = require("ini");

var config = ini.parse(fs.readFileSync(__dirname+"/creds.ini","utf-8"));

exports.config = config;