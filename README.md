# SPIFFS-testing WITH ERROR. "file2.read" fails !!
This project will do some initial basic reading and writing of a SPIFFS flash system.

The code will first try to locate the file "test.txt" in SPIFFS - and if not found then in the data directory.
Write the test-file onto the SPIFFS flash. Then try to read the file.

HOWEVER THE CODE DOES NOT WORK!!
  Serial.println("File Content - code OK till here -"); 
    while(file2.available()){
        Serial.println("File code never gets here !!!"); 
        Serial.write(file2.read());        
    }






