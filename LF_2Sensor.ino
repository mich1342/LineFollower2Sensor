#define sL A0
#define sR A1

#define Pin1 5
#define Pin2 6   
#define Pin3 9
#define Pin4 10

int L, R;

int batas = 250;

int SpeedL = 150;
int SpeedR = 125 ;

void setup() {
  Serial.begin(115200);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT); 
  pinMode(sL, INPUT);
  pinMode(sR, INPUT);
}

void loop() {
  baca();
  gerak();
}

void gerak(){
  if((L > batas) && (R > batas)){
    maju();    
  }
  if((L < batas) && (R > batas)){
    kiri();    
  }
  if((L > batas) && (R < batas)){
    kanan();    
  }
  if((L < batas) && (R < batas)){
    diam();    
  }
}

void baca(){
  L = analogRead(sL);
  R = analogRead(sR);
  Serial.print(L);
  Serial.print(" ");
  Serial.println(R);
}

void maju(){
  analogWrite(Pin1, SpeedL);
  analogWrite(Pin2, 0);
  analogWrite(Pin3, SpeedR);
  analogWrite(Pin4, 0);
}

void kiri(){
  analogWrite(Pin1, SpeedL);
  analogWrite(Pin2, 0);
  analogWrite(Pin3, 0);
  analogWrite(Pin4, SpeedR);
}

void kanan(){
  analogWrite(Pin1, 0);
  analogWrite(Pin2, SpeedL);
  analogWrite(Pin3, SpeedR);
  analogWrite(Pin4, 0);
}

void diam(){
  analogWrite(Pin1, 0);
  analogWrite(Pin2, 0);
  analogWrite(Pin3, 0);
  analogWrite(Pin4, 0);
}
