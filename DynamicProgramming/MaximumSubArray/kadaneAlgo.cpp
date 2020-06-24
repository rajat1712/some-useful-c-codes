#include<iostream>
using namespace std;
int maxSum(int *arr,int n){
	int max_ending_here=0;
	int max_so_far=arr[0];
	
	for(int i=0;i<n;i++){
		max_ending_here=max_ending_here+arr[i];
		
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}
		
		if(max_ending_here<0){
			max_ending_here=0;
		}
	}
	
	return max_ending_here;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int ans=maxSum(arr,n);
	cout<<ans<<endl;
}
