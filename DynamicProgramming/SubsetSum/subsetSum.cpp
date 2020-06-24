#include<iostream>
using namespace std;
int helper(int *arr,int n,int **output,int sum){
	for(int i=0;i<n+1;i++){
		output[i][0]=1;
	}
	
	for(int i=1;i<sum+1;i++){
		output[0][i]=0;
	}
	
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[n-1] > sum){
				output[i][j]=output[i-1][j];
			}
			else{
				int x=output[i-1][j-arr[i-1]];
				int y=output[i-1][j];
			    output[i][j]= x||y;
			}
		}
	}
	return output[n][sum];
}
bool subsetSum(int *arr,int n,int sum){
	int **output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[sum+1];
		for(int j=0;j<sum+1;j++){
			output[i][j]=-1;
		}
	}
	
	int ans=helper(arr,n,output,sum);
	if(ans==0){
		return false;
	}
	else{
		return true;
	}
}
int main(){
      int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
	  int sum;
	  cin>>sum;
      bool ans=subsetSum(arr,n,sum);
      cout<<ans<<endl;
}
