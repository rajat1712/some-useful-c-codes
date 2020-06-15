#include<iostream>
using namespace std;
int getCodes(string input,string *output)
{
	if(input.empty())
	{
		output[0]="";
		return 1;
	}
	
	string smallOutput1[100];
	string smallOutput2[100];
	int tobeAttached=input[0]-48;
	char value1=tobeAttached+'a'-1;
	int size1=getCodes(input.substr(1),smallOutput1);
	int size2=0;
	char value2='\0';
	if(input[1]!='\0')
	{
		int tobeAttached2=tobeAttached*10+input[1]-48;
		if(tobeAttached2 >=10 && tobeAttached2 <= 26)
		{
			value2=tobeAttached2+'a'-1;
			size2=getCodes(input.substr(2),smallOutput2);
		}
	}
	int k=0;
	for(int i=0;i<size1;i++)
	{
		output[k]=value1+smallOutput1[i];
		k++;
	}
	
	for(int i=0;i<size2;i++)
	{
		output[k]=value2+smallOutput2[i];
		k++;
	}
	
	return k;
}
int main()
{
	string input;
	cin>>input;
	string output[100];
	int ans=getCodes(input,output);
	for(int i=0;i<ans;i++)
	{
		cout<<output[i]<<endl;
	}
}
