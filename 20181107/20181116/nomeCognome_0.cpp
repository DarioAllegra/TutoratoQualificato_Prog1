#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string nome;
	string cognome;
	
	cout<<"Inserisci nome:"<<endl;
	//cin>>nome;
	nome="Dario";
	
	cout<<"Inserisci cognome:"<<endl;
	//cin>>cognome;
	cognome="Allegra";
	
	cout<<endl;
	cout<<nome<<" "<<cognome<<endl;
	
	//Recupero lunghezza stringhe
	int lN=nome.length();
	int lC=cognome.length();
	cout<<lN<<" "<<lC<<endl;
	
	//Controllo se per qualche motivo una delle stringhe e vuota, in tal caso termino il programma
	if((lN==0)||(lC==0))
	{
		cout<<"Una delle stringhe e' vuota";
		return -1;
	}
	
	//Risolvo Punto 1 dell'esercizio - parte 1
	cout<<"Punto 1"<<endl;
	cout<<"Il primo carattere del nome e': "<<nome[0]<<endl;
	cout<<"L'ultimo carattere del nome e': "<< nome[lN-1]<<endl;
	
	
	//Controllo se il secondo e il terzo carattere del cognome esistono
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
		//Risolvo Punto 1 dell'esercizio - parte 2
		cout<<"Il secondo carattere del cognome e': "<<cognome[1]<<endl;
		cout<<"Il terzo e': "<<cognome[2]<<endl;
	}
	
	//Rendo tutto minuscolo - Lo facciamo se non vogliamo distinguere tra maiuscole e minuscole
	int i;
	
	i=0;
	while(nome[i]!='\0')
	{
		if((nome[i]>='A')&&(nome[i]<='Z'))
		{
			nome[i]=nome[i]-'A'+'a';
		}
		i++;
	}
	
	i=0;
	while(cognome[i]!='\0')
	{
		if((cognome[i]>='A')&&(cognome[i]<='Z'))
		{
			cognome[i]=cognome[i]-'A'+'a';
		}
		i++;
	}
	
	//****************************
	//Risolvo punto 2
	
	stringstream shared;
	string shd;
	
	for(i=0;i<lN;i++)
	{
		for(int j=0;j<lC;j++)
		{
			if(nome[i]==cognome[j])
			{
				shd=shared.str();
				int k=0;
				bool nonDuplicato=true;
				while((shd[k]!='\0')&&(nonDuplicato))
				{
					if(shd[k]==nome[i])
						nonDuplicato=false;
					
					k++;
				}
				if(nonDuplicato)
					shared<<nome[i];
			}
		}
	}
	
	//Svuota lo stream
	shared>>shd;
	cout<<"Condivisi: "<<shd<<endl;
	
	
	//***************************
	//Risolvo Punto 3 - 1
	if(nome[0]==cognome[lC-1])
		cout<<"La prima lettera del nome e' uguale all'ultima del cognome"<<endl;
	else
		cout<<"La prima lettera del nome NON e' uguale all'ultima del cognome"<<endl;
	
	//Risolvo Punto 3 - 2
	if(lC==lN)
		cout<<"Nome e cognome hanno la stessa lunghezza"<<endl;
	else
		cout<<"Nome e cognome NON hanno la stessa lunghezza"<<endl;
	
	//Risolvo Punto 3 - 3
	i=0;
	int cNome=0;
	int cCognome=0;
	
	while(nome[i]!='\0')
	{
		if((nome[i]!='a')&&(nome[i]!='e')&&(nome[i]!='i')&&(nome[i]!='o')&&(nome[i]!='u'))
			cNome++;
		i++;
	}
	
	i=0;
	while(cognome[i]!='\0')
	{
		if((cognome[i]!='a')&&(cognome[i]!='e')&&(cognome[i]!='i')&&(cognome[i]!='o')&&(cognome[i]!='u'))
			cCognome++;
		i++;
	}
	
	cout<<"Consonanti nome: "<<cNome<<endl;
	cout<<"Consonanti cognome: "<<cCognome<<endl;
		
	
	
	
	
	return 0;
}