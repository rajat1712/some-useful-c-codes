#include<iostream>
#include<climits>
using namespace std;
int helper(int *ans,int n){
	ans[0]=0;
	ans[1]=1;
	ans[2]=2;
	ans[3]=3;
	for(int i=4;i<n+1;i++){
		int smallAns=i;
		for(int j=1;j<=i/2;j++){
			int k=i-(j*j);
			if(k>=0){
				smallAns=min(smallAns,ans[k]+1);
			}
		}
		ans[i]=smallAns;
	}
	return ans[n];
}
int minCount(int n){
	int *ans=new int[n+1];
	for(int i=0;i<n+1;i++){
		ans[i]=-1;
	}
  return helper(ans,n);
}
int main(){
	int n;
	cin>>n;
	int ans=minCount(n);
	cout<<ans<<endl;
}
