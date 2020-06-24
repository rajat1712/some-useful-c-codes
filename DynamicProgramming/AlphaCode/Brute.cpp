#include<iostream>
using namespace std;
int alphaCode(int *arr,int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 1;
	}
	int output=alphaCode(arr,n-1);
	if(arr[n-2]*10 + arr[n-1] <=26){
		output+=alphaCode(arr,n-2);
	}
	return output;
	
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=alphaCode(arr,n);
	cout<<ans<<endl;
}
