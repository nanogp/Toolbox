#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelà la gestiàn)

#define GENERICA_CANT_MAX 10
#define GENERICA_LARGO_NOMBRE 50
#define GENERICA_ID_MIN 1
#define GENERICA_ID_MAX 1000000
#define GENERICA_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE GENERICA)
#define GENERICA_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE GENERICA)
#define GENERICA_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE GENERICA)
#define GENERICA_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE GENERICA)
#define GENERICA_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %d - %s - %d)
#define GENERICA_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre - edad)
#define GENERICA_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define GENERICA_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay m s lugares disponibles para altas de Generica)
#define GENERICA_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de alta)
#define GENERICA_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de EstructuraGenerica: )
#define GENERICA_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID v lido: )
#define GENERICA_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de EstructuraGenerica ingresado no existe)
#define GENERICA_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: )
#define GENERICA_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: )
#define GENERICA_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gesti¢n?)
#define GENERICA_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho EstructuraGenerica?)
#define GENERICA_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl EstructuraGenerica se dio de baja)
#define GENERICA_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl EstructuraGenerica se modificà.)

#define DEPENDE_CANT_MAX 10
#define DEPENDE_LARGO_NOMBRE 50
#define DEPENDE_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE DEPENDE)
#define DEPENDE_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE DEPENDE)
#define DEPENDE_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE DEPENDE)
#define DEPENDE_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE DEPENDE)

#define ESTADISTICAS_CANT_MAX (GENERICA_CANT_MAX * DEPENDE_CANT_MAX)
#define ESTADISTICAS_LARGO_NOMBRE 50
#define ESTADISTICAS_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE ESTADISTICAS)

typedef struct
{
    char nombre[DEPENDE_LARGO_NOMBRE];
    //------------
    int idGenerica;
    int estado;
}eGenerica;

typedef struct
{
    char nombre[DEPENDE_LARGO_NOMBRE];
    //------------
	int idDepende;
    int idGenerica;
    int estado;
}eDepende;

typedef struct
{
    char nombre[DEPENDE_LARGO_NOMBRE];
    //------------
	int idEstadisticas;
    int idDepende;
    int estado;
}eEstadisticas;

int eGenerica_init(eGenerica listado[], int limite);
int eGenerica_buscarPorId(eGenerica listado[], int limite, int id);
int eGenerica_pedirIdYBuscar(eGenerica listado[], int limite);
int eGenerica_siguienteId(eGenerica listado[], int limite);
int eGenerica_buscarLugarLibre(eGenerica listado[], int limite);
int eGenerica_estaVacio(eGenerica listado[], int limite);
void eGenerica_mostrarUno(eGenerica parametro);
void eGenerica_mostrarListado(eGenerica[], int limite);
void eGenerica_mostrarListadoConBorrados(eGenerica[], int limite);
void eGenerica_alta(eGenerica listado[], int limite);
void eGenerica_baja(eGenerica listado[], int limite);
void eGenerica_modificarUno(eGenerica registro[]);
void eGenerica_modificacion(eGenerica listado[], int limite);
void eGenerica_ordenar(eGenerica listado[], int limite, char orden[]);
void eGenerica_gestion(eGenerica listado[], int limite);

int eDepende_init(eDepende listado[], int limite);
int eDepende_buscarPorId(eDepende listado[], int limite, int id);
int eDepende_buscarPorIdGenerica(eDepende listado[], int limite, int IdGenerica);
int eDepende_siguienteId(eDepende listado[], int limite);
int eDepende_buscarLugarLibre(eDepende listado[], int limite);
int eDepende_estaVacio(eGenerica listado[], int limite);
void eDepende_mostrarUno(eDepende parametro);
void eDepende_mostrarListado(eDepende listado[], int limite);
void eDepende_mostrarListadoConBorrados(eDepende listado[], int limite);
void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica[], int limiteGenerica);
void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica[], int limiteGenerica);
void eDepende_modificarUno(eDepende registro[]);
void eDepende_modificacion(eDepende listado[], int limite);
void eDepende_ordenar(eDepende listado[], int limite, char orden[]);
void eDepende_gestion(eDepende listado[], int limite);



#endif // ESTRUCTURAGENERICA_H_INCLUDED
