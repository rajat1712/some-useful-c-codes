//staircase
#include<iostream>
using namespace std;
int staircase(int n)
{
	if(n==1 || n==2)
	{
		return n;
	}
	
	if(n==3)
	{
		return 4;
	}
	
   	int smallAns1=staircase(n-1);
   	int smallAns2=staircase(n-2);
   	int smallAns3=staircase(n-3);
   	
   	
   	return smallAns1+smallAns2+smallAns3;
	
}
int main()
{
	int n;
	cin>>n;
	int ans=staircase(n);
	cout<<ans<<endl;
}
