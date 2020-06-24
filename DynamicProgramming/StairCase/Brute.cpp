#include<iostream>
using namespace std;
long staircase(int n){
    if(n==0 || n==1 || n==2){
    	return n;
	}
	
	if(n==3){
		return 4;
	}
	
	long x=staircase(n-1);
	long y=staircase(n-2);
	long z=staircase(n-3);
	
	return x+y+z;
	
}
int main(){
	int n;
	cin>>n;
	int ans=staircase(n);
	cout<<ans<<endl;
}
