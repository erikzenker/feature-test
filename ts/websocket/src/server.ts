
import * as websocket from 'websocket'
import * as http from 'http'

const server = http.createServer(function(request : any, response : any) {
  console.log((new Date()) + ' Received request for ' + request.url);
  response.writeHead(404);
  response.end();
});

server.listen(8080, function() {
  console.log((new Date()) + ' Server is listening on port 8080');
});

var wsServer = new websocket.server({
  httpServer: server
});

wsServer.on('request', function(request : any) {
  console.log((new Date()) + ' Connection from origin '
      + request.origin + '.');

  const subProtocol : string = 'subprotocol'
  const connection = request.accept(subProtocol, request.origin); 
  
  console.log((new Date()) + ' Connection accepted.');

  connection.on('message', function(message : any) {
    if (message.type === 'utf8') {
      console.log((new Date()) + ' ' + "Received: '" + message.utf8Data + "'" + " echo back");
      connection.sendUTF(message.utf8Data);
    }
  });

  connection.on('close', function(connection : any) {
      console.log((new Date()) + " Peer "
          + connection.remoteAddress + " disconnected.");
  });
});