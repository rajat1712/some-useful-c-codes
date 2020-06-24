#include<iostream>
using namespace std;
int helper(int *ans,int n){
	ans[0]=0;
	ans[1]=1;
	ans[2]=2;
	ans[3]=4;
	for(int i=4;i<n+1;i++){
		ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
	}
	return ans[n];
}
int staircase(int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
	return helper(ans,n);
}
int main(){
	int n;
	cin>>n;
	int ans=staircase(n);
	cout<<ans<<endl;
}
