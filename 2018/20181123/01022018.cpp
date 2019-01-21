#include <iostream>

using namespace std;

bool sorelle(string s1, string s2)
{
	int vs1=0;
	int vs2=0;
	int i=0;
	
	while(s1[i]!='\0')
	{
		if((s1[i]=='a')||(s1[i]=='e')||(s1[i]=='i')||(s1[i]=='o')||(s1[i]=='u'))
			vs1++;
		i++;
	}
	
	i=0;
	while(s2[i]!='\0')
	{
		if((s2[i]=='a')||(s2[i]=='e')||(s2[i]=='i')||(s2[i]=='o')||(s2[i]=='u'))
			vs2++;
		i++;
	}
	
	return vs1==vs2;
}


bool esercizio2(string*** S, int r, int c)
{		
	for(int j=0; j<c; j++)
	{
		for(int i=0; i<r-1; i++)
		{
			for(int k=i+1; k<r; k++)
			{
				
				if(sorelle(*S[i][j],*S[k][j]))
					return true;
			}
		}
	}
	
	return false; 
}


int main()
{
	int row=3;
	int col=2;
	
	string*** test;
	
	
	test= new string**[row];
	
	for(int i=0;i<row;i++)
	{
		test[i]=new string*[col];
	}
	
	for(int i=0; i<row;i++)
	{
		for(int j=0; j<col;j++)
		{
			test[i][j]= new string;
		}
	}
	
	/*
	***test="ciao";
	
	//*test[0][0]="ciao";		
						***(test+3)="ciao";
						//*test[0][1]="ciao";
	***(test+1)="ddd";
	//*test[1][0]="ddd";		
						*test[1][1]="ggggg";
	
	***(test+2)="uuuu";
	//*test[2][0]="uuuu";		
						*test[2][1]="uoopp";
	*/
	
	
	
	*test[0][0]="ciao";		*test[0][1]="hey";
	*test[1][0]="ddd";		*test[1][1]="ggggg";
	*test[2][0]="uuuu";	*test[2][1]="uopp";
	
	int rr=2;
	int cc=1;

	cout<<*(*(*test+cc)+row*rr)<<endl;
	
	if(esercizio2(test,row,col))
		cout<<"Ci sono stringhe sorelle"<<endl;
	else
		cout<<"NON ci sono stringhe sorelle"<<endl;
	
}

/*

//TEST - NON va scritto durante l'esame
int main()
{
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
	
	
	*test[0][0]="ciao";		*test[0][1]="ciao";
	*test[1][0]="ddd";		*test[1][1]="ggggg";
	*test[2][0]="uuuu";		*test[2][1]="uopp";
	
	
	cout<<esercizio2(test,row,col);
	
	//Alla fine di deve deallocare la memoria.
}
*/
