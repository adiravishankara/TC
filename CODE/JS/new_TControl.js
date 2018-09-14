
var thurstD = 1.5;
var thrust;
var pwmD = 1370;
var P = 0.09;
var err;
var uC;
var pwm = 1000;


// Creates a new file in the directory and then activates sensor reading
rcb.files.newLogFile({prefix:"stepTest11"});
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
function thrustControl(){
	err = thrustD - thurst; //calculates the error
	uC = P*err; // This value is the proportional control value (P is set by hand)
	pwm = pwmD + pwmD*uC;

	rcb.output.pwm("esc",pwm);
	rcb.wait(thrustControl,0.1);
}
//ESC initialization
rcb.console.print("Initializing ESC...");
rcb.output.pwm("esc",1000);
rcb.console.print("Activating Thrust Control");
rcb.wait(thrustControl,2);
