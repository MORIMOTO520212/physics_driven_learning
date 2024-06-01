void setup() {
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
}

uint8_t clock = 0;
void loop() {
  digitalWrite(7, clock);
  digitalWrite(13, clock);
  clock ^= 1;
  delay(1000);
}