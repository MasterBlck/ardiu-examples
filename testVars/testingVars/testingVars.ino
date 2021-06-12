/*
 * Programa para checar los tipos de datos y variables que maneja Arduino
 * 
 */
//Declaración de variables GLOBALES
boolean myBoolean;
char    myChar;
int     myInt;
float   myFloat;
String  myString;


void setup() {
  Serial.begin(9600);
  myBoolean = false;
  myChar    = 'a';
  myInt     = 10;
  myFloat   = 3.1416;
  myString  = "Hola Arduino";
}

void loop() {
  // checking the boolean
  if (!myBoolean){
    Serial.println("Not myBoolean");
  } else {
    Serial.println("Yes myBoolean");
  }

  //playing with char & int
  Serial.print("myChar is currently: ");
  Serial.write(myChar);
  Serial.println();

  Serial.print("myInt is currently: ");
  Serial.print(myInt);
  Serial.println();

  Serial.print("Then here is myChar + myInt: ");
  Serial.write(myChar + myInt);
  Serial.println();

  //playing with float & int
  Serial.print("myFloat is: ");
  Serial.print(myFloat);
  Serial.println();

  //putting the content of myFloat into myInt
  myInt = myFloat;
  Serial.print("I put myFloat into myInt, and here is myInt now: ");
  Serial.println(myInt);

  //playing with String
  Serial.print("myString is currently: ");
  Serial.println(myString);

  myString += myChar; //concatening myString with myChar
  Serial.print("myString has a lenght of ");
  Serial.print(myString.length());
  Serial.print(" and equiale now ");
  Serial.println(myString);

  //myString becomes too long, more than 15, removing the las 3 elements
  if( myString.length() > 15 ){
    Serial.println("myString too long... Come on, let's clean it up!");
    myInt = myString.lastIndexOf('!'); //Finding the place of the '!'
    myString = myString.substring(0, myInt+1);  //removing Characters
    Serial.print("myString is now cleanner: ");
    Serial.println(myString);
  } else {
    myBoolean = false;
  }

  delay(10000);
  Serial.println();
  Serial.println();
}
