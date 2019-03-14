#include "..DtFecha.h"
#include <string>

//Constructor
DtFecha(int di, int me, int an){
	d = di;
	m = me;
	a = an;
}

//getters
int DtFecha::getDia(){
	return d;
}

int DtFecha::getMes(){
	return m;
}

int DtFecha::getAnio(){
	return a;
}

//setters
void DtFecha::setDia(int dia){
	d = dia;
}

void DtFecha::setMes(int mes){
	m = mes;
}

void DtFecha::setAnio(int anio){
	a = anio;
}

void DtFecha::setAnio(int dia, int mes, int anio){
	d = dia;
	m = mes;
	a = anio;
}

//Destructor

//Otras

DtFecha DtFecha::operator=(DtFecha fechita){
	DtFecha aux;
	aux.d = getDia(fechita);
	aux.m = getMes(fechita);
	aux.a = getAnio(fechita);
	return aux;
}