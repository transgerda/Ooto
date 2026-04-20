const int buzzer_pin = 8;
const int echo_pin_1 = 13;
const int trigger_pin_1 = 12;

const int drive_pin_right = 4;
const int reverse_pin_right = 5;
const int reverse_pin_left = 6;
const int drive_pin_left = 7;

long duration;
float distance;

void setup() {
  pinMode(trigger_pin_1, OUTPUT);
  pinMode(echo_pin_1, INPUT);
  pinMode(buzzer_pin, OUTPUT);

  pinMode(drive_pin_right, OUTPUT);
  pinMode(drive_pin_left, OUTPUT);
  pinMode(reverse_pin_right, OUTPUT);
  pinMode(reverse_pin_left, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger_pin_1, LOW);

  delayMicroseconds(2);

  digitalWrite(trigger_pin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin_1, LOW);

  duration = pulseIn(echo_pin_1, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Afstand: ");
  Serial.print(distance);
  Serial.println(" cm");

 
  // ===== DRIVING LOGIC =====
  if (distance > 25) {
    driveForward();
  }
  else {
    stopDriving();
    delay(100);
    if (random(0, 2) == 0) {
…}

void turnLeft() {
  digitalWrite(reverse_pin_right, HIGH);
  digitalWrite(drive_pin_right, LOW);
  
  digitalWrite(reverse_pin_left, LOW);
  digitalWrite(drive_pin_left, HIGH);
}

void turnRight() {
  digitalWrite(reverse_pin_right, LOW);
  digitalWrite(drive_pin_right, HIGH);
  
  digitalWrite(reverse_pin_left, HIGH);
  digitalWrite(drive_pin_left, LOW);
}

void stopDriving() {
  digitalWrite(drive_pin_right, LOW);
  digitalWrite(drive_pin_left, LOW);
}

void driveForward() {
  digitalWrite(reverse_pin_right, LOW);
  digitalWrite(drive_pin_right, HIGH);

  digitalWrite(reverse_pin_left, LOW);
  digitalWrite(drive_pin_left, HIGH);
}

void driveBackward() {
  digitalWrite(reverse_pin_right, HIGH);
  digitalWrite(drive_pin_right, LOW);

  digitalWrite(reverse_pin_left, HIGH);
  digitalWrite(drive_pin_left, LOW);
}