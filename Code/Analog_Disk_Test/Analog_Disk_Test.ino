
// to the pins used:
const int analogInPin_XL = A2;  // Analog input pin that the potentiometer is attached to
const int analogInPin_XR = A3;

const int analogInPin_YU = A0;
const int analogInPin_YD = A1;

const int analogInPin_T0 = A4;

int sensorValue_XL_0 = 0;
int sensorValue_XL_1 = 0;
int sensorValue_XR_0 = 0;
int sensorValue_XR_1 = 0;

int sensorValue_YU_0 = 0;
int sensorValue_YU_1 = 0;
int sensorValue_YD_0 = 0;
int sensorValue_YD_1 = 0;


int sensorValue_T0_0 = 0;
int sensorValue_T0_1 = 0;
 
int voidValue = 2;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  sensorValue_XL_0 = analogRead(analogInPin_XL);
  sensorValue_XL_1 = sensorValue_XL_0;
  sensorValue_XR_0 = analogRead(analogInPin_XR);
  sensorValue_XR_1 = sensorValue_XR_0;
  sensorValue_YU_0 = analogRead(analogInPin_YU);
  sensorValue_YU_1 = sensorValue_YU_0;
  sensorValue_YD_0 = analogRead(analogInPin_YD);
  sensorValue_YD_1 = sensorValue_YD_0;
  sensorValue_T0_0 = analogRead(analogInPin_T0);
  sensorValue_T0_1 = sensorValue_T0_0;
}

void loop() {
  // read the analog in value:
  sensorValue_XL_0 = analogRead(analogInPin_XL);
  sensorValue_XR_0 = analogRead(analogInPin_XR);
  sensorValue_YU_0 = analogRead(analogInPin_YU);
  sensorValue_YD_0 = analogRead(analogInPin_YD);
  sensorValue_T0_0 = analogRead(analogInPin_T0);
  
  // print the results to the serial monitor:
  if ((sensorValue_XL_1 > sensorValue_XL_0 - voidValue) and (sensorValue_XL_1 < sensorValue_XL_0 + voidValue) and
      (sensorValue_XR_1 > sensorValue_XR_0 - voidValue) and (sensorValue_XR_1 < sensorValue_XR_0 + voidValue) and
      (sensorValue_YU_1 > sensorValue_YU_0 - voidValue) and (sensorValue_YU_1 < sensorValue_YU_0 + voidValue) and
      (sensorValue_YD_1 > sensorValue_YD_0 - voidValue) and (sensorValue_YD_1 < sensorValue_YD_0 + voidValue) and
      (sensorValue_T0_1 > sensorValue_T0_0 - voidValue) and (sensorValue_T0_1 < sensorValue_T0_0 + voidValue))
  {
    //Serial.print("sensor = TEST\n");
  }
  else
  {
    Serial.print("LEFT = ");
    Serial.print(sensorValue_XL_0);
    Serial.print("\t");
    
    Serial.print("RIGHT = ");
    Serial.print(sensorValue_XR_0);
    Serial.print("\t");
    
    Serial.print("UP = ");
    Serial.print(sensorValue_YU_0);
    Serial.print("\t");
    
    Serial.print("DOWN = ");
    Serial.print(sensorValue_YD_0);
    Serial.print("\t");

    Serial.print("TRIGGER = ");
    Serial.print(sensorValue_T0_0);
    Serial.print("\n");
  }

  delay(2);
  
  sensorValue_XL_1 = sensorValue_XL_0;
  sensorValue_XR_1 = sensorValue_XR_0;
  sensorValue_YD_1 = sensorValue_YD_0;
  sensorValue_YU_1 = sensorValue_YU_0;
  sensorValue_T0_1 = sensorValue_T0_0;
    
    
}
