#include <iostream>
using namespace std;
int count(char * arr,int n){
    int f[26]={0};
    int max=0;
    for(int i=0;i<n;i++){
        int x= (int)arr[i]-97;
        f[x]+=1;
    }
    for(int i=0;i<26;i++){
        if(f[i]>max) max=f[i];
    }
    return max;
}
int main(){
int n;
cout<<"enter n:";
cin>>n;
char arr[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
}
for(int i=0;i<n;i++){
    cout<<arr[i];
}
cout<<endl;
int c= count(arr,n);
cout<<"most occuerence is "<<c<<endl;
return 0;
}