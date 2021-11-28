#ifndef FACULTAD_H
#define FACULTAD_H
#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct ALUMNO{
    string cedula;
    string nombre;
    string correo;
    bool operator==(ALUMNO alumno);
};
typedef vector<ALUMNO> Array;
struct PARALELO{
    int codigo;
    string nombre;
    Array estudiantes;
    bool operator==(PARALELO paralelo);
};
typedef vector<PARALELO> ArrayParalelo;
struct MATERIA {
    int codigo;
    string nombre;
    ArrayParalelo paralelos;
    bool operator==(MATERIA semestre);
};
typedef vector<MATERIA> ArrayMateria;
struct SEMESTRE{
    int codigo;
    string nombre;
    ArrayMateria materias;
    bool operator==(SEMESTRE semestre);
};
typedef vector<SEMESTRE> ArraySemestre;
struct CARRERA{
    int codigo;
    string nombre;
    ArraySemestre semestres;
    bool operator==(CARRERA carrera);
};
typedef vector<CARRERA> ArrayCarrera;
struct FACULTAD{
    int codigo; 
    string nombre; 
    ArrayCarrera carreras;  
    bool operator==(FACULTAD FACULTAD);
};
typedef vector<FACULTAD> ArrayFacu;
struct MATRICULA{
    string cedula;
    int codigo_paralelo;
    double nota;
    bool operator==(FACULTAD FACULTAD);
};
typedef vector<MATRICULA> ArrayMatricula;

typedef set<double > SetNotas;

//////////////////////////////////////////////////////////////////////////////
//FACULTADES
void insert_facultad(ArrayFacu &facultades,
    FACULTAD facultad);
FACULTAD select_facultad_by_name(const ArrayFacu facultades, string name);
void update_facultad(ArrayFacu &facultades,
    FACULTAD facultad);
void delete_facultad(ArrayFacu &facultades, int codigo);
void printFacultad(FACULTAD facultad);
void printFacultades(const ArrayFacu &facultades);
//////////////////////////////////////////////////////////////////////////////
//CARRERAS
void insert_carrera(ArrayCarrera &carreras,
    CARRERA carrera);    
CARRERA select_carrera_by_name(const ArrayCarrera carreras, string name);
void update_carrera(ArrayCarrera &carreras,
    CARRERA carrera);
void delete_carrera(ArrayCarrera &carreras, int codigo);
void printCarrera(CARRERA carrera);
void printCarreras(const ArrayCarrera &carreras);

////    ////    ////    ////    ////    ////    ////    ////    ////    ////
void agregar_carrera_crud(ArrayFacu &facultades,CARRERA nueva_carrera,int codigo_facultad);
void modificar_carrera_crud(ArrayFacu &facultades,CARRERA nueva_carrera,int codigo_facultad);
void eliminar_carrera_crud(ArrayFacu &facultades, int codigo_facu, int codigo_carrera);
void consultar_carrera_crud(const ArrayFacu &facultades);
void consultar_carrera_por_nombre_crud(const ArrayFacu &facultades,string nombre_carrera);

//////////////////////////////////////////////////////////////////////////////
//SEMESTRES
void insert_semestre(ArraySemestre &semestres,
    SEMESTRE semestre);
SEMESTRE select_semestre_by_name(const ArraySemestre semestres, string name);
void update_semestre(ArraySemestre &semestres,
    SEMESTRE semestre);
void delete_semestre(ArraySemestre &semestres, int codigo);
void printSemestre(SEMESTRE semestre);
void printSemestres(const ArraySemestre &semestres);

////    ////    ////    ////    ////    ////    ////    ////    ////    ////
void agregar_semestre_crud(ArrayFacu &facultades,SEMESTRE nuevo_semestre,
    int codigo_facultad, int codigo_carrera);
void modificar_semestre_crud(ArrayFacu &facultades,SEMESTRE semestre,
    int codigo_carrera, int codigo_facultad);
void eliminar_semestre_crud(ArrayFacu &facultades,
    int codigo_facu, int codigo_carrera, int codigo_semestre);
void consultar_semestre_crud(const ArrayFacu &semestres);
void consultar_semestre_por_nombre_crud(const ArrayFacu &facultades,string nombre_semestre);
//////////////////////////////////////////////////////////////////////////////
//MATERIAS
ArrayMateria materia_default(CARRERA carrera, SEMESTRE nuevo_semestre);

void insert_materia(ArrayMateria &materias,
    MATERIA materia);
MATERIA select_materia_by_name(const ArrayMateria materias, string name);
void update_materia(ArrayMateria &materias,
    MATERIA materia);
void delete_materia(ArrayMateria &materias, int codigo);
void printMateria(MATERIA materia);
void printMaterias(const ArrayMateria &materias);


//////////////////////////////////////////////////////////////////////////////
//PARALELOS
void insert_paralelo(ArrayParalelo &paralelos, PARALELO paralelo);
void select_all(ArrayParalelo paralelos);
PARALELO select_paralelo_by_name(const ArrayParalelo paralelos, string name);
PARALELO select_paralelo_by_codigo(const ArrayParalelo paralelos, int codigo);
void update_paralelo(ArrayParalelo &paralelos,
    PARALELO paralelo);
void delete_paralelo(ArrayParalelo &paralelos, int codigo);
void printParalelo(PARALELO paralelo);
void printParalelos(const ArrayParalelo &paralelos);
////    ////    ////    ////    ////    ////    ////    ////    ////    ////
void consultar_paralelo_crud(const ArrayFacu &facultades);
void consultar_paralelo_por_nombre_crud(const ArrayFacu &facultades, string nombre_paralelo);
void agregar_paralelo_crud(ArrayFacu &facultades, PARALELO nuevo_paralelo,
                           int codigo_semestre,int codigo_facultad, int codigo_carrera);

void eliminar_paralelo_crud(ArrayFacu &facultades, int codigo_paralelo,
                            int codigo_facultad, int codigo_carrera, int codigo_semestre);
void modificar_paralelo_crud(ArrayFacu &facultades, PARALELO nuevo_paralelo,
                             int codigo_semestre,int codigo_facultad, int codigo_carrera);

void agregar_paralelo_crud(ArrayFacu &facultades, PARALELO nuevo_paralelo,
                           int codigo_semestre,int codigo_facultad, int codigo_carrera);

//////////////////////////////////////////////////////////////////////////////
//ALUMNOS
void insert_alumno(Array &alumnos, ALUMNO alumno);
void select_all(Array alumnos);
ALUMNO select_alumno_by_cedula(const Array alumnos, string cedula);
void update_alumno(Array &alumnos,
    ALUMNO alumno);
void delete_alumno(Array &alumnos, string cedula);
void printAlumno(ALUMNO alumno);
void printAlumnos(const Array &alumnos);

void agregar_alumno_crud(ArrayFacu &facultades, ALUMNO nuevo_alumno,
                           int codigo_semestre,int codigo_facultad, int codigo_carrera);

void modificar_alumno_crud(ArrayFacu &facultades, ALUMNO nuevo_alumno);
void eliminar_alumno_crud(ArrayFacu &facultades, string cedula);
void consultar_alumno_crud(const ArrayFacu &facultades);
void consultar_alumno_por_cedula_crud(const ArrayFacu &facultades, string cedula);
//////////////////////////////////////////////////////////////////////////////
//MATRICULA
void insert_matricula(ArrayMatricula &matriculas, MATRICULA matricula);
void update_matricula(ArrayMatricula &matriculas,
                   MATRICULA matricula_search);

MATRICULA select_matricula_by_cedula_codigo(const ArrayMatricula matriculas,
    MATRICULA matricula_search);
bool is_matricula_registred(const ArrayFacu &facultades, int codigo_paralelo, string cedula);
//////////////////////////////////////////////////////////////////////////////
//CONSULTA NOTAS

SetNotas get_codigo_paralelo(ArrayMatricula matriculas);
void consultar_notas_paralelo_crud(ArrayMatricula matriculas);
void sumar_por_paralelo(ArrayMatricula matriculas, int codigo_paralelo);

set<string> get_cedula_alumno(ArrayMatricula matriculas);
void consultar_notas_cedula_crud(ArrayMatricula matriculas);
void sumar_por_cedula(ArrayMatricula matriculas, string cedula);

void consultar_notas_materia_crud(const ArrayFacu facultades,const ArrayMatricula matriculas);


#endif
