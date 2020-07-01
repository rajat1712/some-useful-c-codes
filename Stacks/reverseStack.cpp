#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &input,stack<int> &extra){
	
	if(input.empty() || input.size()==1){
		return ;
	}
	
	int element=input.top();
	input.pop();
	
	reverseStack(input,extra);
	
	while(!input.empty()){
		int x=input.top();
		input.pop();
		extra.push(x);
	}
	
	input.push(element);
	while(!extra.empty()){
		int y=extra.top();
		extra.pop();
		input.push(y);
	}
}
int main(){
	stack<int> input;
    int size;
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
    	cin>>arr[i];
    	input.push(arr[i]);
	}
	stack<int> extra;
	reverseStack(input,extra);
	while(!input.empty()){
		int x=input.top();
		input.pop();
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}
