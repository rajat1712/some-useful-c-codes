#include<iostream>
#include "privateClass.cpp"
using namespace std;
int main()
{
	shop flour;
	shop maggi;
	shop rice;
	shop daal;
	shop spices;
	
	
	flour.quantity=20;
	maggi.quantity=50;
	rice.quantity=30;
	daal.quantity=10;
	spices.quantity=90;
	
	cout<<"Click 1 to see the qauntity of all items:";
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"Flour: "<<flour.quantity<<endl;
		cout<<"Maggi: "<<maggi.quantity<<endl;
		cout<<"Rice: "<<rice.quantity<<endl;
		cout<<"Daal: "<<daal.quantity<<endl;
		cout<<"Spices: "<<spices.quantity<<endl;
	}
	
	flour.setPrice(200,123);
	maggi.setPrice(50,123);
	rice.setPrice(30,123);
	daal.setPrice(40,123);
	spices.setPrice(20,123);
	
	cout<<"Do you wish to update/see price of any item?"<<endl;
	cout<<"Enter 1 or 0"<<endl;
	int choice;
	cin>>choice;
	
	string update="U";
	string see="S";
	string input;
	cout<<"For updation click U"<<endl;
	cout<<"For seeing click S"<<endl;
	cin>>input;
	
    
	if(input==update)
	{
		cout<<"For Flour Updation: "<<endl;
		int password;
		cout<<"Enter password"<<endl;
		cin>>password;
		int price1;
		cout<<"Enter price"<<endl;
		cin>>price1;
		flour.setPrice(price1,password);
		
	}
	
		
}
