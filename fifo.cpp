#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

using namespace std;

struct paciente
{
	char nombre[30];
	int doc;
	paciente *siguiente;
};
paciente *primero = NULL;

void ingresar_paciente()
{
	system("cls");
	paciente *aux = new paciente();
	cout<<"ingrese el nombre del paciente: "; cin>>aux->nombre;
	cout<<endl<<"ingrese el documento del paciente: "; cin>>aux->doc;
	aux->siguiente = NULL;
	
	if(primero==NULL)
	{
		primero=aux;
	}
	else
	{
		paciente *aux2 = primero;
		while(aux2->siguiente!=NULL) aux2 = aux2->siguiente;
		
		aux2->siguiente=aux;
		aux2=NULL;
		aux=NULL;
	}
	
	
}

void mostrar_pacientes()
{
	system("cls");
	for(paciente *aux = primero;aux!=NULL;aux = aux->siguiente)
   {
    cout<<"nombre: "<<aux->nombre<<endl;
    cout<<"documento: "<<aux->doc<<endl;
    cout<<"\n";
    
   }
   system("pause");
}

int main()
{
	int op;
	do
	{
		system("cls");
		cout<<"1. ingresar paciente"<<endl<<"2. mostrar paciente"<<endl<<"3. salir"<<endl<<"--> ";
		cin>>op;
		if(op<1||op>3) 
		{
			system("cls");
			cout<<endl<<endl<<"la opcion no existe";	
			sleep(2);
		}
		switch(op)
		{
			case 1:
				ingresar_paciente();
				break;
			case 2:
				mostrar_pacientes();
				break;
		}
		
	}while(op!=3);
}






// primero -> juan / siguiente -> NULL
// ultimo -> pedro / siguiente -> pedro