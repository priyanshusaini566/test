#include<iostream>
using namespace std;

void matrix(int m,int arr[][3]){
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    matrix(3,arr);
    return 0;
}