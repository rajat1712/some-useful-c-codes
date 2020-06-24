#include<iostream>
#include<climits>
using namespace std;
int helper(int **input,int n,int m,int **output,int x,int y){
	if(x>=n || y>=m){
		return INT_MAX;
	}
	
	if(x==n-1 && y==m-1){
		return input[x][y];
	}
	
	if(output[x][y]!=-1){
		return output[x][y];
	}
	
	int path1=helper(input,n,m,output,x,y+1);
	int path2=helper(input,n,m,output,x+1,y);
	int path3=helper(input,n,m,output,x+1,y+1);
	
	int smallAns=min(path1,min(path2,path3));
	smallAns+=input[x][y];
	output[x][y]=smallAns;
	
	
	return smallAns;
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
