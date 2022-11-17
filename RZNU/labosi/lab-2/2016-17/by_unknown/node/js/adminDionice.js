

    if (window.WebSocket) {
        var socket = io();
        $('form').submit(function(){
        socket.emit('chat message', $('#m').val());
        $('#m').val('');
        return false;
        });
        socket.on('edit', function(msg){
        var list= msg.split("#");
        redak=list[0];
        var currentdate = new Date(); 
        var datetime = "Last Sync: " + currentdate.getDate() + "/"
                    + (currentdate.getMonth()+1)  + "/" 
                    + currentdate.getFullYear() + " @ "  
                    + currentdate.getHours() + ":"  
                    + currentdate.getMinutes() + ":" 
                    + currentdate.getSeconds();
        $('#messages').append($('<li>').text(datetime+" Redak:" + redak + " Broj izdanih: "+list[1] + " Nominala: "+list[2]));
    
        document.getElementById("BrojIzdanih"+redak).value=list[1];
        document.getElementById("Nominala"+redak).value=list[2];
        console.log(document.getElementById("BrojIzdanih"+redak).value);
        });
    }else{
        alert("Vas preglednik ne podrzava WebSockete");
    }








    $(function() {


   var people = [];
   var counter=0;
   $.getJSON('../json/dionice.json', function(data) {
       $.each(data.dionice, function(i, f) {
          
          counter++;
          var tblRow = '<tr id="Izdatatelj_' + counter +'">' + "<td>" + f.Izdavatelj + "</td>" +
           "<td>" + f.ISIN + "</td>" + '<td><input type="text" id="BrojIzdanih'+ counter +'" value=' + f.BrojIzdanih +  ' name="lname">' + "</td>" + '<td><input type="text" id="Nominala'+ counter + '"value=' + f.Nominala +  ' name="lname">' + "</td>" + 
           "<td>" + ' <button type="button" onclick="editDionica(' + counter + ')">Spremi</button> ' + "</td>"+
           "</tr>"
           $(tblRow).appendTo("#dioniceTable tbody");
     });

   });

});


function editDionica(redak){
    
    
    var brojIzdanih=document.getElementById("BrojIzdanih"+redak).value;
    var nominala=document.getElementById("Nominala"+redak).value;
    socket.emit('edit', redak+"#"+brojIzdanih+ "#" + nominala);
    return ;
    
}
