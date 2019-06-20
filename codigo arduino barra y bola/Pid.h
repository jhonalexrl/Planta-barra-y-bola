


//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,10,3,5,P_ON_E, DIRECT); //P_ON_M specifies that Proportional on Measurement be used
                                                            //P_ON_E (Proportional on Error) is the default behavior

void SetupPid()
{
  //initialize the variables we're linked to
  Input = dist();
  Setpoint = 20;

  //turn the PID on
    myPID.SetTunings(2.5,0,1.5);
    myPID.SetControllerDirection(DIRECT);
    myPID.SetSampleTime(50);
    myPID.SetOutputLimits(0,140);
//    myPID.Initialize();  
    myPID.SetMode(AUTOMATIC);

}

void TareaPID()
{
  Input = dist();
  myPID.Compute();
//Serial.print(Input);
//Serial.print(" ");
//Serial.println(Output);

//myservo= Serial.read();            //  lee el valor del potenciómetro (valor entre 0 y 1023)
//Output = map(Output, 0, 1023, 0, 150);     // escala para usarlo con el servo (valor entre 0 y 180)
myservo.write(Output); 


}
