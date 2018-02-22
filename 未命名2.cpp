#include<iostream>
using namespace std;
class cs{
    int x;
    public:
    cs(){
        cout<<"1 called"<<endl;
    }
    cs(int n){
        x=n;
        cout<<"2 called"<<endl;
    }
};
int main()
{
    cs array1[2];
    cout<<"step1"<<endl;
    cs array2[2]={4,5};
    cout<<"step2"<<endl;
    cs array3[2]={3};
    cs *array4=new cs[2];
    delete []array4;
    return 0;
}
