#include<iostream>
using namespace std;
int helper(int *arr,int n,int *ans){
	ans[0]=1;
    ans[1]=1;
	for(int i=2;i<n+1;i++){
		ans[i]=ans[i-1];
		if(arr[i-2]*10+arr[i-1]<=26){
			ans[i]=ans[i]+ans[i-2];
		}
	}
	return ans[n];
}
int alphaCode(int *arr,int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
	return helper(arr,n,ans);
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
