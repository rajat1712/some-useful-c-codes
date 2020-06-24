#include<iostream>
using namespace std;
int findMaxSquareWithAllZeros(int *input,int n){
	int output[n][n];
	
	for(int i=0;i<n;i++){
		if(input[0][i]==1){
			output[0][i]=0;
		}
		else{
			output[0][i]=1;
		}
	}
	
	for(int i=0;i<n;i++){
		if(input[i][0]==1){
			output[i][0]=0;
		}
		else{
			output[i][0]=1;
		}
	}
	
	
	int max=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(input[i][j]==1){
				output[i][j]=0;
			}
			else{
				output[i][j]=min(output[i][j-1],min(output[i-1][j-1],output[i-1][j]))+1;
				if(output[i][j] > max){
					max=output[i][j];
				}
			}
		}
	}
	return max;
}
int main(){
	int **input=new int*[n];
	for(int i=0;i<n;i++){
		input[i]=new int[n];
	  for(int j=0;j<n;j++){
	  	cin>>input[i][j];
	  }
	}
	
	int ans=findMaxSquareWithAllZeros(input,n);
	cout<<ans<<endl;
}
