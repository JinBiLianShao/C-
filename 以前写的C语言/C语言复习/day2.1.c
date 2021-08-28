/*
练习题 
时间：2020.7.25
判断数据类型所占内存空间 
练习：其余的数据类型所占字节。 
*/
#include<stdio.h>
/*
	sizeof是一种运算符，不是函数。功能是读取类型所占的内存字节数。 
*/ 
int main(){
	int i = sizeof(int);
	int s = sizeof(short);
	int l = sizeof(long);
	printf("int占%d字节\nshort占%d字节\nlong占%d字节",i,s,l);
	return 0; 
} 
