#include<stdio.h>
main()
{
	double a, b, d;
	char c;
	printf("��ӭʹ�ü�����\n");
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
		printf("������������");
	} 
 } 
