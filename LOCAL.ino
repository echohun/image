//#include <stdlib.h>
#include <LiquidCrystal.h>
const float Threshold=15.0; //定义阀值


char val; // 儲存蓝牙接收的数据
String str;
int flag = -1;
float Pitch, Rate;
int pinBuzzer = 3;//蜂鸣器接口（）
long frequency = 300; //频率, 单位Hz   
LiquidCrystal lcd(5, 4, 6, 7, 8, 9); //(rs,e,4,5,6,7)
void setup()
{
 pinMode(pinBuzzer, OUTPUT);//蜂鸣器接口设置为输出
   lcd.begin(16, 2);
  lcd.print("Waiting for ");
  lcd.setCursor(0,1);
  lcd.print("BlueTooth......");
  Serial1.begin(115200);
  while (!Serial1);
  int i=0;
//Serial.begin(9600);
//while(!Serial);
  str = "";
// while(Serial1.read()!='(' )
//  {
//
//     if(Serial1.available())
//     {
//    delay(2); 
//     lcd.clear();
//     lcd.print(String(i++));
//     }
//
//    }
  while(val!='(')
  {
    if(Serial1.available())
    {
      val=Serial1.read();
    }
    
  }

}


void Get()
{
  if (flag == 0 || flag == 2)
  {
    str += val;
    // if(flag==0)
    // Serial.println("flag=0:"+str);
  }
}

void Save1()
{
  if (flag == 0)
  {
    Pitch = str.toFloat();
    // Serial.println("SAVE1:"+str+","+String(Pitch));
  }
  str = "";
}

void Save2()
{
  Rate = str.toFloat();
  str = "";
}

void loop()
{   
  if (Serial1.available())
  {
    val = Serial1.read();
    //Serial.print(val);
    switch (val)
    {
      case '\n':
        flag = -1;
        str = "";
        break;
      case '(':
        flag = 0;
        break;
      case ',':
        Save1();
        flag = 1;
        break;
      case '$':
        flag = 2;
        break;
      case ')':
        flag = 3;
        Save2();
       if(Rate>=Threshold)
    {
        tone(pinBuzzer, frequency );  
        delay(1000);
        noTone(pinBuzzer);
     }
        break;
      default:
        Get();
    }
    if(Rate<0)
      Rate=-1*Rate;
    //if (flag == 0)
      //Serial.println("\nGet:"+'[' + String(Pitch) + ',' + String(Rate) + ']');
      lcd.clear();
      lcd.print("Change:"+String(Rate));
      lcd.setCursor(0, 1);
      lcd.print(Pitch);


  }

}
