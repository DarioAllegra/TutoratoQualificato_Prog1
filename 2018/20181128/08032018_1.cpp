#include<iostream>
#include<string>

using namespace std;

//Alternativa
/*
#define K 10
bool esercizio1_2(int* A[K][K])
{
	return true;
}
*/

bool esercizio1(int*** A, int n)
{
	int sum=0;
	
	for(int i=1; i<n; i++)
		sum+=*A[i][n-i];	
	
	return sum%n==0;
}


bool stringCheck(string s1, string s2, short w)
{
	if ((s1.length()>=w)&&(s2.length()>=w))
	{
		return s1.substr(0,w)==s2.substr(s2.length()-w,w);
	}
	return false;
}



bool esercizio2(string** A, short  w,  int r, int c)
{
	
	for(int i=0;i<r;i++)
	{
		for(int j=0; j<c-1;j++)
		{
			if(stringCheck(A[i][j], A[i][j+1], w))
				return true;
		}
	}
	
	return false;
}


//TEST per provare i metodi. NON va implementanto nel compito
int main()
{
	//********************Test esercizio 1************************
	int n=3;
	
	int*** test1=new int**[n];
	
	for(int i=0;i<n;i++)
		test1[i]=new int*[n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			test1[i][j]=new int;
	}
	
	*test1[0][0]=1;	*test1[0][1]=1;	*test1[0][2]=1;
	*test1[1][0]=1;	*test1[1][1]=1;	*test1[1][2]=1;
	*test1[2][0]=1;	*test1[2][1]=1;	*test1[2][2]=1;
	
	
	//cout<<esercizio1(test1,n)<<endl;
	
		
	//**************************************************************
	//**************************************************************
	
	//**********************Test esercizio 2************************
	short w=4;
	
	int row=3;
	int col=2;
	
	string** test;
	
	test=new string*[row];
	
	for(int i=0;i<row;i++)
	{
		test[i]= new string[col];
	}
	
	
	test[0][0]="ciao";		test[0][1]="ciaociao";
	test[1][0]="ddd";		test[1][1]="ggggg";
	test[2][0]="puuu";		test[2][1]="uopu";
	
	
	cout<<esercizio2(test,w, row, col)<<endl;
	
	
	
	
	
	
}

