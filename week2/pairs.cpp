// Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.


#include <iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter key: ";
    cin>>key;
    int sum=0;
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[j]-arr[i])==key) count ++;
        }
    }

    cout<<"count = "<<count<<endl;
    return 0;
}