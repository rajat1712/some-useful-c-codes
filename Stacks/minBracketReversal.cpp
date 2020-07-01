#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int countBracketReversals(char input[]){
	stack<int> s;
	int length=strlen(input);
	if(length%2!=0)
   {
       return -1;
   }
	int count=0;
	for(int i=0;i<length;i++){
		if(input[i]=='{'){
			s.push(input[i]);
		}
		else if(input[i]='}'){
			if(s.empty()){
				s.push(input[i]);
			}
			
			else{
				if(s.top()=='{'){
					s.pop();
				}
				else{
					s.push(input[i]);
				}
			}
		}	
	}
	
	while(!s.empty()){
		char ch1=s.top();
		s.pop();
		char ch2=s.top();
		s.pop();
		if(ch1==ch2){
			count++;
		}
		else{
			count+=2;
		}
	}
	return count;
}
int main(){
	char input[100];
	cin>>input;
	int ans=countBracketReversals(input);
	cout<<ans<<endl;
}
