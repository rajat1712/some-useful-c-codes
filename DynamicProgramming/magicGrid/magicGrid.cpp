#include<bits/stdc++.h>
#include<climits>
using namespace std;
int magicGrid(int **input,int m,int n){
	int output[m][n];
	if(input[m-1][n-1]=0){
		output[m-1][n-1]=1;
	}
	else{
		output[m-1][n-1]=abs(input[m-1][n-1])+1;
	}
	
    for(int i=m-2;i>=0;i--){
    	output[i][n-1]=max(output[i+1][n-1]-input[i][n-1],1);
	}
	for(int i=m-2;i>=0;i--){
		output[m-1][i]=max(output[m-1][i+1]-input[m-1][i],1);
	}
	
	
	for(int i=m-2;i>=0;i
	--){
		for(int j=n-2;j>=0;j--){
			int smallAns=min(output[i+1][j],output[i][j+1]);
			output[i][j]=max(smallAns-input[i][j],1);
		}
	}
	return output[0][0];
}
int main(){
	int m;
	int n;
	cin>>m;
	cin>>n;
	int **input=new int*[m];
	for(int i=0;i<m;i++){
		input[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>input[i][j];
		}
	}
	
  int ans=magicGrid(input,m,n);
  cout<<ans<<endl;
}
