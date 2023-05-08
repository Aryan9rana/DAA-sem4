#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;
const int MAX = 26;
char RandomLetter()
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
  
    char res;
    res =alphabet[rand() % MAX];
      
    return res;
}
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
for(int i=0;i<n;i++){
    char ch=RandomLetter();
arr[i]=tolower(ch);
}
cout<<"enter array elements are:"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i];
}
cout<<endl;
clock_t start=clock();
int c= count(arr,n);
clock_t end= clock();
double total=(double)(end - start)/CLOCKS_PER_SEC;
cout<<"most occuerence is "<<c<<endl;
cout<<"total time taken "<<total*1000<<" micro seconds"<<endl;
return 0;
}