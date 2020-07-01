#include<iostream>
#include<queue>
using namespace std;
void reverseQ(queue<int> &q){
	if(q.size()==0 || q.size()==1){
		return;
	}
	int x=q.front();
	q.pop();
	reverseQ(q);
	q.push(x);
}
int main(){
	queue<int> q;
	int size;
	cin>>size;
	int *input=new int[size];
	for(int i=0;i<size;i++){
		cin>>input[i];
		q.push(input[i]);
	}
	reverseQ(q);
	while(q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
	}
}
