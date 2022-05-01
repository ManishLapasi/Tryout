var fs = require("fs");

fs.open("newfile.txt","w",function(err,file){
    if(err) throw err;
    console.log("file created");
});

fs.writeFile("newfile.txt","writing stuff",function(err, file){
    if(err) throw err;
    console.log("file written!");
});

fs.readFile("newfile.txt","utf-8",function(err,data){
    if(err) throw err;
    console.log("file read");
    console.log(data);
});

fs.appendFile("newfile.txt","\nappend stuff",function(err){
    if(err) throw err;
    console.log("appended!");
})


fs.unlink("newfile.txt",function(err){
    if(err) throw err;
    console.log("deleted");
})