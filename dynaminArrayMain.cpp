#include<iostream>
#include "dynaminArrayClass.cpp"
using namespace std;
int main()
{
	dynamicArray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
		
	dynamicArray d2(d1);
	d1.add(60);

	dynamicArray d3=d2;
	d2.print();
	d2.add(70);
	d3.print();
}
