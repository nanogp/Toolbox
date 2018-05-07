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
#define GENERICA_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define GENERICA_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE GENERICA)
#define GENERICA_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE GENERICA)
#define GENERICA_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE GENERICA)
#define GENERICA_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE GENERICA)
#define GENERICA_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE GENERICA)
#define GENERICA_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %d - %s - %d)
#define GENERICA_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre - edad)
#define GENERICA_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define GENERICA_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay m s lugares disponibles para altas de Generica)
#define GENERICA_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Generica: \0)
#define GENERICA_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID v lido: \0)
#define GENERICA_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Generica ingresado no existe)
#define GENERICA_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define GENERICA_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define GENERICA_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gesti¢n?)
#define GENERICA_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de alta)
#define GENERICA_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Generica?)
#define GENERICA_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de baja)
#define GENERICA_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nGenerica actual: \0)
#define GENERICA_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nGenerica modificado: \0)
#define GENERICA_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Generica se modifico)

#define DEPENDE_CANT_MAX 10
#define DEPENDE_LARGO_NOMBRE 50
#define DEPENDE_ID_MIN 1
#define DEPENDE_ID_MAX 1000000
#define DEPENDE_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define DEPENDE_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE DEPENDE)
#define DEPENDE_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE DEPENDE)
#define DEPENDE_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE DEPENDE)
#define DEPENDE_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE DEPENDE)
#define DEPENDE_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE DEPENDE)
#define DEPENDE_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %d - %s - %d)
#define DEPENDE_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre - edad)
#define DEPENDE_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define DEPENDE_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay m s lugares disponibles para altas de Depende)
#define DEPENDE_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Depende: \0)
#define DEPENDE_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID v lido: \0)
#define DEPENDE_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Depende ingresado no existe)
#define DEPENDE_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define DEPENDE_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define DEPENDE_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gesti¢n?)
#define DEPENDE_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de alta)
#define DEPENDE_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Depende?)
#define DEPENDE_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de baja)
#define DEPENDE_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nDepende actual: \0)
#define DEPENDE_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nDepende modificado: \0)
#define DEPENDE_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Depende se modifico)

#define ESTADISTICAS_CANT_MAX (GENERICA_CANT_MAX * DEPENDE_CANT_MAX)
#define ESTADISTICAS_LARGO_NOMBRE 50
#define ESTADISTICAS_ID_MIN 1
#define ESTADISTICAS_ID_MAX 1000000
#define ESTADISTICAS_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define ESTADISTICAS_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE ESTADISTICAS)
#define ESTADISTICAS_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE ESTADISTICAS)
#define ESTADISTICAS_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %d - %s - %d)
#define ESTADISTICAS_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre - edad)
#define ESTADISTICAS_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define ESTADISTICAS_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay m s lugares disponibles para altas de Estadisticas)
#define ESTADISTICAS_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Estadisticas: \0)
#define ESTADISTICAS_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID v lido: \0)
#define ESTADISTICAS_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Estadisticas ingresado no existe)
#define ESTADISTICAS_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define ESTADISTICAS_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define ESTADISTICAS_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gesti¢n?)
#define ESTADISTICAS_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se dio de alta)
#define ESTADISTICAS_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Estadisticas?)
#define ESTADISTICAS_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se dio de baja)
#define ESTADISTICAS_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nEstadisticas actual: \0)
#define ESTADISTICAS_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nEstadisticas modificado: \0)
#define ESTADISTICAS_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se modifico)

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
int eGenerica_siguienteId(eGenerica listado[], int limite);
int eGenerica_pedirIdYBuscar(eGenerica listado[], int limite);
int eGenerica_buscarLugarLibre(eGenerica listado[], int limite);
int eGenerica_estaVacio(eGenerica listado[], int limite);
void eGenerica_mostrarUno(eGenerica parametro);
void eGenerica_mostrarListado(eGenerica listado[], int limite);
void eGenerica_listar(eGenerica listado[], int limite);
void eGenerica_pedirNombre(char retorno[]);
eGenerica eGenerica_pedirIngreso(eGenerica listado[], int limite);
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
int eDepende_pedirIdYBuscar(eDepende listado[], int limite);
int eDepende_buscarLugarLibre(eDepende listado[], int limite);
int eDepende_estaVacio(eDepende listado[], int limite);
void eDepende_mostrarUno(eDepende parametro);
void eDepende_mostrarListado(eDepende listado[], int limite);
void eDepende_listar(eDepende listado[], int limite);
void eDepende_pedirNombre(char retorno[]);
eDepende eDepende_pedirIngreso(eDepende listado[], int limite);
void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);
void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);
void eDepende_modificarUno(eDepende registro[]);
void eDepende_modificacion(eDepende listado[], int limite);
void eDepende_ordenar(eDepende listado[], int limite, char orden[]);
void eDepende_gestion(eDepende listado[], int limite);


int eEstadisticas_init(eEstadisticas listado[], int limite);
int eEstadisticas_buscarPorId(eEstadisticas listado[], int limite, int id);
int eEstadisticas_buscarPorIdGenerica(eEstadisticas listado[], int limite, int idDepende);
int eEstadisticas_siguienteId(eEstadisticas listado[], int limite);
int eEstadisticas_pedirIdYBuscar(eEstadisticas listado[], int limite);
int eEstadisticas_buscarLugarLibre(eEstadisticas listado[], int limite);
int eEstadisticas_estaVacio(eEstadisticas listado[], int limite);
void eEstadisticas_mostrarUno(eEstadisticas parametro);
void eEstadisticas_mostrarListado(eEstadisticas listado[], int limite);
void eEstadisticas_listar(eEstadisticas listado[], int limite);
void eEstadisticas_pedirNombre(char retorno[]);
eEstadisticas eEstadisticas_pedirIngreso(eEstadisticas listado[], int limite);
void eEstadisticas_alta(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende);
void eEstadisticas_baja(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende);
void eEstadisticas_modificarUno(eEstadisticas registro[]);
void eEstadisticas_modificacion(eEstadisticas listado[], int limite);
void eEstadisticas_ordenar(eEstadisticas listado[], int limite, char orden[]);
void eEstadisticas_gestion(eEstadisticas listado[], int limite);

#endif // ESTRUCTURAGENERICA_H_INCLUDED
