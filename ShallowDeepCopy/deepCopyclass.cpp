#include<iostream>
#include "deepCopyMain.cpp"
using namespace std;
int main()
{
	char name[]="abcd";
	student s1(20,name);
	s1.display();
	name[3]='e';
	student s2(24,name);
	
	s2.display();
	
	s1.display();
}
