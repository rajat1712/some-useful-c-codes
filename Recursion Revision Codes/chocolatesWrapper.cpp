#include<iostream>
using namespace std;
int chocolatesHelper(int init,int price,int wrap)
{
	if(init < wrap)
	{
		return 0;
	}
	
	int newChoc=init/wrap;
	return newChoc+chocolatesHelper(newChoc,price,wrap);
}
int chocolates(int money,int price,int wrap)
{
	int init=money/price;
	return init+chocolatesHelper(init,price,wrap);
}
int main()
{
	int money;
	cin>>money;
	int price;
	cin>>price;
	int wrap;
	cin>>wrap;
	int ans=chocolates(money,price,wrap);
	cout<<ans<<endl;
}
