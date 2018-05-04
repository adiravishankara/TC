/** The calculations
yd = thrust nominal (the desired thrust)
un = pwm nominal (pwm for desired thrust)
y = measured thrust
e = yd - y (the error between desired and measured)
P = 0.2 The proportional constant
uc = e*P
u = uc+un


**/
//
//
//
//var yd = 2.5;
//var y = result.thrust.displayvalue;
//
//rcb.console.print("Listening for keypress...");
//rcb.onKeyboardPress(function(key){
//var ascii = String.fromCharCode(key);
//rcb.console.print("You pressed " + ascii);
//});
//// up arrow == &
////down arrow == (
////left arrow == %
////right arrow = '
//
////Continuous recording
//rcb.files.newLogFile({prefix:"ThrustTest"});
//readSensor();
//function readSensor(){
//    rcb.sensors.read(saveResult,10);
//}function saveResult(result){
//    rcb.files.newLogEntry(result,readSensor);
//}
//var output = 1200;
//rcb.output.pwm("esc",output);
//
//

rcb.console.print("Initializing ESC...");
rcb.output.pwm("esc",1000);

rcb.wait(thrustControl,2);

//My Variables
var escSpeed = 1000;
var thrust;
var thrustd = 2.5;
var pwmd = 1350;
var P = 0.2;
var e;
var uc;
var pwm;
//reading the sensor;
readSensor();
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

//ESC initialization
rcb.console.print("Initializing ESC...");
rcb.output.pwm("esc",escSpeed);
rcb.wait(thrustControl,2);

//Thrust contorl function
function thrustControl(){
    rcb.console.print("Thrust Control is Active");
    e = thrustd - thrust;
    uc = P*e;
    pwm = uc + pwmd;
    rcb.output.pwm("esc",pwm);
    rcb.wait(thrustControl,0.001)
}
//use ramp function to go between current and desired speeds.
//rcb.sensors.read(callback,1);
//
//function callback(result){
//    result.thrust.displayValue;
//}
//var ascii;
//rcb.console.print("Listening for keypress...");
//rcb.onKeyboardPress(function(key){
//ascii = String.fromCharCode(key);
//rcb.console.print("You pressed " + ascii);
//});
//if(ascii == "A"){
//    escSpeed = 1150;
//}
//
//


