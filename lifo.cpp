
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct nodo
{
    int val;
    char color[10];
    nodo *sig;
};

nodo *cab,*aux;

struct color{
    int val;
    char color[10];
} colores [5] = {
    {50, "morado"},
    {40, "azul"},
    {30, "rojo"},
    {20, "amarillo"},
    {10, "verde"}
};

 int opc=0,opc1;

int main();
void registrar();
void consultar();
void eliminar();

void registrar()
{  
    system("cls");
        cout<<"********************"<<endl;
        cout<<"REGISTRAR DATOS"<<endl;
        cout<<"********************"<<endl;
      for(int i = 0;i<5;i++)
      {
        aux = (struct nodo *) malloc(sizeof(struct nodo));
        aux->val = colores[i].val;
        strcpy(aux->color,colores[i].color);
        if(cab==NULL)
        {
            cab = aux;
            cab->sig = NULL;
        }else
        {
            aux->sig = cab;
            cab = aux;

            aux=NULL;
            free(aux);
        }

      }  

             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>opc;

            if(opc==1)
            {
                main();
            }else if(opc==2)
            {
                registrar();
            }else if(opc==3)
            {
                exit(0);
            }
}

void eliminar()
{
    if(cab!=NULL)
    {
        aux = cab;
        cab = cab->sig;
        free(aux);

    }else
    {
        cout<<" no hay nada para eliminar";
    }
    consultar();
    cout<<"n";
             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>opc;

            if(opc==1)
            {
                main();
            }else if(opc==2)
            {
                eliminar();
            }else if(opc==3)
            {
                exit(0);
            }

}

void consultar()
{
    system("cls");
    cout<<"********************"<<endl;
    cout<<"CONSULTANDO DATOS"<<endl;
    cout<<"*******************"<<endl;
    for(aux = cab;aux!=NULL;aux = aux->sig)
    {
        cout<<aux->val<<" Color: "<<aux->color<<endl;
    }

    
             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>opc;

            if(opc==1)
            {
                main();
            }else if(opc==2)
            {
                consultar();
            }else if(opc==3)
            {
                exit(0);
            }

}

void menu()
{
   
    do
    {
    system("cls");
   
    cout<<"**********************************"<<endl;
    cout<<" 1.registrar datos."<<endl;
    cout<<" 2.consultar datos."<<endl;
    cout<<" 3.eliminar datos."<<endl;
    cout<<" 4.salir."<<endl;
    cout<<"**********************************"<<endl;
    cout<<"digite la opcion que desee -> ";cin>>opc;

        switch (opc)
        {
        case 1: registrar();
            break;
        case 2: consultar();
            break;    
        case 3: eliminar();
            break;
        case 4: exit(0);
            break;
        
        }
        if(opc>4)
        {
            cout<<" LA OPCION SELECCIONADA NO EXISTE. "<<endl;
        
        
            cout<<" DESEA CONTINUAR 1.SI/2.NO. -> ";cin>>opc1;
        }
        
    }while (opc1==1);
    
}

int main(){
    
    menu();
    
    
    return 0;
}