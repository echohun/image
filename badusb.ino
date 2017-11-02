#include <Keyboard.h>
void setup() {
  // put your setup code here, to run once:
Keyboard.begin();//开始键盘通讯
delay(3000);//延时
Keyboard.press(KEY_LEFT_GUI);//win键
delay(50);
Keyboard.press('r');//r键
delay(50);
Keyboard.release(KEY_LEFT_GUI);
Keyboard.release('r');
delay(1000);
Keyboard.println("cmd \n"); //注意这里命令的最后多了一个空格 如果目标终端的输入法是中文的话这个空格非常关键
delay(500);
Keyboard.println("calc \n"); ; //注意最后有一个空格
delay(1000);//延时
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
}
