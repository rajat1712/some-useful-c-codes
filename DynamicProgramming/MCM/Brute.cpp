#include<iostream>
using namespace std;
int helper(int *p,int n,int i,int j){
	if(i>=j){
		return 0;
	}
	int min=INT_MAX;
	for(int k=i;k<=j-1;k++){
		int smallAns=helper(p,n,i,k)+helper(p,n,k+1,j)+(p[i-1]*p[k]*p[j]);
		if(smallAns<min){
			min=smallAns;
		}
	}
	return min;
}
int mcm(int *p,int n){
	int i=1;
	int j=n-1;
	return helper(p,n,i,j);
}
int main(){
	int n;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<=n;i++){
		cin>>p[i];
	}
	int ans=mcm(p,n);
	cout<<ans<<endl;
}
