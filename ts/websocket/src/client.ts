import * as websocket from 'websocket'

const client = new websocket.client();

client.on('connectFailed', function(error: any) {
    console.log('Connect Error: ' + error.toString());
});

client.on('connect', function(connection : any) {
    console.log((new Date()) + ' ' + 'WebSocket Client Connected');
    connection.on('error', function(error : any) {
        console.log((new Date()) + ' ' +"Connection Error: " + error.toString());
    });
    connection.on('close', function() {
        console.log((new Date()) + ' ' +'echo-protocol Connection Closed');
    });

    connection.on('message', function(message : any) {
        if (message.type === 'utf8') {
            console.log((new Date()) + ' ' +"Received: '" + message.utf8Data + "'");
        }
    });
    
    function sendNumber() {
        if (connection.connected) {
            var number = Math.round(Math.random() * 0xFFFFFF);
            connection.sendUTF(number.toString());
            setTimeout(sendNumber, 1000);
        }
    }
    sendNumber();
});
 
client.connect('ws://localhost:8080/', 'subprotocol');