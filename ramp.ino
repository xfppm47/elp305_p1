/*Negative Slope Ramp.
In this case not all range of frequencies
gives appropriate ramp cause of the 
filtering nature of the cap in this circuit.

Limit in bandwidth of input!

Sometimes during change in frequency or amplitude 
the output gets distored. Our guess is due to cap overloading 
when going beyond the bandwidth limit. 

Stopping and running the simulation
does seem to solve the problem for the sake of observation.
*/

void setup(){
  pinMode(A1, INPUT);
  pinMode(4, OUTPUT);

}

void loop(){
  int input = analogRead(A1); 
  digitalWrite(4,HIGH);
  delay(0.5);
  digitalWrite(4, LOW);
 
  delay(input);
}

