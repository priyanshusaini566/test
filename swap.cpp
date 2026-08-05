#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cout<<"enter the value of a: ";
    cin>>a;

    cout<<"enter the value of b: ";
    cin>>b;

    int temp;
    temp=a;
    a=b;
    b=temp;

    cout<<a<<endl<<b;

    cout<<sizeof(a);

}