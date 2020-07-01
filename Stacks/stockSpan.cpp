#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> stockSpan(int *input,int n,vector<int> &v){
     stack<pair<int,int> > s;
     for(int i=0;i<n;i++){
     	if(s.empty()){
     	    v.push_back(-1);
		 }
		 
		else if(!s.empty() && s.top().first > input[i]){
			v.push_back(s.top().second);
		}
		
		else if(!s.empty() && s.top().first <= input[i]){
			while(!s.empty() && s.top().first <= input[i]){
				s.pop();
			}
			
			if(s.empty()){
				v.push_back(-1);
			}
			else{
				v.push_back(s.top().second);
			}
		}
		
		s.push({input[i],i});
	 }
	 
	 for(int i=0;i<v.size();i++){
	 	v[i]=i-v[i];
	 }
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
	vector<int> ans=stockSpan(input,n,v);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
