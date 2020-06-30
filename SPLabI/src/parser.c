#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eBicicleta.h"
#include "parser.h"

/** \brief Parsea los datos los datos de las bicicletas desde el archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBici LinkedList*
 * \return int [0] OK
 *
 */
int parser_BikeFromText(FILE* pFile , LinkedList* pArrayListBikes)
{
	int error = 0;
	char buffer[4][128];
	int amount;
	eBicicleta* auxBici;
	eBicicleta bici;

	fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	printf("%s, %s, %s, %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	while (!feof(pFile))
	{
		amount = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
		if (amount == 4)
		{
			auxBici = eBicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
			if (auxBici != NULL)
			{

				eBicicleta_getId(auxBici, &bici.id_bike);
				eBicicleta_getNombre(auxBici, bici.nombre);
				eBicicleta_getTipo(auxBici, bici.tipo);
				eBicicleta_getTiempo(auxBici, &bici.tiempo);
				printf("%d,%s,%s,%d\n", bici.id_bike, bici.nombre, bici.tipo, bici.tiempo);
				ll_add(pArrayListBikes, auxBici);
			}
		}
		else
		{
			break;
		}
	}
    return error;
}
