
       //Open a web socket
        var ws = new WebSocket('ws://localhost:5500/');
        //The web socket is connected. Use the send() method to send data.
        ws.onopen = function() {
                ws.send('Hello server! I am Gao~');
        }
        //Accept messages from the server.
        ws.onmessage = function(e) {
            console.log(e.data)
        }

