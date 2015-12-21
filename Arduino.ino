#include  <LiquidCrystal.h>

int a_luz = A2, buzzer = 10, a_temp = A1;
int luz = 0, temp = 0;
LiquidCrystal  lcd    (12, 11, 5, 4, 3, 2); 

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  egg();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("            ");
  lcd.setCursor(0, 1);
  lcd.print("            ");
  luz = analogRead(a_luz);
  temp = analogRead(a_temp);
  lcd.setCursor(0, 0);
  Serial.print("Luminosidade: \t");
  Serial.println(luz);
  lcd.print("luz:");
  lcd.print(luz);
  lcd.setCursor(0, 1);
  lcd.print("temp:");
  Serial.print("Temperatura:   \t");
  Serial.println((500*temp)/1023);
  lcd.print((500*temp)/1023);
  lcd.print("C");
  
  if (luz < 100 && luz > 20 && temp > 0){
    tone(buzzer,2500);
    delay(100);
    noTone(buzzer);
    delay(10000);
  }else{
    tone(buzzer,1500);
    delay(100);   
  }
  
}

void egg(){
    lcd.print("Teste");
    lcd.setCursor(0,1);
    lcd.print("Numero 1");
    delay(1000);
}
