#include<iostream>
using namespace std;
int editDistance(string s,string t){
	if(s.empty() || t.empty()){
		return max(s.length(),t.length());
	}
	int smallAns;
	if(s[0]==t[0]){
	   smallAns=editDistance(s.substr(1),t.substr(1));	
	}
	
	else{
		int insert=editDistance(s.substr(1),t);
		int deletion=editDistance(s,t.substr(1));
		int replace=editDistance(s.substr(1),t.substr(1));
		
		smallAns=min(insert,min(deletion,replace))+1;
	}
	return smallAns;
}
int main(){
	string s;
	string t;
	cin>>s;
	cin>>t;
	int ans=editDistance(s,t);
	cout<<ans<<endl;
}
