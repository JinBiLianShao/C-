#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main()
{
    char cmd[20]="shutdown -s -t ";
    char t[10]="0";
    system("title С�ιػ�����");  //����cmd���ڱ���
    system("mode con cols=48 lines=25");  //���ڿ�ȸ߶� 
    system("color f0");  //����д�� red ������ɫ��
    system("date /T");
    system("TIME /T");
 
    printf("----------- �ػ����� -----------\n");
	printf("�����ڶ��ٷ��Ӻ��Զ��رռ������\n");
    scanf("%s",t);
    system(strcat(cmd,t));
    system("pause"); 
    return 0;
} 

