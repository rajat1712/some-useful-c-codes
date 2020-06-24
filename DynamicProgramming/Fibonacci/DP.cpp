#include<iostream>
using namespace std;
int helper(int *ans,int n){
	ans[0]=0;
	ans[1]=1;
	for(int i=2;i<n+1;i++){
		ans[i]=ans[i-1]+ans[i-2];
	}
	return ans[n];
	
}
int fib(int n){
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
	int ans=fib(n);
	cout<<ans<<endl;
}
