#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter the number : ";
    cin>>num;

    int n=num;
    int count=0;

    while(num>0){
        int rem=num%10;
        count=count*10+rem;
        num=num/10;
    }
    if(count==n){
        cout<<"the given number is palindrome";
    }
    else{
        cout<<"not a palindrome number";
    }



}