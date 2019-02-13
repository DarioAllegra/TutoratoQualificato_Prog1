#include<iostream>
#include<typeinfo>
#include<cmath>
#include<cstdlib>

using namespace std;

class A
{
	protected:
		int n;
	
	public:
		A(int _n)
		{
			n=_n;
		}
		
		virtual int const f(int)=0;
		
		A& operator ++()
		{
			n++;
			return *this;
		}
		
		virtual ostream& put(ostream& os)=0;
};


class B: public A
{
	private:
		int m;
	
	public:
		B(int _n):A(_n)
		{
			m=3*(n%7);
		}
		
		int const fatt(int arg)
		{
			int res=1;
			
			for(int i=arg; i>1; i--)
			{
				res=res*i;
			}
			
			return res;
		}
		
		int const f(int z)
		{
			if(n<z)
				return fatt(n);
			return fatt(m);
		}
		
		ostream& put(ostream& os)
		{
			os<<"B: \t n="<<n<<", m="<<m<<" f(5)="<<f(5);
			return os;
		}
		
};

template <typename T>
class C:public A
{
	
	private:
		T x;
	
	public:
		T const g(T arg)
		{
			return arg*arg;
		}
		
		int const f(int z)
		{
			return g(n+x+z);
		}
		
		C(int _n):A(_n)
		{
			if(typeid(T)==typeid(int))
				x=g(n);
			else if(typeid(T)==typeid(double))
				x=sin(n);
			else
				x=0;			
		}
		
		ostream& put(ostream& os)
		{
			string ty="?";
			
			if(typeid(T)==typeid(double))
				ty="double";
			else if (typeid(T)==typeid(int))
				ty="int";
			
			os<<"C<"<<ty<<">:\t n="<<n<<", x="<<x;
			os<<" f(5)="<<f(5)<<", g(5)="<<g(5);
			return os;
		}
	
	
};


ostream& operator<<(ostream& os, A& obj)
{
	return obj.put(os);
}


int main()
{
	const int DIM=50;
	A* vett[DIM];
	
	srand(328832748);
	for(int i=0; i<DIM; i++) 
	{
		int n=1+rand()%100;
		switch(rand()%3) 
		{			
			case 0: vett[i]= new B(n); break;
			case 1: vett[i]= new C<double>(n);break;
			case 2: vett[i]= new C<int>(n);
		}
	}
	
	//Punto 0
	
	for(int i=0;i<DIM;i++)
	{
		cout<<i<<") ";
		cout<<*vett[i]<<endl;
	}
	
	//Punto 1
	
	int max=vett[0]->f(5);
	int tmp;
	double sum=0; 
	
	for(int i=0;i<DIM;i++)
	{
		tmp=vett[i]->f(5);
		
		if(tmp>max)
			max=tmp;
		
		if(typeid(*vett[i])==typeid(C<double>))
			sum=sum+((C<double>*)vett[i])->g(5);
	}
	
	cout<<"Max = "<<max<<",\t Sum = "<<sum<<endl; 
	
	
	
	//Punto 2
	
	
	cout<<(*vett[0])<<endl;
	++(*vett[0]);
	
	cout<<(*vett[0])<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}