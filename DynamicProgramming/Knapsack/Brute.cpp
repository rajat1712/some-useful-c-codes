#include<iostream>
#include<climits>
using namespace std;
int knapsack(int *weights,int n,int *values,int maxWeight){
	if(n==0 || maxWeight==0){
		return 0;
	}
	
	if(weights[0] > maxWeight){
		return knapsack(weights+1,n-1,values+1,maxWeight);
	}
	
	int x=knapsack(weights+1,n-1,values+1,maxWeight-weights[0])+values[0];
	int y=knapsack(weights+1,n-1,values+1,maxWeight);
	return max(x,y);
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
		cin>>values[n];
	}
	int maxWeight;
	cin>>maxWeight;
	int ans=knapsack(weights,n,values,maxWeight);
	cout<<ans<<endl;
}
