/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Joystick controlled car**************
*************************
*/
int xVal; //X values from joystick1
int yVal; //Y values from joystick1
int xVal2; //X values from joystick2
int yVal2; //Y values from joystick2

int enA = 9;//setting pin 9 as the enable pin of motor1
int in1 = 5;//setting pin 5 as the input command for motor1
int in2 = 4;//setting pin 4 as the input command for motor1
int enB = 10;//setting pin 10 as the enable pin of motor2
int in3 = 3;//setting pin 3 as the input command for motor2
int in4 = 2;//setting pin 2 as the input command for motor2


void setup() {


  Serial.begin(9600); //Starts serial at 9600 baud

  pinMode(A0, INPUT); //Sets the analog ports used to an input
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); //Sets the analog ports used to an input
  pinMode(A3, INPUT);
  pinMode(enA, OUTPUT);//Sets the digital ports used to an output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(enA, HIGH);//setting enable pin of motor high
  digitalWrite(enB, HIGH);

}

void loop()
{

  xVal = analogRead(A0); //reads the X value from joystick 1

  yVal = analogRead(A1); //reads the Y value from joystick 1

  xVal2 = analogRead(A2); //reads the X value from joystick 2

  yVal2 = analogRead(A3); //reads the Y value from joystick 2
 
  if ((yVal >= 400) && (xVal >= 1000))
  {

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("first motor forward");//motor1 runs forward
  }

  if ((yVal >= 400) && (xVal <= 100))
  {
    digitalWrite(enA, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("first motor backward");//motor1 runs forward
  }

//  if ((yVal >= 900) && (xVal >= 400))
//  {
//    Serial.println("First motor right");
//  }

//  if ((yVal <= 100) && (xVal >= 400))
//  {
//    Serial.println("First motor left");
//  }
  if ((yVal <= 600) && (xVal <= 600) && (yVal >= 400) && (xVal >= 400))
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
//    Serial.println("first motor rest");
  }
  if ((yVal2 >= 400) && (xVal2 >= 1000))
  {


    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("second motor forward");//motor2 runs forward
  }

  if ((yVal2 >= 400) && (xVal2 <= 100))
  {

    digitalWrite(enB, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("second motor backward");//motor2 runs forward
  }

//  if ((yVal2 >= 900) && (xVal2 >= 400))
//  {
//    Serial.println("second motor right");
//  }

//  if ((yVal2 <= 100) && (xVal2 >= 400))
//  {
//    Serial.println("second motor left");
//  }
  if ((yVal2 <= 600) && (xVal2 <= 600) && (yVal2 >= 400) && (xVal2 >= 400))
  {

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
//    Serial.println("second motor rest");
  }

  delay(300);
}       
