
#include <MPU6050.h>
#include<Wire.h>
#include<SPI.h>
MPU6050 mpu;
#define CE_PIN 10
#define CSN_PIN 9
int flex1 = A0;
int flex2 = A1;// flex sensor is connected with analog pin A0
int flex3 = A2;
int flex4 = A6; 
int flex5 = A7;
float data[8];
const uint64_t pipe = 0x1;
//RF24 radio(CE_PIN,CSN_PIN);
void setup()
{
 Serial.begin(115200);

  Serial.println("Inicjalizacja MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Nie mozna znalezc MPU6050 - sprawdz polaczenie!");
    delay(500);
  }
    mpu.calibrateGyro();
 
  // Ustawienie czułości
  mpu.setThreshold(3); 
  pinMode(flex1, INPUT);
  pinMode(flex2, INPUT);
    pinMode(flex3, INPUT);
  pinMode(flex4, INPUT);
    pinMode(flex5, INPUT);
}

void loop()
{
  int kat1 = map(analogRead(flex1),351,432,90,0);
  int kat2 = map(analogRead(flex2),39,53,90,0);
  int kat3 = map(analogRead(flex3),345,577,90,0);
  int kat4 = map(analogRead(flex4),200,367,90,0);
  int kat5 = map(analogRead(flex5),120,367,90,0);
  kat1 = constrain(kat1,0,90);
  kat2 = constrain(kat2,0,90);
  kat3 = constrain(kat3,0,90);
  kat4 = constrain(kat4,0,90);
  kat5 = constrain(kat5,0,90);

    Serial.println("teraz katy");
Serial.println(kat1);
  Serial.println(kat2); 
    Serial.println(kat3);
  Serial.println(kat4);
    Serial.println(kat5);
    Serial.println();
    Vector rawGyro = mpu.readRawGyro();
  Vector normGyro = mpu.readNormalizeGyro();
 
  Serial.print(" Xraw = ");
  Serial.print(rawGyro.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(rawGyro.YAxis);
  Serial.print(" Zraw = ");
  Serial.println(rawGyro.ZAxis);
 
  Serial.print(" Xnormgyr = ");
  Serial.print(normGyro.XAxis);
  Serial.print(" Ynormgyr = ");
  Serial.print(normGyro.YAxis);
  Serial.print(" Znormgyr = ");
  Serial.println(normGyro.ZAxis);
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
 
  Serial.print(" Xraw = ");
  Serial.print(rawAccel.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(rawAccel.YAxis);
  Serial.print(" Zraw = ");
 
  Serial.println(rawAccel.ZAxis);
  Serial.print(" Xnormacc = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynormacc = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znormacc = ");
  Serial.println(normAccel.ZAxis);
  data[0]=kat1;
  data[1]=kat2;
  data[2]=kat3;
  data[3]=kat4;
  data[4]=kat5;
  data[5]=(normAccel.XAxis);
  data[6]=(normAccel.YAxis);
  data[7]=(normAccel.ZAxis);
  
  delay(1000);
}
