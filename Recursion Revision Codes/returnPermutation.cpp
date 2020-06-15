//NHI HUA
#include<iostream>
using namespace std;
int getCodes(string input,string output[])
{
	if(input.length()==1)
	{
	   output[0]=input[0];
	   return 1;
	}
	
	string  first;
	string second;
	int lengthString=strlen(input);
	for(int i=0;i<lengthString;i++)
	{
		string tobeAttached=input[i];
		for(int j=0;j<i-1;j++)
		{
		   first[j]=input[j];
		}
		
		for(int j=i+1;i<lengthString;i++)
		{
			second[j]=input[j];
		}
		string permutationsTobeFound=first+second;
	}
}
int main()
{
	string input;
	cin>>input;
	string output[100];
	int ans=getCodes(input,output);
	cout<<ans<<endl;
}
