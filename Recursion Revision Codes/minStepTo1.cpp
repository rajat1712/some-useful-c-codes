#include<iostream>
#include<climits>
using namespace std;
int countStepsTo1(int n)
{
	if(n<=1)
	{
		return 0;
	}
	
	int x=countStepsTo1(n-1);
	int y=INT_MAX;
	int z=INT_MAX;
	if(n%2==0)
	{
		y=countStepsTo1(n/2);
	}
	
	if(n%3==0)
	{
		z=countStepsTo1(n/3);
	}
	
	int ans=min(x,min(y,z));
	return ans+1;
}
int main()
{
	int n;
	cin>>n;
	int ans=countStepsTo1(n);
	cout<<ans<<endl;
}
