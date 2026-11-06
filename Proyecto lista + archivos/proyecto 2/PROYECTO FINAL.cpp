#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#define lim 50
#include <time.h>

using namespace std;

struct nodo{
	int cod;
	char nom[20];
	int ed;
	char sex[20];
	char date[20];
	char pass[20];
	struct nodo *sgte;
};

int cod;
char nom[20];
int ed;
char sex[20];
char date[20];
char pass[20];
typedef struct nodo *tlista;

void menu();
void gotoxy(int x,int y);
void recuadro(int x1,int y1,int x2,int y2);
void insertar(tlista&, int, char[], int, char[], char[]);
void mostrar(tlista);
void buscar(tlista);
void modificar(tlista);
void escribir(nodo *&);
void leer(nodo *&);
void inicio();
void imprimir(nodo *&);


void recuadro(int x1,int y1,int x2,int y2){
	int i;

//lineas horizontales
    for(i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304";
		gotoxy(i,y2); cout << "\304";
    }
//lineas verticales
    for(i=y1;i<y2;i++){
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

nodo *lista2 = NULL;
nodo *lista  = NULL;

void leer2(nodo *&);
void buscar2(tlista);
void escribir2(nodo *&);

void leer2(nodo *&lista2){
 ofstream f2;
 f2.open("inicio.txt",ios::app);
 f2.close();
 ifstream f1;
 f1.open("inicio.txt",ios::out);
 if(f1.fail()){
 	gotoxy(4,6);cout<<"No hay datos en el archivo";
 	getch();
 	inicio();
 }
 lista2 = NULL;

  while(!f1.eof()){	
	f1>>nom>>pass;	
	if(!f1.eof()){
		 nodo *actual2 = new nodo();
			strcpy(actual2->nom,nom);
			strcpy(actual2->pass,pass);	
			actual2->sgte=NULL;
				  
			nodo *aux1 = lista2;
			 if(aux1 == NULL){
			  lista2 = actual2;
			 }
			 else{
			  while(aux1->sgte!=NULL){
				aux1=aux1->sgte;}
			  aux1->sgte = actual2;
			 }
		}
   }  
 f1.close();
}

void buscar2(tlista lista2){
	system("cls");
	int i=0;
	char passb[20];
	char nomb[20];
	recuadro(0,0,79,24);
	
	gotoxy(15,9);cout<<"Nombre: ";
	fflush(stdin);
	cin.getline(nomb,20);
	gotoxy(15,11);cout<<"password: ";
	fflush(stdin);
	cin.getline(passb,20);
	leer2(lista2); 	

	while(lista2!=NULL){		 
		if(strcmp(lista2->nom,nomb)==0){
			if(strcmp(lista2->pass,passb)==0){	
			i=1;}
			
			else{
			system("cls");
			gotoxy(3,3);cout<<"contrasena incorrecta: ";
			i=0;
			getch();
			inicio();	
			}		
		}
	lista2 = lista2->sgte;
	}
	if(i==0){
	system("cls");
	gotoxy(7,5);cout<<"No se encontro el nombre de usuario";
	getch();
	inicio();
	}
	else{
	menu();
	}
}		

void inicio(){
 	int op=0;
	tlista lista2=NULL;
 do{
    system("cls");  
    recuadro(0,0,79,24);
    
    gotoxy(8,2); cout << "    E S T U D I A N T E S   D E    L A    F A C U L T A D   "; 
	gotoxy(18,3); cout<<"     D E    I N G.    S I S T E M A S    ";
 
 	gotoxy(4,6);cout<<"1.Iniciar sesion"<<endl;
	gotoxy(4,7);cout<<"2.Crear cuenta"<<endl;
	gotoxy(4,8);cout<<"3.Salir"<<endl;
    gotoxy(4,9);cin>>op;
    
    while(op<1 || op>3){	
		gotoxy(2,8);cout<<"ingrese una opcion correcta: ";cin>>op;;
	}
   	char passb[20];
	char nomb[20];
   system("cls");
   switch(op){
   	
	   case 1:{
	    buscar2(lista2);
		break;
	   } 
	   case 2: {
	   			 recuadro(0,0,79,24);
	   			leer2(lista2);
				gotoxy(15,9);cout<<"Nombre: ";
			   fflush(stdin);
			   cin.getline(nomb,20);
				gotoxy(15,11);cout<<"password: ";
			   fflush(stdin);
			   cin.getline(passb,20);
	      
	   			tlista t;
				tlista q=new(struct nodo);
				
				strcpy(q->nom,nomb);
				strcpy(q->pass,passb);
				q->sgte=NULL;
				
				if(lista2==NULL) lista2=q;
				else{
					t=lista2;
					while(t->sgte!=NULL)t=t->sgte;
					t->sgte=q;
				}
			 escribir2(lista2);
		break;
	   }
		   
	   case 3:{	exit(0);
				break;
	   }  	 
	  				   
   }
 }while(op!=3);	
}

void escribir2(nodo *&lista2){
ofstream f2;
f2.open("inicio.txt",ios::out);	
nodo *aux2 = lista2;
	while(aux2!=NULL){		
		f2<<aux2->nom<<" "<<aux2->pass<<endl;					
		aux2=aux2->sgte;
 	}
f2.close();			 
}

void escribir(nodo *&lista){
 ofstream f2;
 f2.open("lista.txt",ios::out);
 nodo *aux2 = lista;
 while(aux2!=NULL){		
	f2<<aux2->cod<<" "<<aux2->nom<<" "<<aux2->ed<<" "<<aux2->sex<<" "<<aux2->date<<"\n";	
	
	aux2=aux2->sgte;
 }
 f2.close();
}

void leer(nodo *&lista){
 ofstream f2;
 f2.open("lista.txt",ios::app);
 f2.close();	  
 ifstream f1;
 f1.open("lista.txt",ios::out);
 if(f1.fail()){
 	gotoxy(4,6);cout<<"No hay datos en el archivo";
 	getch();
 	menu();
 }
 lista=NULL;
  while(!f1.eof()){	
	f1>>cod>>nom>>ed>>sex>>date;	
	if(!f1.eof()){
		 nodo *actual2 = new nodo();
			(actual2->cod=cod);
			strcpy(actual2->nom,nom);
			(actual2->ed=ed);
			strcpy(actual2->sex,sex);
			strcpy(actual2->date,date);
			actual2->sgte=NULL;
				  
			nodo *aux1 = lista;
 
			 if(aux1 == NULL){
			  lista = actual2;
			 }
			 else{
			  while(aux1->sgte!=NULL){
				aux1=aux1->sgte;
			  }
			  aux1->sgte = actual2;
			 }
		}
   }   
 f1.close();
}

void insertar(tlista& lista, int cod, char nom[], int ed, char sex[], char date[]){
	recuadro(0,0,79,24);
	tlista t;
	leer(lista);
	tlista q=new(struct nodo);
	q->cod=cod;
	strcpy(q->nom,nom);
	q->ed=ed;
	strcpy(q->sex,sex);
	strcpy(q->date,date);
	q->sgte=NULL;
	
	if(lista==NULL) lista=q;
	else{
		t=lista;
		while(t->sgte!=NULL){
		t=t->sgte;	
		}
		t->sgte=q;
	}
	escribir(lista);	
}

void mostrar(tlista lista){
	system("mode con: cols=80 lines=120");
		
	HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //almacena las dimensiones actuales de la consola

    MoveWindow(console, r.left, r.top, 655, 450, TRUE); // 655 ancho, 450 alto
	leer(lista);
	system("cls");
	int i=1;
	recuadro(0,0,76,118);
	gotoxy(2,2); cout<<"LISTA DE ESTUDIANTES:"<<endl;
		
	while(lista!=NULL){
		cout<<"\n\t["<<i<<"] ""Codigo 	     : "<<lista->cod;
		cout<<"\n\t["<<i<<"] ""Nombre	     : "<<lista->nom;
		cout<<"\n\t["<<i<<"] ""Edad   	     : "<<lista->ed;
		cout<<"\n\t["<<i<<"] ""Sexo   	     : "<<lista->sex;
		cout<<"\n\t["<<i<<"] ""Fecha de ingreso : "<<lista->date<<endl;
		cout<<"\t";
		
		lista = lista->sgte;
		i++;
	}	
}

void buscar(tlista lista){
	system("cls");
	nodo *aux = new nodo();	
	int i=0;
	int y=4;
	char opc;
	leer(lista);
	char nombb[lim];
	recuadro(0,0,79,24);
	gotoxy(3,1); cout<<"Ingrese nombre a buscar: ";
	cin>>nombb;

	while(lista!=NULL){
		if(strcmp(lista->nom,nombb)==0){
			recuadro(15,4,65,17);
			gotoxy(21,5); cout << "C A R N E T    U N I V E R S I T A R I O";
			gotoxy(18,8);cout<<"Codigo  	    	: "<<lista->cod;y++;
			gotoxy(18,9);cout<<"Nombre  	    	: "<<lista->nom;y++;
			gotoxy(18,10);cout<<"Edad     	    	: "<<lista->ed;y++;
			gotoxy(18,11);cout<<"Sexo     	    	: "<<lista->sex;y++;
			gotoxy(18,12);cout<<"Fecha de ingreso   	: "<<lista->date;y++;y++;
			gotoxy(18,15.9);cout<<"Ingenieria de Sistemas";
			gotoxy(60,16);cout<<"2022";
			i++;
			
			(aux->cod=lista->cod);
			strcpy(aux->nom,lista->nom);
			(aux->ed=lista->ed);
			strcpy(aux->sex,lista->sex);
			strcpy(aux->date,lista->date);
		}		
	lista = lista->sgte;
	}

	if(i==0){
	gotoxy(7,5);cout<<"No se encontro estudiante"<<endl;
		getch();
		menu();
	}
	gotoxy(2,19);cout<<"-Presione 'S' para imprimir: ";
	gotoxy(2,20);cout<<"-Presione 'F' para Filtrar alumnos por codigo: ";
	opc=getch();
	if(opc=='s' || opc=='S'){
		imprimir(aux);
	}
	
	if(opc=='F' || opc=='f'){
		system("cls");
		int codd;
		recuadro(0,0,79,24);
		gotoxy(3,1);cout<<"Ingrese el codigo a buscar: ";cin>>codd;
		leer(lista);		
		int i=0;
		int y=4;
		char opc;	
			while(lista!=NULL){
				if(lista->cod==codd){
					recuadro(15,4,65,17);
					gotoxy(21,5); cout << "C A R N E T    U N I V E R S I T A R I O";
					gotoxy(18,8);cout<<"Codigo  	    	: "<<lista->cod;y++;
					gotoxy(18,9);cout<<"Nombre  	    	: "<<lista->nom;y++;
					gotoxy(18,10);cout<<"Edad     	    	: "<<lista->ed;y++;
					gotoxy(18,11);cout<<"Sexo     	    	: "<<lista->sex;y++;
					gotoxy(18,12);cout<<"Fecha de ingreso  	: "<<lista->date;y++;y++;
					gotoxy(18,15.9);cout<<"Ingenieria de Sistemas";
					gotoxy(60,16);cout<<"2022";
					i++;
					
					(aux->cod=lista->cod);
					strcpy(aux->nom,lista->nom);
					(aux->ed=lista->ed);
					strcpy(aux->sex,lista->sex);
					strcpy(aux->date,lista->date);
				}		
			lista = lista->sgte;
			}
			if(i==0){
			gotoxy(7,5);cout<<"No se encontro estudiante"<<endl;
				getch();
				menu();
			}
			
		gotoxy(2,19);cout<<"-Presione 'S' para imprimir: ";
		opc=getch();
		if(opc=='s' || opc=='S'){
			imprimir(aux);
		}
	menu();			
	}
}

void modificar(tlista lista){
	system("cls");
	leer(lista);
	char tem[20], modnomb[lim];
	int temp, opc, i=0;
	recuadro(0,0,79,24);
	gotoxy(3,3); cout<<"Ingrese nombre a buscar: ";
	cin>>modnomb;
	nodo *listatem = NULL;
	listatem = lista;
	
	while(lista!=NULL){		 
		if(strcmp(lista->nom,modnomb)==0){		
			i++;
		while(opc!=6){
		system("cls");
		recuadro(0,0,79,24);
		gotoxy(3,3);cout<<"EDITAR DATOS ";
		gotoxy(7,6);cout<<"1) Codigo  	    	: "<<lista->cod; 
		gotoxy(7,8);cout<<"2) Nombre  	    	: "<<lista->nom; 
		gotoxy(7,10);cout<<"3) Edad     	    	: "<<lista->ed; 
		gotoxy(7,12);cout<<"4) Sexo     	    	: "<<lista->sex; 
		gotoxy(7,14);cout<<"5) Fecha de ingreso      : "<<lista->date; 
		gotoxy(7,16);cout<<"6) salir    "; 
		gotoxy(7,18);cout<<"seleccione una opcion: ";cin>>opc;	
		
		switch(opc){
				case 1:{
					gotoxy(6,20);cout<<"ingrese el codigo: ";
					cin>>cod;
					swap(lista->cod,cod);
								
					break;
				}
				case 2:{
					gotoxy(6,20);cout<<"ingrese el nombre: ";
					cin>>nom;
					swap(lista->nom,nom);
					break;
				}
				case 3:{
					gotoxy(6,20);cout<<"ingrese la edad: ";
					cin>>ed;
					swap(lista->ed,ed);
					break;
				}
				case 4:{
					gotoxy(6,20);cout<<"ingrese el sexo: ";
					cin>>sex;
					swap(lista->sex,sex);
					break;
				}
				case 5:{
					gotoxy(6,20);cout<<"ingrese la fecha : ";
					cin>>date;
					swap(lista->date,date);
	
					break;
				}
				case 6:{	
					escribir(listatem);
					mostrar(lista);
					getch();
					menu();	
					break;	
				}
				
			}
		}
	}		
	lista = lista->sgte;
	}	
	if(i==0){
	gotoxy(7,5);cout<<"No se encontro estudiante"<<endl;
	getch();
	menu();
	}
	
	
}



void imprimir(nodo *&aux){
	time_t t = time(NULL);
	struct tm *fecha; 
	fecha=localtime(&t);
	ofstream f2;
	f2.open("Imprimir.txt",ios::out);
	gotoxy(19,10); f2<<"	                    UNIVERSIDAD NACIONAL"<<endl<<endl;
	gotoxy(20,10); f2<<"CARNET DE ESTUDIANTE  "<<endl;
	f2<<"  Facultad: Ingenieria de sistemas e ingenieria civil"<<endl;
	f2<<"  Escuela:  Ingenieria de sistemas                           "<<fecha->tm_mday<<"/"<<fecha->tm_mon+1<<"/"<<fecha->tm_year+1900<<"  "<<fecha->tm_hour<<":"<<fecha->tm_min<<":"<<fecha->tm_sec<<endl;
	f2<<"-----------------------------------------------------------------------------------"<<endl;
	f2<<endl<<"  Nombre: "<<aux->nom<<endl<<"  Codigo: "<<aux->cod<<endl<<"  Edad: "<<aux->ed<<endl<<"  Sexo: "<<aux->sex<<endl<<"  Fecha de ingreso: "<<aux->date<<endl<<endl;
	f2<<"-----------------------------------------------------------------------------------"<<endl;
	f2.close();
	gotoxy(31,19);cout<<"Informacion guardada";
	system("NOTEPAD /P imprimir.txt");
}

int main(){	
	system("mode con: cols=80 lines=25");
	system("COLOR F0");
	
	recuadro(0,0,79,24);
	recuadro(7,1,71,4);
	
	PlaySound(TEXT("made.wav"), NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(0,0,0);
	inicio();	
	menu();
	
	return 0;
}

void menu(){
	
	int opc, edad, codigo, i, n;
	char nombre[lim], sexo[lim], fecha[lim];
	do{ system("mode con: cols=80 lines=25");
		system("cls");
		
		recuadro(0,0,79,24);
		gotoxy(4,6); cout<<"Lista de estudiantes(+)";
		gotoxy(4,9); cout<<"1. Insertar ";
		gotoxy(4,11);cout<<"2. Mostrar ";
		gotoxy(4,13);cout<<"3. Buscar ";
		gotoxy(4,15);cout<<"4. Modificar ";
		gotoxy(4,17);cout<<"5. Cerrar sesion ";
		gotoxy(4,19);cout<<"Ingrese opcion: ";
		cin>>opc;		
		switch(opc){		
			case 1: system("cls");
			recuadro(0,0,79,24);
			gotoxy(1,1); cout<<"Ingrese cantidad de alumnos: ";
			cin>>n;
			
			for(i=0;i<n;i++){
				system("cls");
				recuadro(0,0,79,24);
				gotoxy(4,7);cout<<"Codigo "<<"		: ";
				cin>>codigo;
				gotoxy(4,9);cout<<"Nombre "<<"		: ";
				fflush(stdin);
				cin.getline(nombre,20);
				gotoxy(4,11);cout<<"Edad   "<<"		: ";
				cin>>edad;
				gotoxy(4,13);cout<<"Sexo   "<<"		: ";
				fflush(stdin);
				cin.getline(sexo,20);
				gotoxy(4,15);cout<<"Fecha de ingreso   "<<"	: ";
				fflush(stdin);
				cin.getline(fecha,20);
				insertar(lista, codigo, nombre, edad, sexo, fecha);
			}
			break;
			
			case 2: system("cls");
			mostrar(lista);
			getch();
			break;
			
			case 3: buscar(lista);
			getch();
			break;
			
			case 4: modificar(lista);
			getch();
			break;
		
			case 5: inicio();	
			break;	
		}
	}while(opc!=5);
}
