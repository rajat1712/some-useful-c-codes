#include<bits/stdc++.h>
using namespace std;
int kadaneAlgo(int *arr,int n){
	int max_so_far=arr[0];
	int max_ending_here=0;
	int start,end,s;
	
	for(int i=0;i<n;i++){
		max_ending_here=max_ending_here+arr[i];
	  if(max_so_far < max_ending_here){
	  	max_so_far=max_ending_here;
	  }
	  if(max_ending_here<0){
	  	max_ending_here=0;
	  }
	}
	return max_so_far;
	
}
int maxSumRectangle(int m,int n,int **input){
	
	int maxSum=INT_MIN;
	int maxLeft;
	int maxRight;
	int maxUp;
	int maxDown;
	int newArray[m];
	int sum=0;
	int start;
	int end;
	
	for(int left=0;left<n;left++){
		for(int right=left;right<n;right++){
			
			for(int i=0;i<m;i++){
				newArray[i]=newArray[i]+input[i][right];
			}
		  sum=kadaneAlgo(newArray,n);
		  
		 if(sum > maxSum){
		 	maxSum=sum;
		 }
		}
	}
	
	return maxSum;
}
int main(){
	int m;
	cin>>m;
	int n;
	cin>>n;
	int **input=new int*[m];
	for(int i=0;i<m;i++){
	   input[i]=new int[n];
	   for(int j=0;j<n;j++){
	   	cin>>input[i][j];
	 }
	}
	
	int ans=maxSumRectangle(m,n,input);
	cout<<ans<<endl;
}
