#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
using namespace std;


class A
{
	private:
		string sa;
		float* p;
		short l;
	
	public:
		
		A(string s1, short n)
		{
			sa="";
			for(int i=0; i<s1.length();i++)
			{
				if(((s1[i]>='a')&&(s1[i]<='z'))||((s1[i]>='0')&&(s1[i]<='9')))
					sa=sa+s1[i];
				
			}
			
			p=new float[n];
			
			for(int i=0; i<n; i++)
			{
				p[i]=rand()/(float)RAND_MAX;
			}
			
			l=n;
			
			
		}
		
		virtual ostream& put(ostream& os) const
		{
			os<<"Class "<<(typeid(*this)).name()<<": ";
			os<<"sa= "<<sa;
			os<<" p=[";
			
			for(int i=0; i<l;i++)
			{
				os<<p[i]<<" ";
			}
			os<<"]";
			
			return os;
		}
		
		
		
	
		virtual float f(short i, float x)=0;
		
	protected:
		
		float val(short j)
		{
			return p[j%l];
		}
	
};

class B: public A
{
	private:
		string str;
	
	public:
		
		B(string w, short k, int v):A(w,k)
		{
			if(v%2==0)
				str=w.substr(0,k);
			else
				str=w.substr(w.length()-k);
		}
	
		float f(short i, float x)
		{
			if(x<val(i))
				return x;
			
			return val(i);
		}
		
		ostream& put(ostream& os) const
		{
			A::put(os);
			os<<"{str="<<str<<"}";
			return os;
		}
		
		
	
};

class C: public A
{
	private:
		float y;
	
	public:
		
		C(string a1, string a2):A(a1+a2,1+abs((int)(a1.length()-a2.length()))*2)
		{
			//AGGIUNGERE cast
			y=(a1.length()+a2.length())/2.0;
		}
		
		//NON FA PARTE DELL'ESERCIZIO
		/*
		C(float y):A("ciao",0)
		{
			this[0].y=y;
		}
		*/
	
		float f(short i, float x)
		{
			if(x!=0)
			{
				if(i%2==0)
					return sin(val(i)*x);
				return val(i)/x;
			}
			return 0;
		}
	
		
		float g() const
		{
			return log(y);
		}
		
		ostream& put(ostream& os) const
		{
			A::put(os);
			os<<"{y="<<y<<"}";
			return os;
		}
		
	
	
};



ostream& operator<<(ostream& os, A& obj)
{
	return obj.put(os);
}



int main()
{
	const int DIM = 30;
	srand(111222333);
	A *vett[DIM];

	string s1, s2;
	int l1, l2;
	short k;

	for(int i=0; i<DIM; i++)
	{
		if(rand()%2==0)
		{ // B
			s1 = "";
			l1 = rand()%5 + 5; 
			k = rand()% (l1/2)+1;
			
			for(int j=0; j<l1; j++)
				s1+=((rand()%2) ? (char) (rand()%26 + 'a') : (char) (rand()%10 + '0'));
			
			vett[i] = new B(s1, k, rand()%100);
		}
		else
		{ // C
			s1 = "";
			s2 = "";
			l1 = rand()%5 +5;
			l2 = rand()%5 +5;
			for(int j=0; j<l1; j++)
				s1+=(rand()%2 ? (char) (rand()%26 + 'a') : (char) (rand()%10 + '0'));      

			for(int k=0; k<l2; k++)
				s2+=(rand()%2 ? (char) (rand()%26 + 'a') : (char) (rand()%10 + '0'));

			vett[i] = new C(s1, s2);
		}
	}
	
	
	//Punto 1
	for(int i=0; i<DIM; i++)
	{
		cout<<i<<")"<<*vett[i]<<endl;
		
		if(typeid(*vett[i])==typeid(C))
			cout<<"g()="<<((C*)vett[i])->g()<<endl;
	}
	
	//Punto 2
	
	for(int i=0; i<DIM;i++)
	{
		if(vett[i]->f(5,0.5)<0.5)
			cout<<i<<" ";
	}
	cout<<endl;
	
	
	//Punto 3
	float res=0;
	int count=0;
	C* tmp;
	
	for(int i=0;i<DIM;i++)
	{
		tmp=dynamic_cast<C*>(vett[i]);
		
		if(tmp!=NULL)
		{
			count++;
			res=res+tmp->g();
		}
		
	}
	
	cout<<res/count<<endl;
	
	
	return 0;
}

















