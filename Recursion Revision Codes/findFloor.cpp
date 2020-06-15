#include<iostream>
using namespace std;
int findFloor(int *arr,int n,int x)
{
    if(n==0)
    {
      return -1;
	}
	
	
	int smallAns=findFloor(arr+1,n-1,x);
	
	if(arr[0] < x && arr[0] > smallAns)
	{
		return arr[0];
	}
	else{
		return smallAns;
	}
	
	
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cin>>x;
	int ans=findFloor(arr,n,x);
	cout<<ans<<endl;
}
