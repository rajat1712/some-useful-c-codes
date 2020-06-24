#include<iostream>
using namespace std;
int helper(int *weights,int n,int *values,int maxWeight,int **output){
	if(n==0 || maxWeight==0){
		return 0;
	}
	
	if(output[maxWeight][n]!=-1){
		return output[maxWeight][n];
	}
	
	if(weights[0] > maxWeight){
		return helper(weights+1,n-1,values+1,maxWeight,output);
	}
	else{
		int x=helper(weights+1,n-1,values+1,maxWeight-weights[0],output)+values[0];
	int y=helper(weights+1,n-1,values+1,maxWeight,output);
	int smallAns=max(x,y);
	}
	
	output[maxWeight][n]=smallAns;
	return smallAns;
}
int knapsack(int *weights,int n,int values,int maxWeight){
	int **output=new int*[maxWeight+1];
	for(int i=0;i<=maxWeight;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
		  output[i][j]=-1;
		}
	}
	
	return helper(weights,n,values,maxWeight,output);
}
int main(){
	int n;
	cin>>n;
	int *weights=new int[n];
	int *values=new int[n];
	for(int i=0;i<n;i++){
		cin>>weights[i];
	}
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	int maxWeight;
	cin>>maxWeight;
	int ans=knapsack(weights,n,values,maxWeight);
}
