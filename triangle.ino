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