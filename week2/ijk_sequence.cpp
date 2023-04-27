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
    int sum;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        sum=arr[i]+arr[j];
        for(int k=j+1;k<n;k++){
            if(sum==arr[k]){
                cout<<"index are "<<arr[i]<<" "<<arr[j]<<" = "<<arr[k]<<endl;
            }
        }
        }
    }


    return 0;
}