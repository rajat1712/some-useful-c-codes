#include<iostream>
using namespace std;
int helper(int *ans,int n){
	if(n==0 || n==1 || n==2 || n==3){
		return n;
	}
	
	if(ans[n]!=-1){
		return ans[n];
	}
	
	int smallAns=n;
	for(int i=1;i<=n;i++){
		int temp=i*i;
		if(temp>n){
			break;
	   }
	 smallAns=min(smallAns,helper(ans,n-temp)+1);
	}
	ans[n]=smallAns;
	return ans[n];
}
int minCount(int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
	return helper(ans,n);
}
int main(){
	int n;
	cin>>n;
	int ans=minCount(n);
	cout<<ans<<endl;
}
