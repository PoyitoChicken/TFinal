#include <iostream>

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video{

  protected:
    int ID;
    string nombre;
    int duracion;
    string genero;
    int calificacion;

  public:
    //Constructores
    Video();
    Video(int, string, int, string);
    virtual void setCalificacion(int);
    //Gets
    int getID(){return ID;};
    string getNombre(){return nombre;};
    int getDuracion(){return duracion;};
    string getGenero(){return genero;};
    //Funciones
    virtual void mostrarDatos();
    virtual string getTituloEp(){return "";};
    virtual int getNumTemp(){return 0;};
    virtual int getCalificacion(){return 0;};
};
/*
      string getTituloEp(){return tituloEp;};
    int getNumTemp(){return numTemp;};
    int getCalificacion(){return calificacion;};
*/
//Constructores
Video::Video(){
  ID = 0;
  nombre = "Video";
  duracion = 0;
  genero = "Sin Genero";
}

Video::Video(int _ID, string nom, int _duracion, string gen){
  ID = _ID;
  nombre = nom;
  duracion = _duracion;
  genero = gen;
}

void Video::setCalificacion(int _calificacion){
  calificacion = _calificacion;
}
//Funciones
void Video::mostrarDatos(){
  cout << ID << " " << nombre << " " << duracion << " " << genero << " ";
}


#endif // VIDEO_H