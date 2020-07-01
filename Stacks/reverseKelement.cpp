#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> reverseKElements(queue<int> input, int k){
	stack<int> s;
	while(k--){
		int x=input.front();
		input.pop();
		s.push(x);
	}
	
	queue<int> q;
	while(!s.empty()){
		int y=s.top();
		s.pop();
		q.push(y);
	}
	while(!input.empty()){
		int z=input.front();
		input.pop();
		q.push(z);
	}
	return q;
}
using namespace std;
int main(){
	int n=0;
	cin>>n;
	queue<int> Queue;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		Queue.push(temp);
	}
	int k;
	cin>>k;
	
	queue<int> ans = reverseKElements(Queue,k);
	while (!ans.empty()) {
        	cout << ans.front() << endl;
        	ans.pop();
    	}
}
