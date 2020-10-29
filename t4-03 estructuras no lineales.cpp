#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
	
struct nodo{
	int dato;
	nodo*der;
	nodo*izq;
};


void menu();
nodo*crearnodo(int);
void insertarnodo(nodo *&,int);
void mostrararbol(nodo *,int);

nodo *arbol=NULL;

int main (){
	menu();
	getch();
	return 0;
	
}

void menu(){
	int dato,opcion,contador=0;
	do{
		cout<<"\t.:menu:."<<endl;
		cout<<"1. insertar un nuevo nodo"<<endl;
		cout<<"2.mostrar el arbol completo"<<endl;
		cout<<"3. salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1:cout<<"\nDigite un numero: ";
			cin>>dato;
			insertarnodo(arbol,dato);
			cout<<"\n";
			system("pause");
			break;
			case 2: cout<<"\nmostrando el arbol completo\n\n";
			mostrararbol(arbol,contador);
			cout<<"\n";
			system("pause");
			break;
		}
		system("cls");		
	}while(opcion!=3);
}



nodo *crearnodo(int n){
	nodo *nuevo_nodo = new nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

void insertarnodo(nodo *&arbol, int n){
	if (arbol == NULL){
		nodo *nuevo_nodo=crearnodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorraiz =arbol->dato;
		if(n<valorraiz){
			insertarnodo(arbol->izq,n);
		}
		else{
			insertarnodo(arbol->der,n);
		}
	}
	
}

void mostrararbol(nodo* arbol,int cont){
	if(arbol==NULL){
		return ;
	}
	else{
		mostrararbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrararbol(arbol->izq,cont+1);
		
	}
}
