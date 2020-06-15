#include<iostream>
using namespace std;
int binarySearchHelper(int *input,int n,int start,int end,int x){
	if(start>=end)
	{
		return -1;
	}
    int middle=(start+end)/2;
	if(input[middle]==x)
	{
		return middle;
	}
	else if(input[middle] < x)
	{
		return binarySearchHelper(input,n,middle+1,end,x);	
    }
    else if(input[middle] > x){
    	return binarySearchHelper(input,n,start,middle-1,x);
	}
    
}
int binarySearch(int *input,int n,int x)
{
    int start=0;
    int end=n-1;
    
   int ans=binarySearchHelper(input,n,start,end,x);
   return ans;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cin>>x;
	int ans=binarySearch(arr,n,x);
	cout<<ans<<endl;
}
