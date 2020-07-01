#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
bool countBracketReversals(char input[]){
	stack<char> s;
	
	int length=strlen(input);
	s.push(input[0]);
	
	for(int i=1;i<=length-1;i++){
		int count=0;
		if(input[i]==')'){
			while(s.top()!='('){
				s.pop();
				count++;
		  }
		  if(count==0)
		  {
		  	return true;
		  }
		  s.pop();
	   }
		else{
			s.push(input[i]);
		}
	 }
	 return false;
}
int main(){
	char input[100];
	cin>>input;
	bool ans=countBracketReversals(input);
	cout<<ans<<endl;
	
}
