byte minSpeed = 55;
byte a1 = 2;
byte a2 = 4;
byte aSpeedPIN = 3;
byte b1 = 7;
byte b2 = 8;
byte bSpeedPIN = 5;

void InitMotors() {
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(aSpeedPIN, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(bSpeedPIN, OUTPUT);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
}

void RunRight(double speedRaw) {
  if (speedRaw < 0) {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
  } else {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
  }

  analogWrite(aSpeedPIN, map(abs(speedRaw), 0, 50, minSpeed, 255));
}

void RunLeft(double speedRaw) {
  if (speedRaw < 0) {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
  } else {
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
  }

  analogWrite(bSpeedPIN, map(abs(speedRaw), 0, 50, minSpeed, 255));
}

void RunMotors(double speedRight, double speedLeft) {
  RunRight(speedRight);
  RunLeft(speedLeft);
}
