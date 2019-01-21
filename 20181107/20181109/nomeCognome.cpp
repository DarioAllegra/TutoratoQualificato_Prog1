#include <iostream>
#include <string>

using namespace std;

int main()
{
	string nome;
	string cognome;
	
	cout<<"Inserisci nome:"<<endl;
	cin>>nome;
	
	cout<<"Inserisci cognome:"<<endl;
	cin>>cognome;
	
	cout<<endl;
	cout<<nome<<" "<<cognome<<endl;
	
	//Recupero lunghezza stringhe
	int lN=nome.length();
	int lC=cognome.length();
	cout<<lN<<" "<<lC<<endl;
	
	if((lN==0)||(lC==0))
	{
		cout<<"Una delle stringhe e' vuota";
		return -1;
	}
	
	cout<<"Punto 1"<<endl;
	cout<<"Il primo carattere del nome e': "<<nome[0]<<endl;
	cout<<"L'ultimo carattere del nome e': "<< nome[lN-1]<<endl;
	
	if(lC<2)
	{
		cout<<"Non esistono il secondo e terzo carattere del cognome"<<endl;
	}
	else if(lC<3)
	{
		cout<<"Non esiste il terzo carattere del cognome"<<endl;
		cout<<"Il secondo e': "<<cognome[1]<<endl;
	}
	else
	{
		cout<<"Il secondo carattere del cognome e': "<<cognome[1]<<endl;
		cout<<"Il terzo e': "<<cognome[2]<<endl;
	}
	
	
	
	
	
	
	return 0;
}