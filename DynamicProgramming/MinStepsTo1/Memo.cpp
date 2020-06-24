#include<iostream>
#include<climits>
using namespace std;
int helper(int *ans,int n){
	if(n<=1){
		return 0;
	}
	
	if(ans[n]!=-1){
		return ans[n];
	}
	
	int x=helper(ans,n-1);
	int y=INT_MAX;
	int z=INT_MAX;
	if(n%2==0){
		y=helper(ans,n/2);
	}
	if(n%3==0){
		z=helper(ans,n/3);
	}
	
	ans[n]=min(x,min(y,z))+1;
	return ans[n];
}

int minSteps1(int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
	
	return helper(ans,n);
}
int main()
{
	int n;
	cin>>n;
	int ans=minSteps1(n);
	cout<<ans<<endl;
}
