/*
Jorge Cooley Magallanes A00833271
Oscar Cortés A00825972
*/

#include <iostream>

using namespace std;

#include "Video.h"

class Pelicula : public Video{

  private:
    string calificacion;

  public:
    //Constructores
    Pelicula();
    Pelicula(string, string, string, string, string);
    //Gets
    void setCalificacion(string);

    string getCalificacion(){return calificacion;};
    //Funciones
    void mostrarDatos();
};

//Constructores
Pelicula::Pelicula() : Video(){
  calificacion = "";
}

Pelicula::Pelicula(string _ID, string nom, string _duracion, string gen, string calif) : Video (_ID, nom, _duracion, gen){
  calificacion = calif;
}


//Sets
void Pelicula::setCalificacion(string _calificacion){
  calificacion = _calificacion;
}

//Funciones
void Pelicula::mostrarDatos(){
    Video::mostrarDatos();
    cout << calificacion << endl;
}
