#include<iostream>
using namespace std;
int getMin(int *arr,int n){
	int *arr1=new int[n];
	arr1[0]=1;
	for(int i=1;i<n;i++){
		if(arr[i] > arr[i-1]){
			arr1[i]=1+arr1[i-1];    //filling from left
		}
		else{
			arr1[i]=1;
		}
	}
	
	int *arr2=new int[n];
	arr2[n-1]=arr1[n-1];
	for(int i=n-2;i>=0;i--){
		if(arr[i] > arr[i+1]){
			if(arr1[i] <= arr1[i+1]){
				arr1[i] = arr1[i+1] +1;     //filling from right
			}
			
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr1[i];                 //returning sum of second array
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=getMin(arr,n);
	cout<<ans<<endl;
}
//6 4 6 4 5 6 2
//10 2 4 2 6 1 7 8 9 2 1
