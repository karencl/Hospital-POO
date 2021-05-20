/*
 * Proyecto Hospital
 * Karen Cebreros López
 * A01704254
 * 11/05/2021
 *
 * main.cpp
 * Hospital-POO
 * Created by Karen CL on 10/11/20.
 * Copyright © 2020 KarenCbrs. All rights reserved.
 */

/*
 * Descripción:
 * Este es un proyecto para la clase de programación orientada
 * a objetos.
 * Es un programa que simula el funcionamiento de un hospital.
 */

//Librerías utilizadas
#include <iostream>
#include <vector>
#include <iomanip>

//Clases del proyecto
#include "Hospital.hpp"
#include "Persona.hpp"
#include "Cuarto.hpp"

using namespace std;

//Prototipos de funciones (hasta abajo están las declaraciones)
void crea_pacientes(vector<Paciente> &pacientes);
void crea_medicos(vector<Medico> &medicos);
void muestra_menu();
void muestra_medicos(vector<Medico> medicos);
void muestra_pacientes(vector<Paciente> pacientes);

int main() {
    
    //Crea objeto de prueba de la clase Hospital
    Hospital hospital1("Star Medica", 3);
    hospital1.crea_cuartos_prueba();
    
    //Crea vector de objetos de la clase Paciente
    vector<Paciente> pacientes(6);
    crea_pacientes(pacientes);
    
    //Crea vector de objetos de la clase Medico
    vector<Medico> medicos(4);
    crea_medicos(medicos);
    
    cout << "App: Hospital-POO" << endl;
    cout << "*** Agranda la ventana para ver mejor las cosas que se imprimirán en la consola ***" << endl;
    int opcion = 1;
    
    //Ciclo while donde se desplegará el menú de opciones
    while (opcion != 9) {
        muestra_menu();
        cout << "Selecciona una opción para continuar: ";
        cin >> opcion;
        cout << endl;
        
        //Opción 1: muestra vector de objetos Medico
        if (opcion == 1) {
            muestra_medicos(medicos);
        }
        
        //Opción 2: muestra vector de objetos Paciente
        else if (opcion == 2) {
            muestra_pacientes(pacientes);
        }
        
        //Opción 3: muestra vector (creado desde la clase Hospital) de objetos Cuarto
        else if (opcion == 3) {
            hospital1.muestra_cuartos();
        }
        
        //Opción 4: Agrega un nuevo cuarto (crea un nuevo objeto y lo agrega al vector)
        else if (opcion == 4) {
            cout << "Se agregará un nuevo cuarto al hospital!" << endl;
            
            int cap;
            cout << "Ingresa la capacidad del nuevo cuarto: ";
            cin>> cap;
            
            hospital1.agrega_cuarto(cap);
        }
        
        //Opción 5: Ingresa un nuevo paciente (crea un nuevo objeto y lo agrega al vector)
        else if (opcion == 5) {
            cout << "Se ingresará un nuevo paciente al hospital..." << endl;
            long tel;
            string nomb, gen, cond;
            int edad, cuarto;
            cout << "Nombre: ";
            cin >> nomb;
            cout << "Edad: ";
            cin >> edad;
            cout << "Género: ";
            cin >> gen;
            cout << "Condición en la que ingresa: ";
            cin >> cond;
            cout << "Teléfono de contacto: ";
            cin >> tel;
            cout << "Número de cuarto a asignar: ";
            cin >> cuarto;
            cout << endl;
            
            hospital1.ingresa_paciente(pacientes, nomb, edad, gen, tel, cond, cuarto);
        }
        
        //Opción 6: Contrata un nuevo médico (crea un nuevo objeto y lo agrega al vector)
        else if (opcion == 6) {
            cout << "Se contratará un nuevo médico en el hospital..." << endl;
            long tel;
            string nomb, gen, esp;
            int edad;
            cout << "Nombre: ";
            cin >> nomb;
            cout << "Edad: ";
            cin >> edad;
            cout << "Género: ";
            cin >> gen;
            cout << "Especialidad que tiene: ";
            cin >> esp;
            cout << "Teléfono de contacto: ";
            cin >> tel;
            cout << endl;

            hospital1.contrata_medico(medicos, nomb, edad, gen, tel, esp);
        }
        
        //Opción 7: Se ingresa un paciente a operación (cambian características del perfil)
        else if (opcion == 7) {
            cout << " >> MÉDICOS " << endl;
            muestra_medicos(medicos);
            cout << endl;
            
            cout << " >> PACIENTES " << endl;
            muestra_pacientes(pacientes);
            cout << endl;
            
            int id_p, id_m;
            cout << " * Ingresa el ID del médico que va a realizar la operación: ";
            cin >> id_m;
            cout << " * Ingresa el ID del paciente a operar: ";
            cin >> id_p;
            cout << endl;
            
            if (id_m > medicos.size() || id_p > pacientes.size()) {
                cout << "Error! Revisa los IDs de las personas involucradas en la operación." << endl;
            } else {
                Persona * involucrados_op[2];
                involucrados_op[0] = &pacientes[id_p-1];
                involucrados_op[1] = &medicos[id_m-1];
            
                hospital1.realiza_operacion(involucrados_op);
            }
        }
        
        //Opción 8: Da de alta a un paciente (elimina objeto y lo saca del vector)
        else if (opcion == 8) {
            cout << "Proceso para dar de alta a un paciente...\n" << endl;
            
            muestra_pacientes(pacientes);
            
            long id;
            cout << "\nIngresa el ID del paciente: ";
            cin>> id;
            cout << endl;
            
            hospital1.da_alta_paciente(pacientes, id-1);
        }
        
        //Opción 9: Salir del programa
        else if (opcion == 9) {
            cout << "Has salido. Hasta pronto!" << endl;
        }
        
        //Cualquier otra opción: error
        else {
            cout << "Error! Opción no encontrada. Intenta de nuevo." << endl;
        }
    }
    
    return 0;
}

/*
 * Función "crea_pacientes()" -> crea objetos de prueba de la clase Paciente
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void crea_pacientes(vector<Paciente> &pacientes) {
    pacientes[0].set_datos(1, "Paco", 27, "Masculino", 9831236712, "Estable", 10, 1, 7700, 1);
    pacientes[1].set_datos(2, "Jimena", 15, "Femenino", 1981236746, "Estable", 3, 0, 1500, 3);
    pacientes[2].set_datos(3, "Samuel", 42, "Masculino", 7788223641, "Critico", 21, 4, 24200, 5);
    pacientes[3].set_datos(4, "Luis", 30, "Masculino", 2345243127, "Estable", 17, 2, 13000, 1);
    pacientes[4].set_datos(5, "Carla", 31, "Femenino", 9912574832, "Terapia", 39, 3, 18100, 4);
    pacientes[5].set_datos(6, "Laura", 25, "Femenino", 1244587341, "Estable", 8, 1, 7500, 4);
}

/*
 * Función "crea_medicos()" -> crea objetos de prueba de la clase Medico
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void crea_medicos(vector<Medico> &medicos) {
    medicos[0].set_datos(1, "Andrea", 49, "Femenino", 4876129086, "Neuróloga", 27, 80000);
    medicos[1].set_datos(2, "Omar", 51, "Masculino", 3493582127, "Oncólogo", 15, 40000);
    medicos[2].set_datos(3, "Liliana", 55, "Femenino", 1173498784, "Endocrinóloga", 8, 30000);
    medicos[3].set_datos(4, "Carlos", 47, "Masculino", 2455610082, "Cardiólogo", 20, 60000);
}

/*
 * Función "muestra_menu()" -> muestra el menú de opciones
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void muestra_menu() {
    cout << endl;
    cout << "---------- MENÚ ----------" << endl;
    cout << "1) Muestra la lista de médicos" << endl;
    cout << "2) Muestra la lista de pacientes" << endl;
    cout << "3) Muestra la disponibilidad de cuartos" << endl;
    cout << "4) Agrega un nuevo cuarto" << endl;
    cout << "5) Ingresa paciente" << endl;
    cout << "6) Contrata un médico" << endl;
    cout << "7) Ingresa a un paciente a operación" << endl;
    cout << "8) Da de alta a un paciente" << endl;
    cout << "9) Salir" << endl;
    cout << endl;
}

/*
 * Función "muestra_medicos()" -> muestra los objetos Medico del vector "medicos"
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void muestra_medicos(vector<Medico> medicos) {
    cout << "ID:" << setw(13) <<"NOMBRE:" << setw(13) << "EDAD:" << setw(16) << "GÉNERO:" <<
    setw(18) << "CONTACTO:" << setw(22) << "ESPECIALIDAD:" << setw(33) <<
    "TIEMPO EN QUIRÓFANO (hrs):" << setw(29) << "TOTAL DE HONORARIOS ($):" << endl;
    for (int i = 0; i < medicos.size(); i++) {
        cout.width(2); cout << medicos[i].get_id();
        cout.width(13); cout << medicos[i].get_nombre();
        cout.width(12); cout << medicos[i].get_edad();
        cout.width(16); cout << medicos[i].get_genero();
        cout.width(18); cout << medicos[i].get_tel();
        cout.width(22); cout << medicos[i].get_especialidad();
        cout.width(32); cout << medicos[i].get_temp_quir();
        cout.width(28); cout << medicos[i].get_tot_honrs() << endl;
    }
}

/*
 * Función "muestra_pacientes()" -> muestra los objetos Paciente del vector "pacientes"
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void muestra_pacientes(vector<Paciente> pacientes) {
    cout << "ID:" << setw(13) <<"NOMBRE:" << setw(13) << "EDAD:" << setw(16) << "GÉNERO:" <<
    setw(18) << "CONTACTO:" << setw(23) << "CONDICIÓN:" << setw(34) << "TIEMPO HOSPITALIZAD@ (días):" <<
    setw(23) << "NUM OPERACIONES:" << setw(14) << "CUENTA ($):" << setw(14) << "CUARTO:" << endl;
    for (int i = 0; i < pacientes.size(); i++) {
        cout.width(2); cout << pacientes[i].get_id();
        cout.width(13); cout << pacientes[i].get_nombre();
        cout.width(12); cout << pacientes[i].get_edad();
        cout.width(16); cout << pacientes[i].get_genero();
        cout.width(18); cout << pacientes[i].get_tel();
        cout.width(23); cout << pacientes[i].get_condicion();
        cout.width(31); cout << pacientes[i].get_temp_hosp();
        cout.width(22); cout << pacientes[i].get_num_ops();
        cout.width(14); cout << pacientes[i].get_cuenta();
        cout.width(14); cout << pacientes[i].get_num_cuarto() << endl;
    }
}
