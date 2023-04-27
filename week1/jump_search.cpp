#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
void printarray(int *arr, int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int jumpSearch(int *arr,int n,int key){
        for(int i=0;i<n;i++){
        int x= pow(2,i); 
        int y= pow(2,i+1); 
        if(arr[x]==key ){
            return x;
        }
        if(arr[y]==key) return y;
        else if(arr[x]<key&& arr[y]>key){
            for (int j=x;j<y;j++){
                if(arr[j]==key) 
                return j;
            }
        }
    }
    return -1;
}
int main(){
    int n=0;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printarray(arr,n);
    int key;
    cout<<"enter key: ";
    cin>>key;
    int s= jumpSearch(arr,n,key);
    if(s){
        cout<<"found "<<key<<" at index "<<s<<endl;
    }
    else cout<<"not found "<<key<<endl;
    return 0;
}