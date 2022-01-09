# SPIFFS-testing WITH ERROR. Read FAILS !! See line 11 in this readme
This project will do some initial basic reading and writing of a SPIFFS flash system.
In this case a test-file from a data directory containing a file called "test.txt" (on a ESP32). 
The code will first try to locate the file in SPIFFS.
If it cannot find the code, it will try to locate the file in the data directory
and write the file onto the SPIFFS flash.
It will not try to format the flash.
HOWEVER THE CODE DOES NOT WORK!!
  Serial.println("File Content - code OK till here -"); 
    while(file2.available()){
        Serial.println("File code never gets here !!!"); 
        Serial.write(file2.read());        
    }






