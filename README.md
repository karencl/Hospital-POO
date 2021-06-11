# Para correcciones de competencias...
Se dejó la competencia de "Tecnologías y herramientas" sin calificar. Es decir, no se me puso ni se me quitó la competencia.

# Proyecto para la materia: programación orientada a objetos
Este trabajo es parte del proyecto para la materia "Programación orientada a objetos".

En este, se trabajarán conceptos de programación, utilizando c++ y se pondrán en práctica, con el fin de practicar más a fondo la programación orientada a objetos, viendo el funcionamiento de nuevos métodos y conexiones, junto con su utilidad.

# Hospital-POO
Mi proyecto se llama "Hospital-POO".

Esta aplicación tiene como propósito, simular la organización de un hospital (a pequeña escala), tomando en cuenta las actividades que se desarrollan en estos; como lo son:
- Administrar el espacio de cuartos para pacientes
- El movimiento del personal médico (tiempo en quirófano, especialidades, honorarios, etc)
- Ingresar y dar de alta a pacientes
- El uso de salas quirúrjicas
- Etc

Esto se quiere hacer, debido a que con la situación actual de la pandemia, muchos hospitales no se han dado abasto en cuanto a suministros médicos y la calidad de administración de ingreso de pacientes, se ha visto reducida por la satuación de espacios en estos.

Para ello, se utilizarán clase como: "Hospital", "Cuarto" y "Persona", junto con sus clases hijas "Medico" y "Paciente".
Todas estas junto sus respectivos atributos y métodos. Lo cual facilitará la construcción y funcionamiento del programa.

# Funcionalidad del programa
- Se crearán objetos de prueba con funciones en el inicio del programa, para observar mejor su funcionamiento.
- A través de un menú de opciones, se podrán llevar a cabo las actividades mencionadas arriba.
- Se hará uso de 5 clases en total (dos de ellas heredn de una).
- Se usarán vectores para el manejo de los objetos de las clases.

# Consideraciones
El programa fue hecho con c++ en la aplicación "Xcode". 
Este debe de correr para todo sistema operativo y se deben de utilizar todos los archivos de código incluidos en este repositorio (el main.cpp y los .h que son de las clases).

Nota: el programa se debe de compilar dependiendo el sistema operativo. Ejemplo: en Windows sería... \a.exe

# Casos para los que el programa...
Funcionaría:
- Se respetan los límites de los vectores al momento de por ejemplo: querer dar de alta a un paciente
- Se ingresan los tipos de datos correctos al momento de crear un nuevo objeto
- Se toman en cuenta los datos y disponibilidades de los cuartos al momento de ingresar un paciente
- Se elige una opción válida en el menú

NO funcionaría:
- Se sobrepasan las posiciones de los vectores "médicos" y "pacientes"
- Se quiere utilizar más médicos de los que hay en una operación
- Se pasan datos erroneos al momento de ingresar o contrarar a un paciente
- Se ignoran los datos de los cuartos (disponibilidad/ capacidad/ etc), por lo que no se pueden ingresar pacientes
- Se ingresan cadenas de caracteres en donde se piden números

# Ejemplo de un alogritmo del programa
- Inicio del ciclo while () {}
- Despliega menú y pide opción al usuario
- if/ else if/ else -> opcion == _numero_
- Se lleva a cabo la instrucción para la opción ingresada
- Cuando termine de correr las instrucciones de esa opción, vuelve al inicio del while
- En caso de ingresar una opción inválida, le vuelve a pedir al usuario una opción
- En caso de ingresar la opción 9, sale del ciclo while 
- Sale del programa

