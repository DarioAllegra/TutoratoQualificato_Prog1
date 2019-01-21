#include <iostream>


using namespace std;


void maxArray2(int A[], int n, int *out)
{	
	int max=A[0];
	
	for(int i=1;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}
	
	*out=max;
}

int maxArray(int A[], int n)
{	
	int max=A[0];
	
	for(int i=1;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}
	
	return max;
}

int somma(int a, int b)
{
	return a+b;
}


int main()
{
	
	int add1=19;
	int add2=1;
	
	int res=somma(add1,add2);
	
	cout<<res<<endl;
	cout<<somma(14,7)<<endl;
	
	int v[]={4,32,5,6,7,9,56,2,1,0,67,9};
	
	int dim=sizeof(v)/sizeof(v[0]);
	
	res=maxArray(v,dim);
	cout<<res<<endl;
	
	v[5]=123;
	maxArray2(v,dim,&res);
	cout<<res<<endl;

	
}

