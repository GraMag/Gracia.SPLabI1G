#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eBicicleta.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBike)
{
	int error = -1;
	FILE* file;

	if(path != NULL && (ll_isEmpty(pArrayListBike))) {
		file = fopen(path, "r");
		if(file != NULL){
			parser_BikeFromText(file,pArrayListBike);
		}
		fclose(file);
		error = 0;
	}
    return error;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] si hay error [0] esta Ok
 *
 */
int controller_ListBikes(LinkedList* pArrayListBike)
{
	int error = -1;
	if(!ll_isEmpty(pArrayListBike)){
		eBicicleta_mostrarBicis(pArrayListBike);
		error = 0;
	}
    return error;
}

int controller_Filter(LinkedList* pArrayListBike)
{
	int error = -1;
	eBicicleta* bici;
	LinkedList* listFiltrada = ll_newLinkedList();
	if(!ll_isEmpty(pArrayListBike))
	{
		switch (filterMenue()) {
			case 1:
				listFiltrada = ll_filter(pArrayListBike, filtrarTipoBMX(bici));
				break;
			case 2:
				listFiltrada = ll_filter(pArrayListBike, filtrarTipoMtb(bici));
						break;
			case 3:
				listFiltrada = ll_filter(pArrayListBike, filtrarTipoPlayera(bici));
				break;
			case 4:
				listFiltrada = ll_filter(pArrayListBike, filtrarTipoPaseo(bici));
				break;
			default:
				break;
		}
		if(!ll_isEmpty(listFiltrada))
		{
			eBicicleta_mostrarBicis(listFiltrada);
			controller_saveAsText("filtrado.csv", listFiltrada);
			error = 0;
		}
	}
	return error;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] si hay error [0] si esta OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBike)
{
	int error = -1;
	eBicicleta* bici;
	eBicicleta auxBici;

	int len = ll_len(pArrayListBike);
	FILE* file;

	if(path != NULL && !(ll_isEmpty(pArrayListBike))) {
		file = fopen(path, "w");

		if(file != NULL)
		{
			fprintf(file,"id_bike,nombre,tipo,tiempo\n");
			for(int i = 0; i < len; i++)
			{
				bici = (eBicicleta*) ll_get(pArrayListBike, i);
				eBicicleta_getId(bici, &auxBici.id_bike);
				eBicicleta_getNombre(bici, auxBici.nombre);
				eBicicleta_getTipo(bici, auxBici.tipo);
				eBicicleta_getTiempo(bici, &auxBici.tiempo);

				fprintf(file,"%d,%s,%s,%d\n", auxBici.id_bike, auxBici.nombre, auxBici.tipo, auxBici.tiempo);
			}

		}
		fclose(file);
		error = 0;
	}
    return error;
}
