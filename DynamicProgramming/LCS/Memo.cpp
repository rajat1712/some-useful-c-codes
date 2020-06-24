#include<iostream>
using namespace std;
int helper(string s,string t,int **output){
	int m=s.length();
	int n=t.length();
	
	if(s.empty() || t.empty()){
		return 0;
	}
	
	if(output[m][n]!=-1){
		return output[m][n];
	}
	int ans;
	if(s[0]==t[0]){
		ans=helper(s.substr(1),t.substr(1),output)+1;
	}
	
	else{
		int a=helper(s.substr(1),t,output);
		int b=helper(s,t.substr(1),output);
		int c=helper(s.substr(1),t.substr(1),output);
		
		ans=max(a,max(b,c));
	}
	
	output[m][n]=ans;
	return ans;
}
int lcs(string s,string t){
	int m=s.length();
	int n=t.length();
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
	string t;
	cin>>s;
	cin>>t;
	int length=lcs(s,t);
	cout<<length<<endl;
}
