//DECLARACION DE PUERTOS EN MODO CONST (NO MODIFICABLE)
const int datos = 2; //Informacion (Entrada)
const int salida = 3; //Reloj de salida
const int despla = 4; //Reloj de desplazamiento

int final [8];

//INICIO DE CADA FILA LSBFIRST--------------------------------
int fila[8] = {127, 191, 223, 239, 247, 251, 253, 254};

//LETRAS Y NUMEROS--------------------------------------------
int LetraA[8] = {0,56,68,68,124,68,68,68};
int LetraB[8] = {0,120,68,68,120,68,68,120};
int LetraC[8] = {0,56,68,64,64,64,68,56};
int LetraD[8] = {0,120,68,68,68,68,68,120};
int LetraE[8] = {0,124,64,64,124,64,64,124};
int LetraF[8] = {0,124,64,64,124,64,64,64};
int LetraG[8] = {0,56,68,64,92,68,68,56};
int LetraH[8] = {102,102,102,126,126,102,102,102};
int LetraI[8] = {0,56,16,16,16,16,16,56};
int LetraK[8] = {0,66,66,68,120,68,66,66};
int LetraL[8] = {0,64,64,64,64,64,64,124};
int LetraM[8] = {0,68,108,84,68,68,68,68};
int LetraN[8] = {0,68,68,100,84,76,68,68};
int LetraO[8] = {0,56,68,68,68,68,68,56};
int LetraP[8] = {0,124,68,68,124,64,64,64};
int LetraQ[8] = {0,56,68,68,68,84,76,60};
int LetraR[8] = {0, 60, 34, 34, 60, 40, 36, 34};
int LetraS[8] = {0,56,68,64,56,4,68,56};
int LetraT[8] = {0,124,16,16,16,16,16,16};
int LetraU[8] = {0,56,68,68,68,84,76,60};
int LetraV[8] = {0,68,68,68,68,68,40,16};
int LetraW[8] = {0,68,68,68,68,84,108,68};
int LetraX[8] = {0,68,68,40,16,40,68,68};
int LetraZ[8] = {0,124,4,8,16,32,64,124};

//Numeros


//PRESETS-------------------------------------------------------
int kokoro[8] = {0, 102, 153, 129, 66, 36, 24, 0};
int TodoEncendido[8] = {255, 255, 255, 255, 255, 255, 255, 255};

//lineas verticales
int LV1[8]={1,1,1,1,1,1,1,1};
int LV2[8]={2,2,2,2,2,2,2,2};
int LV3[8]={4,4,4,4,4,4,4,4};
int LV4[8]={8,8,8,8,8,8,8,8};
int LV5[8]={16,16,16,16,16,16,16,16};
int LV6[8]={32,32,32,32,32,32,32,32};
int LV7[8]={64,64,64,64,64,64,64,64};
int LV8[8]={128,128,128,128,128,128,128,128};


//lineas horizonatales 
int LH1[8]={1,0,0,0,0,0,0,0};
int LH2[8]={2,1,0,0,0,0,0,0};
int LH3[8]={4,2,1,0,0,0,0,0};
int LH4[8]={8,4,2,1,0,0,0,0};
int LH5[8]={16,8,4,2,1,0,0,0};
int LH6[8]={32,16,8,4,2,1,0,0};
int LH7[8]={64,32,16,8,4,2,1,0};
int LH8[8]={128,64,32,16,8,4,2,1};
int LH9[8]={0,128,64,32,16,8,4,2};
int LH10[8]={0,0,128,64,32,16,8,4};
int LH11[8]={0,0,0,128,64,32,16,8};
int LH12[8]={0,0,0,0,128,64,32,16};
int LH13[8]={0,0,0,0,0,128,64,32};
int LH14[8]={0,0,0,0,0,0,128,64};
int LH15[8]={0,0,0,0,0,0,0,128};


//CUADRADO
int cuadro1[8] = {255,129,129,129,129,129,129,255};
int cuadro2[8] = {0,126,66,66,66,66,126,0};
int cuadro3[8] = {0,0,60,36,36,60,0,0};
int cuadro4[8] = {0,0,0,24,24,0,0,0};

//PROTOTIPOS-----------------------------------------------------
void iluminar(int [8]);
void verificacion(int [8]);
void imagen();


//SETUP ARDUINO---------------------------------------------------
void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(datos, OUTPUT); // Entrada de datos
  pinMode(salida, OUTPUT); // Salida de datos
  pinMode(despla, OUTPUT); // Desplazamiento
  
  pinMode(13, OUTPUT);
  
  //-----------CODIGO------------------------
  int opcion, Final [8];;
  Serial.println("Indique su opcion");
  Serial.print("\n");
  Serial.println("1- Patron de letras y numeros (Escritura por monitor)");
  Serial.println("2- Patron predefinido");
  Serial.println("3- Patron personalizado Animacion(Led por Led)");
  Serial.println("4- Patron personalizado Estatico (Led por Led)");
  Serial.print("\n");
  while (Serial.available()==0);
  opcion=Serial.parseInt();

  switch (opcion)
  {
    //---------------------------------------
    case 1: //letras y numeros
    {
      char patron;
      Serial.print("Acontinuacion ingresa el patron: ");
      Serial.print("\n");
      patron=Serial.parseInt();
      
      Serial.print(patron);
      /*
      new int num;
      int array[num]
      while (Serial.available()==0); 
      Serial.readBytes(array, num);
      delete num;
      */
      
    }
    break;
    //---------------------------------------
    case 2: //patron predefinido
    {
      Serial.println("Elige uno de los patrones: ");
      Serial.println("1 - lineas verticales");
      Serial.println("2 - cuadrado");
      Serial.println("3 - lineas horizontales");
      Serial.println("4 - Prueba de leds");
      Serial.print("\n");
      int n;
      while (Serial.available()==0);
  	  n=Serial.parseInt();
      Serial.println("Encendiendo leds");
      switch (n){
        case 1://lineas verticales 
        {
          for(int i=0; i<=100; i++)
          {
           	Iluminar(LV1);
            Iluminar(LV2);
            Iluminar(LV3);
            Iluminar(LV4);
            Iluminar(LV5);
            Iluminar(LV6);
            Iluminar(LV7);
            Iluminar(LV8);
          }
        }
        
        break;
        //------------
        case 2://cuadrado
        {
         for (int i=0; i<=8; i++)
         {
           Iluminar(cuadro1);
           Iluminar(cuadro2);
           Iluminar(cuadro3);
           Iluminar(cuadro4);
         }
            
        }
        break;
        //-------------
        case 3: //Lineas horizontales 
        {
          for(int i=0; i<=100; i++){
          	Iluminar(LH1);
            Iluminar(LH2);
            Iluminar(LH3);
            Iluminar(LH4);
            Iluminar(LH5);
            Iluminar(LH6);
            Iluminar(LH7);
            Iluminar(LH8);
			Iluminar(LH9);
            Iluminar(LH10);
            Iluminar(LH11);
            Iluminar(LH12);
            Iluminar(LH13);
            Iluminar(LH14);
            Iluminar(LH15);
            
          }
        }
        break;
        //---------------
        case 4:
        {
          for(int i=0; i<=100; i++)
          {
            verificacion(TodoEncendido);
          }
        }
      }
    }
    break;
    //---------------------------------------
    case 3: //patron personalizado animado
    {
      char posi, linea[8],array[8][8],arreg[8];
      unsigned int numero[8]={128,64,32,16,8,4,2,1}, bits[8], posi2, posi1;
      bool veri;
      Serial.print("A continuacion ingrese 8 digitos por linea horizontal empezando desde arriba, los leds encendidos se marcan con una X y los apagados con la letra O. EJ: 0000X000");
      Serial.print("\n");
      for (int j=0; j<=7; j++)
      {
        Serial.print("Cadena de led horiontal ");
        Serial.print(j+1);
        Serial.print(": ");
        while (Serial.available()<=9);
        Serial.readBytes(linea, 8);
        Serial.print("\n");
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
              Serial.print(j+2);
              Serial.print(": ");
              while (Serial.available()<=9);
              Serial.readBytes(linea, 8);
              Serial.print("\n");
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
        Final[k]=suma;
      }
    }
    break;
    //-------------------------------------
    case 4: //patron personalizado estatico
    {
      imagen();
    }
    break;
  } 
}

//LOOP ARDUINO
void loop()
{
}


// FUNCIONES 


void Iluminar(int array[8])
{
  int j = 0;
  for(int i=0; i<8; i++)
  {
    //DigitalWitre debe estar en bajo, antes de llamar la funcion shitfout
    digitalWrite(salida, LOW);
    shiftOut(datos, despla, LSBFIRST, array[j]);
    shiftOut(datos, despla, LSBFIRST, fila[i]);
    digitalWrite(salida, HIGH);
    j++;
  }
  delay(500);
}

void verificacion(int array[8])
{
  int j = 0;
  for(int i=0; i<8; i++)
  {
    //DigitalWitre debe estar en bajo, antes de llamar la funcion shitfout
    digitalWrite(salida, LOW);
    shiftOut(datos, despla, LSBFIRST, array[j]);
    shiftOut(datos, despla, LSBFIRST, fila[i]);
    digitalWrite(salida, HIGH);
    j++;
  }
}

void imagen()
{
      char posi, linea[8],array[8][8],arreg[8];
      unsigned int numero[8]={128,64,32,16,8,4,2,1}, bits[8], posi2, posi1;
      int Final[8];
      bool veri;
      Serial.print("A continuacion ingrese 8 digitos por linea horizontal empezando desde arriba, los leds encendidos se marcan con una X y los apagados con la letra O. EJ: 0000X000");
      Serial.print("\n");
      for (int j=0; j<=7; j++)
      {
        Serial.print("Cadena de led horiontal ");
        Serial.print(j+1);
        Serial.print(": ");
        while (Serial.available()<=9);
        Serial.readBytes(linea, 8);
        Serial.print("\n");
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
              Serial.print(j+2);
              Serial.print(": ");
              while (Serial.available()<=9);
              Serial.readBytes(linea, 8);
              Serial.print("\n");
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
        Final[k]=suma;
      }
  	  for (int i=0; i<=100; i++)
      {
        verificacion(Final);
      }
}