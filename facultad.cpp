#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include "struct/Facultad.h"
#include "cedula.h"
using namespace std;
bool FACULTAD::operator==(FACULTAD facultad)
{
    return facultad.codigo == codigo;
}

bool PARALELO::operator==(PARALELO paralelo)
{
    return paralelo.codigo == codigo;
}

bool ALUMNO::operator==(ALUMNO alumno)
{
    return alumno.cedula == cedula;
}
bool CARRERA::operator==(CARRERA carrera)
{
    return carrera.codigo == codigo;
}
bool SEMESTRE::operator==(SEMESTRE semestre)
{
    return semestre.codigo == codigo;
}
bool MATERIA::operator==(MATERIA materia)
{
    return materia.codigo == codigo;
}


void delete_facultad(ArrayFacu &facultades, int codigo)
{
    if (facultades.empty())
        cout << endl
             << "Esta vacio :c" << endl;
    else
    {
        //Itera cada elemento del arrayfacu de tipo FACULTAD facultades
        //auto infiere el tipo de dato de "facultad" en este caso es FACULTAD
        for (auto facultad : facultades)
        {
            if (facultad.codigo == codigo)
            {
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // codigo:""
                //Remove retorna un iterador del arrayfacu excepto el facultad a borrar
                ArrayFacu::iterator iterador = remove(facultades.begin(), facultades.end(), facultad);
                //Reemplaza el contenido de facultad por iterador
                //borra del arrayfacu
                facultades.erase(iterador,
                                 facultades.end());
                return;
            }
        }
        cout << "No se encontró el facultad :c";
    }
}

void insert_facultad(ArrayFacu &facultades, FACULTAD facu)
{
    facultades.push_back(facu);
}

FACULTAD select_facultad_by_name(const ArrayFacu facultades, string name)
{
    FACULTAD notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto facultad : facultades)
    {
        if (facultad.nombre == name)
            return facultad;
    }
    return notFound;
}
void printFacultad(FACULTAD facultad)
{
    cout << endl
         << "Datos del facultad: " << facultad.nombre << endl
         << "Codigo: " << facultad.codigo << endl;
}

void printFacultades(const ArrayFacu &facultades)
{
    if (facultades.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto facultad : facultades)
            printFacultad(facultad);
    }
}
void update_facultad(ArrayFacu &facultades,
                     FACULTAD facu)
{
    if (facultades.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable facultad pueda modificar directamente al arrayfacu :D
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == facu.codigo)
            {
                facultad.nombre = facu.nombre;
                cout << endl
                     << "Registro actualizado de: " << facu.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el FACULTAD :(" << endl;
    }
}
///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD CARRERA///////////////////////

void delete_carrera(ArrayCarrera &carreras, int codigo)
{
    if (carreras.empty())
        cout << endl
             << "No hay carreras :c" << endl;
    else
    {
        //Itera cada elemento del arraycarrera de tipo CARRERA carreras
        //auto infiere el tipo de dato de "carrera" en este caso es CARRERA
        for (auto carrera : carreras)
        {
            if (carrera.codigo == codigo)
            {
                cout << endl
                     << "Se ha eliminado la carrera " << carrera.nombre;
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // codigo:""
                //Remove retorna un iterador del arraycarrera excepto el carrera a borrar

                ArrayCarrera::iterator iterador = remove(carreras.begin(), carreras.end(), carrera);
                //Reemplaza el contenido de carrera por iterador
                //borra del arraycarrera
                carreras.erase(iterador,
                               carreras.end());
                return;
            }
        }
        cout << "No se encontró el carrera :c";
    }
}

void insert_carrera(ArrayCarrera &carreras, CARRERA carrera)
{
    carreras.push_back(carrera);
}

CARRERA select_carrera_by_name(const ArrayCarrera carreras, string name)
{
    CARRERA notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto carrera : carreras)
    {
        if (carrera.nombre == name)
            return carrera;
    }
    return notFound;
}
void printCarrera(CARRERA carrera)
{
    cout << endl
         << "Datos del carrera: " << carrera.nombre << endl
         << "Codigo: " << carrera.codigo << endl;
}

void printCarreras(const ArrayCarrera &carreras)
{
    if (carreras.empty())
    {
        cout << endl
             << "No hay carreras :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto carrera : carreras)
            printCarrera(carrera);
    }
}
void update_carrera(ArrayCarrera &carreras,
                    CARRERA career)
{
    if (carreras.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable carrera pueda modificar directamente al arraycarrera :D
        for (auto &carrera : carreras)
        {
            if (carrera.codigo == career.codigo)
            {
                carrera.nombre = career.nombre;
                cout << endl
                     << "Registro actualizado de: " << career.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el CARRERA :(" << endl;
    }
}

///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////
void agregar_carrera_crud(ArrayFacu &facultades, CARRERA nueva_carrera, int codigo_facultad)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == codigo_facultad)
            {
                insert_carrera(facultad.carreras, nueva_carrera);
                cout << endl
                     << "Se ha registrado la carrera en la facultad "
                     << facultad.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se encontro la FACULTAD :c" << endl;
    }
}
void modificar_carrera_crud(ArrayFacu &facultades, CARRERA carrera, int codigo_facultad)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == codigo_facultad)
            {
                update_carrera(facultad.carreras, carrera);
                return;
            }
        }
        cout << endl
             << "No se encontro la FACULTAD :c" << endl;
    }
}

void eliminar_carrera_crud(ArrayFacu &facultades, int codigo_facu, int codigo_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (codigo_facu == facultad.codigo)
            {
                cout << endl
                     << "Facultad " << facultad.nombre << endl;
                delete_carrera(facultad.carreras, codigo_carrera);
            }
        }
    }
}

void consultar_carrera_crud(const ArrayFacu &facultades)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            cout << endl
                 << "Carreras de la facultad: " << facultad.nombre << endl;
            printCarreras(facultad.carreras);
        }
    }
}
void consultar_carrera_por_nombre_crud(const ArrayFacu &facultades, string nombre_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            CARRERA career = select_carrera_by_name(facultad.carreras, nombre_carrera);
            if (career.codigo != 0)
            {
                cout << "Facultad: " << facultad.nombre << endl;
                printCarrera(career);
                return;
            }
        }
        cout << "No se ha encontrado la carrera " << nombre_carrera << ":c" << endl;
    }
}
///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD SEMESTRE///////////////////////

void delete_semestre(ArraySemestre &semestres, int codigo)
{
    if (semestres.empty())
        cout << endl
             << "No hay semestres :c" << endl;
    else
    {
        //Itera cada elemento del arraysemestre de tipo SEMESTRE semestres
        //auto infiere el tipo de dato de "semestre" en este caso es SEMESTRE
        for (auto semestre : semestres)
        {
            if (semestre.codigo == codigo)
            {
                cout << endl
                     << "Se ha eliminado la semestre " << semestre.nombre;
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // codigo:""
                //Remove retorna un iterador del arraysemestre excepto el semestre a borrar

                ArraySemestre::iterator iterador = remove(semestres.begin(), semestres.end(), semestre);
                //Reemplaza el contenido de semestre por iterador
                //borra del arraysemestre
                semestres.erase(iterador,
                                semestres.end());
                return;
            }
        }
        cout << "No se encontró el semestre :c";
    }
}

void insert_semestre(ArraySemestre &semestres, SEMESTRE semestre)
{
    semestres.push_back(semestre);
}

SEMESTRE select_semestre_by_name(const ArraySemestre semestres, string name)
{
    SEMESTRE notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto semestre : semestres)
    {
        if (semestre.nombre == name)
            return semestre;
    }
    return notFound;
}
void printSemestre(SEMESTRE semestre)
{
    cout << endl
         << "Datos del semestre: " << semestre.nombre << endl
         << "Codigo: " << semestre.codigo << endl;
}

void printSemestres(const ArraySemestre &semestres)
{
    if (semestres.empty())
    {
        cout << endl
             << "No hay semestres :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto semestre : semestres)
            printSemestre(semestre);
    }
}
void update_semestre(ArraySemestre &semestres,
                     SEMESTRE semester)
{
    if (semestres.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable semestre pueda modificar directamente al arraysemestre :D
        //Cambiarse
        for (auto &semestre : semestres)
        {
            if (semestre.codigo == semester.codigo)
            {
                semestre.nombre = semestre.nombre;
                cout << endl
                     << "Registro actualizado de: " << semestre.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el SEMESTRE :(" << endl;
    }
}

ArrayMateria materia_default(CARRERA carrera,
                             SEMESTRE nuevo_semestre)
{
    ArrayMateria
        materias = {
            {1, "MATERIA_1_CARRERA_" + to_string(carrera.codigo) + "_SEMESTRE_" + to_string(nuevo_semestre.codigo)},
            {2, "MATERIA_2_CARRERA_" + to_string(carrera.codigo) + "_SEMESTRE_" + to_string(nuevo_semestre.codigo)},
            {3, "MATERIA_3_CARRERA_" + to_string(carrera.codigo) + "_SEMESTRE_" + to_string(nuevo_semestre.codigo)},
            {3, "MATERIA_4_CARRERA_" + to_string(carrera.codigo) + "_SEMESTRE_" + to_string(nuevo_semestre.codigo)},
        };
    return materias;
}
///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////
void agregar_semestre_crud(ArrayFacu &facultades, SEMESTRE nuevo_semestre,
                           int codigo_facultad, int codigo_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (codigo_facultad == facultad.codigo)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        ArrayMateria materias_default = materia_default(carrera, nuevo_semestre);
                        nuevo_semestre.materias.assign(materias_default.begin(),
                                                       materias_default.end());

                        cout << endl
                             << nuevo_semestre.materias[0].nombre << endl;
                        insert_semestre(carrera.semestres, nuevo_semestre);
                        cout << endl
                             << "Se ha registrado el semestre en la carrera "
                             << carrera.nombre << endl;
                        return;
                    }
                }
                cout << endl
                     << "No se encontro la CARRERA :c" << endl;
                return;
            }


        }
        cout << endl
                     << "No se encontro la FACULTAD :c" << endl;

    }
}
void modificar_semestre_crud(ArrayFacu &facultades, SEMESTRE semestre,
                             int codigo_carrera, int codigo_facultad)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == codigo_facultad)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        update_semestre(carrera.semestres, semestre);
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return;
            }

        }
        cout << endl
             << "No se encontro la FACULTAD :c" << endl;
    }
}

void eliminar_semestre_crud(ArrayFacu &facultades,
                            int codigo_facu, int codigo_carrera, int codigo_semestre)
{

    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (codigo_facu == facultad.codigo && !facultad.carreras.empty())
            {

                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {

                        cout << endl
                             << "Carrera: " << carrera.nombre << endl;
                        delete_semestre(carrera.semestres, codigo_semestre);
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return;
            }
        }
        cout << "No se encontro la FACULTAD" << endl;

    }
}

void consultar_semestre_crud(const ArrayFacu &facultades)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            if (!facultad.carreras.empty())
            {
                for (const auto carrera : facultad.carreras)
                {
                    cout << endl
                         << "Semestres de la carrera: " << carrera.nombre << endl;
                    printSemestres(carrera.semestres);
                }
            }
            else
                cout << "La facultad " << facultad.nombre << " no tiene carreras :c" << endl;
        }
    }
}
void consultar_semestre_por_nombre_crud(const ArrayFacu &facultades, string nombre_semestre)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            for (auto carrera : facultad.carreras)
            {
                SEMESTRE semester = select_semestre_by_name(carrera.semestres, nombre_semestre);
                if (semester.codigo != 0)
                {
                    cout << endl
                         << "Facultad: " << facultad.nombre << endl;
                    printSemestre(semester);
                }
                else
                    cout << "No se ha encontrado el semestre: "
                         << nombre_semestre << " :c" << endl;
            }
        }

    }
}

///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD PARALELO///////////////////////
void delete_materia(ArrayMateria &materias, int codigo)
{
    if (materias.empty())
        cout << endl
             << "Esta vacio :c" << endl;
    else
    {
        //Itera cada elemento del arraymateria de tipo MATERIA materias
        //auto infiere el tipo de dato de "materia" en este caso es MATERIA
        for (auto materia : materias)
        {
            if (materia.codigo == codigo)
            {
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // codigo:""
                //Remove retorna un iterador del arraymateria excepto el materia a borrar
                ArrayMateria::iterator iterador = remove(materias.begin(), materias.end(), materia);
                //Reemplaza el contenido de materia por iterador
                //borra del arraymateria
                materias.erase(iterador,
                                materias.end());
                return;
            }
        }
        cout << "No se encontró el materia :c";
    }
}

void insert_materia(ArrayMateria &materias,
                     MATERIA facu)
{
    materias.push_back(facu);
}
void select_all(const ArrayMateria materias)
{
    if (materias.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        for (const auto materia : materias)
            cout << materia.nombre << endl;
    }
}
MATERIA select_materia_by_name(const ArrayMateria materias, string name)
{
    MATERIA notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto materia : materias)
    {
        if (materia.nombre == name)
            return materia;
    }
    return notFound;
}
void printMateria(MATERIA materia)
{
    cout << endl
         << "Datos del materia: " << materia.nombre << endl
         << "Codigo: " << materia.codigo << endl;
}

void printMaterias(const ArrayMateria &materias)
{
    if (materias.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto materia : materias)
            printMateria(materia);
    }
}
void update_materia(ArrayMateria &materias,
                     MATERIA facu)
{
    if (materias.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable materia pueda modificar directamente al arraymateria :D
        for (auto &materia : materias)
        {
            if (materia.codigo == facu.codigo)
            {
                materia.nombre = facu.nombre;
                cout << endl
                     << "Registro actualizado de: " << facu.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el MATERIA :(" << endl;
    }
}

///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD PARALELO///////////////////////
void delete_paralelo(ArrayParalelo &paralelos, int codigo)
{
    if (paralelos.empty())
        cout << endl
             << "Esta vacio :c" << endl;
    else
    {
        //Itera cada elemento del arrayparalelo de tipo PARALELO paralelos
        //auto infiere el tipo de dato de "paralelo" en este caso es PARALELO
        for (auto paralelo : paralelos)
        {
            if (paralelo.codigo == codigo)
            {
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // codigo:""
                //Remove retorna un iterador del arrayparalelo excepto el paralelo a borrar
                ArrayParalelo::iterator iterador = remove(paralelos.begin(), paralelos.end(), paralelo);
                //Reemplaza el contenido de paralelo por iterador
                //borra del arrayparalelo
                paralelos.erase(iterador,
                                paralelos.end());
                return;
            }
        }
        cout << "No se encontró el paralelo :c";
    }
}

void insert_paralelo(ArrayParalelo &paralelos,
                     PARALELO facu)
{
    paralelos.push_back(facu);
}
void select_all(const ArrayParalelo paralelos)
{
    if (paralelos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        for (const auto paralelo : paralelos)
            cout << paralelo.nombre << endl;
    }
}
PARALELO select_paralelo_by_name(const ArrayParalelo paralelos, string name)
{
    PARALELO notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto paralelo : paralelos)
    {
        if (paralelo.nombre == name)
            return paralelo;
    }
    return notFound;
}
PARALELO select_paralelo_by_codigo(const ArrayParalelo paralelos, int codigo)
{
    PARALELO notFound;
    notFound.nombre = "NA";
    notFound.codigo = 0;
    for (const auto paralelo : paralelos)
    {
        if (paralelo.codigo == codigo)
            return paralelo;
    }
    return notFound;
}
void printParalelo(PARALELO paralelo)
{
    cout << endl
         << "Datos del paralelo: " << paralelo.nombre << endl
         << "Codigo: " << paralelo.codigo << endl;
}

void printParalelos(const ArrayParalelo &paralelos)
{
    if (paralelos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto paralelo : paralelos)
            printParalelo(paralelo);
    }
}
void update_paralelo(ArrayParalelo &paralelos,
                     PARALELO facu)
{
    if (paralelos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable paralelo pueda modificar directamente al arrayparalelo :D
        for (auto &paralelo : paralelos)
        {
            if (paralelo.codigo == facu.codigo)
            {
                paralelo.nombre = facu.nombre;
                cout << endl
                     << "Registro actualizado de: " << facu.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el PARALELO :(" << endl;
    }
}
///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////

void agregar_paralelo_crud(ArrayFacu &facultades, PARALELO nuevo_paralelo,
                           int codigo_semestre,int codigo_facultad, int codigo_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (codigo_facultad == facultad.codigo)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        for(auto &semestre: carrera.semestres){
                            if(semestre.codigo == codigo_semestre)
                            {
                                for(auto &materia: semestre.materias){
                                    cout << endl
                                         << "Se ha registrado la materia: " << materia.nombre << " en el paralelo: "
                                         << nuevo_paralelo.nombre << endl;
                                    insert_paralelo(materia.paralelos,nuevo_paralelo);
                                }
                                return;
                            }

                        }
                        cout << endl << "No se encontro el SEMESTRE" << endl;
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return ;
            }

        }
        cout << "No se encontro la facultad" << endl;

    }
}


void modificar_paralelo_crud(ArrayFacu &facultades, PARALELO nuevo_paralelo,
                             int codigo_semestre,int codigo_facultad, int codigo_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == codigo_facultad)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        for(auto &semestre: carrera.semestres){
                            if(semestre.codigo == codigo_semestre)
                            {
                                for(auto &materia: semestre.materias){
                                    cout << endl << " El paralelo: "
                                         << nuevo_paralelo.nombre << endl
                                         << "ha sido modificado en la materia: " << materia.nombre << endl;
                                    update_paralelo(materia.paralelos,nuevo_paralelo);
                                }
                                return;
                            }

                        }
                        cout << endl << "No se encontro el SEMESTRE" << endl;
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return ;
            }

        }
        cout << endl
             << "No se encontro el SEMESTRE :c" << endl;
    }
}

void eliminar_paralelo_crud(ArrayFacu &facultades, int codigo_paralelo,
                            int codigo_facultad, int codigo_carrera, int codigo_semestre)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (facultad.codigo == codigo_facultad)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        for(auto &semestre: carrera.semestres){
                            if(semestre.codigo == codigo_semestre)
                            {
                                for(auto &materia: semestre.materias){
                                    cout << endl
                                    << "Carrera: " << carrera.nombre << endl;
                                    delete_paralelo(materia.paralelos,codigo_paralelo);

                                }
                                return;
                            }
                        }
                        cout << endl << "No se encontro el SEMESTRE" << endl;
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return ;
            }

        }
        cout << "No se encontro la facultad" << endl;
    }
}

void consultar_paralelo_crud(const ArrayFacu &facultades)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            if (!facultad.carreras.empty())
            {
                for (const auto carrera : facultad.carreras)
                {
                    for (const auto semestre: carrera.semestres)
                    {
                        for(const auto materia: semestre.materias)
                        {
                            cout << endl << "Materia:" << materia.nombre;
                            printParalelos(materia.paralelos);
                        }

                    }
                }
            }
            else
                cout << "La facultad " << facultad.nombre << " no tiene carreras :c" << endl;
        }
    }
}
void consultar_paralelo_por_nombre_crud(const ArrayFacu &facultades, string nombre_paralelo)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            for (const auto carrera : facultad.carreras)
            {
                for (const auto semestre: carrera.semestres)
                {
                    for(const auto materia: semestre.materias)
                    {
                        PARALELO paralelo = select_paralelo_by_name(materia.paralelos,nombre_paralelo);
                        if (paralelo.codigo != 0)
                        {
                            cout << endl
                                << "Semestre: " << semestre.nombre << endl;
                            printParalelo(paralelo);
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool is_matricula_registred(const ArrayFacu &facultades, int codigo_paralelo, string cedula)
{
    bool isFound = true;
    if (facultades.empty())
        return !isFound;
    else
    {
        for (const auto facultad : facultades)
        {
            for (const auto carrera : facultad.carreras)
            {
                for (const auto semestre: carrera.semestres)
                {
                    for(const auto materia: semestre.materias)
                    {
                        PARALELO paralelo = select_paralelo_by_codigo(materia.paralelos,codigo_paralelo);
                        if (paralelo.codigo == codigo_paralelo)
                        {                            
                            ALUMNO alumno = select_alumno_by_cedula(paralelo.estudiantes,cedula);
                            if (alumno.cedula == cedula)
                                return isFound;                            
                        }
                    }
                }
            }
        }
        return !isFound;
    }
}


///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD ALUMNO///////////////////////

void delete_alumno(Array &alumnos, string cedula)
{
    if (alumnos.empty())
        cout << endl
             << "Esta vacio :c" << endl;
    else
    {
        //Itera cada elemento del array de tipo ALUMNO alumnos
        //auto infiere el tipo de dato de "alumno" en este caso es ALUMNO
        for (auto alumno : alumnos)
        {
            if (alumno.cedula == cedula)
            {
                //Lo deja en blanco pero sigue la posicion vacia en memoria:
                //Tipo:
                // nombre:""
                // correo:""
                // cedula:""
                //Remove retorna un iterador del array excepto el alumno a borrar
                Array::iterator iterador = remove(alumnos.begin(), alumnos.end(), alumno);
                //Reemplaza el contenido de alumno por iterador
                //borra del array
                alumnos.erase(iterador,
                              alumnos.end());
                return;
            }
        }
        cout << "No se encontró el alumno :c";
    }
}

void insert_alumno(Array &alumnos, ALUMNO alumno)
{

    if(validar_cedula(alumno.cedula))
    {
        cout << endl << "Registro exitoso :)" << endl;
        alumnos.push_back(alumno);
    }
        
    else
        cout << endl << "Cedula no valida :(" << endl;
}
void select_all(const Array alumnos)
{
    if (alumnos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        for (const auto alumno : alumnos)
            cout << alumno.nombre << endl;
    }
}
ALUMNO select_alumno_by_cedula(const Array alumnos, string cedula)
{
    ALUMNO notFound;
    notFound.nombre = "NA";
    notFound.correo = "NA";
    notFound.cedula = "NA";
    for (const auto alumno : alumnos)
    {
        if (alumno.cedula == cedula)
            return alumno;
    }
    return notFound;
}
void printAlumno(ALUMNO alumno)
{
    cout << endl
         << "Datos del alumno: " << alumno.nombre << endl
         << "Correo: " << alumno.correo << endl
         << "Cedula: " << alumno.cedula << endl;
}

void printAlumnos(const Array &alumnos)
{
    if (alumnos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }

    else
    {
        //se Agrego const porque no se va a modificar el elemento por asignacion :)
        for (const auto alumno : alumnos)
            printAlumno(alumno);
    }
}
void update_alumno(Array &alumnos,
                   ALUMNO alumn)
{
    if (alumnos.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable alumno pueda modificar directamente al array :D
        for (auto &alumno : alumnos)
        {
            if (alumno.cedula == alumn.cedula)
            {
                alumno.correo = alumn.correo;
                alumno.nombre = alumn.nombre;
                cout << endl
                     << "Registro actualizado de: " << alumn.nombre << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el Alumno :(" << endl;
    }
}


///////// ///////// ///////// ///////// ///////// ///////// ///////// ///////// /////////

void agregar_alumno_crud(ArrayFacu &facultades, ALUMNO nuevo_alumno,
                           int codigo_semestre,int codigo_facultad, int codigo_carrera)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            if (codigo_facultad == facultad.codigo)
            {
                for (auto &carrera : facultad.carreras)
                {
                    if (carrera.codigo == codigo_carrera)
                    {
                        for(auto &semestre: carrera.semestres){
                            if(semestre.codigo == codigo_semestre)
                            {
                                for(auto &materia: semestre.materias){
                                    for (auto &paralelo : materia.paralelos)
                                    {
                                        cout << endl
                                            << "Registrando: " << nuevo_alumno.nombre  << " en el paralelo: "
                                            << paralelo.nombre << endl;
                                        
                                        insert_alumno(paralelo.estudiantes, nuevo_alumno);
                                    }
                                }
                                return;
                            }

                        }
                        cout << endl << "No se encontro el SEMESTRE" << endl;
                        return;
                    }
                }
                cout << "No se encontro la CARRERA" << endl;
                return ;
            }

        }
        cout << "No se encontro la facultad" << endl;

    }
}


void modificar_alumno_crud(ArrayFacu &facultades, ALUMNO nuevo_alumno)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            for (auto &carrera : facultad.carreras)
            {
                for(auto &semestre: carrera.semestres){

                    for(auto &materia: semestre.materias){
                        for (auto &paralelo : materia.paralelos)
                        {
                            cout << endl
                                << "Se ha modificado el alumno: " << nuevo_alumno.nombre  << " en el paralelo: "
                                << paralelo.nombre << endl;
                            update_alumno(paralelo.estudiantes,nuevo_alumno);
                        }
                    }
                }
                // cout << endl << "No se encontro el SEMESTRE" << endl;
                // return;
            }
            // cout << "No se encontro la CARRERA" << endl;
            // return;
        }
        cout << endl
             << "No se encontro el SEMESTRE :c" << endl;
    }
}

void eliminar_alumno_crud(ArrayFacu &facultades, string cedula)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (auto &facultad : facultades)
        {
            for (auto &carrera : facultad.carreras)
            {
                for(auto &semestre: carrera.semestres){
                    
                    for(auto &materia: semestre.materias){
                        cout << endl << endl << "Materia: " << materia.nombre << endl;
                        for (auto &paralelo : materia.paralelos)
                        {
                            cout << endl << "Estudiante: " << carrera.nombre << endl;
                            delete_alumno(paralelo.estudiantes,cedula);
                        }
                    }
                    //return;
                }
                    // cout << endl << "No se encontro el SEMESTRE" << endl;
                    // return;
            }
            // cout << "No se encontro la CARRERA" << endl;
            // return ;
        }
        cout << "No se encontro la facultad" << endl;
    }
}

void consultar_alumno_crud(const ArrayFacu &facultades)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            if (!facultad.carreras.empty())
            {
                for (const auto carrera : facultad.carreras)
                {
                    for (const auto semestre: carrera.semestres)
                    {
                        for(const auto materia: semestre.materias){
                            cout << endl << endl << "Materia: " << materia.nombre << endl;
                            for (const auto paralelo : materia.paralelos)
                            {
                                cout << endl << "Paralelo: " << paralelo.nombre << endl;
                                printAlumnos(paralelo.estudiantes);
                            }
                        }

                    }
                }
            }
            else
                cout << "La facultad " << facultad.nombre << " no tiene carreras :c" << endl;
        }
    }
}
void consultar_alumno_por_cedula_crud(const ArrayFacu &facultades, string cedula)
{
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            for (const auto carrera : facultad.carreras)
            {
                for (const auto semestre: carrera.semestres)
                {
                    for(const auto materia: semestre.materias)
                    {
                        for(const auto materia: semestre.materias){
                            for (const auto paralelo : materia.paralelos)
                            {
                                ALUMNO alumno = select_alumno_by_cedula(paralelo.estudiantes,cedula);
                                if (alumno.cedula != "NA")
                                {
                                    cout << endl << "Paralelo: " << paralelo.nombre << endl;
                                    printAlumno(alumno);
                                    return;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////
////////////////////////////////////CRUD MATRICULA///////////////////////
void insert_matricula(ArrayMatricula &matriculas, MATRICULA matricula)
{
    matricula.nota = 0;
    matriculas.push_back(matricula);
}
MATRICULA select_matricula_by_cedula_codigo(const ArrayMatricula matriculas,
    MATRICULA matricula_search)
{
    MATRICULA notFound;
    notFound.codigo_paralelo = 0;
    notFound.cedula = "NA";
    for (const auto matricula : matriculas)
    {
        if (matricula.cedula == matricula_search.cedula &&
            matricula_search.codigo_paralelo == matricula.codigo_paralelo)
            return matricula;
    }
    return notFound;

}

bool is_matricula_registred(const ArrayMatricula matriculas,
    MATRICULA matricula_search)
{
    bool isFounded = false;
    if(!matriculas.empty())
    {
        MATRICULA buscando = select_matricula_by_cedula_codigo(matriculas,matricula_search);
        if(buscando.cedula != "NA")
            return !isFounded;
    }
    return isFounded;


}


void update_matricula(ArrayMatricula &matriculas,
                   MATRICULA matricula_search)
{
    if (matriculas.empty())
    {
        cout << endl
             << "Esta vacio :c" << endl;
    }
    else
    {
        //Se agrega el & para que la variable matricula pueda modificar directamente al array :D
        for (auto &matricula : matriculas)
        {
            if (matricula.cedula == matricula_search.cedula &&
                matricula_search.codigo_paralelo == matricula.codigo_paralelo)
            {
                matricula.nota = matricula_search.nota;
                cout << endl
                     << "Registro actualizado" << endl;
                return;
            }
        }
        cout << endl
             << "No se pudo encontrar el Matricula :(" << endl;
    }
}
void sumar_por_paralelo(ArrayMatricula matriculas, int codigo_paralelo){
    vector<double> notas;
    double suma;
    for (const auto &matricula: matriculas)
    {
        if(matricula.codigo_paralelo == codigo_paralelo && matricula.nota > 0)
        {
            cout<< endl << "Cedula del estudiante: " << matricula.cedula
                << endl << "Nota: " << matricula.nota << endl;
                notas.push_back(matricula.nota);
        }

    }
    suma = accumulate(notas.begin(), notas.end(), 0.0);
    cout << "Suma de paralelo " << codigo_paralelo << ": "
             << suma << endl
             << "Promedio de paralelo: " << suma/notas.size() << endl << endl;

}


//Paralelo coleccion
SetNotas get_codigo_paralelo(ArrayMatricula matriculas){
    SetNotas paralelos;
    for (const auto &matricula: matriculas)
        paralelos.insert(matricula.codigo_paralelo);

    return paralelos;
}


void consultar_notas_paralelo_crud(ArrayMatricula matriculas){
    SetNotas paralelos = (get_codigo_paralelo(matriculas));
    for(SetNotas::iterator i = paralelos.begin(); i!=paralelos.end(); ++i){
        cout << endl << "Codigo de Paralelo: " << *i << endl;
        sumar_por_paralelo(matriculas,*i);
    }
}

void sumar_por_cedula(ArrayMatricula matriculas, string cedula){
    vector<double> notas;
    double suma;
    for (const auto &matricula: matriculas)
    {
        if(matricula.cedula == cedula && matricula.nota > 0)
        {
            cout<< endl << "Codigo de Paralelo: " << matricula.codigo_paralelo
                << endl << "Nota: " << matricula.nota << endl;
                notas.push_back(matricula.nota);
        }
    }
    suma = accumulate(notas.begin(), notas.end(), 0.0);
    cout << "Suma de notas: " << suma << endl
             << "Promedio de paralelos: " << suma/notas.size() << endl;

}
set<string> get_cedula_alumno(ArrayMatricula matriculas){
    set<string> cedulas;
    for (const auto &matricula: matriculas)
        cedulas.insert(matricula.cedula);
    return cedulas;
}
void consultar_notas_cedula_crud(ArrayMatricula matriculas){
    set<string> cedulas = (get_cedula_alumno(matriculas));

    for(set<string>::iterator i = cedulas.begin(); i!=cedulas.end(); ++i){
        cout << endl << "Cedula del estudiante: " << *i << endl << endl;
        sumar_por_cedula(matriculas,*i);
    }
}

void consultar_notas_materia_crud(const ArrayFacu facultades,const ArrayMatricula matriculas_search){
    if (facultades.empty())
        cout << "No hay facultades registradas :c" << endl;
    else
    {
        for (const auto facultad : facultades)
        {
            for (const auto carrera : facultad.carreras)
            {
                for (const auto semestre: carrera.semestres)
                {
                    for(const auto materia: semestre.materias)
                    {
                        
                        cout << "Materia: " << materia.nombre << endl;
                        vector<double> notas;
                        double suma;                        

                        for (const auto paralelo : materia.paralelos)
                        {                            
                            for (const auto &matricula : matriculas_search)
                            {
                                    for (const auto alumno : paralelo.estudiantes)
                                    {
                                        if(matricula.cedula == alumno.cedula && matricula.codigo_paralelo == paralelo.codigo)
                                        {
                                            cout << "Nota: " << matricula.nota << endl; 
                                            notas.push_back(matricula.nota);
                                        }
                                            
                                    }                                
                                
                            }
                        }
                        suma = accumulate(notas.begin(), notas.end(), 0.0);
                        cout << "Suma de notas: " << suma << endl
                                << "Promedio de materia: " << suma/notas.size() << endl <<endl;
                        
                    }
                }
            }
        }
    }

}


