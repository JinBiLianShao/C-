/*
	第一课，C语言基本结构
	时间：2020.7.18 
*/


/*
	1.每一个C语言程序有且仅有一个main()函数。main是C语言程序的入口。
	2.{}大括号括起来的区域为函数体，是程序执行的区域。
	3.每一句代码后面都要有“；”结尾。说明这句话是一句完整的命令。
	4.C语言区分大小写，且所有编码符号都是英文输入法。
	5.C语言一共有32个关键字，这些关键字是不能更改的和自定义的，且全为小写字母。
	6.标识符：这个可以类比人类的名称，便于标识。它本身还是有一些规范的，比如不建议用汉字标识（其实也可以）。
	规范：标识符只能由英文字母（大小写），数字，下划线组成，并且第一个字符不能为数字。
	7.运算符：参与运算的字符，数据本身就可以进行运算，如果你看完离散数学后，你就知道所有的事物都可以离散，都可以数据化参与计算。
	8.分隔符：C语言中常用逗号和空格进行分隔变量。 
	
*/ 
#include<stdio.h>/*这个是头文件，.h是这个头文件的后缀名，include是预处理命令，形象的理解成提前加载所需要的东西*/
int Sum(int a,int b){ 
	return a+b;	
}
int main(){  
	printf("hello word! \n 你好 \n");/*printf是输出函数，意思就是将内容显示在你的屏幕上。\n为转义符，这个转义符是回车换行的意思*/
	int t = Sum(2,3);
	printf("sum的返回值为%d",t);
	return 0;/*return是返回值的意思，在这里返回值为0。*/ 
}


