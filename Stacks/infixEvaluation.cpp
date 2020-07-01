#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int precedence(char op){
	if(op=='+'){
		return 1;
	}
	else if(op=='-'){
		return 1;
	}
	else if(op=='*'){
		return 2;
	}
	else{
		return 2;
	}
}

int operation(int val1,int val2,char op){
	if(op=='+'){
		return val1+val2;
	}
	else if(op=='-'){
		return val1-val2;
	}
	else if(op=='*'){
		return val1*val2;
	}
	else{
		return val1/val2;
	}
}


int infixEvaluation(char input[]){
	stack<int> operators;
	stack<int> operands;
	
	int length=strlen(input);
	for(int i=0;i<length;i++){
		if(input[i]=='('){
			operators.push(input[i]);
		}
		else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/'){
			if(operators.size()>0 && operators.top()!='(' && precedence(input[i]) <= precedence(operators.top())){
				int val2=operands.top();
				operands.pop();
				int val1=operands.top();
				operands.pop();
				
				char ch=operators.top();
				operators.pop();
				int val=operation(val1,val2,ch);
				operands.push(val);
			}
			
			operands.push(input[i]);
		}
		else if(input[i]==')'){
			while(operators.size() > 0 && operators.top()!='('){
				int val2=operands.top();
				operands.pop();
				int val1=operands.top();
				operands.pop();
				
				char ch=operators.top();
				operators.pop();
				int val=operation(val1,val2,ch);
				operands.push(val);
			}
			
		    if(operators.size()>0){
			operators.pop();
		 }
		}
		
		else {
			operands.push(input[i]-'0');
		}
	}
	
	
	int ans=operands.top();
	operands.pop();
	return ans;
	
}
int main(){
	char input[100];
	cin>>input;
	int ans=infixEvaluation(input);
	cout<<ans<<endl;
}











