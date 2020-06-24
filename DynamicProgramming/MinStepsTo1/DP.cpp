#include<iostream>
#include<climits>
using namespace std;
int helper(int *ans,int n){
	ans[0]=0;
	ans[1]=1;
	ans[2]=1;
	ans[3]=1;
	for(int i=4;i<n+1;i++){
		int x=i-1;
		int y;
		int z;
		int ans1=INT_MAX;
		int ans2=INT_MAX;
		if(i%2==0){
		 y=i/2;
		 ans1=ans[y];
		}
		
		if(i%3==0){
		 z=i/3;
		 ans2=ans[z];
		}
		
	 ans[i]=min(ans[x],min(ans1,ans2))+1;
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
