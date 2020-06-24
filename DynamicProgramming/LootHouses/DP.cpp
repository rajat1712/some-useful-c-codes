#include<iostream>
using namespace std;
int lootHouses(int *arr,int n){
	int *output=new int[n];
	int max=INT_MIN;
	output[0]=arr[0];
	output[1]=arr[1];
	for(int i=2;i<=n;i++){
	  for(int j=i-2;j>=0;j--){
	  	int element=output[j];
	  	 if(element > max){
	  	 	max=element;
		   }
	  }
	  output[i]=arr[i]+max;
	} 
	
  int largest=0;
  for(int i=0;i<n;i++){
  	if(output[i] > largest){
  		largest=output[i];
	  }
  }
  return largest;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=lootHouses(arr,n);
	cout<<ans<<endl;
}
