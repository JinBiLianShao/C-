/*
    时间：2021.4.18
    作者：小鑫
    功能：
        1.一元二次方程求解
        2.通过一元二次方程了解和学习C语言基本的：输出函数，表达式，运算符，赋值等
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int a,b,c;//定义三个变量表示二元一次方程的系数
    double delta; //delta表示b*b-4*a*c的值
    double x1;
    double x2;//存放二元一次方程的两个解

    printf("请输入一元二次方程的系数a,b,c。并用空格隔开：\n"); //输出函数
    scanf("%d %d %d", &a, &b, &c); //输入函数 
    //&是取地址符，%d是控制符（%d表示整型）。因为存入内存都是二进制，你要告诉计算机是以怎样的编码格式存进去的，方便取出时解码。

    delta = b*b - 4*a*c;

    if(delta >= 0)
    {
        x1 = (-b + sqrt(delta)) / (2*a); //sqrt()是math.h中求根号的方法。
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("该一元二次方程的解有两个：x1 = %f, x2 = %f\n", x1, x2);
    }
    else
    {
       printf("该方程无解！！"); 
    }

    return 0;
}

/*
    犯错总结：
    1.输出的解易写成 %d 的控制符，而x1与x2是double（浮点型），故此解码时，数据不对。
    
*/
