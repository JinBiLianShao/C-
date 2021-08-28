#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main()
{
    char cmd[20]="shutdown -s -t ";
    char t[10]="0";
    system("title 小鑫关机程序");  //设置cmd窗口标题
    system("mode con cols=48 lines=25");  //窗口宽度高度 
    system("color f0");  //可以写成 red 调出颜色组
    system("date /T");
    system("TIME /T");
 
    printf("----------- 关机程序 -----------\n");
	printf("您想在多少分钟后自动关闭计算机？\n");
    scanf("%s",t);
    system(strcat(cmd,t));
    system("pause"); 
    return 0;
} 

