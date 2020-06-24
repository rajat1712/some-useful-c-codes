#include<iostream>
#include<climits>
using namespace std;
int helper(int **input,int n,int m,int x,int y){
	
	if(x>=n || y>=m){
		return INT_MAX;
	}
	
	if(x==n-1 && y==m-1){
		return input[x][y];
	}
	
	int path1=helper(input,n,m,x+1,y);
	int path2=helper(input,n,m,x+1,y+1);
	int path3=helper(input,n,m,x,y+1);
	
	int smallAns=min(path1,min(path2,path3));
	return smallAns+input[x][y];
}
int minCost(int **input,int n,int m){
	return helper(input,n,m,0,0);
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
