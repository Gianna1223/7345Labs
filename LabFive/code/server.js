var ws = require('nodejs-websocket');
var myDate = new Date();
var server = ws.createServer(function(socket){

//Read the string from the client
    socket.on('text', function(str) {
　　     //The console outputs messages from the front end
        console.log(str);
        //Reply message to the front end
        socket.sendText('Hello Qing!');
    });

var t1 = myDate.getMilliseconds();
console.log("Time:",t1);

}).listen(5500);