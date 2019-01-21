#include<iostream>

using namespace std;



int main()
{
	int a[5]={258,3,48,5,10};
	
	cout<<"Inizio esercizio"<<endl;
	
	//cout<<sizeof(a)<<endl;
	
	for(int i=0;i<5;i++)
	{
		int j=6;
		cout<<a[i]<<endl;
	}
	
	//Esempio scope
	if(true)
	{
		int j=6;
	}
	//cout<<j;
	
	//int max=INT32_MIN;
	int max=a[0];
	int min=a[0];
	
	
	for(int i=1;i<5;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	
	
	float media=(max+min)/2.0;
	
	//Errore se istanzio i al volo nel for
	//cout<<i<<endl;
	cout<<"Il massimo e': "<< max<<endl;
	cout<<"Il minimo e': "<< min<<endl;
	cout<<"La media e': "<< media<<endl;
	//cout<<5/(float)2<<endl;
	
}



