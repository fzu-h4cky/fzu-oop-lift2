#ifndef ELEVATOR_H
#define ELEVATOR_H
#define LINE 5
class passenger
{
	public:
		int time,from,to;
		bool OE;//on elevator
		bool OW;//on waiting
		bool ARR;//arrived
		
		void sett(int t,int f,int too)
		{
			time=t;f=from;to=too;
			OE=false;OW=true;ARR=false;
		}
};

class elevator
{
	public:
		int on_num,wait_num,arrive_num;
		int time,tottime;
		int floor; 
		passenger onelevator[LINE+5];
		void liftup(passenger *pp)//乘客上电梯
		{
			tottime+=(wait_num+on_num);//自增统计总共用时 
			wait_num--;
			on_num++;
			time++;//接客耗时 
			pp->OE = true;
			pp->OW = false;
			onelevator[on_num]=*pp;
		}
		void liftoff(passenger *pp)//送达乘客 
		{
			tottime+=(wait_num+on_num);//自增统计总共用时 
			on_num--;
			arrive_num++;
			time++;//卸客耗时
			pp->OE =false;
			pp->ARR =true;
			pp->OW=false;
		}
		void up()//电梯上行 
		{
			tottime+=(wait_num+on_num);//自增统计总共用时 
			time++;
			floor++;
		}
		void down()//电梯下行 
		{
			tottime+=(wait_num+on_num);//自增统计总共用时 
			time++;
			floor--;
		}
		void tofloor(int tto)//行至目标楼层 
		{
			while(tto>floor)up();
			while(tto<floor)down();
		}
		 elevator()
		 {
		 	on_num=0;time=0;floor=1;wait_num=LINE;arrive_num=0;tottime=0;
		 }
	
};
#endif
#ifndef ELEVATOR_H
#define ELEVATOR_H

class elev
{
	public:
	protected:
};

#endif
