#include "mbed.h"
DigitalOut yuya1(LED1);
DigitalOut yuya2(LED2);
DigitalOut yuya3(LED3);
DigitalOut yuya4(LED4);
Serial device(p9, p10);  // tx, rx
Serial pc(USBTX,USBRX);


int ms = 0;

void fan1_on () {
    pc.printf("flagA %i\n", flag1);
     pc.printf("back fan power = on\n");
     yuya1 = 1;
     ms += 1;
     //wait(5.0);
}
void fan1_off () {
    //if(ms == 10){
    pc.printf("flagA %i\n", flag1);
    pc.printf("back fan power = off\n");
    yuya1 = 0;
    //wait(5.0);
    //}
}

void fan2_on () {
    pc.printf("flagB %i\n", flag2);
    pc.printf("left fan power = on\n");
    yuya2 = 1;
    ms += 1;
    //wait(5.0);
    pc.putc(pc.getc());
}

void fan2_off () {
    //if(ms == 20){
    pc.printf("flagB %i\n", flag2);
    pc.printf("left fan power = off\n");
    yuya2 = 0;
    //wait(5.0);
    pc.putc(pc.getc());
    //}
}

void fan3_on () {
    pc.printf("flagC %i\n", flag3);
    pc.printf("right fan power = on\n");
    yuya3 = 1;
    ms += 1;
    //wait(5.0);
}

void fan3_off () {
    //if(ms == 30){
    pc.printf("flagC %i\n", flag3);
    pc.printf("right fan power = off\n");
    yuya3 = 0;
    //wait(5.0);
    //}
}

void fan4_on () {
    pc.printf("flagD %i\n", flag4);
    pc.printf("front fan power = on\n");
    yuya4 = 1;
    ms += 1;
    //wait(5.0);
}

void fan4_off () {
    pc.printf("flagD %i\n", flag4);
    pc.printf("front fan power = off\n");
    yuya4 = 0;
    //wait(5.0);
}

void dev_rx () {
    pc.putc(device.getc());
}

void kanri () {
    if(flag1 == 1){
           pc.attach(fan1_on,Serial::RxIrq);
    }else{
           pc.attach(fan1_off,Serial::RxIrq);
    }
}
int main() {
    //pc.attach(fan1_on,Serial::RxIrq);
    //char c = pc.getc();
      pc.attach(fan4_off,Serial::RxIrq);
      pc.attach(fan1_on,Serial::RxIrq);
      //}else if((ms > 10) && (ms <= 20)){
      pc.attach(fan1_off,Serial::RxIrq);
      pc.attach(fan2_on,Serial::RxIrq); 
      //}else if((ms > 20) && (ms <= 30)){
      pc.attach(fan2_off,Serial::RxIrq);
      pc.attach(fan3_on,Serial::RxIrq);
      //}else if((ms > 30) && (ms <= 40)){
      pc.attach(fan3_off,Serial::RxIrq);
      pc.attach(fan4_on,Serial::RxIrq);  
      //}else{
      ms = 0;
      while(1){
    }
      //}           
}
