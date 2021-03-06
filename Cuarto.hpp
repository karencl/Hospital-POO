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

/*
 * La clase Cuarto contiene todos los métodos para objetos de esta, que mayormente
 * incluyen obtener y modificar los atributos de estos.
 * Se puede ver que la relación de Cuarto con la clase Hospital es de tipo
 * composición, ya que estos objetos son creados allá y su tiempo de vida,
 * depende del tiempo de vida de la otra clase.
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
    
        //Otros constructores
        Cuarto(long nc, int cap, string disp, int np): num_cuarto(nc),
            capacidad(cap), disponibilidad(disp), num_pacientes(np){};
    
        Cuarto(long nc, int cap): num_cuarto(nc), capacidad(cap),
            disponibilidad("Disponible"), num_pacientes(0){};
    
        //Métodos
        void set_datos(long, int, string, int);
        long get_num_cuarto();
        int get_capacidad();
        string get_disponibilidad();
        int get_num_pacientes();
        void set_num_pacientes_mas();
        void set_num_pacientes_menos();
        void set_disponibilidad();
    
        //Destructor
        ~Cuarto();
};

/*
 * Setter de los datos de un objeto de la clase Cuarto
 *
 * @param  long _num_cuarto, int _capacidad, string _disponibilidad,
 *         int _num_pacientes
 * @return
 *
 */
void Cuarto::set_datos(long _num_cuarto, int _capacidad,
                       string _disponibilidad, int _num_pacientes){
    
    num_cuarto = _num_cuarto;
    capacidad = _capacidad;
    disponibilidad = _disponibilidad;
    num_pacientes = _num_pacientes;
}

/*
 * Getter del atributo "num_cuarto" de un objeto Cuarto
 *
 * @param
 * @return long -> número de cuarto de un objeto Cuarto
 *
 */
long Cuarto::get_num_cuarto() {
    return num_cuarto;
}

/*
 * Getter del atributo "capacidad" de un objeto Cuarto
 *
 * @param
 * @return int -> capacidad de cuarto de un objeto Cuarto
 *
 */
int Cuarto::get_capacidad() {
    return capacidad;
}

/*
 * Getter del atributo "disponibilidad" de un objeto Cuarto
 *
 * @param
 * @return string -> disponibilidad de un objeto Cuarto
 *
 */
string Cuarto::get_disponibilidad() {
    return disponibilidad;
}

/*
 * Getter del atributo "num_pacientes" de un objeto Cuarto
 *
 * @param
 * @return int -> número de pacientes de un objeto Cuarto
 *
 */
int Cuarto::get_num_pacientes() {
    return num_pacientes;
}

/*
 * Setter del número de pacientes que hay en un cuarto (pone)
 *
 * @param
 * @return
 *
 */
void Cuarto::set_num_pacientes_mas() {
    num_pacientes++;
}

/*
 * Setter del número de pacientes que hay en un cuarto (quita)
 *
 * @param
 * @return
 *
 */
void Cuarto::set_num_pacientes_menos() {
    num_pacientes--;
}

/*
 * Setter de la disponibilidad del cuarto
 *
 * @param
 * @return
 *
 */
void Cuarto::set_disponibilidad() {
    if (num_pacientes == capacidad)
        disponibilidad = "No disponible";
    else
        disponibilidad = "Disponible";
}

/*
 * Destructor de un objeto Cuarto
 *
 * @param
 * @return 
 *
 */
Cuarto::~Cuarto(){}

#endif /* Cuarto_hpp */
