#include<iostream>
using namespace std;
int helper(int *weights,int n,int *values,int maxWeight,int **output){
	for(int i=0;i<n+1;i++){
		output[0][i]=0;
	}
	
	for(int i=0;i<maxWeight+1;i++){
		output[i][0]=0;
	}
	
	for(int i=1;i<=maxWeight;i++){
		for(int j=1;j<=n;j++){
			if(weights[0] > i){
				output[i][j]=output[i][j-1];     //helper(weights+1,n-1,values+1,maxWeight,output);----Recursive Function
			}
			else{
				int x=output[i-weights[0]][j-1]+values[0];         //helper(weights+1,n-1,values+1,maxWeight-weights[0],output)+values[0];---Rescursive Function
				int y=output[i][j-1];    //helper(weights+1,n-1,values+1,maxWeight,output);-----Recursive Function
				output[i][j]=max(x,y);
			}
		}
	}
	return output[maxWeight][n];
}
int knapsack(int *weights,int n,int *values,int maxWeight){
	int **output=new int*[maxWeight+1];
	for(int i=0;i<maxWeight+1;i++){
		output[i]=new int*[n+1];
	  for(int j=0;j<n+1;j++){
	  	output[i][j]=-1;
	  }
	  }
	}
	return helper(weights,n,values,maxWeight,output);
}
using namespace std;
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
