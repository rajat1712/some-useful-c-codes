#include<iostream>
using namespace std;
void printPermutationsHelper(string input,string output)
{
	if(input.empty())
	{
		cout<<output<<endl;
		return;
	}
	
	for(int i=0;i<output.length();i++)
	{
		printPermutationsHelper(input.substr(1),output.substr(0,i)+input[0]+output.substr(i));
	}
}
void printPermutations(string input)
{
	string output=" ";
	printPermutationsHelper(input,output);
}
int main()
{
	 string input;
	 cin>>input;
	 printPermutations(input);
}
