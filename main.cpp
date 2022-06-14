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


int main(){
    string ID, nombre, duracion, genero, tituloEp, numTemp, calificacion;
    ifstream Datos;
    Datos.open("Datos.txt");
    Datos >> ID;
    int Id = 1;
    Datos.clear();
    Datos.seekg(0, ios::beg);
    int j = -1;
    Video *videos[16];
    goto Peli;
    if (Id % 2 == 0){
            Serie:j++;
            Datos>> ID >> nombre >> duracion >> genero >> tituloEp >> numTemp >> calificacion;
            videos[j] = new Serie(ID, nombre, duracion, genero, tituloEp, numTemp, calificacion);

            if (j >= 15){
                goto Continuar;
            }
            goto Peli;
        }
        else if (Id % 2 != 0){
            Peli:j++;
            Datos>> ID >> nombre >> duracion >> genero >> calificacion;
            videos[j] = new Pelicula(ID, nombre, duracion, genero, calificacion);

            if (j >= 15){
                goto Continuar;
            }
            goto Serie;
        }

    Continuar:
    while (true){
        Interfaz:
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
        cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "4. Mostrar las películas con cierta calificacion" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        int decision;
        cout << "Ingrese una opción: ";
        cin >> decision;
        switch (decision){
            case 1:
                for (int i = 0; i<=15; i++){
                    videos[i] -> mostrarDatos();
                }
                cout << "\n\n\n";
                goto Interfaz;
                break;
            case 2:
            {
                cout << "Quiere filtrar por calificacion (c) o por genero(g): ";
                char opcion;
                cin >> opcion;
                if (opcion == 'c'){
                    string c;
                    cout << "Ingrese la calificacion: ";
                    cin >> c;
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
                cout << "\n\n\n";
                goto Interfaz;
                break;
            }
            case 3:
            {
                cout << "Ingrese el titulo de la serie: ";
                string punt;
                string titulo;
                cin >> titulo;
                cout << "Ingrese la puntuacion del capitulo:";
                cin >> punt;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] ->getNombre() == titulo){
                                if (videos[i] -> getCalificacion() == punt){
                                    videos[i] -> mostrarDatos();
                                }
                        }
                    }
                }
                cout << "\n\n\n";
                goto Interfaz;
                break;
            }
            case 4:
            {
                cout << "Ingrese la calificacion: ";
                string calificacion;
                cin >> calificacion;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getCalificacion() == calificacion){
                                videos[i] -> mostrarDatos();
                            }
                        }
                    }
                cout << "\n\n\n";
                goto Interfaz;
                break;
            }
            case 5:
            {
                cout << "Ingrese el ID del video: ";
                string id;
                cin >> id;
                cout << "Ingresa la calificacion del video: ";
                string cal;
                cin >> cal;
                for (int i = 0; i<=15; i++){
                    if (videos[i] != NULL){
                        if (videos[i] -> getID() == id){
                            cout << "\nAntes: ";
                            videos[i] -> mostrarDatos();
                            cout <<"\n";
                            videos[i] -> setCalificacion(cal);
                            cout << "Despues: ";
                            videos[i] -> mostrarDatos();
                            cout <<"\n";
                        }
                    }
                }
                goto Interfaz;
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
                goto Interfaz;
                break;
            }
        }
        }
        return 0;
    }
}
