#include<iostream>
using namespace std;
int helper(int **input,int n,int m,int **output,int x,int y){
	output[n-1][m-1]=input[n-1][m-1];
	
	for(int i=n-2;i>=0;i--){
		output[i][m-1]=output[i+1][m-1]+input[i][m-1];
	}
	
	for(int i=m-2;i>=0;i--){
		output[n-1][i]=output[n-1][i+1]+input[n-1][i];
	}
	
	
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
		}
	} 
	
	return output[0][0];
	
}
int minCost(int **input,int n,int m){
	int **output=new int*[n];
	for(int i=0;i<n;i++){
		output[i]=new int[m];
	  for(int j=0;j<m;j++){
	  	output[i][j]=-1;
	  }
	}
	
  return helper(input,n,m,output,0,0);
}
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int **input=new int*[n];
	for(int i=0;i<n;i++){
		input[i]=new int[m];
	  for(int j=0;j<m;j++){
	  	cin>>input[i][j];
	  }
	}
  int ans=minCost(input,n,m);
  cout<<ans<<endl;
}



