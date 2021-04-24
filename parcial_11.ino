//DECLARACION DE PUERTOS EN MODO CONST (NO MODIFICABLE)
const int datos = 2; //Informacion (Entrada)
const int salida = 3; //Reloj de salida
const int despla = 4; //Reloj de desplazamiento

int final [8];

//INICIO DE CADA FILA LSBFIRST--------------------------------
int fila[8] = {127, 191, 223, 239, 247, 251, 253, 254};

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
void publik();


//SETUP ARDUINO---------------------------------------------------
void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(500);
  // 74HC595
  pinMode(datos, OUTPUT); // Entrada de datos
  pinMode(salida, OUTPUT); // Salida de datos
  pinMode(despla, OUTPUT); // Desplazamiento
  
  pinMode(13, OUTPUT);
  
  //-----------CODIGO------------------------
  int opcion, Final [8];;
  Serial.println("Indique su opcion");
  Serial.print("\n");
  Serial.println("1- Secuencia de patrones (Escritura por monitor)");
  Serial.println("2- Patron predefinido");
  Serial.println("3- Patron personalizado Animacion(Led por Led)");
  Serial.println("4- Patron personalizado Estatico (Led por Led)");
  Serial.print("\n");
  while (Serial.available()==0);
  opcion=Serial.parseInt();

  switch (opcion)
  {
    //---------------------------------------
    case 1: //Patrones digitados por el usuario 
    {
           
      publik(); 
    }
    //fin case
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
        while (Serial.available()==0);
        Serial.readBytes(linea, 8);
        for (int i=0;i<=7;i++)
        {
          Serial.print(linea[i]);
        }
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
              while (Serial.available()==0);
              Serial.readBytes(linea, 8);
              for (int i=0;i<=7;i++)
              {
                Serial.print(linea[i]);
              }
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
      Iluminar(Final);
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


void publik()
{
	
  int patron,time; 
  int *p;
  
  Serial.println("A continuacion ingrese la cantida de patrones a mostrar: ");
  while (Serial.available()==0);
  patron=Serial.parseInt();
  
  Serial.println("A continuacion ingrese el tiempo entre patrones: ");
  while (Serial.available()==0);
  time=Serial.parseInt();
  
  Serial.print("\n");
 
  p = new int[8*patron]; //Crear arreglo dinamico 
	
  for(int h=-1;h<patron-1;h++)
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
        Serial.flush();
        while (Serial.available()==0);
        Serial.readBytes(linea, 8);
        for (int i=0;i<=7;i++)
        {
          Serial.print(linea[i]);
        }
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

              Serial.flush();
              Serial.print("Cadena invalida");
              Serial.print("\n");
              Serial.print("Cadena de led horiontal ");
              Serial.print(j+2);
              Serial.print(": ");
              while (Serial.available()==0);
              Serial.readBytes(linea, 8);
              for (int i=0;i<=7;i++)
              {
                Serial.print(linea[i]);
              }
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
     	
      int num1=Final[0], num2=Final[1], num3=Final[2], num4=Final[3], num5=Final[4], num6=Final[5], num7=Final[6], num8=Final[7];
        p[(h+1)*8]=num1;
        p[((h+1)*8)+1]=num2;
        p[((h+1)*8)+2]=num3;
        p[((h+1)*8)+3]=num4;
        p[((h+1)*8)+4]=num5;
        p[((h+1)*8)+5]=num6;
        p[((h+1)*8)+6]=num7;
        p[((h+1)*8)+7]=num8;
      
  }
  int semifinal [8];
  for (int k=-1; k<patron-1; k++)
  {
    int num1=p[((k+1)*8)];
    int num2=p[((k+1)*8)+1];
    int num3=p[((k+1)*8)+2];
    int num4=p[((k+1)*8)+3];
    int num5=p[((k+1)*8)+4];
    int num6=p[((k+1)*8)+5];
    int num7=p[((k+1)*8)+6];
    int num8=p[((k+1)*8)+7];

    semifinal[0]=num1;
    semifinal[1]=num2;
    semifinal[2]=num3;
    semifinal[3]=num4;
    semifinal[4]=num5;
    semifinal[5]=num6;
    semifinal[6]=num7;
    semifinal[7]=num8;

    
    for (int i=0; i<=time; i++)
    {
      verificacion(semifinal);
    }
  }

  delete[] p;  
}

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
        while (Serial.available()==0);
        Serial.readBytes(linea, 8);
        for (int i=0;i<=7;i++)
        {
          Serial.print(linea[i]);
        }
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
              while (Serial.available()==0);
              Serial.readBytes(linea, 8);
              for (int i=0;i<=7;i++)
              {
                Serial.print(linea[i]);
              }
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