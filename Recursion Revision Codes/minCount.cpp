#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int minCount(int n)
{
	if(sqrt(n) - floor(sqrt(n))==0)
	{
		return 1;
	}
	if(n==1 || n==2 || n==3)
	{
		return n;
	}
	
	
	int temp=sqrt(n);
	int ans=n;
	for(int i=1;i<=temp;i++){
		int x=i*i;
		ans=min(ans,minCount(n-x)+1);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int ans=minCount(n);
	cout<<ans<<endl;
}
