var set_rpm = [1200,1000,1300,1000,1400,1000,1500,1000,1600,1000,1700,1000,1800,1000,1900,1000,2000,1000];
var run_time = 30;
var i = 0;
// Creates a new file in the directory and then activates sensor reading
rcb.files.newLogFile({prefix:"stepTest"});
readSensor();


//These functions are used together to read and set the thrust actual value

function readSensor(){
    rcb.console.setVerbose(false);
    rcb.sensors.read(readDone, 10);
    rcb.console.setVerbose(true);
}
function readDone(result){
    rcb.console.setVerbose(false);
    rcb.files.newLogEntry(result,readSensor);
    thrust = result.thrust.displayValue;
    
    rcb.console.setVerbose(true);
}
function stepUP(){
    rcb.console.print(i);
    rcb.console.print(set_rpm[i]);
    rcb.output.pwm("esc",set_rpm[i]);
    i++;
    if(i > 18){ i =18 ;}
    rcb.wait(stepUP,run_time);
}

//ESC initialization
rcb.console.print("Initializing ESC...");
rcb.output.pwm("esc",1000);
rcb.console.print("Activating Thrust Control");
rcb.wait(stepUP,2);