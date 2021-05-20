/*
 * Proyecto: Hospital
 * Karen Cebreros López
 * A01704254
 * 11/05/2021
 *
 * Persona.hpp
 * Hospital-POO
 * Created by Karen CL on 11/05/2021.
 * Copyright © 2020 KarenCbrs. All rights reserved.
 */

#ifndef Persona_hpp
#define Persona_hpp

//Librerías del proyecto
#include <stdio.h>
#include <iostream>

using namespace std;

//Declaración de la clase Persona (es una clase papá y es abstracta)
class Persona {
    protected:
        //Atributos
        long id;
        string nombre;
        int edad;
        string genero;
        long telefono;
    public:
        //Constructor por default de la clase Persona
        Persona(): id(0), nombre(""), edad(0), genero(""), telefono(0){};
        //Otro constructor
        Persona(long i, string nomb, int ed, string gen, long tel): id(i), nombre(nomb),
        edad(ed), genero(gen), telefono(tel){};
    
        //Métodos abstractos que serán sobreescritos (se aplica polimorfismo)
        virtual void operacion();
    
        //Métodos
        void set_datos(long, string, int, string, long); //Será sobreescrito
        long get_id();
        string get_nombre();
        int get_edad();
        string get_genero();
        long get_tel();
        void set_id(long);
};

/*
 * Setter de los datos de un objeto de la clase Persona
 *
 * @param _id, _nombre, _edad, _genero, _telefono
 * @return No retorna nada
 *
 */
void Persona::set_datos(long _id, string _nombre, int _edad, string _genero,
                        long _telefono){
    id = _id;
    nombre = _nombre;
    edad = _edad;
    genero = _genero;
    telefono = _telefono;
}

/*
 * Función "operacion()" -> se realiza una operación a una persona
 * Esta es una función abstracta que será sobreescrita
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void Persona::operacion() {
    cout << "Operación en proceso..." << endl;
}

/*
 * Getter del atributo "id" de un objeto Persona
 *
 * @param No recibe parámetros
 * @return long -> id del objeto Persona
 *
 */
long Persona::get_id() {
    return id;
}

/*
 * Getter del atributo "nombre" de un objeto Persona
 *
 * @param No recibe parámetros
 * @return string -> nombre del objeto Persona
 *
 */
string Persona::get_nombre() {
    return nombre;
}

/*
 * Getter del atributo "edad" de un objeto Persona
 *
 * @param No recibe parámetros
 * @return int -> edad del objeto Persona
 *
 */
int Persona::get_edad() {
    return edad;
}

/*
 * Getter del atributo "genero" de un objeto Persona
 *
 * @param No recibe parámetros
 * @return string -> género del objeto Persona
 *
 */
string Persona::get_genero() {
    return genero;
}

/*
 * Getter del atributo "telefono" de un objeto Persona
 *
 * @param No recibe parámetros
 * @return long -> teléfono del objeto Persona
 *
 */
long Persona::get_tel() {
    return telefono;
}

/*
 * Setter del atributo "id" de un objeto Persona
 *
 * @param _id
 * @return No retorna nada
 *
 */
void Persona::set_id(long _id) {
    id = _id;
}



//Declaración de la clase Médico que hereda de Persona
class Medico : public Persona {
    private:
        //Atributos
        string especialidad;
        int tiempo_quirofano;
        double total_honorarios;
    public:
        //Constructor por default de la subclase Medico
        Medico(): Persona(), especialidad(""), tiempo_quirofano(0),
        total_honorarios(0.0){};
        //Otros constructor
        Medico(long i, string nomb, int ed, string gen, long tel, string esp, int tq,
        double th): Persona(i, nomb, ed, gen, tel), especialidad(esp),
        tiempo_quirofano(tq), total_honorarios(th){};
        Medico(long i, string nomb, int ed, string gen, long tel,
        string esp): Persona(i, nomb, ed, gen, tel), especialidad(esp),
        tiempo_quirofano(0), total_honorarios(0){};
    
        //Métodos
        void set_datos(long, string, int, string, long, string, int, double);
        void operacion();
        string get_especialidad();
        int get_temp_quir();
        double get_tot_honrs();
};

/*
 * Setter de los datos de un objeto de la subclase Médico
 *
 * @param _id, _nombre, _edad, _genero, _telefono, _especialidad,
 * _tiempo_quirofano, _total_honorarios
 * @return No retorna nada
 *
 */
void Medico::set_datos(long _id, string _nombre, int _edad, string _genero,
                        long _telefono, string _especialidad,
                        int _tiempo_quirofano, double _total_honorarios){
    id = _id;
    nombre = _nombre;
    edad = _edad;
    genero = _genero;
    telefono = _telefono;
    especialidad = _especialidad;
    tiempo_quirofano = _tiempo_quirofano;
    total_honorarios = _total_honorarios;
}

/*
 * Función "operacion()" -> se realiza una operación a una persona
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void Medico::operacion() {
    tiempo_quirofano += 4;
    total_honorarios += 10000;
}

/*
 * Getter del atributo "especialidad" de un objeto Medico
 *
 * @param No recibe parámetros
 * @return string -> especialidad de un objeto Medico
 *
 */
string Medico::get_especialidad() {
    return especialidad;
}

/*
 * Getter del atributo "tiempo_quirofano" de un objeto Medico
 *
 * @param No recibe parámetros
 * @return int -> tiempo en quirófano de un objeto Medico
 *
 */
int Medico::get_temp_quir() {
    return tiempo_quirofano;
}

/*
 * Getter del atributo "total_honorarios" de un objeto Medico
 *
 * @param No recibe parámetros
 * @return double -> total de honorarios de un objeto Medico
 *
 */
double Medico::get_tot_honrs() {
    return total_honorarios;
}



//Declaración de la clase Paciente que hereda de Persona
class Paciente : public Persona {
    private:
        //Atributos
        string condicion;
        int tiempo_hospitalizacion;
        int num_operaciones;
        double cuenta;
        int cuarto;
    public:
        //Constructor por default de la subclase Paciente
        Paciente(): Persona(), condicion(""), tiempo_hospitalizacion(0),
        num_operaciones(0), cuenta(0.0), cuarto(1){};
        //Otros constructor
        Paciente(long i, string nomb, int ed, string gen, long tel, string cond, int th,
        int no, double cue, int cua): Persona(i, nomb, ed, gen, tel), condicion(cond),
        tiempo_hospitalizacion(th), num_operaciones(no), cuenta(cue), cuarto(cua){};
        Paciente(long i, string nomb, int ed, string gen, long tel, string cond,
        int cua): Persona(i, nomb, ed, gen, tel), condicion(cond),
        tiempo_hospitalizacion(0), num_operaciones(0), cuenta(0), cuarto(cua){};
    
        //Métodos
        void set_datos(long, string, int, string, long, string, int, int, double, int);
        void operacion();
        string get_condicion();
        int get_temp_hosp();
        int get_num_ops();
        double get_cuenta();
        int get_num_cuarto();
};

/*
 * Setter de los datos de un objeto de la subclase Paciente
 *
 * @param _id, _nombre, _edad, _genero, _telefono, _condicion,
 * _tiempo_hospitalizacion, _num_operaciones, _cuenta, _cuarto
 * @return No retorna nada
 *
 */
void Paciente::set_datos(long _id, string _nombre, int _edad, string _genero,
                        long _telefono, string _condicion,
                        int _tiempo_hospitalizacion, int _num_operaciones,
                        double _cuenta, int _cuarto){
    id = _id;
    nombre = _nombre;
    edad = _edad;
    genero = _genero;
    telefono = _telefono;
    condicion = _condicion;
    tiempo_hospitalizacion = _tiempo_hospitalizacion;
    num_operaciones = _num_operaciones;
    cuenta = _cuenta;
    cuarto = _cuarto;
}

/*
 * Función "operacion()" -> se realiza una operación a una persona
 *
 * @param No recibe parámetros
 * @return No retorna nada
 *
 */
void Paciente::operacion() {
    num_operaciones ++;
    tiempo_hospitalizacion += 2;
    cuenta += 5200;
}

/*
 * Getter del atributo "condicion" de un objeto Paciente
 *
 * @param No recibe parámetros
 * @return string -> condicion de un objeto Paciente
 *
 */
string Paciente::get_condicion() {
    return condicion;
}

/*
 * Getter del atributo "tiempo_hospitalizacion" de un objeto Paciente
 *
 * @param No recibe parámetros
 * @return int -> tiempo de hospitalización de un objeto Paciente
 *
 */
int Paciente::get_temp_hosp() {
    return tiempo_hospitalizacion;
}

/*
 * Getter del atributo "num_operaciones" de un objeto Paciente
 *
 * @param No recibe parámetros
 * @return int -> número de operaciones de un objeto Paciente
 *
 */
int Paciente::get_num_ops() {
    return num_operaciones;
}

/*
 * Getter del atributo "cuenta" de un objeto Paciente
 *
 * @param No recibe parámetros
 * @return double -> cuenta de un objeto Paciente
 *
 */
double Paciente::get_cuenta() {
    return cuenta;
}

/*
 * Getter del atributo "cuarto" de un objeto Paciente
 *
 * @param No recibe parámetros
 * @return int -> número de cuarto de un objeto Paciente
 *
 */
int Paciente::get_num_cuarto() {
    return cuarto;
}

#endif /* Persona_hpp */
