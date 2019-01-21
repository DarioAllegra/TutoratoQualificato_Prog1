#include<iostream>

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
};

int main()
{
	return 0;
}

