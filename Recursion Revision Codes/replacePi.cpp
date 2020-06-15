#include<iostream>
#include<cstring>
using namespace std;
void replacePi(char input[],int start)
{
	if(input[start]=='\0' || input[start+1]=='\0')
	{
		return;
	}
	
	replacePi(input,start+1);
	int length=strlen(input);
	if(input[start]=='p' && input[start+1]=='i')
	{
	    for(int i=length-1;i>=start+1;i--)
	    {
	    	input[i+2]=input[i];
		}
		
		input[start]='3';
		input[start+1]='.';
		input[start+2]='1';
		input[start+3]='4';
	}
	input[length+3]='\0';
	cout<<input<<endl;
}
int main()
{
	char input[100];
	cin>>input;
	int start=0;
	replacePi(input,start);
    
}
