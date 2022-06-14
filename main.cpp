/*
Jorge Cooley Magallanes A00833271
Oscar Cortés A00825972
*/

#include "Serie.h"
#include "Pelicula.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


using namespace std;

string ID, nombre, duracion, genero, tituloEp, numTemp, calificacion;
string nlinea;
int linea = 0;
int posicion = 0;


int main(){
    ifstream Datos;
    Datos.open("Datos.txt");
    Datos >> ID;
    int Id = stoi(ID);
    Datos.clear();
    Datos.seekg(0, ios::beg);
    int i = 0;
    Video *videos[15];
    if (Id % 2 == 0){
            i++;
            Serie:Datos>> ID >> nombre >> duracion >> genero >> tituloEp >> numTemp >> calificacion;
            videos[i] = new Serie(stoi(ID), nombre, stoi(duracion), genero, tituloEp, stoi(numTemp), stoi(calificacion));
            if (i >= 15){
                goto Continuar;
            }
            goto Peli;
        }
        else if (Id % 2 != 0){
            i++;
            Peli:Datos>> ID >> nombre >> duracion >> genero >> calificacion;
            videos[i] = new Pelicula(stoi(ID), nombre, stoi(duracion), genero, stoi(calificacion));


            if (i >= 15){
                goto Continuar;
            }
            goto Serie;
        }
    
    Continuar:
    cout << "1. Cargar archivo de datos" << endl;
    cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
    cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
    cout << "4. Mostrar las películas con cierta calificacion" << endl;
    cout << "5. Calificar un video" << endl;
    cout << "0. Salir" << endl;
    while (true){
        int decision;
        cout << "Ingrese una opción: ";
        cin >> decision;
        switch (decision){
            case 1:
                for (int i = 0; i<=15; i++){
                    videos[i] -> mostrarDatos();
                }
                break;
            case 2:
            {
                cout << "Quiere filtrar por calificacion (c) o por genero(g): ";
        char opcion;
        cin >> opcion;
        if (opcion == 'c'){
            int c;
            cout << "Ingrese la calificacion: ";
            for (int i = 0; i<=15; i++){
                if (videos[i] != NULL){
                    if (videos[i] -> getCalificacion() == c){
                        videos[i] -> mostrarDatos();
                    }
                }
            }
        }
        else if (opcion == 'g'){
            cout << "Ingrese el genero drama(d), misterio(m) y accion(a): ";
            string genero;
            cin >> genero;
            if (genero == "d"){
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getGenero() == "Drama"){
                            videos[i] -> mostrarDatos();
                        }
                    }
                }
            }
            else if (genero == "m"){
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getGenero() == "Misterio"){
                            videos[i] -> mostrarDatos();
                        }
                    }
                }
            }
            else if (genero == "a"){
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getGenero() == "Accion"){
                            videos[i] -> mostrarDatos();
                        }
                    }
                }
            }

        }  
                break;
            }
            case 3:
            {
                cout << "Ingrese el titulo de la serie: ";
                string titulo;
                cin >> titulo;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getTituloEp() == titulo){
                            videos[i] -> mostrarDatos();
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout << "Ingrese la calificacion: ";
                int calificacion;
                cin >> calificacion;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getCalificacion() == calificacion){
                                videos[i] -> mostrarDatos();
                            }
                        }
                    }
                break;
            }
            case 5:
            {
                cout << "Ingrese el ID del video: ";
                int id;
                cin >> id;
                cout << "Ingresa la calificacion del video: ";
                int cal;
                cin >> cal;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getID() == id){
                            videos[i] -> setCalificacion(cal);
                        }
                    }
                }
                break;
            }
            case 0:
            {
                Datos.close();
                cout << "Gracias por usar el programa" << endl;
                exit(0);
                break;             
            default:
            {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }
        }
        return 0;
    }
}