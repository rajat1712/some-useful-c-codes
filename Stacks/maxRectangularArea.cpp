#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;
vector<int> returnLeft(int *input,int n){
	vector<int> left;
	int element=-1;
	stack<pair<int,int> > s1;
	for(int i=0;i<n;i++){
		if(s1.empty()){
			left.push_back(element);
		}
		else if(!s1.empty() && s1.top().first < input[i]){
			left.push_back(s1.top().second);
		}
		else if(!s1.empty() && s1.top().first > input[i]){
			while(!s1.empty()){
				if(s1.top().first < input[i]){
					left.push_back(s1.top().second);
				}
				else{
					s1.pop();
		    	}
			}
			if(s1.empty()){
				left.push_back(element);
			}
		}
		
		s1.push({input[i],i});
	}
	return left;
}


vector<int> returnRight(int *input,int n){
	vector<int> right;
	int element=n;
	stack<pair<int,int> > s2;
	for(int i=n-1;i>=0;i--){
		if(s2.empty()){
			right.push_back(element);
		}
		
		else if(!s2.empty() && s2.top().first < input[i]){
			right.push_back(s2.top().second);
		}
		else if(!s2.empty() && s2.top().first > input[i]){
			while(!s2.empty()){
				int x=s2.top().second;
				if(x < input[i]){
					right.push_back(s2.top().second);
				}
				else{
					s2.pop();
				}
			}
			if(s2.empty()){
				right.push_back(element);
			}
		}
		
	  s2.push({input[i],i});
	}
	
	reverse(right.begin(),right.end());
	return right;
}


int maxRectangularArea(int *input,int n){
	vector<int> left=returnLeft(input,n);
	vector<int> right=returnRight(input,n);
	int *weights=new int[n];
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		weights[i]=right[i]+left[i]-1;
		if(weights[i] > max){
			max=weights[i];
		}
	}
	return max;
}
int main(){
	int n;
	cin>>n;
	int *input=new int[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	int ans=maxRectangularArea(input,n);
	cout<<ans<<endl;
}
