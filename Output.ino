/*

MinIMU-9-Arduino-AHRS
Pololu MinIMU-9 + Arduino AHRS (Attitude and Heading Reference System)

Copyright (c) 2011-2016 Pololu Corporation.
http://www.pololu.com/

MinIMU-9-Arduino-AHRS is based on sf9domahrs by Doug Weibel and Jose Julio:
http://code.google.com/p/sf9domahrs/

sf9domahrs is based on ArduIMU v1.5 by Jordi Munoz and William Premerlani, Jose
Julio and Doug Weibel:
http://code.google.com/p/ardu-imu/

MinIMU-9-Arduino-AHRS is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your option)
any later version.

MinIMU-9-Arduino-AHRS is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License along
with MinIMU-9-Arduino-AHRS. If not, see <http://www.gnu.org/licenses/>.

*/



void printdata(void)
{   
      float flat, flon;
      unsigned long age, date, time, chars = 0;
      static const double ETF_LAT = 43.8566594, ETF_LON = 18.3980629;
      gps.f_get_position(&flat, &flon, &age);
      //Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");
     // printajsatelite(gps.satellites(), TinyGPS::GPS_INVALID_SATELLITES);
      printajkoordinate(flat, TinyGPS::GPS_INVALID_F_ANGLE,flon, TinyGPS::GPS_INVALID_F_ANGLE);
      //printajudaljenostetf(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0xFFFFFFFF : (unsigned long)TinyGPS::distance_between(flat, flon, ETF_LAT, ETF_LON) / 1000, 0xFFFFFFFF);
      //Serial.print("!");
      #if PRINT_EULER == 1
      //Serial.print("ANG:");
      //Serial.print(ToDeg(roll));
      //Serial.print(",");
      //Serial.print(ToDeg(pitch));
      //Serial.print(",");
      //Serial.print(ToDeg(yaw));
      niz[2]=ToDeg(roll);
      niz[3]=ToDeg(pitch);
      niz[4]=ToDeg(yaw);
      #endif      
      #if PRINT_ANALOGS==1
      Serial.print(",AN:");
      Serial.print(AN[0]);  //(int)read_adc(0)
      Serial.print(",");
      Serial.print(AN[1]);
      Serial.print(",");
      Serial.print(AN[2]);  
      Serial.print(",");
      Serial.print(AN[3]);
      Serial.print (",");
      Serial.print(AN[4]);
      Serial.print (",");
      Serial.print(AN[5]);
      Serial.print(",");
      Serial.print(c_magnetom_x);
      Serial.print (",");
      Serial.print(c_magnetom_y);
      Serial.print (",");
      Serial.print(c_magnetom_z);
      #endif
      #if PRINT_DCM == 1
      Serial.print (",DCM:");
      Serial.print(DCM_Matrix[0][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[0][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[0][2]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[1][2]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][0]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][1]);
      Serial.print (",");
      Serial.print(DCM_Matrix[2][2]);
      #endif
      //Serial.println();
      radio.write(&niz, sizeof(niz));
      smartdelay(20);
      
}

/*
static void printajsatelite(unsigned long val, unsigned long invalid){
  if ( val == invalid){
    //Serial.println("Trenutno nema dostupnih satelilta!");
    //niz[0]=0;
  }
  else{
    //Serial.print("Broj satelita sa kojima arduino komunicira: ");
    //Serial.println(val);
    
  }
}
*/

static void printajkoordinate(float val1, float invalid1, float val2, float invalid2){
  if ( val1==invalid1 || val2==invalid2){
    //Serial.println("Trenutno nisu dostupne GPS koordinate!");
    niz[0]=0;
    niz[1]=0;
  }
  else{
    //Serial.println("Trenutne koordinate arduina su: ");
    //Serial.print(val1,7);
    //Serial.print("  ,   ");
    //Serial.println(val2,7);
    niz[0]=val1;
    niz[1]=val2;
  }
}

/*
static void printajudaljenostetf(unsigned long val, unsigned long invalid){
  if (val==invalid){
  }
  else{
    Serial.print("Procijenjena udaljenost od ETF-a: ");
    Serial.println(val);
  }
}
*/

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
 do
 {
    while (ss.available())
      gps.encode(ss.read());
  }
  while (millis() - start < ms);
} 

/*long convert_to_dec(float x)
{
  return x*10000000;
}*/

