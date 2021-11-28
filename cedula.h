#ifndef CEDULA_H_INCLUDED
#define CEDULA_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

bool validar_cedula(string ced)
{	
	if(ced.size() != 10 )
		return false;
	return true;
}

#endif // CEDULA_H_INCLUDED
