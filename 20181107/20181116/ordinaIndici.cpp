#include <iostream>

using namespace std;

int main()
{
	
	int a[]={46,31,15,25,9};
	int b[]={0,1,2,3,4};
	
	
	int dim=sizeof(a)/sizeof(a[0]);
	
	for(int i=0;i<dim;i++)
		cout<<a[i]<<endl;
	
	int tmp;
	for(int i=0;i<dim-1;i++)
	{
		for(int j=i+1;j<dim;j++)
		{
			if(a[b[i]]>a[b[j]])
			{
				/*
				tmp=a[j];
				a[j]=a[i];
				a[i]=tmp;
				*/
				
				tmp=b[j];
				b[j]=b[i];
				b[i]=tmp;
			}
			
		}
	}
	
	cout<<endl;
	for(int i=0;i<dim;i++)
		cout<<a[b[i]]<<endl;
	
	
	cout<<endl;
	for(int i=0;i<dim;i++)
		cout<<b[i]<<endl;
	
	
	
	
	return 0;
	
	/*
	int a[]={5,1,2,56,7,13};
	
	int dim=sizeof(a)/sizeof(a[0]);
	int tmp;
	
	//Array degli indici
	int idx[]={0,1,2,3,4,5};
	
	//Stampa array
	for(int i=0;i<dim;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	
	for(int i=0;i<dim-1;i++)
	{
		for(int j=i+1;j<dim;j++)
		{
			if(a[j]<a[i])
			{
				//Scambio valori nell'array
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				
				//Scambio valori nell'array degli indici
				tmp=idx[i];
				idx[i]=idx[j];
				idx[j]=tmp;
			}
		}
	}
	
	//Stampa array
	for(int i=0;i<dim;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	
	//Stampa array indici
	for(int i=0;i<dim;i++)
		cout<<idx[i]<<" ";
	
	cout<<endl;
	
	return 0;
	*/
}