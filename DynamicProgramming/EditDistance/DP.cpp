#include<iostream>
using namespace std;
int helper(string s,string t,int  **output){
	int m=s.size();
	int n=t.size();
	
	for(int i=0;i<=n;i++){
		output[0][i]=i;
	}
	
	for(int i=0;i<=m;i++){
		output[i][0]=i;
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[m-i]==t[n-j]){
				output[i][j]=output[i-1][j-1];
			}
			else{
				output[i][j]=min(output[i][j-1],min(output[i-1][j],output[i-1][j-1]))+1;
			}
		}
	}
	return output[m][n];
}
int editDistance(string s,string t){
	int m=s.size();
	int n=t.size();
	
	int **output=new int*[m+1];
	for(int i=0;i<m+1;i++){
		output[i]=new int[n+1];
      for(int j=0;j<n+1;j++){
      	output[i][j]=-1;
	  }
	}
	
	return helper(s,t,output);
}
int main(){
	string s;
	cin>>s;
	string t;
	cin>>t;
	int ans=editDistance(s,t);
	cout<<ans<<endl;
}
