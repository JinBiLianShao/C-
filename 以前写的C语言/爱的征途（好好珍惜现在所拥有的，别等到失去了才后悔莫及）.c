#include<stdio.h>
#include<windows.h>
#include<string.h> 
		//��ʼ����ͼ 
				//��һ�ŵ�ͼ 
    int map1[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,2,1,1,1,4,1,1,1,3,3,3,3,3,3,3,3,3,3,1},
				   {1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,3,1},
				   {1,3,1,1,1,3,3,3,1,3,1,1,4,1,1,1,1,1,3,1},
				   {1,3,3,3,3,3,1,3,1,3,1,1,3,3,3,3,1,1,3,1},
				   {1,1,1,1,1,1,1,3,1,3,1,1,50,1,1,3,1,1,3,1},
				   {1,1,1,1,4,1,1,3,1,3,1,1,4,1,1,3,1,1,3,1},
				   {1,1,1,1,3,1,1,3,1,3,1,1,1,1,1,3,1,1,3,1},
				   {1,1,1,1,3,1,1,5,1,3,1,1,1,1,1,3,1,1,3,1},
				   {1,1,1,1,3,1,1,3,1,3,1,3,3,3,3,3,1,1,3,1},
				   {1,1,1,1,3,1,1,3,1,3,1,3,1,1,1,1,1,1,3,1},
				   {1,3,3,3,3,3,3,3,1,3,1,3,3,3,3,3,3,3,3,1},
				   {1,3,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1},
				   {1,3,1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,1,1},
				   {1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1},
				   {1,3,3,3,1,1,1,1,1,1,3,1,1,9,3,3,3,1,1,1},
				   {1,1,8,1,1,1,1,3,3,3,3,1,1,1,1,1,3,1,1,1},
				   {1,1,3,1,1,1,1,3,1,1,1,1,1,1,1,1,3,3,3,1},
				   {1,1,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,3,6},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
				   		//�ڶ��ŵ�ͼ 	ħ����һ�� 
  int map2[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {11,3,3,15,3,14,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1},
				   {1,3,3,3,3,3,1,3,3,3,3,1,3,3,3,3,3,1,3,1},
				   {1,3,1,1,1,3,1,3,3,1,3,1,3,19,3,7,3,1,3,1},
				   {1,3,1,25,15,3,3,3,3,1,3,1,3,3,3,3,3,1,3,1},
				   {1,3,1,1,1,3,1,3,3,1,3,1,1,1,15,1,1,1,3,1},
				   {1,3,3,3,3,3,1,3,3,1,14,1,1,1,3,1,1,1,3,1},
				   {1,1,1,16,1,1,1,3,3,1,3,1,3,3,3,3,3,1,3,1},
				   {1,3,3,3,3,3,1,3,3,1,3,1,3,18,3,7,3,1,3,1},
				   {1,18,3,3,3,19,1,3,3,1,3,1,3,3,3,3,3,1,3,1},
				   {1,18,3,3,3,19,1,3,3,1,3,1,1,1,15,1,1,1,3,1},
				   {1,18,3,3,3,19,1,3,3,1,3,3,3,3,3,3,3,1,3,1},
				   {1,3,7,7,7,3,1,3,3,1,1,1,1,1,1,1,1,1,3,1},
				   {1,1,1,17,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1},
				   {1,3,3,3,3,3,1,1,1,1,3,1,1,1,1,1,15,1,1,1},
				   {1,3,23,1,1,3,1,1,7,3,3,3,18,1,3,3,3,3,3,1},
				   {1,3,1,1,24,3,1,1,7,3,3,3,18,1,3,3,7,3,3,1},
				   {1,3,3,3,3,3,1,1,7,3,2,3,19,1,3,3,3,3,3,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
				   		//�����ŵ�ͼ 	ħ���ڶ��� 
  int map3[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1},
				   {1,1,3,3,3,3,1,3,3,3,3,1,3,1,1,1,1,1,1,1},
				   {1,1,3,7,7,3,1,3,3,1,3,1,3,1,3,3,3,1,1,1},
				   {1,1,3,7,24,3,16,3,3,1,3,1,3,17,3,23,3,1,1,1},
				   {1,1,3,7,7,3,1,3,3,1,3,1,3,1,3,3,3,1,1,1},
				   {1,1,3,3,3,3,1,3,3,1,3,1,3,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,10,1,1},
				   {1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,1,1,1,3,1,1,1,1,1,1,3,1,1,1,3,1,1},
				   {1,1,3,1,3,3,14,3,3,1,1,3,3,14,3,3,1,3,1,1},
				   {1,1,3,1,3,1,7,1,3,1,1,3,18,1,19,3,1,3,1,1},
				   {1,1,3,1,15,18,1,19,15,1,1,15,1,3,1,15,1,3,1,1},
				   {1,1,3,1,3,1,7,1,3,1,1,3,7,1,7,3,1,3,1,1},
				   {1,1,2,1,3,3,15,3,3,1,1,3,3,15,3,3,1,3,1,1},
				   {1,1,12,1,1,1,1,1,1,1,1,1,1,1,1,1,1,21,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
				   		//�����ŵ�ͼ 	ħ�������� 
  int map4[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,3,3,3,1,3,7,1,1,1,1,1,15,1,1,3,1,1},
				   {1,1,3,7,7,3,1,3,3,3,3,3,1,3,3,3,1,3,1,1},
				   {1,1,3,18,18,3,17,3,3,1,1,3,1,18,3,3,1,3,1,1},
				   {1,1,3,19,19,3,1,3,3,1,1,3,1,1,16,1,1,3,1,1},
				   {1,1,3,3,3,3,1,7,3,1,1,3,1,3,3,3,1,3,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,3,1,3,19,3,1,3,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,1,3,1,1},
				   {1,1,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,3,1,1},
				   {1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,1,1,1,14,1,1,3,1,1,1,1,1,1,1,3,1,1},
				   {1,1,3,1,7,3,3,3,1,3,1,3,3,3,16,3,3,3,1,1},
				   {1,1,17,1,1,1,14,1,1,3,1,3,1,1,1,1,1,3,1,1},
				   {1,1,3,1,3,3,3,7,1,3,1,3,1,3,3,3,1,3,1,1},
				   {1,1,3,1,14,1,1,1,1,3,1,3,1,3,23,3,13,3,1,1},
				   {1,1,3,3,3,3,3,3,1,2,1,3,3,3,3,3,1,3,1,1},
				   {1,1,31,1,1,1,1,1,1,22,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
				   		//�����ŵ�ͼ 	ħ�����Ĳ� 
  int map5[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1},
				   {1,1,3,1,1,1,1,17,1,1,1,1,16,1,1,1,1,3,1,1},
				   {1,1,3,1,1,1,1,17,1,1,1,1,16,1,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,7,3,1,1,3,7,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,7,3,1,1,3,7,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,1,17,1,1,1,1,16,1,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,7,3,1,1,3,7,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,7,3,1,1,3,7,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,1,17,1,1,1,1,16,1,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,3,1,1,1,3,23,3,1,1,3,24,3,13,13,13,3,1,1},
				   {1,1,2,1,1,1,3,3,3,1,1,3,3,3,1,1,1,3,1,1},
				   {1,1,32,1,1,1,1,1,1,1,1,1,1,1,1,1,1,41,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
				   		//�����ŵ�ͼ 	ħ������� 
  int map6[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {1,1,100,1,13,13,13,13,13,13,13,13,13,13,13,13,13,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,1,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,13,13,13,13,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,13,13,13,13,13,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,1,13,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,13,13,13,13,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,13,13,13,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,1,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,13,1,1,13,1,1,1,1,13,1,1,1,1,13,1,1},
				   {1,1,13,1,13,13,13,13,1,1,1,1,13,1,1,1,1,2,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,42,1,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};

		//��ɫ��Ϣ
struct hero{
	char name[20];	//�������� 
	int z_x;		//���Ǻ����� 
	int z_y;		//���������� 
	int jade;		//���֮�� 
	int is_over;	//�ж�һ���ƶ��Ľ��� 
	int hp;			//���ǵ�Ѫ�� 
	int carry;		//���ǵĹ����� 
	int defend;		//���ǵķ����� 
	int fortune; 	//���ǵĽ�� 
	int actor;		//���ǵ���Ϣ������ 
	int backpack; 	//����ͼ�׵ļ����� 
	int shop;		//�̵�ļ����� 
	int floor;		//¥���� 
	int money;		//���ڹ������Ľ�� 
};
struct monster{
	char m1_name[20];	//Сʷ��ķ�� 
	int m1_hp;
	int m1_carry;
	int m1_defend;
	char m1_lose[20];
	int m1Lose;
	char m2_name[20];	//��ʷ��ķ�� 
	int m2_hp;
	int m2_carry;
	int m2_defend;
	char m2_lose[20];
	int m2Lose;
	char m3_name[20];	//а����ʦ 
	int m3_hp;
	int m3_carry;
	int m3_defend;
	char m3_lose[20];
	int m3Lose;
	char m4_name[20];	//˫����ʿ 
	int m4_hp;
	int m4_carry;
	int m4_defend;
	char m4_lose[20];
	int m4Lose;
	char m5_name[20];	//��ʦ 
	int m5_hp;
	int m5_carry;
	int m5_defend;
	char m5_lose[20];
	int m5Lose;
} ;
struct contain{
	struct hero person;
	struct monster ms;
};

struct contain move(struct contain zd,int a[20][20]);
struct contain moveDown(struct contain zd,int a[20][20]); 
struct contain moveUp(struct contain zd,int a[20][20]);
struct contain moveRight(struct contain zd,int a[20][20]);
struct contain moveLeft(struct contain zd,int a[20][20]);
struct contain information(struct contain zd,int a[20][20]);
struct contain monsterBP(struct contain zd,int a[20][20]);
struct contain login(struct contain zd);
struct contain account(struct contain zd);
struct contain ShowMap(struct contain zd,int a[20][20]);
struct contain fightM1(struct contain zd);
struct contain fightM2(struct contain zd); 
struct contain fightM3(struct contain zd); 
struct contain fightM4(struct contain zd); 
struct contain fightM5(struct contain zd);
struct contain addCarry(struct contain zd);
struct contain addDefend(struct contain zd);
struct contain addCarry10(struct contain zd);
struct contain addDefend10(struct contain zd);
struct contain addHp(struct contain zd);
struct contain SHOP(struct contain zd);
struct contain openshop(struct contain zd);

				   		//����һ����ͼ�ĺ��������ֽ�ShowMap 
struct contain ShowMap(struct contain zd,int a[20][20]){
	system("cls"); 
	 zd=account(zd);
	system("color 75");
	int i=0,j=0;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(a[i][j]==1) printf("��");		//ǽ 
			else if(a[i][j]==2) printf("��");	//���� 
			else if(a[i][j]==3) printf("  ");	//�ո� 
			else if(a[i][j]==4) printf("��");	//���֮�� 
			else if(a[i][j]==5||a[i][j]==8||a[i][j]==9||a[i][j]==50) printf("�d");	//���� 
			else if(a[i][j]==6) printf("��");	//���� 
			else if(a[i][j]==7) printf("%c%c",3,3);//Ѫƿ 	200�� 
			else if(a[i][j]==10)printf("��");	//����ͼ�� 
			else if(a[i][j]==11)printf("��");	//һ¥������ 
			else if(a[i][j]==12)printf("��");	//��¥������
			else if(a[i][j]==21)printf("��");	//��¥������ 
			else if(a[i][j]==22)printf("��");	//��¥������
			else if(a[i][j]==31)printf("��");	//��¥������ 
			else if(a[i][j]==32)printf("��");	//��¥������
			else if(a[i][j]==41)printf("��");	//��¥������ 
			else if(a[i][j]==42)printf("��");	//��¥������ 
			else if(a[i][j]==13)printf("��");	//���Դ�͸��ǽ
			else if(a[i][j]==14)printf("��");	//Сʷ��ķ�� 
			else if(a[i][j]==15)printf("��");	//��ʷ��ķ�� 
			else if(a[i][j]==16)printf("��");	//а����ʦ 
			else if(a[i][j]==17)printf("��");	//˫����ʿ 
			else if(a[i][j]==18)printf("��");	//����  2�� 
			else if(a[i][j]==19)printf("��");	//����	2�� 
			else if(a[i][j]==23)printf("��");	//��  ����  10�� 
			else if(a[i][j]==24)printf("��");	//��  ����  10�� 
			else if(a[i][j]==25)printf("��");	//�����̵� 
			else if(a[i][j]==100)printf("��");	//��ʦ  
		}printf("\n");
	}
	if(zd.person.floor>=1)printf("\t        ħ����%d��\n",zd.person.floor);
	return zd;
}
		//���������ǵ���Ѫ����
struct contain account(struct contain zd){
			//Сʷ��ķ�� 
		int x=0,y=0,z=0; 
		z=zd.person.carry-zd.ms.m1_defend;
		if(z!=0) x=zd.ms.m1_hp/z;
  		y=(x-1)*(zd.ms.m1_carry-zd.person.defend);
	if(zd.person.carry<=zd.ms.m1_defend||zd.person.hp<=y){
		strcpy(zd.ms.m1_lose,"?????");
	}else{
		if(zd.ms.m1_carry<=zd.person.defend){
			strcpy(zd.ms.m1_lose,"0");
			zd.ms.m1Lose=0;
		}else {
	      	zd.ms.m1Lose=y;
			itoa(zd.ms.m1Lose,zd.ms.m1_lose,10);
		}
	}
			//��ʷ��ķ�� 
		z=zd.person.carry-zd.ms.m2_defend;
		if(z!=0) x=zd.ms.m2_hp/z;
		y=(x-1)*(zd.ms.m2_carry-zd.person.defend);
	if(zd.person.carry<=zd.ms.m2_defend||zd.person.hp<=y){
		strcpy(zd.ms.m2_lose,"?????");
	}else{
		if(zd.ms.m2_carry<=zd.person.defend){
			strcpy(zd.ms.m2_lose,"0");
			zd.ms.m2Lose=0;
		}else {
       		zd.ms.m2Lose=y;
			itoa(zd.ms.m2Lose,zd.ms.m2_lose,10);
		}
	}
			//а����ʦ  
		z=zd.person.carry-zd.ms.m3_defend;
		if(z!=0) x=zd.ms.m3_hp/z;
		y=(x-1)*(zd.ms.m3_carry-zd.person.defend);
	if(zd.person.carry<=zd.ms.m3_defend||zd.person.hp<=y){
		strcpy(zd.ms.m3_lose,"?????");
	}else{
		if(zd.ms.m3_carry<=zd.person.defend){
			strcpy(zd.ms.m3_lose,"0");
			zd.ms.m3Lose=0;
		}else {
  			zd.ms.m3Lose=y;
			itoa(zd.ms.m3Lose,zd.ms.m3_lose,10);
		}
	}
			//˫����ʿ 
		z=zd.person.carry-zd.ms.m4_defend;
		if(z!=0) x=zd.ms.m4_hp/z;
		y=(x-1)*(zd.ms.m4_carry-zd.person.defend);
	if(zd.person.carry<=zd.ms.m4_defend||zd.person.hp<=y){
		strcpy(zd.ms.m4_lose,"?????");
	}else{
		if(zd.ms.m4_carry<=zd.person.defend){
			strcpy(zd.ms.m4_lose,"0");
			zd.ms.m4Lose=0;
		}else { 
	       	zd.ms.m4Lose=y;
			itoa(zd.ms.m4Lose,zd.ms.m4_lose,10);
		}
	}
			//��ʦ 
		z=zd.person.carry-zd.ms.m5_defend;
		if(z!=0) x=zd.ms.m5_hp/z;
		y=(x-1)*(zd.ms.m5_carry-zd.person.defend);
	if(zd.person.carry<=zd.ms.m5_defend||zd.person.hp<=y){
		strcpy(zd.ms.m5_lose,"?????");
	}else{
		if(zd.ms.m5_carry<=zd.person.defend){
			strcpy(zd.ms.m5_lose,"0");
			zd.ms.m5Lose=0;
		}else { 
			zd.ms.m5Lose=y;
			itoa(zd.ms.m5Lose,zd.ms.m5_lose,10);
		}
	}
	return zd;
} 
		//������ 
int main(void){
	struct hero person={"����",1,1,0,0,400,6,8,0,0,0,0,0,2};
	struct monster ms={ "Сʷ��ķ��",100,20,0,"???",1000000, 
						"��ʷ��ķ��",100,50,0,"???",1000000,
						"а����ʦ",200,70,10,"???",1000000,
						"˫����ʿ",300,100,25,"???",1000000,
						"��ʦ",500,200,60,"???",1000000};
	struct contain zd;
	zd.ms=ms;
	zd.person=person;
	load();
	post();
	background(); 
	scene();
	mention();
	jiazai();
	ShowMap(zd,map1);
	zd=move(zd,map1);
	theme();
	zd=login(zd);
	ShowMap(zd,map2);
	zd=move(zd,map2);
	gameover();
	getch();
} 
		//��Ϸǰ��С����
int mention(void){
	printf("\n\n\t\t\t��ϷС��ʾ:\n");
	printf("\t\t\t��Ϸǰ�뽫���뷨�л�ΪӢ������\n");
	printf("\t\t\t���ϣ�w\n");
	printf("\t\t\t���£�s\n");
	printf("\t\t\t����a\n");
	printf("\t\t\t���ң�d\n");
	printf("\n\t\t\t�����������...\n");
	getch();
	system("cls");
} 
		//���顪�����ˡ��������Ķ��� 
int scene(void){
	printf("\n\n\n\n\t\tloading");
	int x=0;
	for(x=0;x<7;x++){
 			Sleep(100);
			printf(".");
				 }
 	system("cls");
 	printf("\n\n\n\n    \t\t����С�εĶ���:\n");Sleep(1000);printf("\t\t\t��");Sleep(200);printf("��");Sleep(200);
 	printf("��");Sleep(200);printf("ǰ");Sleep(500);printf("��");Sleep(200);printf("��");Sleep(200);
 	printf("��\n");Sleep(1000);printf("\t\t\t��");Sleep(500);printf("��");Sleep(100);printf("��");Sleep(100);
 	printf("ֱ");Sleep(100);printf("��");Sleep(100);printf("��");Sleep(100);printf("һ\n");Sleep(1000);
 	printf("\t\t\t��");Sleep(100);printf("��������\n");Sleep(1000);printf("\t\t\t��");Sleep(100);printf("��");Sleep(700);
	printf("��");Sleep(100);printf("��");Sleep(100);printf("��");Sleep(100);printf("��");Sleep(100);
	printf("��");Sleep(100);printf("��\n");Sleep(1000);printf("\t\t\t��");Sleep(100);printf("��");Sleep(100);
	printf("ͻȻ\n");Sleep(1000);printf("\t\t\t��ʧ");Sleep(100);printf("��");Sleep(100);printf("�ҵ�");Sleep(100);
	printf("��");Sleep(100);printf("��\n");Sleep(500);printf("\n\t\t\t�����������...\n");
	getch();
	system("cls");
}
		//���顪�����ˡ���������Ⱦ
		//��Ļһ
int postOne(int count){
	printf("\n\n\n");
	switch(count){
		case 4:printf("\t\t***************************************\n");
		case 3:printf("\t\t*       ��                            *\n");
		case 2:printf("\t\t*             ������;                *\n");
		case 1:printf("\t\t*                            ��       *\n"); 
	   default:printf("\t\t***************************************\n");
	}
} 
		//��Ļ�� 
int postTwo(int count){
	printf("\n\n\n");
	switch(count){
		case 4:printf("\t\t***************************************\n");
		case 3:printf("\t\t*                              ##     *\n");
		case 2:printf("\t\t*        ��Ա������С�κ͹�������     *\n");
		case 1:printf("\t\t*                                     *\n"); 
	   default:printf("\t\t***************************************\n");
	}
}
		//��Ļ�� 
int postThree(int count){
	printf("\n\n\n");
	switch(count){
		case 4:printf("\t\t***************************************\n");
		case 3:printf("\t\t*         ����             ��         *\n");
		case 2:printf("\t\t*             �������     ��         *\n");
		case 1:printf("\t\t*                      ��      ^-^    *\n"); 
	   default:printf("\t\t***************************************\n");
	}
}
		//��Ļѭ��
int post(){
	int count=0,num=1;
	Sleep(1000);
	for(;num!=4;){
		for(;count!=5;){
		switch(num){
			case 1:postOne(count);
				break;
			case 2:postTwo(count);
				break;
			case 3:postThree(count);
				break;
		}
		Sleep(400); 
		system("cls");
		count++;	
	}
	count--;
	for(;count!=-1;){
		switch(num){
			case 1:postOne(count);
				break;
			case 2:postTwo(count);
				break;
			case 3:postThree(count);
				break;
		}
		Sleep(200); 
		system("cls");
		count--;	
	}
	system("cls");
	Sleep(1000);
	count=0;
	num++;
	}
	
} 
		//���顪����������
int background(){
	char test[1000]="\n \n \n \n \t\t\tѪ �� �� �� �� �� �� Ц \n \t\t\t�� �� �� �� Ҷ \n \t\t\t�� �� �� �� · \n \t\t\t�� �� ʬ �� Ұ \n \t\t\t�� ˵ \n \t\t\t�� �� �� �� �� �� �� �� \n \t\t\t�� �� �� �� �� �� Ѷ �� \n \t\t\t�� �� �� �� �� �� \n \t\t\t�� �� �� \n \t\t\tɱ �� �� �� \n \t\t\t�� �� �� �� \n";
	char *p ;
	p = strtok(test," ");
	while(p){
		printf("%s",p);
		p = strtok(NULL," ");
		Sleep(100);
	}
	printf("\n\t\t\t�����������\n");
	getch();
	system("cls");
} 
		//���ڼ�����
int jiazai(){
	int i=0;
	for(i=0;i<1;i++){
	system("cls");
	printf("\n\t\t\t���Եȣ����ڼ�����...\n");Sleep(15);system("cls");
	printf("\t\t\t��\n"); 
	printf("\t\t\t  �Եȣ����ڼ�����...\n");Sleep(50);system("cls");
	printf("\t\t\t  ��\n"); 
	printf("\t\t\t��  �ȣ����ڼ�����...\n");Sleep(50);system("cls");
	printf("\t\t\t    ��\n"); 
	printf("\t\t\t����  �����ڼ�����...\n");Sleep(50);system("cls");
	printf("\t\t\t      ��\n"); 
	printf("\t\t\t���Ե�  ���ڼ�����...\n");Sleep(50);system("cls");
	printf("\t\t\t        ��\n"); 
	printf("\t\t\t���Եȣ�  �ڼ�����...\n");Sleep(50);system("cls");
	printf("\t\t\t          ��\n"); 
	printf("\t\t\t���Եȣ���  ������...\n");Sleep(50);system("cls");
	printf("\t\t\t            ��\n"); 
	printf("\t\t\t���Եȣ�����  ����...\n");Sleep(50);system("cls");
	printf("\t\t\t              ��\n"); 
	printf("\t\t\t���Եȣ����ڼ�  ��...\n");Sleep(50);system("cls");
	printf("\t\t\t                ��\n"); 
	printf("\t\t\t���Եȣ����ڼ���  ...\n");Sleep(50);system("cls");
	printf("\t\t\t                  .\n"); 
	printf("\t\t\t���Եȣ����ڼ����� ..\n");Sleep(50);system("cls");
	printf("\t\t\t                   .\n"); 
	printf("\t\t\t���Եȣ����ڼ�����. .\n");Sleep(50);system("cls");
	printf("\t\t\t                    .\n"); 
	printf("\t\t\t���Եȣ����ڼ�����.. \n");Sleep(50);system("cls");
	printf("\n\t\t\t���Եȣ����ڼ�����...\n");Sleep(200);
	system("cls");	
	}	
} 
		//���顪����β
int last(){
	printf("\n\n\n\n\t\t\t��");Sleep(300);printf("��");Sleep(300);printf("��");Sleep(300);printf("��");Sleep(500);
	printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);
	printf("��");Sleep(200);printf("��");Sleep(200);printf("��\n");Sleep(2000);
	
	printf("\t\t\t��");Sleep(300);printf("��");Sleep(300);printf("��");Sleep(600);printf("����");Sleep(300);
	printf("����");Sleep(300);printf("С��");Sleep(300);printf("������");Sleep(300);printf("ӵ�뻳��\n");Sleep(1000);
	
	printf("\t\t���ӣ�\n"); Sleep(2000); printf("\t\t\t��");Sleep(200);printf("��Ϊ");Sleep(200);
	printf("��Ҳ");Sleep(200);printf("������");Sleep(200);printf("���ˣ�");Sleep(3000);printf("\n\t\t\t��");Sleep(400);
	printf("��");Sleep(400);printf("��");Sleep(400);printf("��");Sleep(400);printf("��");Sleep(400);
	printf("ӵ\n");Sleep(5000);printf("\t\t������\n");Sleep(2000);printf("\t\t\t����");Sleep(1000);
	printf("�վ�");Sleep(300);printf("û");Sleep(700);printf("���赲");Sleep(200);printf("����");Sleep(200);
	printf("�İ�\n");Sleep(2000);
	
	printf("\t\t\t�Ҳ���");Sleep(700);printf("ʧȥ");Sleep(200);printf("�㣬");Sleep(200);printf("����");Sleep(200);
	printf("�ҡ�������\n");Sleep(2000);printf("\t\t\t�ҵ�");Sleep(200);printf("���ӵ���");Sleep(200);printf("��");Sleep(200);
	printf("��");Sleep(200);printf("��\n");Sleep(2000);
	
	printf("\n\t\t\t��");Sleep(700);printf("��");Sleep(200);printf("ת");Sleep(200);printf("��");Sleep(200);
	printf("\n");Sleep(2000);printf("\t\t\t��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);
	printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(700);
	printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);printf("��");Sleep(200);
	printf("ʯ");Sleep(200);printf("һ");Sleep(200);printf("��");Sleep(200);
	printf("��");Sleep(700);printf("��");Sleep(200);printf("��\n");Sleep(2000);
	
	printf("\n\t\t\t��");Sleep(700);printf("��һ��");Sleep(300);printf("��ʧ");Sleep(200);
	printf("����\n");Sleep(2000);
	
	printf("\t\t��");Sleep(700);printf("��");Sleep(300);printf("ʹ");Sleep(200);printf("�ޣ�\n");Sleep(5000);
	
	printf("\t\t\t��һ��");Sleep(1000);printf("����");Sleep(1000);printf("��");Sleep(1000);printf("��������\n");
	printf("\n\n\t\t\t�����������\n");
	getch();
}  
 		//������
int load(void){
	int i=0,j=0,count=0;
	system("color 73");
	for(i=0;i<=50;i++){
		printf("\n\n\n\n\t\t\t\t     Installing%d%%\n",count);
		for(j=0;j<=count/2;j++){
			printf("_");
		}
		if(count!=100){
			count=count+2;
			Sleep(10);
			system("cls");
		}else {
			printf("\n");
			Sleep(500);
			system("cls");
			return 0;
		}
	}
} 
		//Ч��һ
int actionOne(){
	Sleep(1000);
	system("color 75");
	Sleep(1000);
	system("color 71");
	Sleep(1000);
	system("color 72");
	Sleep(1000);
	system("color 74");
	Sleep(1000);
	system("color 70");
	system("cls");
} 
		//Ģ��
int monsterOne(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t�ɰ���Ģ������\n\n"); 
	printf("\t\t\t           ''''''         	  \n");
	printf("\t\t\t        ''''''''''''         \n");
	printf("\t\t\t      '''''''''''''''��      \n");
	printf("\t\t\t    ''''''''''''''''''''     \n");
	printf("\t\t\t   ''''''''''''''''''''''''   \n");
	printf("\t\t\t  ''''''''���������� '''''''  \n");
	printf("\t\t\t  '''''''����   ��  ��''''''' \n");
	printf("\t\t\t   ''''''��      �� ��''''''  \n");
	printf("\t\t\t      ����   ��     ����      \n");
	printf("\t\t\t         ''''''''''''         \n");
	printf("\t\t\t         ''''''''''''         \n");
	printf("\t\t\t         ''''''''''''         \n");
	printf("\t\t\t         ''''''''''''         \n");
	printf("\t\t\t         ''''''''''''         \n");
	printf("\t\t\t          ''''''''''          \n");
} 
		//Ů��
int monsterTwo(){
		system("cls");
		printf("\n\n");
		printf("\t\t\t      �ɶ������\n\n"); 
		printf("\t\t\t           @@@\n");
		printf("\t\t\t          #   #\n");
		printf("\t\t\t         / \\     \n");
		printf("\t\t\t       /  @-.\\\n");
		printf("\t\t\t     /_  )\\\\  _\\\n");
		printf("\t\t\t    /\\/\\/ | \\/\\/\\\n");
		printf("\t\t\t\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");
		printf("\t\t\t       /~~~~~\\\n");
		printf("\t\t\t      |  ^ ^  |\n");
		printf("\t\t\t      |   .   |\n");
		printf("\t\t\t      | (\\_/) |\n");
		printf("\t\t\t  / .-. \\___/ .-. \\\n");
		printf("\t\t\t @/` /.-.   .-.\\ `\\@\n");
		printf("\t\t\t    @`   \\ /   `@\n");
		printf("\n");
		printf("\n");
} 
			//��ʦ 
int monsterThree(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t      ���ʦ��ٻ\n\n");
	printf("\t\t               ������         	\n");
	printf("\t\t             �֡֡֡֡�         \n");
	printf("\t\t           �֡֡֡֨� �Φ�      \n");
	printf("\t\t          �֡�����������Φ�    \n");
	printf("\t\t        �̡ҡҡ�       �ƦΦ�   \n");
	printf("\t\t       �ҡҡҡ� E    E   �ƦΦ� \n");
	printf("\t\t       �ҡҡҡ�~       �ߦƦΦ� \n");
	printf("\t\t       �ҡҡҡ�    -     �ƦΦ� \n");
	printf("\t\t       �ҡҡҡ�      ��         \n");
	printf("\n\n\n\n");
}
		//�ƶ����ܺ��� 
struct contain move(struct contain zd,int a[20][20]){
	for(;;){
		char position=getch();
	switch(position){
		case 'w':zd=moveUp(zd,a);
	 			 system("cls");
	 			 zd=ShowMap(zd,a);
				 break;
	 	case 'a':zd=moveLeft(zd,a);
	 	         system("cls");
	 			 zd=ShowMap(zd,a);
				 break;
	 	case 's':zd=moveDown(zd,a);
	 			 system("cls");
	 			 zd=ShowMap(zd,a);
				 break;
	 	case 'd':zd=moveRight(zd,a);
	 		if(zd.person.is_over==0){
		 	   	 system("cls");
	 			 zd=ShowMap(zd,a);
		 	} 
		 		 break;
	 	case 'c':		//�鿴������Ϣ 
		 	if(zd.person.actor==1){
	 			zd=information(zd,a);
	 			 system("cls");
	 			 zd=ShowMap(zd,a);
	 		}
				 break;
 		case 'p':		//�����̵� 
		 	if(zd.person.shop==1){
	 			zd=SHOP(zd);
	 			 system("cls");
	 			 zd=ShowMap(zd,a);
	 		}
				 break;
	 	case 'b':		//�鿴����ͼ�� 
  			if(zd.person.backpack==1){
			  	zd=monsterBP(zd,a);
	 			 system("cls");
	 			 zd=ShowMap(zd,a);
			  }
				 break;
	}	
	if(zd.person.is_over==1){
		return zd;
	}
	}
	return zd;
} 
		//�����ƶ� 
struct contain moveUp(struct contain zd,int a[20][20]){
	if(a[zd.person.z_x-1][zd.person.z_y]==3||a[zd.person.z_x-1][zd.person.z_y]==13){//��һ���ǿո� 
		a[zd.person.z_x][zd.person.z_y]=3;
		a[zd.person.z_x-1][zd.person.z_y]=2;
		zd.person.z_x=zd.person.z_x-1;
	}else if(a[zd.person.z_x-1][zd.person.z_y]==4){			//�ռ����֮�� 
		a[zd.person.z_x-1][zd.person.z_y]=3;
		system("cls");
		zd.person.jade++;
		printf("\n\n\t\t�ռ���%d�����֮��\n\t\t����4�����֮��ſ��Ծ�����",zd.person.jade);
		if(zd.person.jade==4){
			getch();
			system("cls");
			printf("\n\n\t\t���Ѽ���4�����֮��\n\t\t��ȥ��������Ӱ�\n");
		}
		getch();
	}else if(a[zd.person.z_x-1][zd.person.z_y]==10){		//�������ͼ�� 
		system("cls");
		printf("\n\n\t\t\t���ߣ�\n\t\t\t    ��ϲ���ù���ͼ��һ����\n\t\t\t    ��Ϸ�а�b������ʱ�鿴������Ϣ\n");
		zd.person.backpack=1;
		a[zd.person.z_x-1][zd.person.z_y]=3;
		getch();
	}else if(a[zd.person.z_x-1][zd.person.z_y]==14){//��һ����Сʷ��ķ�� 
		if(zd.person.hp>zd.ms.m1Lose){
			a[zd.person.z_x-1][zd.person.z_y]=3;
			zd=fightM1(zd); 
		}else {
			faild(zd);
		} 
	}else if(a[zd.person.z_x-1][zd.person.z_y]==15){//��һ���Ǵ�ʷ��ķ�� 
		if(zd.person.hp>zd.ms.m2Lose){
			a[zd.person.z_x-1][zd.person.z_y]=3;
			zd=fightM2(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==16){//��һ����а����ʦ 
		if(zd.person.hp>zd.ms.m3Lose){
			a[zd.person.z_x-1][zd.person.z_y]=3;
			zd=fightM3(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==17){//��һ����˫����ʿ 
		if(zd.person.hp>zd.ms.m4Lose){
			a[zd.person.z_x-1][zd.person.z_y]=3;
			zd=fightM4(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==100){//��һ���Ǵ�ʦ 
		if(zd.person.hp>zd.ms.m5Lose){
			a[zd.person.z_x-1][zd.person.z_y]=3;
			zd=fightM5(zd);
			zd.person.is_over=1;
			return zd; 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==18){//��һ���Ǽӹ�����2�� 
		zd=addCarry(zd);
		a[zd.person.z_x-1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==19){//��һ���Ǽӷ�����2�� 
		zd=addDefend(zd);
		a[zd.person.z_x-1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==23){//��һ���Ǽӹ�����10�� 
		zd=addCarry10(zd);
		a[zd.person.z_x-1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x-1][zd.person.z_y]==24){//��һ���Ǽӷ�����10�� 
		zd=addDefend10(zd);
		a[zd.person.z_x-1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x-1][zd.person.z_y]==7){//��һ���Ǽ�Ѫ200 
		zd=addHp(zd);
		a[zd.person.z_x-1][zd.person.z_y]=3;
	}
	return zd;
}
 		//�����ƶ� 
struct contain moveDown(struct contain zd,int a[20][20]){
	if(a[zd.person.z_x+1][zd.person.z_y]==3||a[zd.person.z_x+1][zd.person.z_y]==13){//����һ���ǿո� 
		a[zd.person.z_x][zd.person.z_y]=3;
		a[zd.person.z_x+1][zd.person.z_y]=2;
		zd.person.z_x=zd.person.z_x+1;
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==12){//��һ������һ¥ 
		zd.person.floor=1;
		ShowMap(zd,map2);
		zd.person.z_x=1;
		zd.person.z_y=1; 
		zd=move(zd,map2);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==21){//��һ��������¥ 
		zd.person.floor=3;
		ShowMap(zd,map4);
		zd.person.z_x=17;
		zd.person.z_y=9;
		zd=move(zd,map4);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==22){//��һ�����¶�¥ 
		zd.person.floor=2;
		ShowMap(zd,map3);
		zd.person.z_x=17;
		zd.person.z_y=17;
		zd=move(zd,map3);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==31){//��һ��������¥ 
		zd.person.floor=4;
		ShowMap(zd,map5);
		zd.person.z_x=17;
		zd.person.z_y=2;
		zd=move(zd,map5);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==32){//��һ��������¥ 
		zd.person.floor=3;
		ShowMap(zd,map4);
		zd.person.z_x=17;
		zd.person.z_y=2;
		zd=move(zd,map4);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==41){//��һ��������¥ 
		zd.person.floor=5;
		ShowMap(zd,map6);
		zd.person.z_x=17;
		zd.person.z_y=17;
		zd=move(zd,map6);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==42){//��һ��������¥ 
		zd.person.floor=4;
		ShowMap(zd,map5);
		zd.person.z_x=17;
		zd.person.z_y=17;
		zd=move(zd,map5);
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==5) {		//����һ���ǵ�һ������ (1)
		jiazai();
		monsterOne();
		sceneFirst();
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==50) {		//����һ���ǵ�һ������ (2)
		jiazai();
		monsterOne();
		sceneFirstII();
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==8) {		//����һ���ǵڶ������� 
		jiazai();
		monsterTwo();
		sceneSecond();
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==9) {		//����һ���ǵ��������� 
		jiazai();
		monsterThree();
		sceneThird();
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==14){//��һ����Сʷ��ķ�� 
		if(zd.person.hp>zd.ms.m1Lose){
			a[zd.person.z_x+1][zd.person.z_y]=3;
			zd=fightM1(zd); 
		}else {
			faild(zd);
		} 
	}else if(a[zd.person.z_x+1][zd.person.z_y]==15){//��һ���Ǵ�ʷ��ķ�� 
		if(zd.person.hp>zd.ms.m2Lose){
			a[zd.person.z_x+1][zd.person.z_y]=3;
			zd=fightM2(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==16){//��һ����а����ʦ 
		if(zd.person.hp>zd.ms.m3Lose){
			a[zd.person.z_x+1][zd.person.z_y]=3;
			zd=fightM3(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==17){//��һ����˫����ʿ 
		if(zd.person.hp>zd.ms.m4Lose){
			a[zd.person.z_x+1][zd.person.z_y]=3;
			zd=fightM4(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==18){//��һ���Ǽӹ�����2�� 
		zd=addCarry(zd);
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==19){//��һ���Ǽӷ�����2�� 
		zd=addDefend(zd);
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==23){//��һ���Ǽӹ�����10�� 
		zd=addCarry10(zd);
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}
	else if(a[zd.person.z_x+1][zd.person.z_y]==24){//��һ���Ǽӷ�����10�� 
		zd=addDefend10(zd);
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==7){//��һ���Ǽ�Ѫ200 
		zd=addHp(zd);
		a[zd.person.z_x+1][zd.person.z_y]=3;
	}else if(a[zd.person.z_x+1][zd.person.z_y]==4){
		a[zd.person.z_x+1][zd.person.z_y]=3;
		system("cls");
		zd.person.jade++;
		printf("\n\n\t\t�ռ���%d�����֮��\n\t\t����4�����֮��ſ��Ծ�����",zd.person.jade);
		if(zd.person.jade==4){
			getch();
			system("cls");
			printf("\n\n\t\t���Ѽ���4�����֮��\n\t\t��ȥ��������Ӱ�\n");
		}
		getch();
	}
	return zd;
}
 		//�����ƶ� 
struct contain moveLeft(struct contain zd,int a[20][20]){
	if(a[zd.person.z_x][zd.person.z_y-1]==3||a[zd.person.z_x][zd.person.z_y-1]==13){//��һ���ǿո� 
		a[zd.person.z_x][zd.person.z_y]=3;
		a[zd.person.z_x][zd.person.z_y-1]=2;
		zd.person.z_y=zd.person.z_y-1;
	}else if(a[zd.person.z_x][zd.person.z_y-1]==11){//��һ�����϶�¥ 
		zd.person.floor=2;
		ShowMap(zd,map3);
		zd.person.z_x=17;
		zd.person.z_y=2;
		zd=move(zd,map3);
	}else if(a[zd.person.z_x][zd.person.z_y-1]==14){//��һ����Сʷ��ķ�� 
		if(zd.person.hp>zd.ms.m1Lose){
			a[zd.person.z_x][zd.person.z_y-1]=3;
			zd=fightM1(zd); 
		}else {
			faild(zd);
		} 
	}else if(a[zd.person.z_x][zd.person.z_y-1]==15){//��һ���Ǵ�ʷ��ķ�� 
		if(zd.person.hp>zd.ms.m2Lose){
			a[zd.person.z_x][zd.person.z_y-1]=3;
			zd=fightM2(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==16){//��һ����а����ʦ 
		if(zd.person.hp>zd.ms.m3Lose){
			a[zd.person.z_x][zd.person.z_y-1]=3;
			zd=fightM3(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==17){//��һ����˫����ʿ 
		if(zd.person.hp>zd.ms.m4Lose){
			a[zd.person.z_x][zd.person.z_y-1]=3;
			zd=fightM4(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==18){//��һ���Ǽӹ�����2�� 
		zd=addCarry(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==19){//��һ���Ǽӷ�����2�� 
		zd=addDefend(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==23){//��һ���Ǽӹ�����10�� 
		zd=addCarry10(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y-1]==24){//��һ���Ǽӷ�����10�� 
		zd=addDefend10(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}else if(a[zd.person.z_x][zd.person.z_y-1]==7){//��һ���Ǽ�Ѫ200 
		zd=addHp(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}else if(a[zd.person.z_x][zd.person.z_y-1]==25){//��һ�����̵�
		zd=openshop(zd);
		a[zd.person.z_x][zd.person.z_y-1]=3;
	}
	return zd;
}
 		//�����ƶ� 
struct contain moveRight(struct contain zd,int a[20][20]){
	if(a[zd.person.z_x][zd.person.z_y+1]==3||a[zd.person.z_x][zd.person.z_y+1]==13){//��һ���ǿո� 
		a[zd.person.z_x][zd.person.z_y]=3;
		a[zd.person.z_x][zd.person.z_y+1]=2;
		zd.person.z_y=zd.person.z_y+1;
	}else if(a[zd.person.z_x][zd.person.z_y+1]==6&&zd.person.jade==4){		//��Ϸ�̵���� 
		system("cls");
		last();
		gameBegin();
		zd.person.is_over=1;
		zd.person.z_x=18;
		zd.person.z_y=10;
		return zd;
	}else if(a[zd.person.z_x][zd.person.z_y+1]==14){//��һ����Сʷ��ķ�� 
		if(zd.person.hp>zd.ms.m1Lose){
			a[zd.person.z_x][zd.person.z_y+1]=3;
			zd=fightM1(zd); 
		}else {
			faild(zd);
		} 
	}else if(a[zd.person.z_x][zd.person.z_y+1]==15){//��һ���Ǵ�ʷ��ķ�� 
		if(zd.person.hp>zd.ms.m2Lose){
			a[zd.person.z_x][zd.person.z_y+1]=3;
			zd=fightM2(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==16){//��һ����а����ʦ 
		if(zd.person.hp>zd.ms.m3Lose){
			a[zd.person.z_x][zd.person.z_y+1]=3;
			zd=fightM3(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==17){//��һ����˫����ʿ 
		if(zd.person.hp>zd.ms.m4Lose){
			a[zd.person.z_x][zd.person.z_y+1]=3;
			zd=fightM4(zd); 
		}else {
			faild(zd);
		} 
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==18){//��һ���Ǽӹ�����2�� 
		zd=addCarry(zd);
		a[zd.person.z_x][zd.person.z_y+1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==19){//��һ���Ǽӷ�����2�� 
		zd=addDefend(zd);
		a[zd.person.z_x][zd.person.z_y+1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==23){//��һ���Ǽӹ�����10�� 
		zd=addCarry10(zd);
		a[zd.person.z_x][zd.person.z_y+1]=3;
	}
	else if(a[zd.person.z_x][zd.person.z_y+1]==24){//��һ���Ǽӷ�����10�� 
		zd=addDefend10(zd);
		a[zd.person.z_x][zd.person.z_y+1]=3;
	}else if(a[zd.person.z_x][zd.person.z_y+1]==7){//��һ���Ǽ�Ѫ200 
		zd=addHp(zd);
		a[zd.person.z_x][zd.person.z_y+1]=3;
	}
	return zd;
}
		//�鿴������Ϣ
struct contain information(struct contain zd,int a[20][20]){
	system("cls");
	printf("\n\n\t\t\t    ��������\n");
	printf("\t\t\t�ǳ�  ��%s\n",zd.person.name);
	printf("\t\t\t����ֵ��%d\n",zd.person.hp);
	printf("\t\t\t����  ��%d\n",zd.person.carry);
	printf("\t\t\t����  ��%d\n",zd.person.defend);
	printf("\t\t\t���  ��%d\n",zd.person.fortune);
	printf("\n\t\t\t�����������\n");
	getch();
	return zd;
} 
		//����ͼ��
struct contain monsterBP(struct contain zd,int a[20][20]){
	system("cls");
	printf("\n\t\t\t\t    <����ͼ��>\n\n");
	printf("\t��:%-10s   Ѫ����%4d  ������%-4d   ������%-4d   ��Ѫ��%s\n\n",zd.ms.m1_name,zd.ms.m1_hp,zd.ms.m1_carry,zd.ms.m1_defend,zd.ms.m1_lose); 
	printf("\t��:%-10s   Ѫ����%4d  ������%-4d   ������%-4d   ��Ѫ��%s\n\n",zd.ms.m2_name,zd.ms.m2_hp,zd.ms.m2_carry,zd.ms.m2_defend,zd.ms.m2_lose); 
	printf("\t��:%-10s   Ѫ����%4d  ������%-4d   ������%-4d   ��Ѫ��%s\n\n",zd.ms.m3_name,zd.ms.m3_hp,zd.ms.m3_carry,zd.ms.m3_defend,zd.ms.m3_lose); 
	printf("\t��:%-10s   Ѫ����%4d  ������%-4d   ������%-4d   ��Ѫ��%s\n\n",zd.ms.m4_name,zd.ms.m4_hp,zd.ms.m4_carry,zd.ms.m4_defend,zd.ms.m4_lose); 
	printf("\t��:%-10s   Ѫ����%4d  ������%-4d   ������%-4d   ��Ѫ��%s\n\n",zd.ms.m5_name,zd.ms.m5_hp,zd.ms.m5_carry,zd.ms.m5_defend,zd.ms.m5_lose); 
	getch();
	return zd;
} 
		//�̵� 
struct contain SHOP(struct contain zd){
	for(;;){
		system("cls");
		printf("\n\t\t\t\t  <ħ���̵�>\n\n");
		printf("\t\t\t�װ���%s����%d�������Թ���\n\n",zd.person.name,zd.person.money);
		printf("\t\t\t\tj ��2�㹥����\n\n"); 
		printf("\t\t\t\tk ��2�������\n\n");
		printf("\t\t\t\tl ���뿪\n\n"); 
		printf("\t\t\t����ǰ������Ϊ��%d\n\n\t\t\t��������ѡ�����Ŀ���ţ��� j ����\n\n",zd.person.fortune);
		char num1=getchar();
		char num=getchar();
		switch(num){
			case 'j':if(zd.person.fortune>=zd.person.money){		//�ӹ�����2�� 
				system("cls");
				zd.person.fortune=zd.person.fortune-zd.person.money;
				zd.person.carry=zd.person.carry+2;
				zd.person.money=zd.person.money*2;
				printf("\n\n\t\t\t���Ĺ�����������2��\n\n");
				printf("\t\t\t��ǰ������Ϊ��%d\n\n",zd.person.carry);
				printf("\t\t\t����ʣ�½�ң�%d\n\n",zd.person.fortune);
				printf("\t\t\t�����������\n");
				getch();
				return zd;
			}else {
				system("cls");
				printf("\n\n\t\t\t�ܱ�Ǹ����û���㹻�Ľ��\n\n");
				printf("\t\t\t�����������\n");
				getch();
				return zd;
			}break;
			case 'k':if(zd.person.fortune>=zd.person.money){		//�ӷ�����2�� 
				system("cls");
				zd.person.fortune=zd.person.fortune-zd.person.money;
				zd.person.defend=zd.person.defend+2;
				zd.person.money=zd.person.money*2;
				printf("\n\n\t\t\t���ķ�����������2��\n\n");
				printf("\t\t\t��ǰ������Ϊ��%d\n\n",zd.person.defend);
				printf("\t\t\t����ʣ�½�ң�%d\n\n",zd.person.fortune);
				printf("\t\t\t�����������\n");
				getch();
				return zd;
			}else {
				system("cls");
				printf("\n\n\t\t\t�ܱ�Ǹ����û���㹻�Ľ��\n\n");
				printf("\t\t\t�����������\n");
				getch();
				return zd;
			}break;
			case 'l': return zd;								//���� 
					break;
			default:system("cls");							//������� 
					printf("\n\n\t\t\t������󣡣���\n\n");
					printf("\t\t\t�����������\n");
					getch();
					return zd; 
		}	
	}
	return zd;
} 
int sceneFirst(void){
	getch();
	system("cls");
	printf("\t\t===============================\n");
	printf("\t\t\t·��Ұ��Ģ��һö\n");
	printf("\t\t===============================\n\n");getch();
	printf("\t\t����(��ɭ)��\n\t\t\t�ÿɰ�����\n");getch();
	printf("\t\tĢ������΢Ц����\n\t\t\t���һؼҰɣ��һ�����ȹ��ܶ�����ʱ��.\n");getch();
	printf("\t\t��������ü����\n\t\t\t�Բ���Ŷ�����Ѿ������Ҷȹ�����ʱ������ˣ���Ҫȥ����\n");getch();
	printf("\t\tĢ�������ѹ�����\n\t\t\t����ֻ�а���ɱ�˲ſ��Թ�ȥ\n");getch();
	printf("\t\t��������ǳǳЦ�⣬��������\n");getch();
	printf("\t\t������ϵ���������ǰ��\n");getch();
	system("cls");
	return 0;
} 
int sceneFirstII(void){
	getch();
	system("cls");
	printf("\t\t===============================\n");
	printf("\t\t\t·��Ұ��Ģ��һö\n");
	printf("\t\t===============================\n\n");getch();
	printf("\t\tĢ������ƽ������\n\t\t\t����ٸ���һ�λ��ᣬ���ѡ����\n");getch();
	printf("\t\t��������Į����\n\t\t\t����\n");getch();
	printf("\t\tĢ�������ѹ�����\n\t\t\tȥ����һ�����֮��ɣ����ȵ����ӡ�\n");getch();
	system("cls");
	return 0;
}
int sceneSecond(void){
	getch();
	system("cls");
	printf("\t\t===============================\n");
	printf("\t\t\t�������ɶ������\n");
	printf("\t\t===============================\n\n");getch();
	printf("\t\t���ţ�Цӯӯ����\n\t\t\t����Ĺ���Ӵ������һ���������ȹ����������\n");getch();
	printf("\t\t�㽫��Ϊ������Ŀ���ˣ�������\n");
	printf("\t\t��������������\n\t\t\t����������ʲô��\n");getch();
	printf("\t\t���ţ�Цӯӯ����\n\t\t\t��ֻ��Ҫԭ·���أ����ӵ����幩������\n");getch();
	printf("\t\t��������ŭ����\n\t\t\t��а�����ţ���Ҫɱ����\n");getch();
	printf("\t\t���ţ����յ�Ц����\n\t\t\t�Ǿ�û�취�ˣ����ְɣ�\n");getch();
	printf("\t\t������Ц����һ��չʾ��ɱ��������\n");getch();
	system("cls");
	return 0; 
}
int sceneThird(void){
	getch();
	system("cls");
	printf("\t\t===============================\n");
	printf("\t\t\t �����������ʦ\n");
	printf("\t\t===============================\n\n");getch();
	printf("\t\tĳĳ����Į����\n\t\t\t���ߵ�������������Ѿ��������\n");getch();
	printf("\t\tҪͨ��ȥ�ű���·������...����������Ⱥ������\n");
	printf("\t\t�����ν���\n\t\t\t����\n");getch();
	printf("\t\t�����������Ÿ�������ζ��\n");getch();
	printf("\t\t�����ٽ���ֱ����ĳĳ����\n");getch();
	printf("\t\t20cm,ĳĳû�ж���\n");getch();
	printf("\t\t10cm,ĳĳû�ж���\n");getch();
	printf("\t\t��Ѫ�����ĳĳ��ɫ���·�\n");getch();
	printf("\t\tĳĳ��\n\t\t\t���ȥ��\n");getch();
	printf("\t\t�����ס���룬�������������Ѫ�Ľ�\n");getch();
	printf("\t\t����ǰ��,��һ�仰����ͣס�Ų�\n");getch();
	printf("\t\tĳĳ��\n\t\t\t�Һ��������ƵĹ���\n");getch();
	system("cls");
	return 0;
}
int gameBegin(void){
	system("cls"); 
	system("color 07");
	char test[1000]="\n\n\n\t\t\t�� �� Ϊ �� �� �� �� Ϸ �� �� �� �� �� ���� ֻ �� �� �� �� �ܣ� \n\t\t\t �� Ϸ �� �� �� �� ʼ\n";
	char *p ;
	p = strtok(test," ");
	while(p){
		printf("%s",p);
		p = strtok(NULL," ");
		Sleep(100);
	}
	printf("\n\t\t\t�����������...\n");
	getch();
	system("cls");
}
		//��ʽ����Ϸ
int theme(){
	int j=1;
	switch(j){
		case 1:one();printf("\t\t��======����������======��\n");two();
		case 2:one();printf("\t\t��======��������  ======��\n");two();
		case 3:one();printf("\t\t��======������    ======��\n");two();
		case 4:one();printf("\t\t��======����      ======��\n");two();
		case 5:one();printf("\t\t��======��        ======��\n");two();
		case 6:one();printf("\t\t��======          ======��\n");two();
		case 7:one();printf("\t\t��======��        ======��\n");two();
		case 8:one();printf("\t\t��======����      ======��\n");two();
		case 9:one();printf("\t\t��======���Ӿ�    ======��\n");two();
		case 10:one();printf("\t\t��======���Ӿȹ�  ======��\n");two();
		case 11:one();printf("\t\t��======���Ӿȹ���======��\n");two();
	}
	printf("\n\n\t\t��������������������������\n");
	printf("\t\t��======================��\n");
	printf("\t\t��====== ������; ======��\n");
	printf("\t\t��======================��\n");
	printf("\t\t��������������������������\n");
	printf("\n\n\t\t\t�����������...\n");
	getch();
} 
int one(){
	printf("\n\n\t\t��������������������������\n");
	printf("\t\t��======================��\n");
}
int two(){
	printf("\t\t��======================��\n");
	printf("\t\t��������������������������\n");
	Sleep(150);
	system("cls");	
}
		//���ע��
struct contain login(struct contain zd){
	int i=0;
	for(i=0;i<3;i++){
		printf("\n\n\n\t\t\t�������ӣ���������Ľ�ɫ����\n");
		Sleep(5);
		system("color f2"); 
		system("cls");
		printf("\n\n\n\t\t\t �������ӣ���������Ľ�ɫ����\n");
		Sleep(5);
		system("color f4");
		system("cls");
	} 
	system("color f0");
	printf("\n\n\n\t\t\t�������ӣ���������Ľ�ɫ����\n\t\t\t\t");
	scanf("%s",&zd.person.name);
	system("cls");
	printf("\n\n\t\t\t    ��������\n");
	printf("\t\t\t�ǳ�  ��%s\n",zd.person.name);
	printf("\t\t\t����ֵ��%d\n",zd.person.hp);
	printf("\t\t\t����  ��%d\n",zd.person.carry);
	printf("\t\t\t����  ��%d\n",zd.person.defend);
	printf("\t\t\t���  ��%d\n",zd.person.fortune);
	printf("\n\t\t��Ϸ�����пɰ���c�����鿴��������\n");
	getch();
	zd.person.is_over=0;
	zd.person.actor=1;
	zd.person.floor=1;
	return zd;
} 
		//�򲻹�
int faild(struct contain zd){
	system("cls");
	printf("\n\n\t\t�װ���%s���㻹�򲻹�����\n",zd.person.name);
	printf("\n\t\t�����������\n");
	getch();
	return 0;
} 
		//��Сʷ��ķ�ִ� 
struct contain fightM1(struct contain zd){
	zd.person.hp=zd.person.hp-zd.ms.m1Lose; 
	zd.person.fortune=zd.person.fortune+10;
	system("cls");
	printf("\n\n\t\t����ʧ��%d��Ѫ�������%s\n",zd.ms.m1Lose,zd.ms.m1_name);
	printf("\t\t��ý�ң�10\n"); 
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//�ʹ�ʷ��ķ�ִ� 
struct contain fightM2(struct contain zd){
	zd.person.hp=zd.person.hp-zd.ms.m2Lose; 
	zd.person.fortune=zd.person.fortune+20;
	system("cls");
	printf("\n\n\t\t����ʧ��%d��Ѫ�������%s\n",zd.ms.m2Lose,zd.ms.m2_name);
	printf("\t\t��ý�ң�20\n"); 
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//��а����ʦ�� 
struct contain fightM3(struct contain zd){
	zd.person.hp=zd.person.hp-zd.ms.m3Lose; 
	zd.person.fortune=zd.person.fortune+50;
	system("cls");
	printf("\n\n\t\t����ʧ��%d��Ѫ�������%s\n",zd.ms.m3Lose,zd.ms.m3_name);
	printf("\t\t��ý�ң�50\n"); 
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//��˫����ʿ�� 
struct contain fightM4(struct contain zd){
	zd.person.hp=zd.person.hp-zd.ms.m4Lose; 
	zd.person.fortune=zd.person.fortune+100;
	system("cls");
	printf("\n\n\t\t����ʧ��%d��Ѫ�������%s\n",zd.ms.m4Lose,zd.ms.m4_name);
	printf("\t\t��ý�ң�100\n"); 
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//�ʹ�ʦ�� 
struct contain fightM5(struct contain zd){
	zd.person.hp=zd.person.hp-zd.ms.m5Lose; 
	zd.person.fortune=zd.person.fortune+1000;
	system("cls");
	printf("\n\n\t\t����ʧ��%d��Ѫ�������%s\n",zd.ms.m5Lose,zd.ms.m5_name);
	printf("\t\t��ý�ң�1000\n"); 
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//�ӹ�����2��
struct contain addCarry(struct contain zd){
	zd.person.carry=zd.person.carry+2; 
	system("cls");
	printf("\n\n\t\t���Ĺ�����������2��\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}	 
		//�ӷ�����2��
struct contain addDefend(struct contain zd){
	zd.person.defend=zd.person.defend+2; 
	system("cls");
	printf("\n\n\t\t���ķ�����������2��\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//�ӹ�����10��
struct contain addCarry10(struct contain zd){
	zd.person.carry=zd.person.carry+10; 
	system("cls");
	printf("\n\n\t\t���Ĺ�����������10��\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}	 
		//�ӷ�����10��
struct contain addDefend10(struct contain zd){
	zd.person.defend=zd.person.defend+10; 
	system("cls");
	printf("\n\n\t\t���ķ�����������10��\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//��Ѫ 
struct contain addHp(struct contain zd){
	zd.person.hp=zd.person.hp+200;
	system("cls");
	printf("\n\n\t\t����Ѫ��������200��\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//�̵�
struct contain openshop(struct contain zd){
	zd.person.shop=1;
	system("cls");
	printf("\n\n\t\t���Ѿ������̵�\n\n");
	printf("\t\t����Ϸ�����а�'p'������ʱ������Ʒ\n");
	printf("\n\t\t�����������\n");
	getch();
	return zd;
}
		//ȫ����
int gameover(){
	system("cls");
	printf("\n\n\t\t���ӣ�����һ��ȥ��������עΪ�����ŵİ��顣������������Զ����Ҫ�ֿ��˺���\n");
	printf("\n\t\t�����������\n");
	getch();
	system("cls");
	printf("\n\n\t\tлл��������\n");
	getch(); 
}	 
