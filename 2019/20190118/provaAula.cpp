#include<iostream>
#include<cmath>
#include<string>
#include<typeinfo>
#include<cstdlib>


using namespace std;

class A
{	
	private:
		string w;
	
	
	protected:
		short par;
	
	public:
		A(string s, short n)
		{
			w=s;
			par=n;
		}
		
		int getSum()
		{
			int sumAll=0;
			int sumV=0;
			
			for(int i=0; i<w.length();i++)
			{
				sumAll=sumAll+(int)w[i];
				
				switch(w[i])
				{
					case 'A':
					case 'E':
					case 'I':
					case 'O':
					case 'U':
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':{sumV+=(int)w[i]; break;}
				}
			}
			
			return sumAll-sumV;
		}
		
		virtual float* val(short *len)=0;
		
		virtual ostream& put(ostream& os)
		{
			os<<"Class "<<typeid(*this).name()<<": ";
			os<<"w="<<w<<", par="<<par<<" ";
			return os;
		}
	
		
	
};

class B:public A
{
	private:
		string str;
	
	public:
		B(string s, short n):A(s,n)
		{
			str="";
			
			for(int i=0;i<s.length();i++)
			{
				if(!((s[i]>='0')&&(s[i]<='9')))
				{
					if((s[i]!='a')&&(s[i]!='e')&&(s[i]!='i')&&(s[i]!='o')&&(s[i]!='u'))
					{
						str=str+s[i];						
					}
					
				}
			}			
			
		}
		
		float* val(short* len)
		{
			*len=str.length();
			float* v=new float[*len];
			
			for(int i=0;i<*len;i++)
			{
				v[i]=((int)str[i])/(float)par;
			}
			
			return v;
			
		}
		
		ostream& put(ostream& os)
		{
			A::put(os);
			os<<"{ str="<<str<<"}";
			return os;
		}
};


class C:public A
{
	private:
		float x;
		string sc;
	
	public:
		
		C(string s, short n):A(s,n)
		{
			x=abs(sin(s.length()/(float)par));
			
			sc=s.substr(0,(int)(x*n+0.5));
		}
		
		float* val(short* len)
		{
			*len=sc.length();
			float* v=new float[*len];
			
			for(int i=0; i<*len;i++)
			{
				v[i]=log( ((int)sc[i])/x);
			}
			
			return v;
			
		}
		
		bool moreThan(float y)
		{
			return (x>=y);
		}
		
		ostream& put(ostream& os)
		{
			A::put(os);
			os<<"{ x="<<x<<", sc="<<sc<<"}";
			return os;
		}

		
};


ostream& operator<<(ostream& os, A& myobj)
{
	return myobj.put(os);
}

int main()
{
	const int DIM = 30;
	srand(111222333);
	A *vett[DIM];
	short r, r1, select;
	int l;
	string str;
    
	for(int i=0; i<DIM; i++)
	{
		str = "";
		r = rand()%5+5;
		r1 = rand()%2;
		l = rand()%8 + 5;
		for(int j=0; j<l; j++)
		{
			select = rand()%3;
			switch(select)
			{           
				case 0:
					str+=(char) ('a' + rand()%25);
					break;
				case 1:
					str+=(char) ('0' + rand()%10);
					break;
				case 2:
					str+=(char) ('A' + rand()%25);
					break;
			}
    
			if(r1)
				vett[i] = new B(str, r);
			else
				vett[i] = new C(str, r);
		}
	}
	
	
	
	
	
	//Punto 1
	cout<<"Punto 1"<<endl;
	
	for(int i=0; i<DIM; i++)
	{
		cout<<i<<")"<<*vett[i]<<endl;
		cout<<"getSum()="<<vett[i]->getSum()<<endl;
	}
	
	//Punto 2
	cout<<"Punto 2"<<endl;
	

	float* vv;
	//short* ln=new short;
	short ln;
	float sum;
	
	for(int i=0; i<DIM; i++)
	{
		vv=vett[i]->val(&ln);
		sum=0;
		
		for(int j=0; j<ln; j++)
		{
			sum+=vv[j];
		}
		
		cout<<sum/ln<<" ";
	}
	
	//Punto 3
	cout<<"Punto 3"<<endl;
	
	for(int i=0; i<DIM;i++)
	{
		if( (typeid(*vett[i])==typeid(C)) && (((C*)vett[i])->moreThan(0.9)))
			cout<<i<<"  ";
			
	}
	
	
	
	return 0;
}

