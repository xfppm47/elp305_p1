Codes

Code for Square Wave
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


Code for Ramp Wave
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


Code for Pulse Wave
void setup()
{
pinMode(10, OUTPUT);
}
double load_factor = 0.4;
int time_period = 1000;
int prev_time = 0;
bool signal_high = false;
void loop()
{
int curr_time = millis();
if (signal_high){
if (curr_time - prev_time >= time_period*load_factor){
digitalWrite(10, LOW); signal_high = false;
prev_time = curr_time;
}
}
else {
if (curr_time - prev_time >= time_period*(1 - load_factor)){
digitalWrite(10, HIGH); signal_high = true;
prev_time = curr_time;
}
}
}


Code for triangular wave
#define OUTPUT_PWM_PIN 3
int x;
void setup()
{
pinMode(OUTPUT_PWM_PIN, OUTPUT);
}
void loop()
{
for (x = 0; x <= 255; x++)
{
analogWrite(OUTPUT_PWM_PIN, x);
delay(2);
}
for (x = 255; x >= 0; x--)
{
analogWrite(OUTPUT_PWM_PIN, x);
delay(2);
}
}


Code for sine wave
#include <avr/interrupt.h>
#include <stdlib.h>
char sinetable [32];
int i ;
int val = 0;
void ioinit (void)
{
DDRD = B11111111;
pinMode(A5, INPUT);
}
void timer_setup(){
TCCR2A = 0;
TCNT2= 455; //455 outputs 1.007khz
TCCR2B = B00000010;
//Timer2 Overflow Interrupt Enable
TIMSK2 = 1<<TOIE2;
}
void setup(){
Serial.begin(9600);
ioinit();
arraysetup();
cli();
timer_setup();
i = 0;
sei();
}
ISR(TIMER2_OVF_vect) {
PORTD=(sinetable[i++]);
TCNT2= val / 4;
if(i==32){
i=0;
}
}
void arraysetup(void){
sinetable[0]=127;
sinetable[1]=152;
sinetable[2]=176;
sinetable[3]=198;
sinetable[4]=217;
sinetable[5]=233;
sinetable[6]=245;
sinetable[7]=252;
sinetable[8]=254;
sinetable[9]=252;
sinetable[10]=245;
sinetable[11]=233;
sinetable[12]=217;
sinetable[13]=198;
sinetable[14]=176;
sinetable[15]=152;
sinetable[16]=128;
sinetable[17]=103;
sinetable[18]=79;
sinetable[19]=57;
sinetable[20]=38;
sinetable[21]=22;
sinetable[22]=10;
sinetable[23]=3;
sinetable[24]=0;
sinetable[25]=3;
sinetable[26]=10;
sinetable[27]=22;
sinetable[28]=38;
sinetable[29]=57;
sinetable[30]=79;
sinetable[31]=103;
}
void loop()
{ val = analogRead(A5);
Serial.println(val);
}
