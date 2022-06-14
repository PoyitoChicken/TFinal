/*
Jorge Cooley Magallanes A00833271
Oscar Cortés A00825972
*/

#include <iostream>

using namespace std;

#include "Video.h"

class Pelicula : public Video{

  private:
    int calificacion;

  public:
    //Constructores
    Pelicula();
    Pelicula(int, string, int, string, int);
    //Gets
    void setCalificacion(int);
    
    int getCalificacion(){return calificacion;};
    //Funciones
    void mostrarDatos();
};

//Constructores
Pelicula::Pelicula() : Video(){
  calificacion = 0;
}

Pelicula::Pelicula(int _ID, string nom, int _duracion, string gen, int calif) : Video (_ID, nom, _duracion, gen){
  calificacion = calif;
}


//Sets
void Pelicula::setCalificacion(int _calificacion){
  calificacion = _calificacion;
}

//Funciones
void Pelicula::mostrarDatos(){
  Video::mostrarDatos();
  cout << calificacion << endl;
}