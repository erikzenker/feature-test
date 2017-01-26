// not nice, but works 
var $ = require('jquery');
var exec = require('child_process').exec;
var sys = require('sys')
var child;

$(document).ready(function(){
    $("#submit").click(function(event){
        event.preventDefault();
        event.stopPropagation();
        
        var timeInMinutes = $("#time").val();

        if(time < 0){
            alert("Can not set a negative timer.");
            return;
        }

        var timeInMillis = timeInMinutes * 60 * 1000;
        let timeout = setTimeout(function(){
            alert("System is going to sleep now.")
            child = exec("sudo pm-suspend", function (error, stdout, stderr) {
                sys.print('stdout: ' + stdout);
                sys.print('stderr: ' + stderr);
                if (error !== null) {
                    console.log('exec error: ' + error);
                }
            });

        }, timeInMillis);

        alert("System going to sleep in " + $("#time").val() + " minutes");

        return false;
    });
}); 
