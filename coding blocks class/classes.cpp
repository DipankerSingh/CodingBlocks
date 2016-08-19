//classes
#include<iostream>
#include<cstring>
using namespace std;

class teacher
{
    char *name;
    int salary;

    public:
    teacher(){

    }

    teacher(int income,char *n)
    {
        salary=income;
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }

    int getsalary(){
    return salary;

    }

    char *getName(){
       return name;
    }


};

int main()
{
    teacher *t1=new teacher(1000,"dipanker");
    teacher t(1000,"dipanker");
    cout<<t.getsalary();
    cout<<t.getName();
    cout<<(*t1).getsalary();
    delete t1;
}
