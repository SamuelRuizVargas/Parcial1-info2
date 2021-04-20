int j = 0;

int k;

void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  
  pinMode(13, OUTPUT);
}

void prueba()
{
  for(k = 0; k<100; k++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(store, LOW);
      digitalWrite(store, HIGH);
      j++;
    }
    j = 0;
  }
}

void loop()
{
  prueba();
}