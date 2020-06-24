#include<iostream>
using namespace std;
int helper(int *length,int *price,int n,int priceSize,int **output){
	if(n==0 || priceSize==0){
		return 0;
	}
    for(int i=0;i<priceSize+1;i++){
    	output[0][i]=0;
	}
	for(int i=0;i<n+1;i++){
		output[i][0]=0;
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<priceSize+1;j++){
			if(length[i-1] > j){
				output[i][j]=output[i-1][j];
			}
			else{
				int x=price[i-1]+output[i][j-length[i-1]];
				int y=output[i-1][j];
				output[i][j]=max(x,y);
			}
		}
	}
	return output[n][priceSize];
}
int cuttingRod(int *length,int *price,int n,int priceSize){
	int **output=new int*[n+1];
	for(int i=0;i<n+1;i++){
		output[i]=new int[priceSize+1];
	 for(int j=0;j<priceSize+1;j++){
	 	output[i][j]=-1;
	 }
	}
	
	int ans=helper(length,price,n,priceSize,output);
	cout<<ans<<endl;
}
int main(){
	int lengthSize;
	cin>>lengthSize;
	int priceSize;
	cin>>priceSize;
	int *length=new int[lengthSize]+1;
	for(int i=0;i<lengthSize;i++){
		cin>>length[i];
	}
	
	int *price=new int[priceSize];
	for(int i=0;i<priceSize;i++){
		cin>>price[i];
	}
	int n;
	cin>>n;
	
	int maxAns=cuttingRod(length,price,n,priceSize);
	cout<<maxAns<<endl;
}
