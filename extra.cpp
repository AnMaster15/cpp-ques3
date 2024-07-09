void setup(){
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
}

void blink(){
  int i=1;
   while(i<=5){
    digitalWrite(2*i,HIGH);
    delay(500);
    digitalWrite(2*i,LOW);
    i++;
  }
  
}

void loop(){
  int i=1;
  while(i<=5){
    digitalWrite(2*i,HIGH);
    delay(500);
    digitalWrite(2*i,LOW);
    i++;
  }
  int arr[5]={2,4,6,8,10};
  for(int i=0;i<5;i++){
    digitalWrite(arr[i],HIGH);
    delay(500);
    digitalWrite(arr[i],LOW);
  }
  delay(500);
  
  for(int i=2;i<=10;i++){
    switch(i){
    case 2: 
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    
    case 4: 
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    
    case 6: 
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    
    case 8: 
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    
    case 10: 
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    }
  }
  
  //blink();
  /*
  for(int i=4;i<=10;i=i+4)
  {
    digitalWrite(i,HIGH);
  }
  delay(2000);
  for(int i=2;i<=10;i=i+4)
  {
    digitalWrite(i,HIGH);
  }
  
  for(int i=2;i<=10;i=i+4)
  {
    digitalWrite(i,LOW);
  }
  delay(2000);
  for(int i=4;i<=10;i=i+4)
  {
    digitalWrite(i,LOW);
  }
  */
  
  int i=1;
  for(int j=0;j<3;j++){
    i=1;
   while(i<=5){
    digitalWrite(2*i,HIGH);
    delay(500);
    digitalWrite(2*i,LOW);
    i++;
   }
  }
  

}

void setup()
{
  pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
}

void loop()
{
for(int i=1;i<=5;i=i+2)
  {
    digitalWrite(i,HIGH);
  delay(2000);
  }
  
  for(int i=2;i<=4;i=i+2)
  {
    digitalWrite(i,HIGH);
    delay(2000);
  }
  
  for(int i=4;i>=2;i=i-2)
  {
    digitalWrite(i,LOW);
    delay(2000);
  }
  
  for(int i=5;i>=1;i=i-2)
  {
    digitalWrite(i,LOW);
    delay(2000);
  }
}

const int numLEDs = 6;  
const int ledPins[] = {1, 2, 3, 4, 5};  

void setup() {
  for (int i = 0; i < numLEDs; ++i) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int num = 0; num < 32; ++num) {
    for (int i = 0; i < numLEDs; ++i) {
      digitalWrite(ledPins[i], bitRead(num, numLEDs - 1 - i));
    }

    delay(500);
  }
}



int n = 5; 
int ledPins[] = {1,2,3,4,5}; 


void setup()
{
   pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
}

void loop()
{
 for (int count = 0; count < 3; ++count) {
    for (int i = 0; i < n; ++i) {
      digitalWrite(ledPins[i], HIGH);
      delay(500);  
      digitalWrite(ledPins[i], LOW);
      delay(500);
    }

    delay(1000); 
  }

  while (true) {
    
  }
  

}