#include<iostream>
#include<climits>
using namespace std;
int minCount(int n){
	int *output=new int[n+1];
	for(int i=0;i<n+1;i++){
		output[i]=-1;
	}
	if(n==0){
		return 0;
	}
	
	if(n==1 || n==2 || n==3){
		return n;
	}
	
	if(output[n]!=-1){
		return output[n];
	}
	
	int smallAns=n;
    for(int i=1;i<=n;i++){
    	int temp=i*i;
    	
    	if(temp > n){
    		break;
		}
    	
    	smallAns=min(smallAns,minCount(n-temp)+1);
	}
	output[n]=smallAns;
	return smallAns;
}
int main()
{
	int n;
	cin>>n;
	int ans=minCount(n);
	cout<<ans<<endl;
}
