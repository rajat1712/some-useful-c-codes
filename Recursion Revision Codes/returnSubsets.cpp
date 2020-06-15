#include<iostream>
using namespace std;
int subsets(int *input,int n,int output[][20])
{
	if(n==0)
	{
		output[0][0]=0;
		return 1;
	}
	
	int smallAns=subsets(input+1,n-1,output);
	
	for(int i=0;i<smallAns;i++)
	{
		int length=output[i][0];
		output[smallAns][0]=length+1;
		output[smallAns][1]=input[0];
		for(int col=2;col<length+1;col++)
		{
			output[i+smallAns][col]=output[i][col-1];
		}
	}
	smallAns=smallAns*2;
	return smallAns;
}
int main()
{
	int n;
	cin>>n;
	int *input=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}
	
	int output[20][20];
	int count=subsets(input,n,output);
	for( int i = 0; i < count; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
