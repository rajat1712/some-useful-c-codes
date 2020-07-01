#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
void sortStack(stack<int> &input){
	vector<int> v;
	while(!input.empty()){
		int x=input.top();
		input.pop();
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		input.push(v[i]);
	}
}
int main(){
	stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}

