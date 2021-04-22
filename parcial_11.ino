//DECLARACION DE PUERTOS EN MODO CONST (NO MODIFICABLE)
const int datos = 2; //Informacion (Entrada)
const int salida = 3; //Reloj de salida
const int despla = 4; //Reloj de desplazamiento


//INICIO DE CADA FILA LSBFIRST
int fila[8] = {127, 191, 223, 239, 247, 251, 253, 254};

//LETRAS Y NUMEROS
int LetraH[8] = {102,102,102,126,126,102,102,102};
int LetraB[8] = {124,66,68,124,68,124,0,0};
int LetraR[8] = {0, 60, 34, 34, 60, 40, 36, 34};

//PRESETS
int kokoro[8] = {0, 102, 153, 129, 66, 36, 24, 0};
int TodoEncendido[8] = {255, 255, 255, 255, 255, 255, 255, 255};


//PROTOTIPOS
void iluminar(int []);


//SETUP ARDUINO
void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(datos, OUTPUT); // Entrada de datos
  pinMode(salida, OUTPUT); // Salida de datos
  pinMode(despla, OUTPUT); // Desplazamiento
  
  pinMode(13, OUTPUT);
  
  //-----------CODIGO------------------------Serial.print();
  int opcion;
  Serial.print("Indique su opcion");
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("1- Patron de letras y numeros (Escritura por monitor)");
  Serial.print("\n");
  Serial.print("2- Patron predefinido");
  Serial.print("\n");
  Serial.print("3- Patron personalizado (Led por Led)");
  Serial.print("\n");
  /*
  opcion=Serial.parse();
  */

  switch (opcion)
  {
    //---------------------------------------
    case 1: //letras y numeros
    {
    }
    break;
    //---------------------------------------
    case 2: //patron predefinido
    {
    }
    break;
    //---------------------------------------
    case 3: //patron personalizado
    {
      char posi, linea[8], array[8][8],arreg[8];
      unsigned int numero[8]={128,64,32,16,8,4,2,1}, bits[8], posi2, posi1;
      int final[8];
      bool veri;
      Serial.print("A continuacion ingrese 8 digitos por linea horizontal empezando desde arriba, los leds encendidos se marcan con una X y los apagados con la letra O. EJ: 0000X000");
      Serial.print("\n");
      Serial.print("En caso de tener mas de 8 digitos solo se tomaran los primeros 8");
      Serial.print("\n");
      for (int j=0; j<=7; j++)
      {
        Serial.print("Cadena de led horiontal ");
        Serial.print(j+1);
        Serial.print(": ");
        /*
        linea=Serial.read();
        */
        veri=false;
        while (veri==false)
        {
          for (int i=0; i<=7; i++)
          {
            posi=linea[i];
            if(posi==79 || posi==88 || posi==120 || posi==111)
            {
              veri=true;
            }
            else
            {
              veri=false;

              Serial.print("Cadena invalida");
              Serial.print("\n");
              Serial.print("Cadena de led horiontal ");
              Serial.print(j+1);
              Serial.print(": ");
              /*
              linea=Serial.read();
              */
              break;
            }
          }
        }
        for(int i=0; i<=7; i++)
        {
          posi=linea[i];
          arreg[i]=posi;
        }
        for(int i=0; i<=7; i++)
        {
          posi=arreg[i];
          array[j][i]=posi;
        }
      }
      //desde aqui traduccion a bits
      for(int k=0; k<=7; k++)
      {
        char actual[8]={0};
        for(int i=0; i<=7; i++)
        {
          posi=array[k][i];
          actual[i]=posi;
        }
        for(int i=0; i<=7; i++)
        {
          posi=actual[i];
          posi2=numero[i];
          if (posi=='x' || posi=='X')
          {
            bits[i]=posi2;
          }
          else
          {
            bits[i]=0;
          }
        }
        int suma=0;
        for(int i=0; i<=7; i++)
        {
          posi1=bits[i];
          suma+=posi1;
        }
        final[k]=suma;
      }
    }
    break;
  } 
}

//LOOP ARDUINO
void loop()
{
  Iluminar(LetraH);
}


// FUNCIONES 


void Iluminar(int array[8])
{
  int j = 0;
  for(int i=0; i<8; i++)
  {
    digitalWrite(salida, LOW);
    shiftOut(datos, despla, LSBFIRST, array[j]);
    shiftOut(datos, despla, LSBFIRST, fila[i]);
    digitalWrite(salida, HIGH);
    j++;
  }
}