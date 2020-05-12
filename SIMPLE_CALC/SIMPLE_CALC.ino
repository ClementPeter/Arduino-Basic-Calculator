//ARDUINO TUTORIAL48  ASSIGNMENT BUILD A SIMPLE CALCULATOR USING THE LCD AND THE ARDUINO

#include <LiquidCrystal.h>

int RS = 7;
int E = 8;
int D4 = 9;
int D5 = 10;
int D6 = 11;
int D7 = 12;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

float val1;
float val2;
float ans;
String add = "+";
String subtract = "-";
String multiply = "*";
String divide = "/";

String myoperator;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(val1, OUTPUT);
  pinMode(val2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //VALUE 1
  lcd.setCursor(0, 0);
  lcd.print("First Value:");
  Serial.println("Enter your first value");

  while (Serial.available() == 0) {

  }
  val1 = Serial.parseInt();
  lcd.setCursor(0, 1);
  Serial.println(val1);

  lcd.print(val1);
  delay(400);

  lcd.clear();


  //VALUE 2
  lcd.setCursor(0, 0);
  lcd.print("Second value :");
  Serial.println("Enter your Second value");

  while ( Serial.available() == 0) {

  }
  val2 = Serial.parseInt();
  lcd.setCursor(0, 1);
  lcd.print(val2);
  Serial.println(val2);
  delay(300);
  lcd.clear();

  //OPERATOR
  Serial.println("Enter your operator : (+, -, *, / ) ");
  lcd.print("Operator: ");

  while (Serial.available() == 0) {
  }
  myoperator = Serial.readString();

  Serial.println(myoperator);

  lcd.print(myoperator);
  delay(500);
  lcd.clear();


  //MATHS  CONDTION 1 +
  if (myoperator == add) {
    ans = val1 + val2;
    Serial.println("SUM ");
    Serial.print(val1);
    Serial.print(add);
    Serial.print( val2);
    Serial.print(" = ");
    Serial.println(ans);
    Serial.println(" ");

    lcd.setCursor(0, 0);
    lcd.print("SUM");
    lcd.setCursor(0, 1);
    lcd.print(ans);

  }
  else if (myoperator == subtract) {
    ans = val1 - val2;
    Serial.println("SUBTRACTION ");
    Serial.print(val1);
    Serial.print(subtract);
    Serial.print( val2);

    Serial.print(" = ");
    Serial.println(ans);
    Serial.println(" ");

    lcd.setCursor(0, 0);
    lcd.print("MINUS");
    lcd.setCursor(0, 1);
    lcd.print(ans);

  }
  else if (myoperator == multiply) {
    ans = val1 * val2;
    Serial.println("MULTIPLICATION");
    Serial.print(val1);
    Serial.print(multiply);
    Serial.print(val2);
    Serial.print(" = ");
    Serial.println(ans);
    Serial.println(" ");

    lcd.setCursor(0, 0);
    lcd.print("MULTIPLY");
    lcd.setCursor(0, 1);
    lcd.print(ans);
  }
  else if (myoperator == divide) {
    ans = val1 / val2;
    Serial.println("DIVISION");
    Serial.print(val1);
    Serial.print(" divided ");
    Serial.print(val2);
    Serial.print(" = ");
    Serial.println(ans);
    Serial.println(" ");

    lcd.setCursor(0, 0);
    lcd.print("DIVIDE");
    lcd.setCursor(0, 1);
    lcd.print(ans);
  }
  else {
    Serial.println("INVALID");
  }

  delay(5000);
  lcd.clear();





}
