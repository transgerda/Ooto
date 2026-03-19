const int buzzer_pin = 8;
const int echo_pin_1 = 9;
const int trigger_pin_1 = 10;

const int drive_pin_left = 7;
const int drive_pin_right = 4;
const int drive_pin_2 = 5;
const int drive_pin_3 = 6;

long duration;
float distance;

void setup() {
  pinMode(trigger_pin_1, OUTPUT);
  pinMode(echo_pin_1, INPUT);
  pinMode(buzzer_pin, OUTPUT);

  pinMode(drive_pin_right, OUTPUT);
  pinMode(drive_pin_left, OUTPUT);
  pinMode(drive_pin_2, OUTPUT);
  pinMode(drive_pin_3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger_pin_1, LOW);

  delayMicroseconds(2);

  digitalWrite(trigger_pin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin_1, LOW);

  duration = pulseIn(echo_pin_1, HIGH);

  if (duration > 3000) {
    Serial.println('Afstant te groot');
  } else {
    distance = duration * 0.034 / 2;

    Serial.print("Afstand: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  turnLeft();m
  delay(2000);
  turnRight();
  delay(2000);
  driveForward();
  delay(2000);
  stopDriving();
  delay(10000);
}

void turnLeft() {
  digitalWrite(drive_pin_right, HIGH);
  digitalWrite(drive_pin_left, LOW);
}

void turnRight() {
  digitalWrite(drive_pin_right, LOW);
  digitalWrite(drive_pin_left, HIGH);
}

void stopDriving() {
  digitalWrite(drive_pin_right, LOW);
  digitalWrite(drive_pin_left, LOW);
}

void driveForward() {
  digitalWrite(drive_pin_right, HIGH);
  digitalWrite(drive_pin_left, HIGH);
}