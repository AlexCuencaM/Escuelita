#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "app.h"
#include "struct/Facultad.h"
//Se uso "recursividad" para evitar iteraciones y errores con whiles :D
//He ahi la explicacion de las veces que saldra el saliendo al final
using namespace std;
Array alumnos;
ArrayFacu facultades;
ArrayMatricula matriculas;
bool isLoaded = true;
FACULTAD test()
{
    FACULTAD facultad = load_test_data();
    return facultad;
}
MATRICULA pedir_matricula(){
    MATRICULA matricula;
    cout << "Ingrese la cedula del alumno: " << endl;
    cin >> matricula.cedula;
    cout << "Ingrese el codigo del paralelo" << endl;
    cin >> matricula.codigo_paralelo;
    return matricula;
}
void init_app()
{
    clrscr();
    int opcion_menu = 0;
    menu();
    cin >> opcion_menu;
    switch (opcion_menu)
    {
    case 1:
        sub_menu("FACULTAD");
        break;
    case 2:
        sub_menu("CARRERA");

        break;
    case 3:
        sub_menu("SEMESTRE");
        break;
    case 4:
        sub_menu("PARALELO");
        break;
    case 5:
        sub_menu("ALUMNO");
        break;
    case 6:
        matriculacion();
        break;
    case 7:
        asignar_notas();
        break;
    case 8:
        promedio_paralelo();
        break;
    case 9:
        promedio_materia();
        break;
    case 10:
        promedio_cedula();
        break;
    case 11:
        default_data();
        break;
    default:
        cout << "Saliendo..." << endl;
    }
}
void main_menu(){

    string confirmar_salida;
    cout << "Ingrese [y] para regresar" << endl
         << "Ingrese un caracter para salir..." <<endl;
    cin >> confirmar_salida;
        transform(confirmar_salida.begin(),
            confirmar_salida.end(), confirmar_salida.begin(), ::toupper);
        if(confirmar_salida == "Y")
            init_app();

}
void matriculacion(){
    clrscr();
    MATRICULA matricula = pedir_matricula();
    bool matricula_registred = is_matricula_registred(facultades, matricula.codigo_paralelo, matricula.cedula);
    if(!matricula_registred)
        cout << "No esta registrado el alumno o el paralelo:c" << endl;
    else{
        //MATRICULAR  A  LA  GENTE :D
        cout << endl << "Matriculando..." << endl;
        insert_matricula(matriculas, matricula);
    }
    main_menu();

}
void asignar_notas(){
    clrscr();
    cout << endl << "FILTRO: " << endl;
    MATRICULA matricula = pedir_matricula();
    if(is_matricula_registred(facultades, matricula.codigo_paralelo, matricula.cedula)){
        cout << "Ingrese nota: " << endl;
        cin >> matricula.nota;
        //Modificar para asignar
        update_matricula(matriculas,matricula);
        main_menu();
    }
    init_app();
}
void promedio_paralelo(){
    clrscr();
    consultar_notas_paralelo_crud(matriculas);
    // consultar_notas_paralelo(matriculas, 3);
    main_menu();
    init_app();
}
void promedio_cedula(){
    consultar_notas_cedula_crud(matriculas);
    main_menu();
    init_app();
}
void promedio_materia(){
    consultar_notas_materia_crud(facultades,matriculas);
    main_menu();
    init_app();
}
void default_data(){
    clrscr();

    if(isLoaded){
        FACULTAD test_facu = test();
        insert_facultad(facultades,test_facu);
    }
    isLoaded = false;
    init_app();
}
string alert_data(){
    return !facultades.empty() ? "DATOS DE PRUEBA CARGADOS EXITOSAMENTE\n": "\n";
}
void menu()
{
    string alert = alert_data();
    cout << "Bienvenidos a la escuela virtual :D " << endl
         << alert
         << "1.-CRUD FACULTAD" << endl
         << "2.-CRUD CARRERA" << endl
         << "3.-CRUD SEMESTRE" << endl
         << "4.-CRUD PARALELO" << endl
         << "5.-CRUD ALUMNO" << endl
         << "6.-MATRICULACION" << endl
         << "7.-ASIGNAR NOTAS" << endl
         << "8.-CONSULTAS DE NOTAS Y PROMEDIO POR CODIGO DE PARALELO" << endl
         << "9.-CONSULTAS DE NOTAS Y PROMEDIO POR CODIGO DE MATERIA" << endl
         << "10.-CONSULTAS DE NOTAS Y PROMEDIO POR CODIGO DE CEDULA" << endl
         << "11.-CARGAR DATOS POR DEFECTO" << endl
         << "12.-SALIR :(" << endl
         << "Por favor, elija una opcion :D" << endl;;
}

void sub_menu(string name_submenu)
{
    clrscr();
    int opcion_menu = 0;
    sub_menu_content(name_submenu);
    cin >> opcion_menu;
    switch (opcion_menu)
    {
    case 1:
        sub_case_1(name_submenu);
        break;
    case 2:
        sub_case_2(name_submenu);
        break;
    case 3:
        sub_case_3(name_submenu);
        break;
    case 4:
        sub_case_4(name_submenu);
        break;
    case 5:
        sub_case_5(name_submenu);
        break;
    case 6:
        sub_case_6(name_submenu);
        break;
    default:
        cout << "Saliendo..." << endl;
    }
}

void sub_menu_content(string name_crud)
{
    clrscr();
    string special =(name_crud == "ALUMNO") ? "CEDULA":"NOMBRE";
    cout << "Sub-menu " << name_crud << endl
         << "1.-AGREGAR" << endl
         << "2.-MODIFICAR" << endl
         << "3.-ELIMINAR" << endl
         << "4.-CONSULTAR POR " + special << endl
         << "5.-CONSULTAR TODOS" << endl
         << "6.-REGRESAR :(" << endl
         << "Por favor, elija una opcion :D" << endl;
}
//Agregar(insert) on CRUD methods
void sub_case_1(string name_crud)
{
    agregar_facultad(name_crud);
    agregar_carrera(name_crud);
    agregar_semestre(name_crud);
    agregar_paralelo(name_crud);
    agregar_alumno(name_crud);

    mini_menu(name_crud);
}
void agregar_alumno(string name_crud){
    if(name_crud == "ALUMNO"){
        ALUMNO alumno;
        int codigo_facultad, codigo_carrera, codigo_semestre;
        cout << "FILTRO" << endl
             << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facultad;
        cout << "Ingrese el codigo de la carrera:";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo del semestre:";
        cin >> codigo_semestre;


        cout << "INSERTAR" << endl
             << "Ingrese cedula: ";
        cin >> alumno.cedula;
        cout << "Ingrese Nombre: ";
        cin >> alumno.nombre;
        cout << "Ingrese correo: ";
        cin >> alumno.correo;

        agregar_alumno_crud(facultades,alumno,codigo_semestre,
            codigo_facultad,codigo_carrera);
    }
}


void agregar_facultad(string name_crud){
    if (name_crud == "FACULTAD"){
        FACULTAD facu;
        cout << "Ingrese codigo: ";
        cin >> facu.codigo;
        cout << "Ingrese Nombre: ";
        cin >> facu.nombre;

        insert_facultad(facultades, facu);
    }
}
void agregar_carrera(string name_crud){
    if (name_crud == "CARRERA"){
        CARRERA career;
        int codigo;
        cout << "Ingrese codigo: ";
        cin >> career.codigo;
        cout << "Ingrese Nombre: ";
        cin >> career.nombre;
        cout << "Ingrese el codigo de la facultad a la que pertenecera la facultad:";
        cin >> codigo;
        agregar_carrera_crud(facultades, career, codigo);
    }
}
void agregar_semestre(string name_crud){
    if(name_crud == "SEMESTRE"){
        SEMESTRE semestre;
        int codigo_facultad, codigo_carrera;
        cout << "FILTRO" << endl
             << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facultad;
        cout << "Ingrese el codigo de la carrera";
        cin >> codigo_carrera;

        cout << "INSERTAR" << endl
             << "Ingrese codigo: ";
        cin >> semestre.codigo;
        cout << "Ingrese Nombre: ";
        cin >> semestre.nombre;

        agregar_semestre_crud(facultades,semestre,codigo_facultad,codigo_carrera);
    }
}

void agregar_paralelo(string name_crud){
    if(name_crud == "PARALELO"){
        PARALELO paralelo;
        int codigo_facultad, codigo_carrera, codigo_semestre;
        cout << "FILTRO" << endl
             << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facultad;
        cout << "Ingrese el codigo de la carrera:";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo del semestre:";
        cin >> codigo_semestre;


        cout << "INSERTAR" << endl
             << "Ingrese codigo: ";
        cin >> paralelo.codigo;
        cout << "Ingrese Nombre: ";
        cin >> paralelo.nombre;

        agregar_paralelo_crud(facultades,paralelo,codigo_semestre,
            codigo_facultad,codigo_carrera);
    }
}

//Modificar(update)
void sub_case_2(string name_crud)
{
    modificar_alumno(name_crud);
    modificar_facultad(name_crud);
    modificar_carrera(name_crud);
    modificar_semestre(name_crud);
    mini_menu(name_crud);
}
void modificar_alumno(string name_crud){
    if (name_crud == "ALUMNO")
    {
        if (alumnos.empty())
            cout << endl
                 << "Esta vacio";
        else
        {
            string nombre, cedula, correo;
            ALUMNO a;
            cout << "Modifique el estudiante buscando por su cedula: ";
            cin >> a.cedula;
            cout << "Ingrese Nombre: ";
            cin >> a.nombre;
            cout << "Ingrese Correo: ";
            cin >> a.correo;
            modificar_alumno_crud(facultades,a);
        }
    }
}

void modificar_facultad(string name_crud){
    if(name_crud == "FACULTAD"){
        if (facultades.empty())
        {
            cout << endl
                 << "Esta vacio";
        }
        else
        {
            string nombre, cedula, correo;
            FACULTAD facu;
            cout << "Modifique la facultad buscando por su codigo: ";
            cin >> facu.codigo;
            cout << "Ingrese Nombre: ";
            cin >> facu.nombre;
            update_facultad(facultades, facu);
        }
    }
}
void modificar_carrera(string name_crud){
    if (name_crud == "CARRERA"){
        CARRERA career;
        int codigo;
        cout << "Ingrese codigo: ";
        cin >> career.codigo;
        cout << "Ingrese Nombre: ";
        cin >> career.nombre;
        cout << "Ingrese el codigo de la facultad a la que pertenecera la facultad:";
        cin >> codigo;
        modificar_carrera_crud(facultades, career, codigo);
    }
}
void modificar_semestre(string name_crud){
    if(name_crud == "SEMESTRE"){
        SEMESTRE semestre;
        int codigo_semestre, codigo_facultad, codigo_carrera;
        cout << "Ingrese codigo: ";
        cin >> semestre.codigo;
        cout << "Ingrese Nombre: ";
        cin >> semestre.nombre;
        cout << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facultad;
        cout << "Ingrese el codigo de la carrera: ";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo del semestre: ";
        cin >> codigo_semestre;
        modificar_semestre_crud(facultades,semestre,
            codigo_facultad,codigo_carrera);
    }
}
void modificar_paralelo(string name_crud){
    if(name_crud == "PARALELO"){
        PARALELO paralelo;
        int codigo_semestre, codigo_facultad, codigo_carrera;
        cout << "Ingrese codigo: ";
        cin >> paralelo.codigo;
        cout << "Ingrese Nombre: ";
        cin >> paralelo.nombre;

        cout << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facultad;
        cout << "Ingrese el codigo de la carrera: ";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo del semestre: ";
        cin >> codigo_semestre;

        modificar_paralelo_crud(facultades,paralelo,codigo_semestre,
            codigo_facultad,codigo_carrera);
    }
}
//Eliminar(delete)
void sub_case_3(string name_crud)
{

    eliminar_facultad(name_crud);
    eliminar_carrera(name_crud);
    eliminar_semestre(name_crud);
    eliminar_paralelo(name_crud);
    eliminar_alumno(name_crud);
    mini_menu(name_crud);
}

string pedir_id_unico(string name_crud){
    return "ELIMINAR\nIngrese el codigo de " + name_crud + ":\n";
}

void eliminar_alumno(string name_crud){
    if (name_crud == "ALUMNO")
    {
        string cedula;
        cout << pedir_id_unico(name_crud);
        cin >> cedula;
        eliminar_alumno_crud(facultades,cedula);
    }
}

void eliminar_facultad(string name_crud){
    if (name_crud == "FACULTAD")
    {
        int codigo;
        cout << pedir_id_unico(name_crud);
        cin >> codigo;
        delete_facultad(facultades, codigo);
    }
}

void eliminar_carrera(string name_crud){
    if(name_crud == "CARRERA"){
        int codigo_carrera, codigo_facu;
        cout << "FILTROS" << endl;
        cout << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facu;

        cout << pedir_id_unico(name_crud);
        cin >> codigo_carrera;

        eliminar_carrera_crud(facultades,codigo_facu, codigo_carrera);
    }
}

void eliminar_semestre(string name_crud){
    if(name_crud == "SEMESTRE"){
        int codigo_carrera, codigo_facu, codigo_semestre;
        cout << "FILTROS" << endl;
        cout << "Ingrese el codigo de la carrera: ";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facu;
        cout << pedir_id_unico(name_crud);
        cin >> codigo_semestre;
        eliminar_semestre_crud(facultades,codigo_facu,
            codigo_carrera,codigo_semestre);

    }
}
void eliminar_paralelo(string name_crud){
    if(name_crud == "PARALELO"){
        int codigo_carrera, codigo_facu, codigo_paralelo,codigo_semestre;
        cout << "FILTROS" << endl;
        cout << "Ingrese el codigo de la carrera: ";
        cin >> codigo_carrera;
        cout << "Ingrese el codigo de la facultad: ";
        cin >> codigo_facu;
        cout << "Ingrese el codigo de semestre: ";
        cin >> codigo_semestre;

        cout << pedir_id_unico(name_crud);
        cin >> codigo_paralelo;
        eliminar_paralelo_crud(facultades,codigo_paralelo, codigo_facu,
            codigo_carrera,codigo_semestre);

    }
}

//Consultar por nombre(select)
void sub_case_4(string name_crud)
{
    consultar_alumno(name_crud);
    consultar_facultad(name_crud);
    consultar_carrera(name_crud);
    consultar_semestre(name_crud);
    consultar_paralelo(name_crud);
    mini_menu(name_crud);
}
void consultar_alumno(string name_crud){
    if (name_crud == "ALUMNO")
    {
        string alumno;
        cout << "Ingrese la cedula del alumno" << endl;
        cin >> alumno;
        consultar_alumno_por_cedula_crud(facultades,alumno);
    }
}
void consultar_facultad(string name_crud){
    if (name_crud == "FACULTAD")
    {
        string alumno;
        cout << "Ingrese el nombre de la facultad" << endl;
        cin >> alumno;
        FACULTAD result = select_facultad_by_name(facultades, alumno);
        printFacultad(result);
    }
}

void consultar_carrera(string name_crud){
    if (name_crud == "CARRERA")
    {
        string carrera;
        cout << "Ingrese el nombre de la carrera" << endl;
        cin >> carrera;
        consultar_carrera_por_nombre_crud(facultades,carrera);
    }
}
void consultar_semestre(string name_crud){
    if(name_crud == "SEMESTRE"){
        string semestre;
        cout << "Ingrese el nombre del semestre" << endl;
        cin >> semestre;
        consultar_semestre_por_nombre_crud(facultades, semestre);
    }
}

void consultar_paralelo(string name_crud){
    if(name_crud == "PARALELO"){
        string paralelo;
        cout << "Ingrese el nombre del paralelo" << endl;
        cin >> paralelo;
        consultar_paralelo_por_nombre_crud(facultades, paralelo);
    }
}

//Consultar(select)
void sub_case_5(string name_crud)
{
    clrscr();
    if (name_crud == "ALUMNO")
        consultar_alumno_crud(facultades);
    else if(name_crud == "FACULTAD")
        printFacultades(facultades);
    else if(name_crud == "CARRERA")
        consultar_carrera_crud(facultades);
    else if(name_crud == "SEMESTRE")
        consultar_semestre_crud(facultades);
    else if(name_crud == "PARALELO")
        consultar_paralelo_crud(facultades);
    mini_menu(name_crud);
}

//Los dirige al menu principal :D
void sub_case_6(string name_crud)
{
    init_app();
}
void mini_menu(string name_crud)
{
    int opcion_menu = 0;
    mini_menu_content();
    cin >> opcion_menu;
    switch (opcion_menu)
    {
    case 1:
        sub_menu(name_crud);
        break;
    case 2:
        init_app();
        /* code */
        break;

    default:
        break;
    }
}

void mini_menu_content()
{
    cout << endl << endl
         << "1.-Regresar al submenu" << endl
         << "2.-Regresar al menu principal" << endl
         << "Ingrese una opcion: ";
}
FACULTAD load_test_data(){
    FACULTAD facu = {
        1,"FMCF",
        {
            //Carreras
            {1, "Software",{
                //Semestres
                {1,"1er semestre",{
                    //Materias
                    {1,"Algoritmos y logica de programacion",{
                        //Paralelos
                        {1,"S1A",{
                            //Estudiantes
                            {"0987654321","Alex", "a@a"},
                            {"0987654322","Karen", "b@a"},
                            {"0987654323","Max", "c@a"},
                        }},
                        {2,"S1B",{
                            //Estudiantes
                            {"0985712524","Juan", "j@a"},
                            {"0985712525","Carol", "b@a"},
                            {"0985712526","Dante", "c@a"},
                        }}
                    }},
                    {2,"Estructuras discretas",{
                        {1,"S1A",{
                            {"0987654321","Alex", "a@a"},
                            {"0987654322","Karen", "b@a"},
                            {"0987654323","Max", "c@a"},
                        }},
                        {2,"S1B",{
                            //Estudiantes
                            {"0985712524","Juan", "j@a"},
                            {"0985712525","Carol", "b@a"},
                            {"0985712526","Dante", "c@a"},
                        }}
                    }},
                    {3,"Calculo diferencial",{
                        {1,"S1A",{
                            {"0987654321","Alex", "a@a"},
                            {"0987654322","Karen", "b@a"},
                            {"0987654323","Max", "c@a"},
                        }},
                        {2,"S1B",{
                            //Estudiantes
                            {"0985712524","Juan", "j@a"},
                            {"0985712525","Carol", "b@a"},
                            {"0985712526","Dante", "c@a"},
                        }}
                    }}

                }}
            }},

            {2, "Tecnologia de la informacion",{
                {1,"1er semestre",{
                    //Materias
                    {4,"Programaacion",{
                        //Paralelos
                        {3,"T1A",{
                            //Estudiantes
                            {"0963412593","Bob", "a@a"},
                            {"0963412594","Maria", "b@a"},
                            {"0963412595","Roberto", "c@a"},
                        }}
                    }},
                    {5,"Algebra Lineal",{
                        {3,"T1A",{
                            {"0963412593","Bob", "a@a"},
                            {"0963412594","Maria", "b@a"},
                            {"0963412595","Roberto", "c@a"},
                        }}
                    }},
                    {6,"Calculo diferencial",{
                        {3,"T1A",{
                            {"0963412593","Bob", "a@a"},
                            {"0963412594","Maria", "b@a"},
                            {"0963412595","Roberto", "c@a"},
                        }}
                    }}

                }}

            } }
        },

    };
    return facu;
}
//Clear screen without SO commands :D
//https://stackoverflow.com/questions/17335816/clear-screen-using-c#32008479
void clrscr()
{
    cout << "\033[2J\033[1;1H";
}
