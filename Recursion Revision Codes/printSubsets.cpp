#include<iostream>
using namespace std;
void printSubsetsOfArray(int *input,int size,int startIndex,int *output,int opSize)
{
    if(size==0)
    {
    	for(int i=0;i<opSize;i++)
    	{
    		cout<<output[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	int smallOutput[50];
	int smallSize=0;
	
	printSubsetsOfArray(input,size,startIndex+1,output,opSize);
	int i;
	for(i=0;i<size;i++)
	{
		smallOutput[i]=output[i];
	}
	smallOutput[i]=input[startIndex];
	printSubsetsOfArray(input,size,startIndex+1,smallOutput,opSize+1);
	
}
int main()
{
   int n;
   cin>>n;
   int *input=new int[n];
   int *output=new int[n];
  
   for(int i=0;i<n;i++)
   {
   	cin>>input[i];
   }
   int startIndex=0;
   printSubsetsOfArray(input,n,startIndex,output,0);
}
