#include <iostream>
#include<cstdio>
#include<cstring> 
#include "elevator.h"
#define LINE 5
#define INPUTNAME "input.txt"
#define OUTPUTNAME "output.txt"
const bool fromfile=false;
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
void outprint()
{
	
}
void solve3(int k)
{
	elevator backup=ele; 
	for(int i=1;i<=ele.on_num;i++)//�������������г˿� 
	{
		if(person[inorder[i]].OE)//��ǰ�˿ͻ��ڵ����� 
		{
			ele.tofloor(ele.onelevator[i].to);//�ƶ�����ǰ�˿�Ŀ�ĵ�
			ele.liftoff(&ele.onelevator[i]);//�¿�
			//
			solve3(k);
			solve2(k+1); 
		}
	}
}
void solve2(int k)
{
	if(k>LINE)return ;
	if(ele.arrive_num==LINE)outprint();
	if(person[inorder[k]].OW)
	{
		elevator backup=ele;//
		ele.tofloor(person[inorder[k]].from);//ǰ���ӿ�
		ele.liftup(& person[inorder[k]]);//�ϵ���
		//��2����� 
		solve2(k+1);//һ��ȥ�¸��ط��ӿ�
		solve3(k);//�������ߵ�����һ���˿� 
		ele=backup; 
	}
	
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
                solve2(1);
            } 
            else solve1 (k+1);
            usedorder[i]=false;
        }
        
    }
}
int main(int argc, char** argv) {
	input();
	elevator ele;
	memset(usedorder,0,sizeof(usedorder));
	solve1(1);
	return 0;
}

