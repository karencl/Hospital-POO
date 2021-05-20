/*
 * Proyecto: Hospital
 * Karen Cebreros López
 * A01704254
 * 11/05/2021
 *
 * Cuarto.hpp
 * Hospital-POO
 * Created by Karen CL on 11/05/2021.
 * Copyright © 2020 KarenCbrs. All rights reserved.
 */

#ifndef Cuarto_hpp
#define Cuarto_hpp

//Librerías del proyecto
#include <stdio.h>
#include <iostream>

using namespace std;

//Declaración de la clase Cuarto
class Cuarto {
    private:
        //Atributos
        long num_cuarto;
        int capacidad;
        string disponibilidad;
        int num_pacientes;
    public:
        //Constructor por default de la clase Cuarto
        Cuarto(): num_cuarto(1), capacidad(1), disponibilidad("Disponible"),
        num_pacientes(0){};
        //Otros constructor
        Cuarto(long nc, int cap, string disp, int np): num_cuarto(nc), capacidad(cap),
        disponibilidad(disp), num_pacientes(np){};
        Cuarto(long nc, int cap): num_cuarto(nc), capacidad(cap),
        disponibilidad("Disponible"), num_pacientes(0){};
    
        //Métodos
        void set_datos(long, int, string, int);
        long get_num_cuarto();
        int get_capacidad();
        string get_disponibilidad();
        int get_num_pacientes();
        void set_num_pacientes();
        void set_disponibilidad();
};

/*
 * Setter de los datos de un objeto de la clase Cuarto
 *
 * @param _num_cuarto, _capacidad, _disponibilidad, _num_pacientes
 * @return No retorna nada
 *
 */
void Cuarto::set_datos(long _num_cuarto, int _capacidad, string _disponibilidad,
                       int _num_pacientes){
    num_cuarto = _num_cuarto;
    capacidad = _capacidad;
    disponibilidad = _disponibilidad;
    num_pacientes = _num_pacientes;
}

/*
 * Getter del atributo "num_cuarto" de un objeto Cuarto
 *
 * @param No recibe parámetros
 * @return long -> número de cuarto de un objeto Cuarto
 *
 */
long Cuarto::get_num_cuarto() {
    return num_cuarto;
}

/*
 * Getter del atributo "capacidad" de un objeto Cuarto
 *
 * @param No recibe parámetros
 * @return int -> capacidad de cuarto de un objeto Cuarto
 *
 */
int Cuarto::get_capacidad() {
    return capacidad;
}

/*
 * Getter del atributo "disponibilidad" de un objeto Cuarto
 *
 * @param No recibe parámetros
 * @return string -> disponibilidad de un objeto Cuarto
 *
 */
string Cuarto::get_disponibilidad() {
    return disponibilidad;
}

/*
 * Getter del atributo "num_pacientes" de un objeto Cuarto
 *
 * @param No recibe parámetros
 * @return int -> número de pacientes de un objeto Cuarto
 *
 */
int Cuarto::get_num_pacientes() {
    return num_pacientes;
}

/*
 * Setter del número de pacientes que hay en un cuarto
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void Cuarto::set_num_pacientes() {
    num_pacientes++;
}

/*
 * Setter de la disponibilidad del cuarto
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void Cuarto::set_disponibilidad() {
    if (num_pacientes == capacidad)
        disponibilidad = "No disponible";
}

#endif /* Cuarto_hpp */
