const int gasPin = A0; //deklarasi Sensor Gas MQ2 ke pin Analog A0
const int speakerPin = 8; //deklarasi Buzzer ke pin Digital 8

void setup() {
  Serial.begin(115200); //deklarasi rate data  dalam bits per second (baud) untuk serial data transmission sebesar 115200
}

void loop() {
  int val=analogRead(gasPin); //mendeklarasi Inputan dari Sensor MQ2 menjadi variable val dengan tipe data int
  val=map(val,0,1023,0,100); //map(value, fromLow, fromHigh, toLow, toHigh)
  /*
   * value    : the number to map
   * fromLow  : the lower bound of the value's current range  
   * fromHigh : the upper bound of the value's current range  
   * toLow    : the lower bound of the value's target range   
   * toHigh   : the upper bound of the value's target range
   */

  if(val>51) //mengecek jika data dari sensor MQ2 lebih dari 51
  {
    //Start code ditampilkan jika kepekat gas diatas 51%
    Serial.println(val); //mengambil data dari variabel "val"
    //End Code
    SoundOn();//fungsi menghidupkan Buzzer
  }

  else if(val>26) //mengecek jika data dari sensor MQ2 lebih dari 26
  {
    //Start code ditampilkan jika kepekat gas diatas 26%
    Serial.println(val); //mengambil data dari variabel "val"
    //End Code
    pinMode (speakerPin, INPUT); //code untuk mematikan Buzzer
  }

  else if(val>0) //mengecek jika data dari sensor MQ2 lebih dari 0
  {
    //Start code ditampilkan jika kepekat gas diatas 0%
    Serial.println(val); //mengambil data dari variabel "val"
    //End Code
    pinMode (speakerPin, INPUT); //code untuk mematikan Buzzer
  }
  delay(6000);
} 

void SoundOn(){
    //Start code menghidupkan Buzzer
    noTone(speakerPin);

    tone(speakerPin,50);
    delay(50);
    
    noTone(speakerPin);
    
    tone(speakerPin,0);
    delay(10);
    
    noTone(speakerPin);
    //End code
}


