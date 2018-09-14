rcb.files.newLogFile({prefix:"TC"});

function readSensor(){
    rcb.console.setVerbose(false);
    rcb.sensors.read(readDone, 10);
    rcb.console.setVerbose(true);
}
function readDone(result){
    rcb.console.setVerbose(false);
    rcb.files.newLogEntry(result,readSensor);
    rcb.console.setVerbose(true);
}
function send_start(){
    rcb.output.pwm("esc", 2300);
    rcb.wait(function(){},1);
    rcb.wait(readSensor,0.00000000001);
}

rcb.wait(send_start,1);
