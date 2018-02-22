#include <iostream>
#include<cstdio>
#include<cstring> 
#include "elevator.h"
#define LINE 5
#define INPUTNAME "input.txt"
#define OUTPUTNAME "output.txt"
const bool fromfile=true;
passenger person[LINE];
void input()
{
	if(fromfile)
	{
		freopen(INPUTNAME,"r",stdin);
		freopen(OUTPUTNAME,"w",stdout);
	 } 
	int i,j;
	for(i=1;i<=LINE;i++)
	{
		int tmptime,tmpfrom,tmpto;
		scanf("%d%d%d",&tmptime,&tmpfrom,&tmpto);
		person[i].sett(tmptime,tmpfrom,tmpto);
	} 
}
bool usedorder[LINE*2];
int inorder[LINE*2];
elevator ele;
elevator reset;
void outprint()
{

}
void solve2(int k);
void solve3(int k)
{
	
	elevator backup1=ele; 
	for(int i=1;i<=backup1.on_num;i++)//�������������г˿� 
	{
		if(person[inorder[i]].OE)//��ǰ�˿ͻ��ڵ����� 
		{
			ele.tofloor(ele.onelevator[i].to);//�ƶ�����ǰ�˿�Ŀ�ĵ�
			ele.liftoff(&ele.onelevator[i]);//�¿�
			//printf("%d",ele.arrive_num);
			if(ele.arrive_num==LINE)outprint();//ȫ���˿͵���  
			elevator backup2=ele;
			solve2(k+1);//ȥ����һ���� 
			ele=backup2; //���� �ָ���һ����� 
		}
	}
}
void solve2(int k)
{
	//printf("%d",k);
	if(k>LINE)return ;
	//printf("%d",ele.arrive_num);
	if(ele.arrive_num==LINE)outprint();
	if(person[inorder[k]].OW)
	{
		elevator backup1=ele;//
		ele.tofloor(person[inorder[k]].from);//ǰ���ӿ�
		ele.liftup(& person[inorder[k]]);//�ϵ���
		elevator backup2=ele;
		//��2����� 
		solve2(k+1);//һ��ȥ�¸��ط��ӿ�
		ele=backup2;
		solve3(k);//�������ߵ�����һ���˿� 
		ele=backup1;  
	}
	
}
void printorder()
{
	for(int i=1;i<=LINE;i++)
	{
		printf("%d\t",inorder[i]);
	}
	printf("\n");
}
void solve1(int k)//�������������ؿ�˳�� 
{

    for(int i=1;i<=LINE;i++)
    {
        if(!usedorder[i])
        {
            inorder[k]=i;
            usedorder[i]=true;
            if(k==LINE)//��������ؿ�˳��
            {
            	ele=reset;
                solve2(1);
            } 
            else solve1 (k+1);
            usedorder[i]=false;
        }
        
    }
}
int main(int argc, char** argv) {
	input();
	memset(usedorder,0,sizeof(usedorder));
	solve1(1);
	return 0;
}

