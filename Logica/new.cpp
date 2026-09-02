#include<iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    cout<<x;
    for(int i=0;i<x;i++){
        cout<<i++<<"\n";
    }
    while(x<=x+10){
        cout<<"X="<<x<<"\n";x++;
    }

    return 0;
}