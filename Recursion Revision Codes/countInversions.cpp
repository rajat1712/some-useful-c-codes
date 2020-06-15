#include<iostream>
using namespace std;
int solve(int *arr,int n)
{
	if(n==0 || n==1)
	{
		return 0;
	}
	int smallAns=solve(arr+1,n-1);
	
	int i=0;
	int first=0;
	for(int j=1;j<n;j++)
	{
		if(arr[i] > arr[j])
		{
			first++;
		}
	}
	
	return smallAns+first;
	
	
	
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
	int ans=solve(arr,n);
	cout<<ans<<endl;
}
