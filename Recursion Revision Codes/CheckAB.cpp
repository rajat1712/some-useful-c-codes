//check AB
#include<iostream>
using namespace std;
bool checkAB(char input[],int start)
{
	if(input[start]=='\0')
	{
		return true;
	}
	
	if(input[start]!='a')
	{
		return false;
	}
	
	if(input[start]=='a')
	   {
		 if(input[start+1]=='\0' || input[start+1]=='a'|| (input[start+1]=='b' && input[start+2]=='b')  )
			{
				return true;
			}
		 else{
				return false;
			}
	   }
	return checkAB(input,start+3);
}
int main()
{
	char input[100];
	cin>>input;
	int start=0;
	bool ans=checkAB(input,start);
	cout<<ans<<endl;
}
