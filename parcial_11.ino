const int datos = 2; //Informacion (Entrada)
const int salida = 3; //Reloj de salida
const int despla = 4; //Reloj de desplazamiento

// contador de columnas
int j = 0;
// tiempo en pantalla
int k;

//byts del inicio de cada fila
int fila[8] = {127, 191, 223, 239, 247, 251, 253, 254};

int LetraR[8] = {0, 60, 34, 34, 60, 40, 36, 34};

int TodoEncendido[8] = {255, 255, 255, 255, 255, 255, 255, 255};


void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(datos, OUTPUT); // Entrada de datos
  pinMode(salida, OUTPUT); // Salida de datos
  pinMode(despla, OUTPUT); // Desplazamiento
  
  pinMode(13, OUTPUT);
}

void Iluminar()
{
  for(k = 0; k<100; k++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(salida, LOW);
      shiftOut(datos, despla, LSBFIRST, TodoEncendido[j]);
      shiftOut(datos, despla, LSBFIRST, fila[i]);
      digitalWrite(salida, HIGH);
      j++;
      //delay(500);
    }
    j = 0;
  }
}

void loop()
{
  Iluminar();
}