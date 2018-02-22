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
	for(int i=1;i<=backup1.on_num;i++)//遍历电梯内所有乘客 
	{
		if(person[inorder[i]].OE)//当前乘客还在电梯上 
		{
			ele.tofloor(ele.onelevator[i].to);//移动到当前乘客目的地
			ele.liftoff(&ele.onelevator[i]);//下客
			//printf("%d",ele.arrive_num);
			if(ele.arrive_num==LINE)outprint();//全部乘客到达  
			elevator backup2=ele;
			solve2(k+1);//去接下一个客 
			ele=backup2; //回溯 恢复上一步情况 
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
		ele.tofloor(person[inorder[k]].from);//前往接客
		ele.liftup(& person[inorder[k]]);//上电梯
		elevator backup2=ele;
		//分2种情况 
		solve2(k+1);//一是去下个地方接客
		ele=backup2;
		solve3(k);//二送送走电梯内一名乘客 
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
void solve1(int k)//回溯生成所有载客顺序 
{

    for(int i=1;i<=LINE;i++)
    {
        if(!usedorder[i])
        {
            inorder[k]=i;
            usedorder[i]=true;
            if(k==LINE)//完成生成载客顺序
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

