// EJERCICIO BASADO EN EL EJEMPLO Simple_MPU6050_Basic_EXAMPLE de Homer Creutz, Copyright (c) 2021 Homer Creutz
//https://github.com/ZHomeSlice/Simple_MPU6050
// Adaptación Citlali Hernández, para la asignatura de Interacción y Escena .- IT 2023

///// Mis Variables y Datos
#include <Servo.h>
Servo myServo;
float vY, vP, vR;     // variables para almacenar los valores del Yaw, Pitch y Roll en grados
float cvY, cvP, cvR;  // variables para modificar, mapear,  alterar los valores de vY, vP y vR.

/// Librerías
#include "Simple_MPU6050.h"
#define MPU6050_DEFAULT_ADDRESS 0x68  // address pin low (GND), default for InvenSense evaluation board
Simple_MPU6050 mpu;

//***************************************************************************************
//******************              Callback Funciton                **********************
//***************************************************************************************

// See mpu.on_FIFO(print_Values); in the Setup Loop
void Print_Values(int16_t *gyro, int16_t *accel, int32_t *quat) {
  Quaternion q;
  VectorFloat gravity;
  float ypr[3] = { 0, 0, 0 };
  float xyz[3] = { 0, 0, 0 };
  mpu.GetQuaternion(&q, quat);
  mpu.GetGravity(&gravity, &q);
  mpu.GetYawPitchRoll(ypr, &q, &gravity);
  mpu.ConvertToDegrees(ypr, xyz);

  Serial.print(F("Yaw "));
  Serial.print(xyz[0]);
  Serial.print(F(",   "));
  Serial.print(F("Pitch "));
  Serial.print(xyz[1]);
  Serial.print(F(",   "));
  Serial.print(F("Roll "));
  Serial.print(xyz[2]);
  Serial.println();

  ////////////////////////////////////////////////////////////////////////
  // Variables del ejercicio - almacenan los valores de Yaw, Pitch, Roll
  vY = xyz[0];
  vP = xyz[1];
  vR = xyz[2];
}

//***************************************************************************************
//******************                Setup and Loop                 **********************
//***************************************************************************************

void setup() {


  // initialize serial communication
  Serial.begin(115200);
  while (!Serial)
    ;  // wait for Leonardo enumeration, others continue immediately
  Serial.println(F("Start:"));

  // Setup the MPU and TwoWire aka Wire library all at once
  mpu.begin();
  mpu.Set_DMP_Output_Rate_Hz(10);  // Set the DMP output rate from 200Hz to 5 Minutes.
  //mpu.Set_DMP_Output_Rate_Seconds(10);   // Set the DMP output rate in Seconds
  //mpu.Set_DMP_Output_Rate_Minutes(5);    // Set the DMP output rate in Minute
  mpu.CalibrateMPU();         // Calibrates the MPU.
  mpu.load_DMP_Image();       // Loads the DMP image into the MPU and finish configuration.
  mpu.on_FIFO(Print_Values);  // Set callback function that is triggered when FIFO Data is retrieved
  // Setup is complete!

  ////// SETUP CIT
  pinMode(3, OUTPUT);  // led en pin 3
  myServo.attach(6);   // Añadimos un servo al PIN 6
}

void loop() {
  static unsigned long FIFO_DelayTimer;
  if ((millis() - FIFO_DelayTimer) >= (99)) {                  // 99ms instead of 100ms to start polling the MPU 1ms prior to data arriving.
    if (mpu.dmp_read_fifo(false)) FIFO_DelayTimer = millis();  // false = no interrupt pin attachment required and When data arrives in the FIFO Buffer reset the timer
  }


  // Llamada a funciones propias
  ledGradual();
  Grados_A_Servo();
}


//***************************************************************************************
//******************            Funciones LED y Motor vía PW       **********************
//***************************************************************************************
void ledGradual() {
  cvR = constrain(vR, 0, 180);  // constrain elimina cualquier número que le llegue fuera del rango
  //Serial.println(vY);
  float valMap = map(cvR, 0, 180, 0, 255);
  analogWrite(3, valMap);
}


void Grados_A_Servo() {        // Enviamos los datos a un motor Servo
  cvY = constrain(vY, 0, 90);  // Hacemos que la lectura se conserve en un rango fijo
  myServo.write(cvY);
}
