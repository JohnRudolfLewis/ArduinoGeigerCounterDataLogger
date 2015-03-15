#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <SPI.h>
#include <SD.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
float seaLevelPressure;
const int chipSelect = 11;
char filename[30];

void setup() {
  // init Geiger Counter  
  Serial1.begin(9600); // UART Serial Port -- Geiger Counter
  Serial1.setTimeout(2000);
  Serial1.readStringUntil('\n');
  
  // init barometric sensor
  if (bmp.begin()) {
    sensors_event_t event;
    bmp.getEvent(&event);
    seaLevelPressure = event.pressure;
  }

  // init SD card
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    return;
  }
  for (int i=0;i<100;i++) {
    snprintf(filename, sizeof(filename), "Geiger%d.csv", i);
    Serial.println(filename);
    if (!SD.exists(filename)) {
      break;
    }
  }
  File dataFile = SD.open(filename, FILE_WRITE);
  
  if (dataFile) {
    dataFile.println("Time,Pressure,AGL,CPS,CPM,uSv/hr");
    dataFile.close();
  }
}

void loop() {
  String data = Serial1.readStringUntil('\n');
  if (data) {
    File dataFile = SD.open(filename, FILE_WRITE);
    if (dataFile) {
      dataFile.print(millis());
      dataFile.print(",");
      
      sensors_event_t event;
      bmp.getEvent(&event);
      
      dataFile.print(event.pressure);
      dataFile.print(",");
      float altitude = bmp.pressureToAltitude(seaLevelPressure,event.pressure);
      dataFile.print(altitude);
      dataFile.print(",");
   
     //CPS, 0, CPM, 16, uSv/hr, 0.09, SLOW
      dataFile.print(getValue(data, ',', 1));
      dataFile.print(",");
      dataFile.print(getValue(data, ',', 3));
      dataFile.print(",");
      dataFile.print(getValue(data, ',', 5));
        
      dataFile.println();
      dataFile.close();
    }
  }
}

String getValue(String data, char separator, int index)
{

    int maxIndex = data.length()-1;
    int j=0;
    String chunkVal = "";

    for(int i=0; i<=maxIndex && j<=index; i++)
    {
      

      if(data[i]==separator)
      {
        j++;

        if(j>index)
        {
          chunkVal.trim();
          return chunkVal;
        }    

        chunkVal = "";    
      } else {
        chunkVal.concat(data[i]);
      }
    }  
}

