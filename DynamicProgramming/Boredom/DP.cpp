#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>A){
  
  int freq[1002];
  int dp[1002];
    
    for(int i=0;i<A.size();i++){
        freq[A[i]]++;
    }
    
    dp[0]=0;
    dp[1]=freq[1];
    
    for(int i=2;i<=1000;i++){
        dp[i]=max(dp[i-1],(i*freq[i])+dp[i-2]);
    }
    return dp[1000];
}
int main()
{
	int n;
   vector<int>A;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
