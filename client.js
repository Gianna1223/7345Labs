


var word = document.getElementById('word');
       //Open a web socket
        var ws = new WebSocket('ws://localhost:5500/');
        //The web socket is connected. Use the send() method to send data.
        ws.onopen = function() {
                ws.send('Hello server! I am Gao~');
        }
        //Accept messages from the server.
        ws.onmessage = function(e) {
            console.log(e.data)
            word.innerHTML = e.data
        }
 
// click the button to trigger the notification
var button = document.querySelector('#button');
button.onclick = function () {
    var option = {
        title: 'Notification',
        body: 'Notification from electron~'
    };
    var myNotification = new window.Notification(option.title, option);

    myNotification.onclick = function () {
        console.log('click');
    }
};
 
// the monitoring network is connected
window.addEventListener('online', function () {

    var option = {
        title: 'Reminder',
        body: 'The internet in connected. It is time to work!'
    };
    var myNotification = new window.Notification(option.title, option);

    myNotification.onclick = function () {
        console.log('click');
    }
});
 
 
// the monitoring network is borken
window.addEventListener('offline', function () {
    
    var option = {
        title: 'Reminder',
        body: 'The network is borken. It is time to rest！'
    };
    var myNotification = new window.Notification(option.title, option);

    myNotification.onclick = function () {
        console.log('click');
    }
})