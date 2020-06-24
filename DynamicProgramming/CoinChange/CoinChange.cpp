#include<iostream>
using namespace std;
int helper(int *denominations,int size,int value,int **output){
	if(value==0){
		return 1;
	}
	if(value <0){
		return 0;
	}
	
	if(value>0 && size==0){
		return 0;
	}
	
	if(output[size][value]!=-1){
		return output[size][value];
	}
	
	int smallAns=helper(denominations+1,size-1,value,output)+helper(denominations,size,value-denominations[0],output);
	output[size][value]=smallAns;
	
	return smallAns;
}
int coinChange(int numdenominations,int *denominations,int value){
	int size=numdenominations;
	int **output=new int*[size+1];
	for(int i=0;i<size+1;i++){
		output[i]=new int[value+1];
	  for(int j=0;j<value+1;j++){
	  	output[i][j]=-1;
	  }
	}
	return helper(denominations,size,value,output);
}
int main(){
	int numdenominations;
	cin>>numdenominations;
	int *denominations=new int[numdenominations];
	for(int i=0;i<numdenominations;i++){
		cin>>denominations[i];
	}
	
	int value;
	cin>>value;
	int ans=coinChange(numdenominations,denominations,value);
	cout<<ans<<endl;
}
