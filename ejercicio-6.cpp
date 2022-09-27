#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
void inicializa(struct cola);
void encola(struct cola &, char[]);
void verCola(struct cola,struct cola,struct cola,struct cola,struct cola,struct cola,struct cola);
int divide(struct cola ,char[]);
void 	encolarep(char[]);
 
  struct nodo{
	char name[20];
	struct nodo * sgte;
};
	char name[20];

struct cola{
	struct nodo * delante;// apunta al primero
	struct nodo * atras;// apunta al ultimo
};

struct cola q,cola1,cola2,cola3,cola4,cola5,cola6;

int main(){
	
int opc;

int n;
inicializa(q);
inicializa(cola1);
inicializa(cola2);
inicializa(cola3);
inicializa(cola4);
inicializa(cola5);
inicializa(cola6);
	while(opc!=3){	
		system("cls");
		cout<<"--no ingrese mas de 4 nombres repetidos--"<<endl;
	    cout<<endl<<"******MENU********"<<endl;
		cout<<"[1] Ingresar Elemento"<<endl;
		cout<<"[2] Ver todas las colas"<<endl;
		cout<<"[3] Salir"<<endl;
		cout<<"Ingrese Opcion: ";
		fflush(stdin);
		cin>>opc;
		switch(opc)
		{
		case 1:	cout<<"Ingresar nombre: ";
				fflush(stdin);
				cin.getline(name,20);
				encola(q,name);
				break;
				
		case 2:	if(q.delante!=NULL){
				verCola(q,cola1,cola2,cola3,cola4,cola5,cola6);
					cout<<endl;
					system("pause");
				}
				else{
					cout<<endl<<"No hay elementos en la cola"<<endl;
					cout<<endl;
					system("pause");
				}
				
				break;
		case 3: exit(0);
		
		}
	}
}

//funciones---------------------------
void inicializa(struct cola s){
	s.delante=NULL;//apunta al primer elemento
 	s.atras=NULL; //apunta al ultimo elemento
}

//INGRESA ELEMENTOS EN LA COLA
void encola(struct cola &q,char n[20]){
	
	struct nodo *p;
	p=new (struct nodo);
	strcpy(p->name,n);
	p->sgte=NULL;
			
	if(q.delante==NULL){
			q.delante=p;				
	}
	 //ingresa el primer elemento
	else{	
		divide(q,n);			
		(q.atras)->sgte=p;
	}
		// si no apunta a un nuevo nodo
	q.atras=p;// la cola apunta al ultimo elemento recientemente ingresado
}


int divide(struct cola q,char dato[20])
{	
	struct nodo *p;
	p=q.delante;// apunta al primer elemento
	
	int rep=0;
	
	while(p!=NULL){
		if(strcmp(p->name,dato)==0){
			rep=1;
		}
		p=p->sgte;	
	}

	if(rep==1){
		encolarep(dato);			
	}
}

void encolarep(char dat[20]){
	int rep=0;
	int rep2=0;
	struct nodo *p;
	p=cola1.delante;
	if(p==NULL){
		encola(cola1,dat);
	}
	else{	
		while(p!=NULL){
			if(strcmp(p->name,dat)==0){
				rep=1;
			}	
		p=p->sgte;	
		}		
		if(rep==1){
			p=cola2.delante;
			while(p!=NULL){
				if(strcmp(p->name,dat)==0){
					rep2=1;
				}	
				p=p->sgte;	
			}
			if(rep2==1){
				encola(cola3,dat);
			}
			else{
				encola(cola2,dat);
			}
		}			
		else{
		encola(cola1,dat);
		}
	}
 main();
}

void verCola(struct cola q,struct cola cola1,struct cola cola2,struct cola cola3,struct cola cola4,struct cola cola5,struct cola cola6)
{
	struct nodo *p;
	p=q.delante;// apunta al primer elementos
	cout<<endl<<"Cola Principal* "<<endl;
	while(p!=NULL)
	{	
		cout<<"nombre: "<<p->name<<" ";
		p=p->sgte;
	}
	p=cola1.delante;
	if(p!=NULL){
		cout<<endl<<"Cola 1* "<<endl;
		
		while(p!=NULL){
			cout<<"nombre: "<<p->name<<" ";
			p=p->sgte;
		}}
	
	p=cola2.delante;
	if(p!=NULL){
	cout<<endl<<"Cola 2* "<<endl;			
		while(p!=NULL){
			cout<<"nombre: "<<p->name<<" ";
			p=p->sgte;
		}
	}
	p=cola3.delante;
	if(p!=NULL){
		cout<<endl<<"Cola 3* "<<endl;				
		while(p!=NULL){
				cout<<"nombre: "<<p->name<<" ";
				p=p->sgte;
		}
	}
	p=cola4.delante;
	if(p!=NULL){
		cout<<endl<<"Cola 4* "<<endl;	
		while(p!=NULL){
			cout<<"nombre: "<<p->name<<" ";
			p=p->sgte;
		}
	}
	p=cola5.delante;		
	if(p!=NULL){
		cout<<endl<<"Cola 5* "<<endl;
		while(p!=NULL){
			cout<<"nombre: "<<p->name<<" ";
			p=p->sgte;
		}
	}
	p=cola6.delante;
	if(p!=NULL){
		cout<<endl<<"Cola 6* "<<endl;
		while(p!=NULL){
		cout<<"nombre: "<<p->name<<" ";
		p=p->sgte;
		}
	}
			
		
}
