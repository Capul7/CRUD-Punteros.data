#include <iostream>
#include <string.h>
#include<stdio.h>

using namespace std;
const char *nom_archivo = "arch.dat";
struct Estudiante{
int codigo;
char nombres[50];
char apellidos[50];
char direccion[50];
int telefono;
}estudiante,*E_estudiante = &estudiante;
	void Datos();
	void mostrar(Estudiante *);
	void crear();
	void leer();
	void actualizar();
	void eliminar ();
main(){
Datos();
mostrar(E_estudiante);
leer();
crear();
actualizar();
eliminar ();
}
void Datos(){
	cout<<"ingresar nombres: ";
	cin.getline(E_estudiante->nombres,50,'\n');
	cout<<"ingresar apellidos: ";
	cin.getline(E_estudiante->apellidos,50,'\n');
	cout<<"ingresar direccion: ";
	cin.getline(E_estudiante->direccion,50,'\n');
	cout<<"ingresar codigo: ";
	cin>>E_estudiante->codigo;
	cout<<"ingresar numero de telefono: ";
	cin>>E_estudiante->telefono;
}
void mostrar(Estudiante *E_estudiante){
	cout<<"\nnombres:"<<E_estudiante->nombres<<endl;
	cout<<"\napellidos:"<<E_estudiante->apellidos<<endl;
	cout<<"\ndireccion:"<<E_estudiante->direccion<<endl;
	cout<<"codigo:"<<E_estudiante->codigo<<endl;
	cout<<"\ntelefono:"<<E_estudiante->telefono<<endl;
}
void leer(){

FILE* archivo = fopen(nom_archivo,"rb");
	if (!archivo){
	archivo = fopen(nom_archivo,"w+b");
}
Estudiante estudiante;
	int id=0;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Direccion"<<"|"<<"Telefono"<<endl;
		do{
			cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			fread(&estudiante,sizeof(Estudiante),1,archivo);
			id+=1;
			}while(feof(archivo)==0);
			fclose(archivo);
			cout<<endl;
}
void actualizar(){
FILE* archivo = fopen(nom_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
		cout<<"ingresar ID que desea Modificar:";
		cin>>id;
		fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		cout<<"ingresar codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"ingresar nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"ingresar apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"ingresar direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"ingresar Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();

fwrite(&estudiante,sizeof(Estudiante),1,archivo);
fclose(archivo);
leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nom_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
do{
	fflush(stdin);
	cout<<"ingresar codigo:";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"ingresar nombres:";
	getline(cin,nombre);
	strcpy(estudiante.nombres,nombre.c_str());
	cout<<"ingresar apellidos:";
	getline(cin,apellido);
	strcpy(estudiante.apellidos,apellido.c_str());
	cout<<"ingresar direccion:";
	getline(cin,direccion);
	strcpy(estudiante.direccion,direccion.c_str());
	cout<<"ingresar elefono:";
	cin>>estudiante.telefono;
	cin.ignore();
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"desea ingresar otro estudiante (s/n):";
	cin>>continuar;
} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
leer();
}
void eliminar (){

FILE* archivo = fopen(nom_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"ingrese el ID que desee a eliminar:";
	cin>>id;
	fseek(archivo,id *sizeof(Estudiante),SEEK_SET);

estudiante.codigo=0;
estudiante.nombres[50]=0;
estudiante.apellidos[50]=0;
estudiante.direccion[50]=0;
estudiante.telefono=0;

cout << "\nestudiante eliminado " << endl;

fwrite(&estudiante,sizeof(Estudiante),1,archivo);
fclose(archivo);
           
  }

