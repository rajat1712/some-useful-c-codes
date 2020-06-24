#include<iostream>
using namespace std;
int helper(int n,int *output){
	if(n<=1){
		return n;
	}
	
	if(output[n]!=-1){
		return output[n];
	}
	
	int a=helper(n-1,output);
	int b=helper(n-2,output);
	output[n]=a+b;
	return output[n];
}
int fib(int n){
	int *output=new int[n+1];
	for(int i=0;i<n+1;i++){
		output[i]=-1;
	}
	
	return helper(n,output);
}
int main()
{
	int n;
	cin>>n;
	int ans=fib(n);
	cout<<ans<<endl;
}
