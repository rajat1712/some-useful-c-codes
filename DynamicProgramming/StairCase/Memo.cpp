#include<iostream>
using namespace std;
int helper(int *ans,int n){
	if(n==0 || n==1 || n==2){
		return n;
	}
	if(n==3){
		return 4;
	}
	
	if(ans[n]!=-1){
		return ans[n];
	}
	
	int x=helper(ans,n-1);
	int y=helper(ans,n-2);
	int z=helper(ans,n-3);
	
	ans[n]=x+y+z;
	return ans[n];
}
int staircase(int n)
{
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
