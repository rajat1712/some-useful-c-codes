#include<iostream>
#include<cstring>
using namespace std;
void removeConsecutiveDuplicates(char *input)
{
	if(input[0]=='\0'|| input[1]=='\0')
	{
		return;
	}
	
	removeConsecutiveDuplicates(input+1);
	int length=strlen(input);
	if(input[0]==input[1])
	{
		for(int i=1;i<length;i++)
		{
			input[i-1]=input[i];
		}
		input[length-1]='\0';
	}
	
}
int main()
{
	char input[100];
	cin>>input;
	int start=0;
	removeConsecutiveDuplicates(input);
	cout<<input<<endl;
}
