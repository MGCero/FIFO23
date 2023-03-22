#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include <vector>

using namespace std;

struct corredor
{
	char nombre[30];
	int num,num_vueltas = 0;
	float promedio;
	float tiempo = 0;
	corredor *siguiente;
};
corredor *primero, *aux, *lifo, *fifo; //= NULL;
int num_corredores;

void ingresar_corredor()
{
	system("cls");
	corredor *aux = new corredor();
	cout<<"ingrese el nombre del corredor: "; cin>>aux->nombre;
	cout<<endl<<"ingrese el documento del corredor: "; cin>>aux->num;
	aux->siguiente = NULL;
	
	if(primero==NULL)
	{
		primero=aux;
	}
	else
	{
		corredor *aux2 = primero;
		while(aux2->siguiente!=NULL) aux2 = aux2->siguiente;
		
		aux2->siguiente=aux;
		aux2=NULL;
		aux=NULL;
	}
	
	num_corredores++;
}
void hacer_prueba()
{
	system("cls");
	int n;
	
	
	for(corredor *aux = primero; aux!=NULL; aux=aux->siguiente)
	{
		cout<<"nombre: "<<aux->nombre;
		cout<<endl<<"documento: "<<aux->num;
		cout<<'\n';
	}
	
	cout<<endl<<endl<<"ingrese el numero del corredor: ";
	cin>>n;
	
	aux = primero;
	bool encontrado = false;
	for(primero; primero!=NULL; primero=primero->siguiente)
	{
		if(n==primero->num)
		{
			int v;
			float aux_prom = 0;
			float tiempo, menorTiempo = 0;
			cout<<endl<<"cuantas vueltas hara el corredor: ";
			cin>>v;
			primero->num_vueltas+=v;
			for(int i =0;i<v;i++){
				
				tiempo = 1+rand() % 100;
				aux_prom += tiempo;	
				cout<<endl<<"tiempo de la vuelta "<<i+1<<": "<<tiempo;
				if(i == 0) menorTiempo = tiempo;	
				if(tiempo < menorTiempo) menorTiempo = tiempo;
			}
			primero->tiempo = menorTiempo;
			aux_prom=aux_prom/v;
			primero->promedio = aux_prom;
			encontrado = true;
			cout<<endl;
			system("pause");
		}
	}
	primero=aux;
	aux=NULL;
	free(aux);
	if(!encontrado) 
	{
		cout<<endl<<"no se encontro el corredor"<<endl;
		system("pause");
	}
}


void mostrar_tiempos()
{
	system("cls");
	vector<corredor> corredores(num_corredores);
	int i = 0;
	corredor corrAux;
	fifo=NULL;
	if(primero!=NULL)
	{
		for(corredor *a = primero; a!= NULL; a=a->siguiente)
		{
			strcpy(corredores[i].nombre,a->nombre);
			corredores[i].num = a->num;
			corredores[i].num_vueltas = a->num_vueltas;
			corredores[i].promedio = a->promedio;
			corredores[i].tiempo = a->tiempo;
			i++;
		}
		for(i = 0; i < num_corredores; i++)
		{
			for(int e = 0; e < num_corredores; e++)
			{
				if(corredores[e].tiempo > corredores[e+1].tiempo)
				{
					if(e+1 < num_corredores)
					{
						corrAux = corredores[e];
						corredores[e]=corredores[e+1];
						corredores[e+1]=corrAux;
					}
				}
			}
		}
		
		for(i = 0; i < num_corredores; i++)
		{
			corredor *AUX = (struct corredor *) malloc (sizeof(struct corredor));
			corredor *AUX2 = (struct corredor *) malloc (sizeof(struct corredor));
			AUX=&corredores[i];
			
			if(fifo==NULL)
	        {
	            fifo = AUX;
	            fifo->siguiente = NULL;
	        }else
	        {
	            AUX->siguiente=NULL;
	            AUX2=fifo;
	            while(AUX2->siguiente!=NULL) AUX2 = AUX2->siguiente;
	            AUX2->siguiente = AUX;
				AUX2=NULL;
				AUX=NULL;
				free(AUX2);
				free(AUX);
	        }
		}
		
		for(corredor *auxfifo = fifo; auxfifo!=NULL; auxfifo=auxfifo->siguiente)
		{
			cout<<"menor tiempo: "<<auxfifo->tiempo;
			cout<<endl<<"nombre: "<<auxfifo->nombre;
			cout<<endl<<"corredor: "<<auxfifo->num;
			cout<<endl<<"numero de vueltas: "<<auxfifo->num_vueltas;
			cout<<endl<<"promedio: "<<auxfifo->promedio;
			cout<<endl<<endl;
		}
		
	}
	else cout<<"aun no hay corredores registrados";
	cout<<endl;
	system("pause");
	
}

void mostrar_promedio()
{
	system("cls");

	vector<corredor> corredores(num_corredores);
	int i = 0;
	corredor corrAux;
	lifo=NULL;
	if(primero!=NULL)
	{
		for(corredor *a = primero; a!= NULL; a=a->siguiente)
		{
			strcpy(corredores[i].nombre,a->nombre);
			corredores[i].num = a->num;
			corredores[i].num_vueltas = a->num_vueltas;
			corredores[i].promedio = a->promedio;
			i++;
		}
		for(i = 0; i < num_corredores; i++)
		{
			for(int e = 0; e < num_corredores; e++)
			{
				if(corredores[e].promedio > corredores[e+1].promedio)
				{
					if(e+1 < num_corredores)
					{
						corrAux = corredores[e];
						corredores[e]=corredores[e+1];
						corredores[e+1]=corrAux;
					}
				}
			}
		}
		
		for(i = 0; i < num_corredores; i++)
		{
			corredor *AUX = (struct corredor *) malloc (sizeof(struct corredor));
			AUX=&corredores[i];
			if(lifo==NULL)
	        {
	            lifo = AUX;
	            lifo->siguiente = NULL;
	        }else
	        {
	            AUX->siguiente = lifo;
	            lifo = AUX;
	
	        }
	        AUX=NULL;
	       	free(AUX);
		}
		
		for(corredor *auxlifo = lifo; auxlifo!=NULL; auxlifo=auxlifo->siguiente)
		{
		
			if(auxlifo->num_vueltas > 1)
			{
				cout<<"nombre: "<<auxlifo->nombre;
				cout<<endl<<"corredor: "<<auxlifo->num;
				cout<<endl<<"numero de vueltas: "<<auxlifo->num_vueltas;
				cout<<endl<<"promedio: "<<auxlifo->promedio;
				cout<<endl<<endl;
			}
		}
		
	}
	else cout<<"aun no hay corredores registrados";
	cout<<endl;
	system("pause");
}
void mostrar_corredores()
{
	system("cls");
	cout<<"NUMERO DE CORREDORES: "<<num_corredores<<'\n';
	for(corredor *aux = primero; aux!=NULL; aux=aux->siguiente)
	{
		cout<<"nombre: "<<aux->nombre;
		cout<<endl<<"corredor: "<<aux->num;
		cout<<endl<<"numero de vueltas: "<<aux->num_vueltas;
		cout<<endl<<"promedio: "<<aux->promedio;
		cout<<endl<<"menor tiempo: "<<aux->tiempo;
		cout<<endl<<endl;
	}
	system("pause");
}



int main()
{
	int op;
	do
	{
		system("cls");
		cout<<"1. ingresar corredor"<<endl<<"2. mostrar corredores"<<endl<<"3. hacer vuelta"<<endl;
		cout<<"4. mostrar promedios"<<endl<<"5. mostrar tiempos"<<endl<<"6. salir"<<endl<<"--> ";
		cin>>op;
		
		switch(op)
		{
			case 1:
				ingresar_corredor();
			break;
			
			case 2:
				mostrar_corredores();
			break;
			
			case 3:
				hacer_prueba();
				break;
			case 4:
				mostrar_promedio();
				break;
			case 5:
				mostrar_tiempos();
				break;
			default:
				system("cls");
				cout<<endl<<endl<<"la opcion no existe"<<endl<<endl;	
				system("pause");
			break;
		}
		
	}while(op!=6);
} 
