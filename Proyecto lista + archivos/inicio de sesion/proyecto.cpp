#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Nodo{
 char name[20];
 char dir[20];
 int edad;
 
 char comida[15]="nada";
 char comida2[15]="nada x2";
 char comida4[15]="nada x3";
 char price[15]="S/. 594.45";
 
 Nodo *siguiente;
 	
};

Nodo *lista = NULL;

char name[20];
char dir[20];
int edad;

void inicio();
void menu();
void insertarlista(Nodo *&,char[],char[],int);
void eliminarnodo(Nodo *&,char[],char[],int);
void buscarlista(Nodo *&,char[],char[],int);
void mostrarlista(Nodo *);
void eliminarlista(Nodo *&,char[],char[],int);
void ordenar(Nodo *&,char[],char[],int);
void escribir(Nodo *&);
void leer(Nodo *&);
char sesion[20];
void gotoxy(int x,int y);
void recuadro(int x1,int y1,int x2,int y2);

void recuadro(int x1,int y1,int x2,int y2){
	int i;

//lineas horizontales	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304";
		gotoxy(i,y2); cout << "\304";
    }
//lineas verticales
    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263";
		gotoxy(x2,i); cout <<"\263";
	}
	
    gotoxy(x1,y1);cout<<"\332";
    gotoxy(x1,y2);cout<<"\300";
    gotoxy(x2,y1);cout<<"\277";
    gotoxy(x2,y2);cout<<"\331";
}

void gotoxy (int x, int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), pos);
}

int main(){
	
	system("mode con: cols=70 lines=25");
	recuadro(0,0,68,24);
	
 inicio();

 return 0;
}

void menu(){
 int opc;

 do{
  system("cls");
  recuadro(0,0,68,24);
  gotoxy(30,1);cout<<" MENU PRINCIPAL\n"<<endl;
  gotoxy(2,3);cout<<" 1. mostrar clientes"<<endl;
  gotoxy(2,4);cout<<" 2. Recibos(x)"<<endl;
  gotoxy(2,5);cout<<" 3. Cambiar direccion de envio(x)"<<endl;
  gotoxy(2,6);cout<<" 4. comprar(x)"<<endl;
  gotoxy(2,7);cout<<" 4. eliminar cuenta(x)"<<endl;
  gotoxy(2,8);cout<<" 6. Cerrar sesion"<<endl;
  gotoxy(2,9);cin>>opc;
  
  switch(opc){
   case 1:  system("cls");
   			gotoxy(2,2);cout<<"clientes: ";
   			gotoxy(2,3);mostrarlista(lista);
   			gotoxy(2,4);getch();
   			
   break;
   case 2: 
   system("pause");
   break;
   case 3: break; 
   case 4:  break;
   case 5:  break; 
   case 6: break;
   case 7:  break; 
  
  }
  system("cls");
 }while(opc != 6);
}

void insertarlista(Nodo *&lista,char n[20],char d[20],int f){
 
	 cout<<"ingresar nombre de usuario: ";
	 fflush(stdin);
		cin.getline(name,20);
	 cout<<"ingresar la direccion de envio: ";
	    cin>>dir;	
	    
 Nodo *nuevo_nodo = new Nodo();
 
 strcpy(nuevo_nodo->name,name);
 strcpy(nuevo_nodo->dir,dir);
 nuevo_nodo->siguiente=NULL;

 Nodo *aux1 = lista;
 
 if(aux1 == NULL){
  lista = nuevo_nodo;
 }
 else{
  while(aux1->siguiente!=NULL){
  	aux1=aux1->siguiente;
  }
  aux1->siguiente = nuevo_nodo;
 }
 
 escribir(lista);
}

void escribir(Nodo *&){
 
 Nodo *aux2 = lista;
 
 ofstream f2;
 f2.open("lista.txt",ios::app);
 while(aux2->siguiente!=NULL){
  	aux2=aux2->siguiente;
  }
 f2<<aux2->name<<" "<<aux2->dir<<"\n";	
 
 f2.close();

}

void leer(Nodo *&){	  
 ifstream f1;
 f1.open("lista.txt",ios::in);
 lista = NULL;

  while(!f1.eof()){	
	f1>>name;
	f1>>dir;
	if(!f1.eof()){

		 Nodo *actual2 = new Nodo();
			strcpy(actual2->name,name);
			strcpy(actual2->dir,dir);
			actual2->siguiente=NULL;
				  
			Nodo *aux1 = lista;
 
			 if(aux1 == NULL){
			  lista = actual2;
			 }
			 else{
			  while(aux1->siguiente!=NULL){
			  	aux1=aux1->siguiente;
			  }
			  aux1->siguiente = actual2;
			 }
		}
   }
   
 f1.close();

}

void inicio(){
 int op=0;

 do{
    system("cls");
    recuadro(0,0,68,24);
 	recuadro(21,1,45,3);gotoxy(22,2); cout << "   T I E N D A  265  "; 
 	gotoxy(2,5);cout<<"1.Iniciar sesion."<<endl;
	gotoxy(2,6);cout<<"2.Crear cuenta."<<endl;
    gotoxy(2,7);cin>>op;
    
    while(op<1 || op>2){	
		gotoxy(2,8);cout<<"ingrese una opcion correcta: ";cin>>op;;
	}
   
   system("cls");
   switch(op){
   	
	   case 1: buscarlista(lista,dir,name,edad);
	   break;
	   
	   case 2: insertarlista(lista,dir,name,edad);
	   break;	   
   }
 }while(op == 1 || op == 2);
 	
}

void buscarlista(Nodo *&lista,char n[20],char d[20],int f){
  char tem[20];
  
  leer(lista);
  
  cout<<"ingresar nombre de usuario: ";
   fflush(stdin);
   cin.getline(tem,20);
   
 Nodo *actual = new Nodo();
 actual = lista;
 bool band = false;
 
 while(actual!=NULL){
  if(strcmp(actual->name,tem)==0){
   band = true;
  }
  actual = actual->siguiente;
 }
 
 if(band == true){
   menu();
 }
 else{
  cout<<"usuario no registrado."<<endl;
  getch();
  inicio();
 }

}

void mostrarlista(Nodo *lista){

 Nodo *actual = lista;
 
 while(actual!=NULL){
  cout<<actual->name<<"  ";
  cout<<actual->dir<<endl;

  actual = actual->siguiente;
 }
 
}

void eliminarlista(Nodo *&lista,char n[20],char d[20],int f){
 char opc;
 
 cout<<"¿Seguro de eliminar todos los elementos de la lista? (S/N): ";
 cin>>opc;
 
 while(lista != NULL){
 Nodo *aux = lista;
 n = aux->dir;
 lista = aux->siguiente;
 delete aux;
 }
 if(((opc == 'S')||(opc == 's'))){
  cout<<"\tTodos los elementos de la lista han sido eliminados.\n"<<endl;
 }
 else{
  cout<<"\tVolver.\n"<<endl;
 }
}

void ordenar(Nodo *&lista,char n[20],char d[20],int f){
 Nodo *i = lista;
 char aux2[20];
 
	while(i!=NULL){
	 	Nodo *j = i->siguiente;
		 	
		while(j!=NULL){
		 	if(i->edad>j->edad){
		 		int aux = j->edad;
		 		j->edad = i->edad;
		 		i->edad = aux;
		 		
		 		strcpy(aux2 , j->name);
		 		strcpy(j->name, i->name);
		 		strcpy(i->name, aux2);
		 		
		 		strcpy(aux2 , j->dir);
		 		strcpy(j->dir, i->dir);
		 		strcpy(i->dir, aux2);
			 }
			 j = j->siguiente;        
	    }
	    i=i->siguiente;
	}
}
