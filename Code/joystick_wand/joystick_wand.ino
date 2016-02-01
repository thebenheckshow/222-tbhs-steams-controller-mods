
// to the pins used:

const int analogInPin_U = A0;
const int analogInPin_D = A1;
const int analogInPin_L = A2;  // Analog input pin that the potentiometer is attached to
const int analogInPin_R = A3;
const int analogInPin_T = A4;

int deadZone = 590;
int limit	= 385;

int xValue = 512;
int yValue = 512;
int tValue = 512;

int upValue = 0;
int downValue = 0;
int leftValue = 0;
int rightValue = 0;
int trigValue = 0;

void setup() {

  //Serial.begin(9600);
  
  Joystick.useManualSend(true);

}


void loop() {

	//Get hall effect values
	
	upValue = analogRead(analogInPin_U);
	downValue = analogRead(analogInPin_D);
	
	leftValue = analogRead(analogInPin_L);
	rightValue = analogRead(analogInPin_R);	
	trigValue = analogRead(analogInPin_T);

	xValue = 512 - map(leftValue, 360, 585, 512, 0);
	xValue += map(rightValue, 430, 585, 512, 0);
	
	if (xValue < 0) {		
		xValue = 0;
	}
	if (xValue > 1023) {		
		xValue = 1023;		
	}	

	yValue = 512 - map(upValue, 410, 580, 512, 0);
	yValue += map(downValue, 425, 590, 512, 0);
	
	if (yValue < 0) {		
		yValue = 0;		
	}
	if (yValue > 1023) {		
		yValue = 1023;		
	}
	
	tValue = map(trigValue, 150, 450, 0, 512);
	
	if (tValue < 0) {		
		tValue = 0;	
	}

	if (xValue < 256) {		
		Keyboard.press(KEY_A);		
	}
	else {
		Keyboard.release(KEY_A);		
	}
	if (xValue > 768) {		
		Keyboard.press(KEY_D);		
	}
	else {
		Keyboard.release(KEY_D);		
	}
	if (yValue < 256) {		
		Keyboard.press(KEY_W);		
	}
	else {
		Keyboard.release(KEY_W);		
	}
	if (yValue > 768) {		
		Keyboard.press(KEY_S);		
	}
	else {
		Keyboard.release(KEY_S);		
	}
	if (tValue < 400) {		
		Keyboard.press(KEY_SPACE);		
	}
	else {
		Keyboard.release(KEY_SPACE);		
	}
	
	
	//Serial.print(xValue, DEC);
	//Serial.print("\t");
	//Serial.println(yValue, DEC);	
  
	Joystick.X(xValue);		//Send the inverse
	Joystick.Y(yValue);
	
	Joystick.Z(tValue);
  
  
  //Joystick.Z(analogRead(2));
  //Joystick.Zrotate(analogRead(3));
  //Joystick.sliderLeft(analogRead(4));
  //Joystick.sliderRight(analogRead(5));

  
  // Because setup configured the Joystick manual send,
  // the computer does not see any of the changes yet.
  // This send_now() transmits everything all at once.
	Joystick.send_now();

  // a brief delay, so this runs "only" 200 times per second
	delay(5);
}

