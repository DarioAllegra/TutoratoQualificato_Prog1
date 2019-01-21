#include<iostream>
#include<string>

using namespace std;

//Alternativa
/*
#define K 10
int* esercizio1_2(int A[K][K], int B[K])
{
	return true;
}
*/

int* esercizio1(int** A, int* B, int n)
{
	int* C=new int[n];
	int k=0;
	
	for(int a=0;a<n;a++)
	{	
		int i=0;
		
		bool found=false;
		
		while((i<n)&&(!found))
		{
			int j=0;
			
			while((j<n)&&(!found))
			{
				
				if(B[a]==A[i][j])
				{
					C[k]=B[a];
					k++;
					found=true;
				}
				
				j++;
			}
			i++;
		}
	}
	
	return C;
}


bool specialCompare(string s1, string s2)
{
	if(s1.length()!=s2.length())
		return false;
	
	for(int i=0; i<s1.length();i++)
	{
		if((s1[i]!=s2[i])&&(s1[i]!='?')&&(s2[i]!='?'))
			return false;
	}
	
	return true;
}



int esercizio2(string* A, int n)
{
	//Trova stringa più lunga. Se sono di più prende la prima.
	string s;
	
	s=A[0];
	
	for(int i=1;i<n;i++)
	{
		if(A[i].length()>s.length())
			s=A[i];
	}
	
	//Conta ripetizioni stringa più lunga
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(specialCompare(s,A[i]))
			count++;
	}
	
	return count;
}



//TEST per provare i metodi. NON va implementanto nel compito
int main()
{
	//********************Test esercizio 1************************
	int n=3;
	
	int** test1=new int*[n];
	
	for(int i=0;i<n;i++)
		test1[i]=new int[n];
	
	
	//int* arr=new int[n];
	int arr[3];

	
	arr[0]=5;			arr[1]=6;			arr[2]=16;
	
	test1[0][0]=1;	test1[0][1]=6;	test1[0][2]=7;
	test1[1][0]=4;	test1[1][1]=2;	test1[1][2]=0;
	test1[2][0]=6;	test1[2][1]=3;	test1[2][2]=5;
	
	
	int* res=esercizio1(test1,arr,n);
	
	cout<<res[0]<<endl;
	
		
	//**************************************************************
	//**************************************************************
	
	//**********************Test esercizio 2************************
	int dim=6;
	
	string* test;
	
	test=new string[dim];
	
	
	test[0]="ciao????";		
	test[1]="ciaociao";
	test[2]="d?d";		
	test[3]="dididi";
	test[4]="fuuu";		
	test[5]="ciao zio";
	
	
	cout<<esercizio2(test, dim)<<endl;
	
	
	
	
	
	
}

