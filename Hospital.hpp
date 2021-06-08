/*
 * Proyecto: Hospital
 * Karen Cebreros López
 * A01704254
 * 11/05/2021
 *
 * Hospital.hpp
 * Hospital-POO
 * Created by Karen CL on 11/05/2021.
 * Copyright © 2020 KarenCbrs. All rights reserved.
 */

/*
 * La clase Hospital, contiene todos los métodos para el movimiento de
 * Medicos, Cuatos y Pacientes en este.
 * Así mismo, contiene un método para realizar operaciones e interactuar con
 * los involucrados dependiendo del tipo de rol que jueguen en el hospital
 * (Medico/ Paciente).
 * Esta clase es utilizada en la función principal del prgrama: el main()
 */

#ifndef Hospital_hpp
#define Hospital_hpp

//Librerías del proyecto
#include <stdio.h>
#include <iostream>

//Clases del proyecto
#include "Cuarto.hpp"
#include "Persona.hpp"

using namespace std;

//Declaración de la clase hospital
class Hospital {
    private:
        //Atributos
        string nombre;
        int nivel;
        vector<Cuarto> cuartos;
    public:
        //Constructor por default de la clase Hospital
        Hospital(): nombre(""), nivel(0){};
    
        //Otro constructor
        Hospital(string nomb, int lvl): nombre(nomb), nivel(lvl){};
    
        //Métodos
        void crea_cuartos_prueba();
        void agrega_cuarto(int);
        bool asigna_cuarto(int);
        void muestra_cuartos();
        void ingresa_paciente(vector<Paciente*> &pacientes, string,
                              int, string, string, string, int);
        void contrata_medico(vector<Medico*> &medicos, string,
                          int, string, string, string);
        void da_alta_paciente(vector<Paciente*> &pacientes, long);
        void realiza_operacion(Persona *personas[], int);
};

/*
 * Función "crea_cuartos_prueba()" -> crea cuartos de prueba para el programa
 *
 * - Se crean objetos de tipo Cuarto y se agregan al vector "cuartos", con sus
 * respectivos datos.
 *
 * @param
 * @return
 *
 */
void Hospital::crea_cuartos_prueba() {
    Cuarto cu;
    cu.set_datos(1, 2, "No disponible", 2);
    cuartos.push_back(cu);
    cu.set_datos(2, 1, "Disponible", 0);
    cuartos.push_back(cu);
    cu.set_datos(3, 3, "Disponible", 1);
    cuartos.push_back(cu);
    cu.set_datos(4, 2, "No disponible", 2);
    cuartos.push_back(cu);
    cu.set_datos(5, 2, "Disponible", 1);
    cuartos.push_back(cu);
    cu.~Cuarto();
}

/*
 * Función "agrega_cuarto()" -> agrega un cuarto al vector de cuartos
 *
 * - Se crea un objeto de tipo cuarto, usando parámetros que nos pasa el usuario
 * y uno de los constructores de la clase.
 *
 * @param int _num_cuarto
 * @return
 *
 */
void Hospital::agrega_cuarto(int _capacidad) {
    Cuarto c(cuartos.size() + 1, _capacidad);
    cuartos.push_back(c);
    
    cout << "Cuarto agregado exitosamente!" << endl;
    c.~Cuarto();
}

/*
 * Función "asigna_cuarto()" -> asgina un cuarto a un paciente
 *
 * - En esta función se comprueba si el atributo "disponibilidad" de un objeto
 * Cuarto se encuentra como disponible o no. En caso de que si, se asigna a un
 * Paciente y se hacen cambios en los atributos "set_num_pacientes" y
 * "disponibilidad" del objeto Cuarto, a través de setters de su respectiva clase.
 *
 * @param int _num_cuarto
 * @return bool -> TRUE si está disponible y FALSE si no lo está
 *
 */
bool Hospital::asigna_cuarto(int _num_cuarto) {
    if (cuartos[_num_cuarto-1].get_disponibilidad() == "Disponible") {
        cuartos[_num_cuarto-1].set_num_pacientes_mas();
        cuartos[_num_cuarto-1].set_disponibilidad();
        return true;
    }
    return false;
}

/*
 * Función "muestra_cuartos()" -> muestra datos de los objetos Cuarto
 *
 * - Se despliegan los datos de todos los objetos Cuarto en el vector "cuartos".
 *
 * @param
 * @return
 *
 */
void Hospital::muestra_cuartos() {
    cout << "# CUARTO:" << setw(15) << "CAPACIDAD:" << setw(20) <<
    "DISPONIBILIDAD:" << setw(17) << "# PACIENTES:" << endl;
    for (int i = 0; i < cuartos.size(); i++) {
        cout.width(8); cout << cuartos[i].get_num_cuarto();
        cout.width(14); cout << cuartos[i].get_capacidad();
        cout.width(22); cout << cuartos[i].get_disponibilidad();
        cout.width(16); cout << cuartos[i].get_num_pacientes() << endl;
    }
}

/*
 * Función "ingresa_paciente()" -> crea un objeto Paciente y lo agrega al vector
 *
 * - Se crea el objeto Paciente con los datos ingresados por el usuario y se
 * agrega al final del vector.
 *
 * @param vector<Paciente*> &pacientes
 * @return
 *
 */
void Hospital::ingresa_paciente(vector<Paciente*> &pacientes, string nomb,
                                int ed, string gen, string tel, string cond,
                                int cu) {
    
    if (asigna_cuarto(cu)) {
        pacientes.push_back(new Paciente(pacientes.size() + 1, nomb, ed, gen,
                                         tel, cond, cu));
        cout << "Paciente ingresado exitosamente!" << endl;
    } else {
        cout << "Error al ingresar! El cuarto no está disponible." << endl;
    }
}

/*
 * Función "contrata_medico()" -> crea un objeto Medico y lo agrega al vector
 *
 * - Se crea el objeto MEdico con los datos ingresados por el usuario y se
 * agrega al final del vector.
 *
 * @param vector<Medico*> &medicos
 * @return
 *
 */
void Hospital::contrata_medico(vector<Medico*> &medicos, string nomb,
                               int ed, string gen, string tel, string esp) {
    
    medicos.push_back(new Medico(medicos.size() + 1, nomb, ed, gen, tel, esp));
    cout << "Nuevo médico contradado exitosamente!" << endl;
}

/*
 * Función "da_alta_paciente()" -> elimina un objeto y lo saca del vector
 *
 * - Se comprueba si el id ingresado por el usuario es válido y en caso de que si,
 * se elimina el apuntador al objeto con "delete" y se libera el espacio
 *
 * @param vector<Paciente*> &pacientes, int id_p
 * @return
 *
 */
void Hospital::da_alta_paciente(vector<Paciente*> &pacientes, long id_p) {
    if (id_p >= pacientes.size()) {
        cout << "Paciente no encontrado!" << endl;
    } else {
        int num_cu = pacientes[id_p]->get_num_cuarto();
        
        delete pacientes[id_p];
        pacientes.erase(pacientes.begin() + id_p);
        
        for (int i = 0; i < pacientes.size(); i++){
            pacientes[i]->set_id(i+1);
        }
    
        cout << "Alta dada exitosamente!" << endl;
        
        cuartos[num_cu-1].set_num_pacientes_menos();
        cuartos[num_cu-1].set_disponibilidad();
    }
}

/*
* Función "realiza_operacion()" -> médicos realizan una operación a un paciente
*
* - Esta función aplica polimorfismo al llamar a la función "operacion()" para
* todos los objetos dentro de "personas" que es de tipo "Persona" (es decir,
* contiene objetos Medico y Paciente).
* Aquí se puede ver como esta dicha función actúa diferente con los diferentes
* tipos de objetos.
* - Cada clase tiene la función "operación()" sobreescrita, ya que modifican
* diferentes atributos segun su tipo
*
* @param Persona * personas[], int pers
* @return
*
*/
void Hospital::realiza_operacion(Persona * personas[], int pers) {
    for (int i = 0; i <= pers; i++) {
        personas[i]->operacion();
    }
    cout << "\nOPERACIÓN REALIZADA CON ÉXITO!" << endl;
    cout << "\n(Checa las modificaciones en los perfiles!)."<<endl;
}

#endif /* Hospital_hpp */
