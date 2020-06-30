#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int mainMenue(){
	int option;

	printf("****************************************************\n"
			"Menu:\n"
			"1. Cargar archivo\n"
			"2. Imprimir lista\n"
			"3. Asignar tiempo\n"
			"4. Filtrar por tipo\n"
			"5. Mostrar posiciones\n"
			"6. Guardar posiciones\n"
			"7. Salir\n"
			"*****************************************************\n\n"
			"Seleccione una opcion: ");
	scanf("%d", &option);

	return option;
}

int exitMenue(){
	int option;

	printf("Esta seguro que desea salir?\n"
			"1. Si\n"
			"2. No\n");
	scanf("%d", &option);

	return option;
}

int filterMenue(){
	int option;

	printf(	"Criterio de filtrado:\n"
			"1. BMX\n"
			"2. MTB\n"
			"3. Playera\n"
			"4. Paseo\n"
			"5. Cancelar\n");
	scanf("%d", &option);

	return option;
}
