#include<iostream>
#include<climits>
using namespace std;
int minSteps1(int n){
	if(n<=1){
		return 0;
	}
	int x=minSteps1(n-1);
	int y=INT_MAX;
	int z=INT_MAX;
	if(n%2==0){
		y=minSteps1(n/2);
	}
	if(n%3==0){
		z=minSteps1(n/3);
	}
	
	return min(x,min(y,z))+1;
	
}
int main()
{
	int n;
	cin>>n;
	int ans=minSteps1(n);
	cout<<ans<<endl;
}
