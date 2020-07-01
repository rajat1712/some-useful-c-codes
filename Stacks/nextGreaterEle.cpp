#include <bits/stdc++.h> 
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(int *input,int n,vector<int> &v){
	stack<int> s;
	for(int i=n-1;i>=0;i--){
		if(s.empty()){
			v.push_back(-1);
		}
		else if(!s.empty() && s.top()>input[i]){
			int element=s.top();
			v.push_back(element);
		}
		else if(!s.empty() && s.top()<input[i]){
			while(!s.empty()){
				int x=s.top();
			    if(x > input[i]){
			    	v.push_back(x);
			    	break;
				}
				else{
					s.pop();
				}
			}
			if(s.empty()){
				v.push_back(-1);
			}
		}
		
       s.push(input[i]);
	}
	
	reverse(v.begin(),v.end());
	return v;
}
int main(){
	int n;
	cin>>n;
	int *input=new int[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	vector<int> v;
	vector<int> ans=nextGreaterElement(input,n,v);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
