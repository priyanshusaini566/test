#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int Principle = 1000;
    int Rate = 5;
    int Time = 2;

    double amount= Principle*pow((1+Rate/100.0),Time);
    double  ci=amount-Principle;


    cout<<"the compound interest will be : "<<ci;
}