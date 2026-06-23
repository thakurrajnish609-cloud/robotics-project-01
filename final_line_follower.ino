int IN1 = 25;
int IN2 = 26;
int IN3 = 27;
int IN4 = 14;

int leftSensor = 32;
int rightSensor =33;

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

}

void loop(){
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);
  
  //case 1 : both sensor on white > to go stringht
  if (leftValue == 1 && rightValue == 1) {
    forword();
  }
  

  // case 2: left sensor black >turn left
  else if (leftValue == 0 && rightValue == 1) {
    leftTurn();
  }

    //case 3 : right sensor black > turn right
    else if (leftValue == 1 && rightValue == 0){

    }

    // case 4 : both black > stop (junction)
    else {
      stopMotor();
    }
  }
  
  void forword(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  void  leftTurn(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
  }
  void rightTurn(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
   void stopMotor(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

   }
