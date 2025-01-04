#define trigpin 6
#define echopin 5
#define buzzerpin 8
void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzerpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  // Measure the time taken for the echo
  long duration = pulseIn(echopin, HIGH);

  // Calculate distance in centimeters
  float distance = duration * 0.034 / 2;

  // Check if the distance is approximately 10 cm
  if (distance >= 9.5 && distance <= 10.5) {
    // Turn on the buzzer
    digitalWrite(buzzerpin, HIGH);
    delay(100); // Beep duration
    // Turn off the buzzer
    digitalWrite(buzzerpin, LOW);
  }
  delay(1000);

}