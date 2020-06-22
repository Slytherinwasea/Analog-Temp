int STATE_TEMP = 1;
int sv = A0;
float v = 0;
float Temp = 0;

void getTemperature(float sv){
  if (STATE_TEMP == 1){
    v = analogRead(sv);
    Temp = log(10000.0 / (1024.0 / v - 1)); 

    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp))* Temp);

    Temp = Temp - 273.15; // Convert Kelvin to Celcius
    Serial.println(Temp);
    delay(1000);
    }
    else{
      Serial.println("None");
      }
  }
void setup()
{
  Serial.begin(9600);
  pinMode(v,INPUT);
}

void loop(){
getTemperature(sv);
}
