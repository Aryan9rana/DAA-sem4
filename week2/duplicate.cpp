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
int first(int * a,int start, int end , int key, int n){
if (end >= start){
      int middle = start + (end - start )/2;
      if ((middle==0 || a[middle-1]<key) && a[middle] == key){
        return middle;
        }
         
      else if (a[middle] < key)
      return  first(a, middle+1, end, key,n);
         else
         return first(a, start, middle-1, key,n);
   }
   return -1;
}
int last(int * a,int start, int end , int key, int n){
if (end >= start){
      int middle = start + (end - start )/2;
      if ((middle==n-1||a[middle+1]>key) &&  a[middle] == key){
        return middle;
        }
         
      else if (a[middle] > key)
         return last(a, start, middle-1, key,n);
         else
      return  last(a, middle+1, end, key,n);
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
    int f =first(arr,0,n-1,key,n);
    int l =last(arr,0,n-1,key,n);

    cout<<"first "<<f<<" last " <<l<<endl;
    return 0;
}
