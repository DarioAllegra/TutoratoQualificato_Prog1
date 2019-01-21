#include<iostream>
#include<string>

using namespace std;

//Alternativa
//#define n 10
//bool esercizio1(bool A[n][n], bool B[n][n], bool C[n][n])

bool esercizio1(bool** A, bool** B, bool** C, int n)
{
	
	for(int i=1; i<n;i++)
	{
		int j=0;
		int k=i;
		bool uguali=true;
		
		while((k<n)&&(uguali))
		{
			uguali=((A[j][k] == B[j][k])&&(A[j][k]==C[j][k]));
			j++;
			k++;
		}
		
		if(uguali)
			return true;
	}
	
	return false;
}


string removeC(string s, char c)
{
	int i=0;
	string res="";
	
	while(s[i]!='\0')
	{
		if(s[i]!=c)
			res=res+s[i];
		i++;
	}
	return res;
}


bool esercizio2(string*** S, int row, int col, char c)
{		
	int dim=row*col;
	int i,j,k,l;
	
	for(int x=0; x<dim-1;x++)
	{
		i=x/col;
		j=x%col;
		
		for(int y=x+1;y<dim;y++)
		{
			k=y/col;
			l=y%col;
			
			if (removeC(*S[i][j],c)==removeC(*S[k][l],c))
				return true;
		}
	}
	
	return false; 
}

int main()
{
	//********************Test esercizio 1************************
	int n=3;
	
	bool** testA=new bool*[n];
	bool** testB=new bool*[n];
	bool** testC=new bool*[n];
	
	for(int i=0;i<n;i++)
	{
		testA[i]=new bool[n];
		testB[i]=new bool[n];
		testC[i]=new bool[n];
	}
	
	
	testA[0][0]=1;	testA[0][1]=0;	testA[0][2]=0;
	testA[1][0]=0;	testA[1][1]=1;	testA[1][2]=0;
	testA[2][0]=1;	testA[2][1]=1;	testA[2][2]=1;
	
	testB[0][0]=1;	testB[0][1]=1;	testB[0][2]=1;
	testB[1][0]=1;	testB[1][1]=1;	testB[1][2]=1;
	testB[2][0]=1;	testB[2][1]=1;	testB[2][2]=1;
	
	testC[0][0]=1;	testC[0][1]=1;	testC[0][2]=1;
	testC[1][0]=1;	testC[1][1]=1;	testC[1][2]=1;
	testC[2][0]=1;	testC[2][1]=1;	testC[2][2]=1;
	
	cout<<esercizio1(testA,testB,testC,n)<<endl;
	
	
	//***********************************************************
	//********************Test esercizio 2************************
	
	int row=3;
	int col=2;
	
	string*** test;
	
	test= new string**[row];
	
	for(int i=0;i<row;i++)
	{
		test[i]= new string*[col];
	}
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			test[i][j]=new string;
		}
	}
	
	
	*test[0][0]="ciao";		*test[0][1]="ccccio";
	*test[1][0]="gg1";		*test[1][1]="ggggg";
	*test[2][0]="uuuup";	*test[2][1]="up";
	
	
	cout<<esercizio2(test,row,col,'g');
}