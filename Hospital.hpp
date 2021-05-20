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
        void ingresa_paciente(vector<Paciente> &pacientes, string,
                              int, string, long, string, int);
        void contrata_medico(vector<Medico> &medicos, string,
                          int, string, long, string);
        void da_alta_paciente(vector<Paciente> &pacientes, long);
        void realiza_operacion(Persona *personas[]);
};

/*
 * Función "crea_cuartos_prueba()" -> crea cuartos de prueba para el programa
 *
 * @param No recibe ningún parámetro
 * @return No retorna nada
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
}

/*
 * Función "agrega_cuarto()" -> agrega un cuarto al vector de cuartos
 *
 * @param _num_cuarto, _capacidad, _disponibilidad, _num_pacientes
 * @return No retorna nada
 *
 */
void Hospital::agrega_cuarto(int _capacidad) {
    Cuarto c(cuartos.size() + 1, _capacidad);
    cuartos.push_back(c);
    
    cout << "Cuarto agregado exitosamente!" << endl;
}

/*
 * Función "asigna_cuarto()" -> asgina un cuarto a un paciente
 *
 * @param _num_cuarto, _id_paciente
 * @return No retorna nada
 *
 */
bool Hospital::asigna_cuarto(int _num_cuarto) {
    if (cuartos[_num_cuarto-1].get_disponibilidad() == "Disponible") {
        cuartos[_num_cuarto-1].set_num_pacientes();
        cuartos[_num_cuarto-1].set_disponibilidad();
        return true;
    }
    return false;
}

/*
 * Función "muestra_cuartos()" -> muestra datos de los objetos Cuarto
 *
 * @param No recibe parámetros
 * @return No retorna nada
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
 * @param vector<Paciente> &pacientes
 * @return No retorna nada
 *
 */
void Hospital::ingresa_paciente(vector<Paciente> &pacientes, string nomb, int ed,
                                string gen, long tel, string cond, int cu) {
    if (asigna_cuarto(cu)) {
        Paciente p(pacientes.size() + 1, nomb, ed, gen, tel, cond, cu);
        pacientes.push_back(p);
        cout << "Paciente ingresado exitosamente!" << endl;
    } else {
        cout << "No se pudo ingresar al paciente! El cuarto no se encuentra disponible." << endl;
    }
}

/*
 * Función "contrata_medico()" -> crea un objeto Medico y lo agrega al vector
 *
 * @param vector<Medico> &medicos
 * @return No retorna nada
 *
 */
void Hospital::contrata_medico(vector<Medico> &medicos, string nomb,
                     int ed, string gen, long tel, string esp) {
    Medico m(medicos.size() + 1, nomb, ed, gen, tel, esp);
    medicos.push_back(m);
    cout << "Nuevo médico contradado exitosamente!" << endl;
}

/*
 * Función "da_alta_paciente()" -> elimina un objeto y lo saca del vector
 *
 * @param vector<Paciente> &pacientes
 * @return No retorna nada
 *
 */
void Hospital::da_alta_paciente(vector<Paciente> &pacientes, long id_p) {
    if (id_p >= pacientes.size()) {
        cout << "Paciente no encontrado!" << endl;
    } else {
        pacientes.erase(pacientes.begin() + id_p);
        for (int i = 0; i < pacientes.size(); i++){
            pacientes[i].set_id(i+1);
        }
    
        cout << "Alta dada exitosamente!" << endl;
    }
}

/*
* Función "realiza_operacion()" -> realiza una operación (modifica objetos)
* Aquí se aplica polimorfismo, al llamar a la función "operacion()" y ver como
* actúa diferente con los diferentes tipos de objetos
*
* @param Paciente &paciente, Medico &medico, duracion, costo
* @return No retorna nada
*
*/
void Hospital::realiza_operacion(Persona * personas[]) {
    for (int i = 0; i < 2; i++) {
        personas[i]->operacion();
    }
    cout << "\nOperación realizada con éxito!" << endl;
    cout << "(Checa las modificaciones en el perfil del paciente y el médico!)."<<endl;
}

#endif /* Hospital_hpp */
