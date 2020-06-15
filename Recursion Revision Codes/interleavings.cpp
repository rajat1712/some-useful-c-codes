#include<iostream>
#include<cstring>
using namespace std;
void interleavingHelper(char *first,int m,char *second,int n,char *output,int startIndex)
{
	if(m==0 && n==0)
	{
		cout<<output<<endl;
		return;
	}
	
	if(m>=1)
	{
		output[startIndex]=first[0];
		interleavingHelper(first+1,m-1,second,n,output,startIndex+1);
	}
	if(n>=1)
	{
		output[startIndex]=second[0];
		interleavingHelper(first,m,second+1,n-1,output,startIndex+1);
	}
}
void interleaving(char *first,char *second)
{
	int sizeFirst=strlen(first);
	int sizeSecond=strlen(second);
	char *output=new char[sizeFirst+sizeSecond];
	int startIndex=0;
	interleavingHelper(first,sizeFirst,second,sizeSecond,output,startIndex);
}
int main()
{
	char first[100];
	cin>>first;
	
	char second[100];
	cin>>second;
	interleaving(first,second);
}
