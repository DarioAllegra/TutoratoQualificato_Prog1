#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int c=rand();
	
	double c01=((double)c)/RAND_MAX;
	
	cout<<c<<"-->"<<c01<<endl;
	
	//cout<<RAND_MAX;
	
	//
	int k=7;
	
	int r=rand();
	
	int rk=r%k;
	
	cout<<r<<"-->"<<rk<<endl;
	
	//Random tra a e b;
	
	int a=10;
	int b=15;
	
	r=rand();
	
	int rab=a+r%(b-a+1);
	
	cout<<r<<"-->"<<rab<<endl;
	cout<<c01<<"-->"<<(int)(c01*(b-a))+a<<endl;
	return 0;
}