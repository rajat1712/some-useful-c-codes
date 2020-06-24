#include<iostream>
using namespace std;
int helper(string s,string t,int **output){
	int m=s.length();
	int n=t.length();
	
	for(int i=0;i<=n;i++){
		output[0][i]=0;
	}
	
	for(int i=0;i<=m;i++){
		output[i][0]=0;
	}
	
	for(int i=1;i<=m;i++){
	  for(int j=1;j<=n;j++){
	  	if(s[m-i]==t[n-j]){
	  		output[i][j]=output[i-1][j-1]+1;
		  }
		else{
			int a=output[i-1][j];
			int b=output[i][j-1];
			int c=output[i-1][j-1];
			output[i][j]=max(a,max(b,c));
		}
	  }
	}
	return output[m][n];
}
int lcs(string s,string t){
	int m=s.length();
	int n=t.length();
	int **output=new int*[m+1];
	for(int i=0;i<m;i++){
		output[i]=new int[n+1];
	 for(int j=0;j<n;j++){
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
	int length=lcs(s,t);
	cout<<length<<endl;
}
