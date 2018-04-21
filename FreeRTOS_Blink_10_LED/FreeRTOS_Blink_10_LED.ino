
//download library: https://github.com/feilipu/Arduino_FreeRTOS_Library

#include <Arduino_FreeRTOS.h>

void Timer_1( void *pvParameters );  // control D3
void Timer_2( void *pvParameters );  // control D4
void Timer_3( void *pvParameters );  // control D5
void Timer_4( void *pvParameters );  // control D6
void Timer_5( void *pvParameters );  // control D7
void Timer_6( void *pvParameters );  // control D8
void Timer_7( void *pvParameters );  // control D9
void Timer_8( void *pvParameters );  // control D10
void Timer_9( void *pvParameters );  // control D11
void Timer_10( void *pvParameters ); // control D12

int time_on_array[10] = {10,20,30,40,50,60,70,80,90,100};  //time on for Timer_1 to Timer_10 x 1/10 second
int time_off_array[10] = {10,20,30,40,50,60,70,80,90,100}; //time off for Timer_1 to Timer_10 x 1/10 second

void setup() {
  
  for(int i=3;i<=12;i++)
{
  pinMode(i,OUTPUT);
}
  xTaskCreate(
    Timer_1
    ,  (const portCHAR *)"Timer1"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_2
    ,  (const portCHAR *)"Timer2"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_3
    ,  (const portCHAR *)"Timer3"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_4
    ,  (const portCHAR *)"Timer4"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_5
    ,  (const portCHAR *)"Timer5"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_6
    ,  (const portCHAR *)"Timer6"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_7
    ,  (const portCHAR *)"Timer6"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_8
    ,  (const portCHAR *)"Timer7"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_9
    ,  (const portCHAR *)"Timer9"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );

  xTaskCreate(
    Timer_10
    ,  (const portCHAR *)"Timer10"
    ,  50
    ,  NULL
    ,  2
    ,  NULL );
}


void loop()
{
  // Empty. Things are done in Tasks.
}

void Timer_1(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(3,HIGH);
  vTaskDelay( time_on_array[0]*100 / portTICK_PERIOD_MS );
  digitalWrite(3,LOW);
  vTaskDelay( time_off_array[0]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_2(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(4,HIGH);
  vTaskDelay( time_on_array[1]*100 / portTICK_PERIOD_MS );
  digitalWrite(4,LOW);
  vTaskDelay( time_off_array[1]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_3(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(5,HIGH);
  vTaskDelay( time_on_array[2]*100 / portTICK_PERIOD_MS );
  digitalWrite(5,LOW);
  vTaskDelay( time_off_array[2]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_4(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(6,HIGH);
  vTaskDelay( time_on_array[3]*100 / portTICK_PERIOD_MS );
  digitalWrite(6,LOW);
  vTaskDelay( time_off_array[3]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_5(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(7,HIGH);
  vTaskDelay( time_on_array[4]*100 / portTICK_PERIOD_MS );
  digitalWrite(7,LOW);
  vTaskDelay( time_off_array[4]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_6(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(8,HIGH);
  vTaskDelay( time_on_array[5]*100 / portTICK_PERIOD_MS );
  digitalWrite(8,LOW);
  vTaskDelay( time_off_array[5]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_7(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(9,HIGH);
  vTaskDelay( time_on_array[6]*100 / portTICK_PERIOD_MS );
  digitalWrite(9,LOW);
  vTaskDelay( time_off_array[6]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_8(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(10,HIGH);
  vTaskDelay( time_on_array[7]*100 / portTICK_PERIOD_MS );
  digitalWrite(10,LOW);
  vTaskDelay( time_off_array[7]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_9(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(11,HIGH);
  vTaskDelay( time_on_array[8]*100 / portTICK_PERIOD_MS );
  digitalWrite(11,LOW);
  vTaskDelay( time_off_array[8]*100 / portTICK_PERIOD_MS );
  }
}

void Timer_10(void *pvParameters)
{
  for (;;)
  {
  digitalWrite(12,HIGH);
  vTaskDelay( time_on_array[9]*100 / portTICK_PERIOD_MS );
  digitalWrite(12,LOW);
  vTaskDelay( time_off_array[9]*100 / portTICK_PERIOD_MS );
  }
}
