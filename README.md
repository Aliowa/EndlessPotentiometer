# EndlessPotentiometer
  Library that works with 4 pin endless potentiometers (360 degree Sin/Cos)
  Constructror gets step in degrees (float, ex 2.4f) and number of samples(byte, ex 4)
  
  Example:
  
  EndlessPotentiometer pot(2.0f, 2); //Step 2 degrees and 2 samples taken
  
  void example() {
  const int potPinA = 1; //Potentiometer pin 1 -> ADC channle 1
  const int potPinB = 2; //Potentiometer pin 2 -> ADC channel 2
  static int value = 0;
  int anglePrev;
  int angleNow = pot.getAngle(potPinA, potPinB);
  if (abs(anglePrev - angleNow) > pot.getStep()) {
    if (angleNow > anglePrev)
      value++;
    else
      value--;
    doSomething(value)
    anglePrev = angleNow;
  }
}
  
