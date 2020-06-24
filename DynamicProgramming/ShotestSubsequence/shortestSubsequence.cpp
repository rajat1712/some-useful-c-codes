#include<iostream>
using namespace std;
int helper(string s,string t,int m,int n,int **output){	
   int smallAns;
	if(m==0){
		return 1001;
	}
	
	if(n==0){
		return 1;
	}
	int x=0;
	int i;
	for(i=0;i<n;i++){
		if(t[i]==s[0]){
			x=1;
			break;
		}
	}
	
	if(x==0){
		return 1;
	}
	
	if(output[m][n]!=-1){
		return output[m][n];
	}
	else{
	int ans1=helper(s.substr(1),t,m-1,n,output);
    int ans2=helper(s.substr(1),t.substr(i+1),m-1,n-i-1,output)+1;
    smallAns=min(ans1,ans2);
	}
	
    output[m][n]=smallAns;
    return smallAns;
    
}
int solve(string s,string t){	
	int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++){
    	output[i]=new int[n+1];
      for(int j=0;j<n+1;j++){
      	output[i][j]=-1;
	  }
	}
    return helper(s,t,m,n,output);
}
int main(){
	string s;
	cin>>s;
	string t;
	cin>>t;
	int ans=solve(s,t);
	cout<<ans<<endl;
}
