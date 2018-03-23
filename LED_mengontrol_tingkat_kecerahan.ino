// pin 2 & 3 sebagai input digital
const int PIN_BT1 = 2;
const int PIN_BT2 = 3;

//ingat, pin 9 support PWM
const int PIN_LED = 9;

void setup() {
 pinMode (PIN_BT1, INPUT);
 pinMode (PIN_BT2, INPUT);
 pinMode (PIN_LED, OUTPUT);

 digitalWrite(PIN_BT1, HIGH);
 digitalWrite(PIN_BT2, HIGH);
}

int brightness = 0;

void loop() {
  if (digitalRead (PIN_BT1) == LOW)
  {
    //jika pushbutton ditekan
    //tambahkan nilai brightness
    brightness++;
  }
  else if (digitalRead (PIN_BT2) == LOW)
  {
    //jika pushbutton2 ditekan
    //kurangi nilai brightness
    brightness--;
  }

  //brightness dibatasi antara 0-255
  //jika dibawah 0,maka diganti dengan 0
  //jika diatas 255, maka diganti dengan 255

  brightness = constrain(brightness, 0, 255);

  //PIN_LED diberi nilai antara 0-255
  analogWrite(PIN_LED, brightness);
  //delay agar perubahannya bertahap
  delay(20);
}
