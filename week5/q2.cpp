#include <iostream>
#include<algorithm>
#include<time.h> 
using namespace std;
void fun()
{
 int n,k,i;
 cout<<"enter n:";
 cin>>n;
 int arr[n];
 for(i=0;i<n;i++)
 {
 arr[i]=rand()%100+1;
 }
for(i=0;i<n;i++)
 {
 cout<<arr[i]<<" ";
 } 
 cout<<endl;
//  cout<<"enter key: ";
//  cin>>k;
k=20;
 sort(arr,arr+n);
 bool b=false;
 int left=0,right=n-1;
 while(left<right)
 {
 int sum=arr[left]+arr[right];
 if(sum==k)
 {
 cout<<arr[left]<<" "<<arr[right]<<endl;
 return ;
 }
 else if(sum<k)
 left++;
 else
 right--;
 }
 if(b==false)
 cout<<"No such element exist"<<endl;
}
int main()
{
double ts = 0.0;
 clock_t tb = clock();
 fun();
 clock_t te = clock();
 ts = (double)(te - tb)/CLOCKS_PER_SEC;
 cout<<ts*1000<<" micro sec"<<endl;

}
