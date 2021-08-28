#include<stdio.h>
#include<string.h> 
main(void) 
{
	loop:
	printf("*********欢迎来到小猪梦琪屋*********\n");
	printf("*************请登录系统哦****************\n");
	int a, b, c, s, j, k, l, z, t, d, h, e, f, p, r, g;   //int 是定义变量的函数，int在这里是整形变量，a,b,在这里就是被定义的一个空间，名称叫做a,b。但是这个空间是有条件的，int就是限制空间存入数据的条件。 
	printf("账号："); //printf是输出函数，就是把你想要呈现的数据呈现在电脑屏幕上。 
	scanf("%d",&a);   //scanf是输入函数，通过键盘你输入数据，把这个数据内容赋值，也即是给一个被定义过的空间。 
	printf("密码：");
	scanf("%d",&b);
	if(a == 2013182991&&b == 7758521)  //这是if判断语句。 判断数据是否符合你定义的条件，然后运行结果。 && 这个符号是逻辑符号，意思是只要有一个不满足就错误。 
	{
		leap:
		printf("欢迎进入小猪梦琪屋主页面\n");
		printf("请根据以下菜单选择您想实现的功能\n");
		printf("1.小猪梦琪屋的简介\n");
		printf("2.用户积分查询\n"); 
		printf("3.进入购物菜单\n");
		printf("4.退出系统\n");
		printf("请输入相应选项：\n");
		scanf("%d",&c );
		if(c == 1)
		{
			liop:
			printf("本店是以爱情为主题创办的，本店的老板年轻时答应自己的妻子，未来要帮她完成奶茶玩具二合一的店铺，\n");
			printf("返回主菜单请输入1\n");
			scanf("%d",&s);
			if(s == 1)
			{
				goto leap;
			}else
			{
				printf("您的输入有误\n");
				goto liop; 
			}
		}
		else if(c == 2)
		{
			leep:
			printf("该功能正在开发中，敬请期待！\n");
			printf("返回主菜单请输入1\n");
			scanf("%d",&s);
			if(s == 1)
			{
				goto leap;
			}else
			{
				printf("您的输入有误\n");
				goto leep; 
			}
		}
		else if(c == 3)//c是购物菜单选项。 
		{
			printf("欢迎进入购物菜单\n");
			printf("1.小猪梦琪奶茶店\n");
			printf("2.小猪梦琪玩具店\n");
			printf("3.返回主菜单\n"); 
			printf("请输入你要选择的选项：\n");
			scanf("%d",&j);//j是奶茶店的选项菜单。 
			if(j == 1)
			{
				printf("欢迎来到小猪梦琪奶茶店\n"); 
				printf("以下是奶茶价格表，选择想买的奶茶输入序号即可，祝您购物愉快\n");
				printf("1.珍珠奶茶*****10￥/杯\n");
				printf("2.椰果奶茶*****10￥/杯\n");
				printf("3.巨无霸奶茶*****15￥/杯\n");
				scanf("%d",&k);
				if(k == 1)
				{
					printf("请输入购买数量：");//l是购买珍珠奶茶的数量。 
					scanf("%d",&l);
					printf("您购买珍珠奶茶的数量为：%d,是否确认？确认请按1\n",l );
					scanf("%d",&z);
					if(z == 1)
					{
						t = 10 * l;
						printf("应收您金额为：%d,欢迎您再次光临\n", t );
						printf("退出请按1\n返回主菜单请按2\n");
						scanf("%d",&d);
						if(d == 1)
						{
							goto loop;
						 }else if(d == 2)
						 {
						 	goto leap;
						  }else
						  {
						  	printf("您的输入有误。\n");
						  }
			        }
					}
					else if(k == 2)
				    {
					printf("请输入购买数量：");//l是购买珍珠奶茶的数量。 
					scanf("%d",&e);
					printf("您购买椰果奶茶的数量为：%d,是否确认？确认请按1\n",e );
					scanf("%d",&h);
					if(h == 1)
					{
						f = 10 * e;
						printf("应收您金额为：%d,欢迎您再次光临\n", f );
						printf("退出请按1\n返回主菜单请按2\n");
						scanf("%d",&p);
						if(p == 1)
						{
							goto loop;
						 }else if(p == 2)
						 {
						 	goto leap;
						  }else
						  {
						  	printf("您的输入有误。\n");
						  }
						 
					}
					 
			        }
				 
			}else if(j == 2)
			{
				printf("欢迎来到小猪梦琪玩具店\n");
				printf("1.购买娃娃机游戏币1￥/枚\n");
				printf("2.小猪梦琪公仔*****150￥/只\n"); 
				printf("3.可爱猪猪公仔*****100￥/只\n"); 
			}
	
		}
		
	}else  //这是否则的意思，如果不满足if里的条件运行的结果。 
	{
		printf("对不起，你输入的账号或者密码有误，请重新输入。\n");
		goto loop;
	}
}
