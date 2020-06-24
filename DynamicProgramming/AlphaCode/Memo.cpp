#include<iostream>
using namespace std;
int helper(int *ans,int n,int *arr){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 1;
	}
	
	if(ans[n]!=-1){
		return ans[n];
	}
	
	
	int output=helper(ans,n-1,arr);
	if(arr[n-2]*10 + arr[n-1] <=26){
		output+=helper(ans,n-2,arr);
	}
	ans[n]=output;
	return ans[n];
}
int alphaCode(int *arr,int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
	
	return helper(ans,n,arr);
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=alphaCode(arr,n);
	cout<<ans<<endl;
}
