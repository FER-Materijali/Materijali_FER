var express = require('express')
var app = express();
var path = require('path')
var http = require('http').Server(app);
var io = require('socket.io')(http);

app.use('/js', express.static(path.join(__dirname, 'js')))
app.use('/css', express.static(path.join(__dirname, 'css')))
app.use('/json', express.static(path.join(__dirname, 'json')))
app.use('/', express.static(__dirname))


var viewsDirName=__dirname+"/views";




app.get('/', function(req, res){
  res.sendFile(viewsDirName + '/index.html');
});
app.get('/original', function(req, res){
  res.sendFile(viewsDirName + '/original.html');
});
app.get('/test', function(req, res){
  res.sendFile(viewsDirName + '/test.html');
});
app.get('/dionice', function(req, res){
  res.sendFile(viewsDirName + '/dionice.html');
});
app.get('/admin', function(req, res){
  res.sendFile(viewsDirName + '/admin.html');
});

io.on('connection', function(socket){
  socket.on('chat message', function(msg){
    console.log('Got text:');
    console.log(msg);
    io.emit('chat message', msg);
  });
  socket.on('chat message1', function(msg){
    console.log('Got text:');
    console.log(msg);
    io.emit('chat message1', msg);
  });
  socket.on('edit', function(msg){
    console.log('Editing text:');
    console.log(msg);
    io.emit('edit', msg);
  });
});






http.listen(3000, function(){
  console.log('listening on *:3000');
});
