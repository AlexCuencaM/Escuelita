#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include <iostream>
#include "struct/Facultad.h"
using namespace std;
void init_app();
void menu();

FACULTAD test();
string alert_data();
void matriculacion();
void main_menu();
MATRICULA pedir_matricula();
void asignar_notas();
void promedio_paralelo();
void promedio_cedula();
void promedio_materia();

//Sub-menu section
void sub_menu(string name_submenu);
void sub_menu_content(string name_crud);

void default_data();
void sub_case_1(string name_crud);
void agregar_facultad(string name_crud);
void agregar_carrera(string name_crud);
void agregar_semestre(string name_crud);
void agregar_materia(string name_crud);
void agregar_paralelo(string name_crud);
void agregar_alumno(string name_crud);

void sub_case_2(string name_crud);
void modificar_facultad(string name_crud);
void modificar_carrera(string name_crud);
void modificar_semestre(string name_crud);
void modificar_materia(string name_crud);
void modificar_paralelo(string name_crud);
void modificar_alumno(string name_crud);


void sub_case_3(string name_crud);
string pedir_id_unico(string name_crud);
void eliminar_facultad(string name_crud);
void eliminar_carrera(string name_crud);
void eliminar_semestre(string name_crud);
void eliminar_materia(string name_crud);
void eliminar_paralelo(string name_crud);
void eliminar_alumno(string name_crud);

void sub_case_4(string name_crud);
void consultar_facultad(string name_crud);
void consultar_carrera(string name_crud);
void consultar_semestre(string name_crud);
void consultar_materia(string name_crud);
void consultar_paralelo(string name_crud);
void consultar_alumno(string name_crud);

void sub_case_5(string name_crud);

void sub_case_6(string name_crud);

//Mini-menu section
void mini_menu(string name_crud);
void mini_menu_content();

FACULTAD load_test_data();
//clear screen :D
void clrscr();
#endif // APP_H_INCLUDED
