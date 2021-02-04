#include <iostream>
using namespace std;

#include <fstream>


void escribirArchivo();
void leerArchivo();


int main() 
{
  int op;
  do{
  cout<<"\tMENU"<<endl;
  cout<<"1.- Ingresar datos"<<endl;
  cout<<"2.- Mostrar datos"<<endl;
  cout<<"Ingrese el numero de su opcion: "<<endl;
  cin>>op;
  
  switch(op){
    case 1:
    escribirArchivo();
    break;
    case 2:
    leerArchivo();
    break;
    default:
    cout<<"Opcion incorrecta"<<endl;
    break;
  }
  }while(op!=3);

  escribirArchivo();
  leerArchivo();
  

}



void escribirArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  string nombrearchivo;
  cout<<"Ingrese el nombre del archivo: ";  
  while(getchar()!='\n');
  getline(cin,nombrearchivo);
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre:";
    getline(cin,nombre); 
    cout<<"\t Ingrese el apellido:";
    getline(cin,apellido); 
    cout<<"\t Ingrese la carrera:";
    getline(cin,carrera);
    cout<<"\t Ingrese la edad:";
    cin>>edad;

    archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;

    cout<<"Desea ingresar otro contacto s/n ";

    cin>>r;

    cin.ignore();
  }
  while(r=='s');

  archivoprueba.close();

}




void leerArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  
  ifstream archivolectura("contactos.txt");
  string texto;
  while(!archivolectura.eof())
    {
      archivolectura>>nombre>>apellido>>carrera>>edad;

      if(!archivolectura.eof())
            {
              cout<<"Nombre:"<<nombre<<endl;
              cout<<"Apellido:"<<apellido<<endl;
              cout<<"Edad:"<<edad<<endl;
              cout<<"Carrera:"<<carrera<<endl;
              cout<<"**************************************"<<endl;
            }
    }
  archivolectura.close();

}
