/*
Jorge Cooley Magallanes A00833271
Oscar Cortés A00825972
*/

#include <iostream>

using namespace std;

#include "Video.h"

class Serie : public Video{

  private:
    string tituloEp;
    int numTemp;
    int calificacion;

  public:
    //Constructores
    Serie();
    Serie(int, string, int, string, string, int, int);
    void setCalificacion(int);
    //Gets
    string getTituloEp(){return tituloEp;};
    int getNumTemp(){return numTemp;};
    int getCalificacion(){return calificacion;};
    //Funciones
    void mostrarDatos();
};


//Constructores
Serie::Serie() : Video(){
  tituloEp = "Titulo-Episodio";
  numTemp = 0;
  calificacion = 0;
}

Serie::Serie(int _ID, string nom, int _duracion, string gen, string _tituloEp, int _numTemp, int calif) : Video(_ID, nom, _duracion, gen){
  tituloEp = _tituloEp;
  numTemp = _numTemp;
  calificacion = calif;
};
void Serie::setCalificacion(int _calificacion){
  calificacion = _calificacion;
}

//Funciones
void Serie::mostrarDatos(){
  Video::mostrarDatos();
  cout << tituloEp << " " << numTemp << " " << calificacion << endl;
}