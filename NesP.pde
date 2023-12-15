import processing.serial.*;
int x = 0,y = 0;
Serial canale;
void setup(){
  size(750,500);
  String porta = Serial.list()[1]; 
  canale = new Serial(this, porta, 9600);
  noStroke();
}


void draw(){
  background(51);
  if(canale.available()>0){
    int val = canale.read();
    
    switch(val){
      case 1:
        y-=5;
        break;
      case 2:
        y+=5;
        break;
      case 3:
        x-=5;
        break;
      case 4:
        x+=5;
        break;
    }
  }
  circle(x, y, 35);
  println(x +""+ y);
}
