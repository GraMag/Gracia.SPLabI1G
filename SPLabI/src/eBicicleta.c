#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "eBicicleta.h"



eBicicleta* eBicicleta_newBici(){

	eBicicleta* newBici = (eBicicleta*) malloc (sizeof(eBicicleta));
	if(newBici != NULL)
	{
		newBici->id_bike = 0;
		strcpy(newBici->nombre, "");
		strcpy(newBici->tipo, "");
		newBici->tiempo = 0;
	}
	else
	{
		free(newBici);
		newBici = NULL;
	}
	return newBici;
}

eBicicleta* eBicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr){

	eBicicleta* newBici = (eBicicleta*) malloc (sizeof(eBicicleta));
	newBici = eBicicleta_newBici();
	if(newBici != NULL)
	{
		eBicicleta_setId(newBici, atoi(idStr));
		eBicicleta_setNombre(newBici, nombreStr);
		eBicicleta_setTipo(newBici, tipoStr);
		eBicicleta_setTiempo(newBici, atoi(tiempoStr));
	}
	else
	{
		free(newBici);
		newBici = NULL;
	}
	return newBici;
}

int eBicicleta_setId(eBicicleta* this,int id){
	int error = -1;
	if(this != NULL && id >= 0)
	{
		this->id_bike = id;
		error = 0;
	}
	return error;
}

int eBicicleta_getId(eBicicleta* this,int* id){
	int error = -1;
	if(this != NULL && id != NULL){
		*id = this->id_bike;
		error = 0;
	}
	return error;
}

int eBicicleta_setNombre(eBicicleta* this,char* nombre){
	int error = -1;
	if(this != NULL && nombre != NULL)
	{
			strcpy(this->nombre, nombre);
			error = 0;
	}
	return error;
}

int eBicicleta_getNombre(eBicicleta* this,char* nombre){
	int error = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		error = 0;
	}
	return error;
}


int eBicicleta_setTipo(eBicicleta* this,char* tipo){
	int error = -1;
	if(this != NULL && tipo != NULL)
	{
			strcpy(this->tipo, tipo);
			error = 0;
	}
	return error;
}

int eBicicleta_getTipo(eBicicleta* this,char* tipo){
	int error = -1;
	if(this != NULL && tipo != NULL){
		strcpy(tipo, this->tipo);
		error = 0;
	}
	return error;
}

int eBicicleta_setTiempo(eBicicleta* this,int tiempo){
	int error = -1;
	if(this != NULL && tiempo > 0)
	{
			this->tiempo = tiempo;
			error = 0;
	}
	return error;
}

int eBicicleta_getTiempo(eBicicleta* this,int* tiempo){
	int error = 1;
	if(this != NULL && tiempo != NULL){
		*tiempo = this->tiempo;
		error = 0;
	}
	return error;
}

int eBicicleta_mostrarBicis(LinkedList* list){
	int error = 1;
	int len = ll_len(list);
	eBicicleta* auxBici;

	if(!ll_isEmpty(list)){
		error = 0;
		printf("id_bike,nombre,tipo,tiempo\n");
		for (int i = 0; i < len; i++)
		{
			auxBici = (eBicicleta*) ll_get(list, i);
			if ( auxBici != NULL)
			{
				eBicicleta_mostrarBici(auxBici);
			}
		}
	}

	return error;
}

int eBicicleta_mostrarBici(eBicicleta* this){
	int error = 1;

	eBicicleta bici;
	eBicicleta_getId(this, &bici.id_bike);
	eBicicleta_getNombre(this, bici.nombre);
	eBicicleta_getTipo(this, bici.tipo);
	eBicicleta_getTiempo(this, &bici.tiempo);

	if(this != NULL){
		printf("%d,%s,%s,%d\n", bici.id_bike, bici.nombre, bici.tipo, bici.tiempo);
		error = 0;
	}

	return error;
}

int filtrarTipoBMX(void* unaBici)
{
	int auxReturn = 0;
	eBicicleta* x;
	if(unaBici != NULL)
	{
		x = ((eBicicleta*) unaBici);
		if(strcmp(x->tipo, "BMX"))
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}
int filtrarTipoPaseo(void* unaBici)
{
	int auxReturn = 0;
	eBicicleta* x;
	if(unaBici != NULL)
	{
		x = ((eBicicleta*) unaBici);
		if(strcmp(x->tipo, "PASEO"))
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}
int filtrarTipoPlayera(void* unaBici)
{
	int auxReturn = 0;
	eBicicleta* x;
	if(unaBici != NULL)
	{
		x = ((eBicicleta*) unaBici);
		if(strcmp(x->tipo, "PLAYERA"))
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}
int filtrarTipoMtb(void* unaBici)
{
	int auxReturn = 0;
	eBicicleta* x;
	if(unaBici != NULL)
	{
		x = ((eBicicleta*) unaBici);
		if(strcmp(x->tipo, "MTB"))
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int getrandom()
{
	int aleatorio;
	aleatorio = rand()% 21 + 50;
	return aleatorio;
}
