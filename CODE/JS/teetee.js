//My Variables
var escSpeed = 1000;
var thrust;
var thrustd = 2.5;
var pwmd = 1350;
var P = 0.09;
var e;
var uc;
var pwm;
var output = 1100;
var timer, timer2;
//reading the sensor;
rcb.files.newLogFile({prefix:"stepTest11"});
readSensor();
function readSensor(){
    rcb.console.setVerbose(false);
    rcb.sensors.read(readDone, 3);
    rcb.console.setVerbose(true);
}
function readDone(result){
    rcb.console.setVerbose(false);
    rcb.files.newLogEntry(result,readSensor);
    //thrust = result.thrust.displayValue;
    
    rcb.console.setVerbose(true);
}

//ESC initialization
rcb.console.print("Initializing ESC...");
rcb.output.pwm("esc",1000);
//rcb.output.pwm("esc",1350);
rcb.console.print("Activating Thrust Control");
rcb.wait(steps,2);

//Thrust contorl function

function thrustControl(){

    e = thrustd - thrust;
    uc = P*e;
    pwm = pwmd; //+pwmd*uc;
    rcb.output.pwm("esc",pwm);
    //rcb.console.print(thrust);
    // if(window.performance.now()/1000%10 === 0){
    //     rcb.console.clear();
    // }
    rcb.wait(thrustControl,0.000000001);
    
}
function steps(){
    
    rcb.output.pwm("esc",output);
    //timer = window.performance.now();


    
    if(output > 2300){ 
        rcb.wait(rcb.endScript,1);
    }else if(output <2300){
    rcb.wait(rcb.console.clear(),5);
    steps();
    }
    }