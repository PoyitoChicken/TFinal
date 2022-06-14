#include <iostream>

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video{

  protected:
    string ID, nombre, duracion, genero, calificacion;

  public:
    //Constructores
    Video();
    Video(string, string, string, string);
    virtual void setCalificacion(string);
    //Gets
    string getID(){return ID;};
    string getNombre(){return nombre;};
    string getDuracion(){return duracion;};
    string getGenero(){return genero;};
    //Funciones
    virtual void mostrarDatos();
    virtual string getTituloEp(){return "";};
    virtual string getNumTemp(){return 0;};
    virtual string getCalificacion(){return 0;};
};
/*
      string getTituloEp(){return tituloEp;};
    int getNumTemp(){return numTemp;};
    int getCalificacion(){return calificacion;};
*/
//Constructores
Video::Video(){
  ID = "";
  nombre = "Video";
  duracion = "";
  genero = "Sin Genero";
}

Video::Video(string _ID, string nom, string _duracion, string gen){
  ID = _ID;
  nombre = nom;
  duracion = _duracion;
  genero = gen;
}

void Video::setCalificacion(string _calificacion){
  calificacion = _calificacion;
}
//Funciones
void Video::mostrarDatos(){
  cout << ID << " " << nombre << " " << duracion << " " << genero << " ";
}


#endif // VIDEO_H
