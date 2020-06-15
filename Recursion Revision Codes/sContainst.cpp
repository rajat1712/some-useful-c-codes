#include<iostream>
#include<cstring>
using namespace std;
bool helper(char *large,int m,char *small,int n,int x,int y)
{
	if(large[x]=='\0' && small[y]=='\0')
	{
		return true;
	}
	int index;
	char ch=small[y];
	for(int i=0;i<m;i++)
	{
		if(large[i]==ch)
		{
			index=i;
			return true;
			break;
		}
	}
	
	return helper(large,m,small,n,index+1,y+1);
	
}
bool checksequence(char *large,char *small)
{
	int m=strlen(large);
	int n=strlen(small);
	return helper(large,m,small,n,0,0);
}
using namespace std;
int main()
{
	char large[100];
	cin>>large;
	char small[100];
	cin>>small;
	
	bool ans=checksequence(large,small);
	cout<<ans<<endl;
}
