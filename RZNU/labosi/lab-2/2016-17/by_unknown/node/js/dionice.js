    //window.WebSocket=undefined;
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
        console.log(redak);
        document.getElementById("BrojIzdanih"+redak).innerHTML=list[1];
        document.getElementById("Nominala"+redak).innerHTML=list[2]+" HRK";
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
           "<td>" + f.ISIN + "</td>" + 
           '<td id="BrojIzdanih'+ counter +'">' + f.BrojIzdanih  + "</td>" + 
           '<td id="Nominala'+ counter + '">' + f.Nominala + " HRK"+"</td>" + 
           
           "</tr>"
           $(tblRow).appendTo("#dioniceTable tbody");
     });

   });

});



