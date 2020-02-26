#define STOP      0
#define FORWARD   1
#define BACKWARD  2
#define JUMP  3
#define JUMPRETURN 4

int leftMotor1 = 4;
int leftMotor2 = 5;
int rightMotor1 = 6;
int rightMotor2 = 7;
int jumpMotor = 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(jumpMotor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //usart read
  if(Serial.available()>0)
  {
    char cmd = Serial.read();//Read the data sent by the Bluetooth module to the serial port
  
    Serial.print(cmd);
    motorRun(cmd);
      
  }  
}
void motorRun(int cmd)
{
  switch(cmd){
    case FORWARD:
      Serial.println("FORWARD"); //output status
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     case BACKWARD:
      Serial.println("BACKWARD"); //output status
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case TURNLEFT:
      Serial.println("TURN  LEFT"); //output status
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case TURNRIGHT:
      Serial.println("TURN  RIGHT"); //output status
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     default:
      Serial.println("STOP"); //输出状态
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
  }
}

//BasicFunctions
//Go STRAIGHT
void STR(){
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL2,LOW);
}

//Turn LEFT
void L(){
  digitalWrite(motorL1,LOW);
  digitalWrite(motorR2,LOW);
  analogWrite(motorL2,100);
  analogWrite(motorR1,100);
}

//Turn RIGHT
void R(){
  digitalWrite(motorL2,LOW);
  digitalWrite(motorR1,LOW);
  analogWrite(motorL1,100);
  analogWrite(motorR2,100);
}

//BACKWARD
void back(){
  digitalWrite(motorL1,LOW);
  digitalWrite(motorR1,LOW);
  analogWrite(motorL2,100);
  analogWrite(motorR2,100);
}

//STOP
void stop(){
  digitalWrite(motorL1,LOW);
  digitalWrite(motorR1,LOW);
  digitalWrite(motorL2,LOW);
  digitalWrite(motorR2,LOW);
}