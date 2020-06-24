#include<iostream>
using namespace std;
int lcs(string s,string t){
	if(s.empty() || t.empty()){
       return 0;		
	}
	
	if(s[0]==t[0]){
		int smallAns=lcs(s.substr(1),t.substr(1));
		return smallAns+1;
	}
	else{
		int a=lcs(s.substr(1),t);
		int b=lcs(s,t.substr(1));
		int c=lcs(s.substr(1),t.substr(1));
		return max(a,max(b,c));
	}
	
}
int main()
{
	string s;
	cin>>s;
	string t;
	cin>>t;
	int ans=lcs(s,t);
	cout<<ans<<endl;
}
