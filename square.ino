void setup(){
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);

}

void loop(){
  int d = analogRead(A0); // the reading from the potetiometer
  digitalWrite(7,HIGH);
  delay(d);
  digitalWrite(7, LOW);
  delay(d);
}