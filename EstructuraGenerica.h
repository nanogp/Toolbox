#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)

#define GENERICA_CANT_MAX 10
#define GENERICA_LARGO_NOMBRE 50
#define GENERICA_LARGO_CLAVE 50
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
#define GENERICA_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Generica)
#define GENERICA_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Generica: \0)
#define GENERICA_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID valido: \0)
#define GENERICA_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Generica ingresado no existe)
#define GENERICA_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define GENERICA_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define GENERICA_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define GENERICA_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define GENERICA_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de alta)
#define GENERICA_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Generica?)
#define GENERICA_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de baja)
#define GENERICA_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nGenerica actual: \0)
#define GENERICA_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nGenerica modificado: \0)
#define GENERICA_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Generica se modifico)
#define GENERICA_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define GENERICA_MENU_MODIFICAR_UNO_CANT 5
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Legajo)
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE3 DEFINIR_MACRO_STRING(3. Edad)
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE4 DEFINIR_MACRO_STRING(4. Nota)
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE5 DEFINIR_MACRO_STRING(0. Cancelar)
#define GENERICA_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(GESTION DE GENERICA)
#define GENERICA_MENU_GESTION_CANT 5
#define GENERICA_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta)
#define GENERICA_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Baja)
#define GENERICA_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion)
#define GENERICA_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Listar)
#define GENERICA_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(0. Volver al menu principal)

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
#define DEPENDE_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Depende)
#define DEPENDE_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Depende: \0)
#define DEPENDE_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID valido: \0)
#define DEPENDE_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Depende ingresado no existe)
#define DEPENDE_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define DEPENDE_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define DEPENDE_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define DEPENDE_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define DEPENDE_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de alta)
#define DEPENDE_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Depende?)
#define DEPENDE_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Depende se dio de baja)
#define DEPENDE_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nDepende actual: \0)
#define DEPENDE_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nDepende modificado: \0)
#define DEPENDE_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Depende se modifico)
#define DEPENDE_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define DEPENDE_MENU_MODIFICAR_UNO_CANT 5
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Legajo)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE3 DEFINIR_MACRO_STRING(3. Edad)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE4 DEFINIR_MACRO_STRING(4. Nota)
#define DEPENDE_MENU_MODIFICAR_UNO_DETALLE5 DEFINIR_MACRO_STRING(0. Cancelar)
#define DEPENDE_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(GESTION DE DEPENDE)
#define DEPENDE_MENU_GESTION_CANT 5
#define DEPENDE_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta)
#define DEPENDE_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Baja)
#define DEPENDE_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion)
#define DEPENDE_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Listar)
#define DEPENDE_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(0. Volver al menu principal)

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
#define ESTADISTICAS_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Estadisticas)
#define ESTADISTICAS_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Estadisticas: \0)
#define ESTADISTICAS_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un n¡mero mayor que cero. Reingrese un ID valido: \0)
#define ESTADISTICAS_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Estadisticas ingresado no existe)
#define ESTADISTICAS_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define ESTADISTICAS_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define ESTADISTICAS_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define ESTADISTICAS_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define ESTADISTICAS_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se dio de alta)
#define ESTADISTICAS_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Estadisticas?)
#define ESTADISTICAS_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se dio de baja)
#define ESTADISTICAS_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\nEstadisticas actual: \0)
#define ESTADISTICAS_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\nEstadisticas modificado: \0)
#define ESTADISTICAS_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Estadisticas se modifico)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_CANT 5
#define ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Legajo)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE3 DEFINIR_MACRO_STRING(3. Edad)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE4 DEFINIR_MACRO_STRING(4. Nota)
#define ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE5 DEFINIR_MACRO_STRING(0. Cancelar)
#define ESTADISTICAS_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(GESTION DE ESTADISTICAS)
#define ESTADISTICAS_MENU_GESTION_CANT 5
#define ESTADISTICAS_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta)
#define ESTADISTICAS_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Baja)
#define ESTADISTICAS_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion)
#define ESTADISTICAS_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Listar)
#define ESTADISTICAS_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(0. Volver al menu principal)

typedef struct
{
    char nombre[GENERICA_LARGO_NOMBRE];
    char clave[GENERICA_LARGO_CLAVE];
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
    char nombre[ESTADISTICAS_LARGO_NOMBRE];
    //------------
	int idEstadisticas;
    int idDepende;
    int estado;
}eEstadisticas;


/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_init(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_siguienteId(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \param id int
 * \return int
 *
 */
int eGenerica_buscarPorId(eGenerica listado[], int limite, int id);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_pedirIdYBuscar(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int eGenerica_buscarPorNombre(eGenerica listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_pedirNombreYBuscar(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_buscarLugarLibre(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return int
 *
 */
int eGenerica_estaVacio(eGenerica listado[], int limite);

/** \brief
 *
 * \param parametro eGenerica
 * \return void
 *
 */
void eGenerica_mostrarUno(eGenerica parametro);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_mostrarListado(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_listar(eGenerica listado[], int limite);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void eGenerica_pedirNombre(char retorno[]);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return eGenerica
 *
 */
eGenerica eGenerica_pedirIngreso(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_alta(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_baja(eGenerica listado[], int limite);

/** \brief
 *
 * \param registro[] eGenerica
 * \return void
 *
 */
void eGenerica_modificarUno(eGenerica registro[]);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_modificacion(eGenerica listado[], int limite);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void eGenerica_ordenar(eGenerica listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_gestion(eGenerica listado[], int limite);

/* FUNCIONES PARA ESTRUCTURAS QUE DEPENDEN DE LA PRINCIPAL */

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_init(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param id int
 * \return int
 *
 */
int eDepende_buscarPorId(eDepende listado[], int limite, int id);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param IdGenerica int
 * \return int
 *
 */
int eDepende_buscarPorIdGenerica(eDepende listado[], int limite, int IdGenerica);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_siguienteId(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_pedirIdYBuscar(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int eDepende_buscarPorNombre(eDepende listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_pedirNombreYBuscar(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_buscarLugarLibre(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return int
 *
 */
int eDepende_estaVacio(eDepende listado[], int limite);

/** \brief
 *
 * \param parametro eDepende
 * \return void
 *
 */
void eDepende_mostrarUno(eDepende parametro);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_mostrarListado(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_listar(eDepende listado[], int limite);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void eDepende_pedirNombre(char retorno[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return eDepende
 *
 */
eDepende eDepende_pedirIngreso(eDepende listado[], int limite);

/** \brief
 *
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \param listadoGenerica[] eGenerica
 * \param limiteGenerica int
 * \return void
 *
 */
void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/** \brief
 *
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \param listadoGenerica[] eGenerica
 * \param limiteGenerica int
 * \return void
 *
 */
void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/** \brief
 *
 * \param registro[] eDepende
 * \return void
 *
 */
void eDepende_modificarUno(eDepende registro[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_modificacion(eDepende listado[], int limite);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void eDepende_ordenar(eDepende listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] eDepende
 * \param limite int
 * \return void
 *
 */
void eDepende_gestion(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica);

/* FUNCIONES PARA ESTRUCTURAS DE ESTADISTICAS */

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_init(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \param id int
 * \return int
 *
 */
int eEstadisticas_buscarPorId(eEstadisticas listado[], int limite, int id);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \param idDepende int
 * \return int
 *
 */
int eEstadisticas_buscarPorIdGenerica(eEstadisticas listado[], int limite, int idDepende);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_siguienteId(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_pedirIdYBuscar(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int eEstadisticas_buscarPorNombre(eEstadisticas listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_pedirNombreYBuscar(eEstadisticas listado[], int limite);



/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_buscarLugarLibre(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return int
 *
 */
int eEstadisticas_estaVacio(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param parametro eEstadisticas
 * \return void
 *
 */
void eEstadisticas_mostrarUno(eEstadisticas parametro);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return void
 *
 */
void eEstadisticas_mostrarListado(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return void
 *
 */
void eEstadisticas_listar(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void eEstadisticas_pedirNombre(char retorno[]);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return eEstadisticas
 *
 */
eEstadisticas eEstadisticas_pedirIngreso(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listadoEstadisticas[] eEstadisticas
 * \param limiteEstadisticas int
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \return void
 *
 */
void eEstadisticas_alta(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende);

/** \brief
 *
 * \param listadoEstadisticas[] eEstadisticas
 * \param limiteEstadisticas int
 * \param listadoDepende[] eDepende
 * \param limiteDepende int
 * \return void
 *
 */
void eEstadisticas_baja(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende);

/** \brief
 *
 * \param registro[] eEstadisticas
 * \return void
 *
 */
void eEstadisticas_modificarUno(eEstadisticas registro[]);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return void
 *
 */
void eEstadisticas_modificacion(eEstadisticas listado[], int limite);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void eEstadisticas_ordenar(eEstadisticas listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] eEstadisticas
 * \param limite int
 * \return void
 *
 */
void eEstadisticas_gestion(eEstadisticas listado[], int limite);

#endif // ESTRUCTURAGENERICA_H_INCLUDED
