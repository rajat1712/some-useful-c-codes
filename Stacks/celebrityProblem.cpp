#include<iostream>
using namespace std;
bool findOnes(int **input,int index,int m,int n){
	int row=m;
	int col=n;
	if(input[index][index]!=0){
			return false;
	}
    for(int i=0;i<row;i++){
    	if(i==index){
    		continue;
		}
    	if(input[i][index]!=1){
    		return false;
		}
	}
	return true;
}


bool  findZeroRow(int **input,int index,int m,int n){
	int row=m;
	int col=n;
	for(int i=0;i<col;i++){
		if(input[index][i]!=0){
			return false;
		}
	}
	return true;
}


int findCelebrity(int **input,int m,int n){
	int row=m;
	int col=n;
	
	for(int i=0;i<col;i++){
		if(input[0][i]==1){
			bool ans1=findOnes(input,i,m,n);
			if(!ans1){
				continue;
			}
			else{
				bool ans2=findZeroRow(input,i,m,n);
				if(ans2){
					return i;
				}
			}
		}
	}
	return -1;
}
int main(){
	int m;
	int n;
	cin>>m;
	cin>>n;
	int **input=new int*[m];
	for(int i=0;i<m;i++){
		input[i]=new int[n];
	 for(int j=0;j<n;j++){
	 	cin>>input[i][j];
	 }
	}
	
  int ans=findCelebrity(input,m,n);
  cout<<ans<<endl;
}
