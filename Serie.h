/*
Jorge Cooley Magallanes A00833271
Oscar Cortés A00825972
*/

#include <iostream>

using namespace std;

#include "Video.h"

class Serie : public Video{

  private:
    string tituloEp, numTemp, calificacion;

  public:
    //Constructores
    Serie();
    Serie(string, string, string, string, string, string, string);
    void setCalificacion(string);
    //Gets
    string getTituloEp(){return tituloEp;};
    string getNumTemp(){return numTemp;};
    string getCalificacion(){return calificacion;};
    //Funciones
    void mostrarDatos();
};


//Constructores
Serie::Serie() : Video(){
  tituloEp = "Titulo-Episodio";
  numTemp = "";
  calificacion = "";
}

Serie::Serie(string _ID, string nom, string _duracion, string gen, string _tituloEp, string _numTemp, string calif) : Video(_ID, nom, _duracion, gen){
  tituloEp = _tituloEp;
  numTemp = _numTemp;
  calificacion = calif;
};
void Serie::setCalificacion(string _calificacion){
  calificacion = _calificacion;
}

//Funciones
void Serie::mostrarDatos(){
    Video::mostrarDatos();
    cout << tituloEp << " " << numTemp << " " << calificacion << endl;
}
