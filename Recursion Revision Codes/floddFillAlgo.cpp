#include<iostream>
using namespace std;
void floodfill(int **arr,int m,int n,int x,int y,int position){
	if(x < 0 || y< 0 || x>=m || y>=n)
	{
		return;
	}
	int preVal=arr[x][y];
	if(arr[x][y]!=preVal)
	{
		return;
	}        
	
	arr[x][y]=position;
	
	floodfill(arr,m,n,x+1,y,position);
	floodfill(arr,m,n,x,y+1,position);
	floodfill(arr,m,n,x,y-1,position);
	floodfill(arr,m,n,x-1,y,position);
}
int main()
{
    int m;
	int n;
	cin>>m;
	cin>>n; 
	int **arr=new int*[m]; 
	for(int i=0;i<m;i++)
	{
	  arr[i]=new int[n];
	  for(int j=0;j<n;i++)
	  {
	  	cin>>arr[i][j];
	  }
    }	
    int x;
    int y;
    cin>>x;
    cin>>y;
    int position;
    cin>>position;
    
 
    floodfill(arr,m,n,x,y,position);
    
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
