var pwm =1100;
rcb.output.pwm("esc",pwm);
rcb.wait(thrustRamp,1);

function thrustRamp(){
    pwm++;
    rcb.output.pwm("esc",pwm);
    rcb.wait(thrustRamp,0.1);
}