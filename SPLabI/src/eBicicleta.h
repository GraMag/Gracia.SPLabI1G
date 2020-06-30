#ifndef EBICICLETA_H_
#define EBICICLETA_H_

typedef struct
{
	int id_bike;
	char nombre[50];
	char tipo[50];
	int tiempo;
}eBicicleta;

#endif /* EBICICLETA_H_ */

eBicicleta* eBicicleta_newBici();
eBicicleta* eBicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);
int eBicicleta_setId(eBicicleta* this,int id);
int eBicicleta_getId(eBicicleta* this,int* id);
int eBicicleta_setNombre(eBicicleta* this,char* nombre);
int eBicicleta_getNombre(eBicicleta* this,char* nombre);
int eBicicleta_setTipo(eBicicleta* this,char* tipo);
int eBicicleta_getTipo(eBicicleta* this,char* tipo);
int eBicicleta_setTiempo(eBicicleta* this,int tiempo);
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo);
int eBicicleta_mostrarBicis(LinkedList* list);
int eBicicleta_mostrarBici(eBicicleta* this);
int filtrarTipoMtb(void* unaBici);
int filtrarTipoPlayera(void* unaBici);
int filtrarTipoBMX(void* unaBici);
int filtrarTipoPaseo(void* unaBici);
