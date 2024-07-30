
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(2, OUTPUT); // Bar INC
  pinMode(3, OUTPUT); // U/D
  pinMode(4, OUTPUT); // Bar CS
  pinMode(13, OUTPUT); // LED

  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay(100);

  digitalWrite(13, HIGH);

  // 最も低い値にする
  digitalWrite(3, LOW);
  delay(100);

  for(uint8_t i = 0; i < 130; i++) {
    digitalWrite(2, HIGH);
    delay(30);
    digitalWrite(2, LOW);
    delay(30);
    Serial.println(i);
  }

  // 値を50タップ上げる
  digitalWrite(3, HIGH);
  delay(100);

  for(uint8_t i = 0; i < 50; i++) {
    digitalWrite(2, HIGH);
    delay(30);
    digitalWrite(2, LOW);
    delay(30);
    Serial.println(i);
  }
  // 値の記録
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);

  digitalWrite(13, LOW);
}

void loop() {

}