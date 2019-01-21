#include <iostream>

using namespace std;

int main()
{
	int a=10;
	int *b;
	int v[5];
	int *g[5];
	int h[5];
	
	b=&a;
	
	for(int i=0;i<5;i++)
	{
		g[i]=&a;
	}
	
	a=29;
	*g[3]=14;
	
	cout<<*(*g)<<endl;
	cout<<a<<endl;
	cout<<*g[0]<<endl;
	cout<<&a<<endl;
	cout<<g[0]<<endl;
	
	/*
	cout<<a<<endl;
	cout<<b<<endl;
	*/

	
	v[0]=14;
	v[1]=213;
	v[2]=44;
	v[3]=445;
	v[4]=91;
	
	b=v;
	//h=v;
	cout<<b[4]<<endl;
	/*
	cout<<v[0]<<endl;
	cout<<v<<endl;
	*/
}