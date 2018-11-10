/*
 * example created by newbie for newbie
 * 19 feb 2017 11:34 PM
 */

#include <DMD3.h>
#include <DejaVuSansBold9.h>
#include <DejaVuSansItalic9.h>
DMD3 display;

void scan(){
    display.refresh();
}
unsigned long lastMillis;
int Step;
bool ret;

void splitMarquee(int y1,int y2,int Speed,String text){
  int total=display.width()+display.textWidth(text); // hitung panjang maksimal panel + text
  if (!ret){
    if (millis()>lastMillis+Speed){ //pulsa untuk menjalankan text
      Step++; //langkah text
      lastMillis=millis();
    }
    if (Step>total){//text telah selesai dijalankan
      Step=0;
      ret=true;
    }
    display.drawFilledRect(0,y1,display.width(),y2,0);//bersihkan area sebelum ditulisi
    display.drawText(display.width()-Step,y1,text);//gambar text dg posisi x sesuai pulsa step
    display.swapBuffersAndCopy();//tampilkan dilayar
  }
}
void setup() {
    Timer1.initialize(1000);
    Timer1.attachInterrupt(scan);
}
void loop() {
    ret=false;
    while(!ret){
      display.setFont(DejaVuSansItalic9);//pilih font u/ text diam
      display.drawText(4,0,"Diam");//gambar text diam
      display.setFont(DejaVuSansBold9);//pilih font u/ text berjalan
      splitMarquee(8,16,50,"Aziz kurosaki :P");//tampilkan text berjalan pada baris ke 8 sampai 16,dg keceepatan 50ms
    }
}

