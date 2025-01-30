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