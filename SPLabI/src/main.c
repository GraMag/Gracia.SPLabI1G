#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "LinkedList.h"
#include "controller.h"
#include "eBicicleta.h"

int main(void) {

	setbuf(stdout,NULL);
	srand(time(NULL));

	int seguir = 0;
	int loadtxt = 0;
	char archivo[100];

	LinkedList* listBicicletas = ll_newLinkedList();

	do
	{
		system("cls");

		switch (mainMenue()) {
			case 1:
				if (loadtxt == 0)
				{
					printf("Ingrese nombre del archivo\n");
					fflush(stdin);
					gets(archivo);
					strcat(archivo,".csv");
					if (controller_loadFromText(archivo, listBicicletas))
					{
						printf("No se pudo abrir el archivo");
					}
					else
					{
						printf("Archivo cargado con exito\n");
						loadtxt = 1;
					}
				}
				else
				{
					printf("El archivo ya esta cargado\n");
				}
				break;
			case 2:
				if (loadtxt == 1)
				{
					controller_ListBikes(listBicicletas);
				}
				else
				{
					printf("El archivo aun no esta cargado\n");
				}
				break;
			case 3:

							break;
			case 4:
				if(loadtxt == 1)
				{
					if(controller_Filter(listBicicletas))
					{
						printf("No se pudo generar el archivo");
					}
					else
					{
						printf("Archivo filtrado");
					}
				}
				else
				{
					printf("El archivo aun no esta cargado\n");
				}
				break;
			case 5:

							break;
			case 6:
				if (loadtxt == 1)
				{
					controller_saveAsText(archivo,listBicicletas);
				}
				else
				{
					printf("El archivo aun no esta cargado\n");
				}
				break;
			case 7:
				exitMenue();
				if(exitMenue() == 1)
				{
					exit(1);
				}
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}

		system("pause");
	} while (seguir == 0);
	return EXIT_SUCCESS;
}


