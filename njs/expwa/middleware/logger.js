const logger = function(req, res, next) {
    console.log("path:",req.path," body:",req.body);
    next();
}

exports.logger = logger;