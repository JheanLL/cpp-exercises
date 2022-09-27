#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void inicializa(struct cola &);
void encola(struct cola &, char[],char[],char[]);
void verCola(struct cola);
void vaciaCola(struct cola &);
int desencola(struct cola &,cola &,cola &);

struct nodo{
	char name[20];
	char sex[20];
	char age[20];
	struct nodo * sgte;
};
	char name[20];
	char sex[20];
	char age[20];
struct cola{
	struct nodo * delante;// apunta al primero
	struct nodo * atras;// apunta al ultimo
};
struct cola q,cola1,cola2;
int main()
{
int opc;

int n;
inicializa(q);
do{	system("cls");
   cout<<endl<<"******MENU********"<<endl;
	cout<<"[1] Ingresa Elementos"<<endl;
	cout<<"[2] Mostrar todas las colas "<<endl;
	cout<<"[3] Visualizar cola"<<endl;
	cout<<"[4] Salir"<<endl;
	cout<<"Ingrese Opcion: ";
	cin>>opc;
	switch(opc)
	{
	case 1:	cout<<"Ingresar nombre: ";
			    fflush(stdin);
			cin.getline(name,20);
			cout<<"Ingresar sexo(m/f): ";
				fflush(stdin);
			cin.getline(sex,20);
			cout<<"Ingresar edad: ";
				fflush(stdin);
			cin.getline(age,20);
			encola(q,name,sex,age);
				system("pause");
			break;
	case 2:	cout<<"Cola principal: \n";
			verCola(q);	
			cout<<"Cola 1: \n";
         	verCola(cola1);
         	cout<<"Cola 2: \n";
         	verCola(cola2);
			
         	
			if(q.delante==NULL){
			cout<<endl<<"No hay elementos en la cola"<<endl;
			}
			system("pause");
			break;
	case 3: cout<<endl<<"Elementos de la cola:"<<endl;
			verCola(q);
				system("pause");
			break;

	}
}while(opc!=4);
}

//funciones---------------------------
void inicializa(struct cola &q)
{q.delante=NULL;//apunta al primer elemento
 q.atras=NULL; //apunta al ultimo elemento
}

//INGRESA ELEMENTOS EN LA COLA
void encola(struct cola &q,char n[20],char s[20],char a[20])
{
struct nodo *p;
p=new (struct nodo);
strcpy(p->name,n);
strcpy(p->sex,s);
strcpy(p->age,a);
p->sgte=NULL;


if(q.delante==NULL)
	q.delante=p; //ingresa el primer elemento
else{
	if(q.delante->sgte!=NULL){
	desencola(q,cola1,cola2);
	}	
	(q.atras)->sgte=p;// si no apunta a un nuevo nodo
	}	
	
q.atras=p;// la cola apunta al ultimo elemento recientemente ingresado


}


//dividir elementos

int desencola(struct cola &q,struct cola &cola1,struct cola &cola2)
{	
	inicializa(cola1);
	inicializa(cola2);
    nodo *p=q.delante;
 	
   while(p!=NULL){
   	nodo *p2=(q.delante)->sgte;
 	 if(p2)while((strcmp(p->name,p2->name)==0))
      {
       encola(cola1,p->name,p->sex,p->age);
      p2=p2->sgte;
	  }
      p=p->sgte;
   }	
	
}


void verCola(struct cola q){
struct nodo *p;
p=q.delante;// apunta al primer elementos
while(p!=NULL)
{	
	cout<<"nombre: "<<p->name<<" ";
	cout<<"sexo: "<<p->sex<<" ";
	cout<<"edad: "<<p->age<<endl;
	p=p->sgte;
}

}




