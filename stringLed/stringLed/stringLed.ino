char incomingByte = '0'; // for incoming serial data
byte pointer=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.println("I received: " +String(incomingByte)+ " ascii = " +int(incomingByte));
    //convert to binary and showing
    if( int(incomingByte) != 32 && int(incomingByte) != 10 ){ // si es diferente de espacio, hacer la iteración
      int current = incomingByte;
      byte byteArr[8] = {254, 254, 254, 254, 254, 254, 254, 254};

      //metiendo los valores a la pila
      for(int i=1; i <= 8; i++){
        if(pointer <= 8 && current <= 0){ push(byteArr, 0); }
        else{
          byte state = current % 2;
          //Serial.println("Poniendo en posicion " +String(pointer)+ " el valor de " +String(state));
          push(byteArr, state);
          delay(400);
          current = (int)(current / 2);
        }
      }

      
      Serial.println();

      //sacando los valores de la pila
      for(int i=1; i <= 8; i++){
        byte myValue = pop(byteArr);
        Serial.print(myValue);
        digitalWrite(LED_BUILTIN, myValue);
        delay(400);
      }
      Serial.println();
    }else {
      delay(2000);
    }
  }
}

void push(byte *arr, byte value){
  if(pointer >= 8) {
    Serial.println("Pila llena...");
    return;
  }
  
  *(arr+pointer) = value;
  if(pointer < 7) pointer++;
}

byte pop(byte *arr){
  if(pointer < 0) {
    Serial.println("Pila ya está vacía...");
    return -1;
  }

  byte toReturn = *(arr+pointer);
  *(arr+pointer) = 254;
  if(pointer != 0) pointer--;
  return toReturn;
}

void setAsEmpty(byte *arr){
  byte i=0;
  while(i < 8){
    *(arr+i) = 254;
    i++;
  }
}
