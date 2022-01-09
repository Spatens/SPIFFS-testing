/*
SPIFFS file testing
Writes a file to SPIFFS and reads it back
https://www.dfrobot.com/blog-1110.html <- write routine
*/

#include <Arduino.h>
#include "SPIFFS.h"

void setup() {
  Serial.begin(115200);
}

void Run_SPIFFS_Write_Test() {
    // always use this to "mount" the filesystem

  bool result = SPIFFS.begin();
  Serial.println("SPIFFS writetest ");
  Serial.print("SPIFFS opened in SPIFFS write - file name: " + result);
  // this opens the file "myfile.txt" in read-mode
  File testFile = SPIFFS.open("/test.txt", FILE_READ);
  if (!testFile) {
    Serial.println("File doesn't exist yet. Creating it");
    // open the file in write mode - taken from the data directory
    File testFile = SPIFFS.open("/test.txt", FILE_WRITE); // write it in SPIFFS
    if (!testFile) {
      Serial.println("Could not create the testfile");
    }
  } 
  else 
    {
    while(testFile.available()) 
    {
      //read line by line from the file
      String line = testFile.readStringUntil('\n');
      Serial.print(line);
    }
  }
  testFile.close();
}

void Run_SPIFFS_Read_Test() {
Serial.println("\nSPIFFS readtest ");
File file2 = SPIFFS.open("/test.txt");
    if(!file2){
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.print("File Content - code OK till here. File name:  "); 
    while(file2.available()){
        Serial.write(file2.read());            
    }
  file2.close();
}

void ReadlinesinFile() {
 File file2 = SPIFFS.open("/test.txt");
     if(!file2){
        Serial.println("SPIFFS File could not open");
        return;
    }
   Serial.println("\nERROR - contents of the file should display here ....."); 
   while(file2.available()){             
     //read line by line from the file
     String line = file2.readStringUntil('\n');          
     Serial.println(line);       
    }
  file2.close();
}

void loop() {
  delay(5000);
  Run_SPIFFS_Write_Test();
  delay(1000);
  Run_SPIFFS_Read_Test();
  delay(1000);
  ReadlinesinFile();
  Serial.print("\n\n"); 
}