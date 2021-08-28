#include<stdio.h>
main()
{
	double a, b, d;
	char c;
	printf("欢迎使用计算器\n");
	scanf("%d%d%d", &a , &c, &b );
	if(c == '+')
	{
		scanf("%d",&b);
		d = a + b;
		printf("d = %d",d );
	}else if(c == '-')
	{
		scanf("%d",&b);
		d = a - b;
		printf("d = %d",d );
	}else if(c == '*')
	{
		scanf("%d",&b);
		d = a * b;
		printf("d = %d",d );
	}else if(c == '/')
	{
		scanf("%d",&b);
		d = a / b;
		printf("d = %d",d );
	}
	else
	{
		printf("您的输入有误");
	} 
 } 
