#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)
#define MSJ_MODIFICANDO_REGISTRO DEFINIR_MACRO_STRING(MODIFICANDO REGISTRO)
#define MSJ_DATOS_A_MODIFICAR DEFINIR_MACRO_STRING(\n\nDatos a modificar:\n)

#define GENERICA_CANT_MAX 10
#define GENERICA_LARGO_NOMBRE 50
#define GENERICA_NUMERO_MIN 1
#define GENERICA_NUMERO_MAX 1000
#define GENERICA_ID_MIN 1
#define GENERICA_ID_MAX 1000000
#define GENERICA_ORDEN DEFINIR_MACRO_STRING(nombreAsc)
#define GENERICA_TITULO_GESTION DEFINIR_MACRO_STRING(GESTION DE GENERICA)
#define GENERICA_TITULO_ALTA DEFINIR_MACRO_STRING(ALTA DE GENERICA)
#define GENERICA_TITULO_BAJA DEFINIR_MACRO_STRING(BAJA DE GENERICA)
#define GENERICA_TITULO_MODIFICACION DEFINIR_MACRO_STRING(MODIFICACION DE GENERICA)
#define GENERICA_TITULO_LISTA DEFINIR_MACRO_STRING(LISTADO DE GENERICA)
#define GENERICA_MASCARA_MOSTRAR_UNO DEFINIR_MACRO_STRING(\n %-3d - %-25s - %-5d)
#define GENERICA_CABECERA_LISTADO DEFINIR_MACRO_STRING(\n ID  - nombre                    - numero)
#define GENERICA_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista esta vacia o todos los registros se dieron de baja)
#define GENERICA_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Generica)
#define GENERICA_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Generica: \0)
#define GENERICA_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define GENERICA_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Generica ingresado no existe)
#define GENERICA_MSJ_NOMBRE_NO_EXISTE DEFINIR_MACRO_STRING(\nEl nombre ingresado no existe)
#define GENERICA_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese nombre: \0)
#define GENERICA_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define GENERICA_MSJ_INGRESE_NUMERO DEFINIR_MACRO_STRING(\nIngrese numero: \0)
#define GENERICA_MSJ_REINGRESE_NUMERO DEFINIR_MACRO_STRING(\nNumero no valido. Reingrese por favor: \0)
#define GENERICA_MSJ_REINTENTAR_GESTION DEFINIR_MACRO_STRING(Desea reintentar la gestion?)
#define GENERICA_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de alta)
#define GENERICA_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Generica?)
#define GENERICA_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Generica se dio de baja)
#define GENERICA_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\n\nGenerica actual: \0)
#define GENERICA_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\n\nGenerica modificado: \0)
#define GENERICA_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Generica se modifico)
#define GENERICA_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define GENERICA_MENU_MODIFICAR_UNO_CANT 5
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define GENERICA_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Numero)
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

typedef struct
{
    char nombre[GENERICA_LARGO_NOMBRE];
    int numero;
    //------------
    int idGenerica;
    int estado;
}eGenerica;

void eGenerica_initHardcode(eGenerica listado[]);

/** \brief
 *
 * \param listado[] eGenerica
 * \param limite int
 * \return void
 *
 */
void eGenerica_init(eGenerica listado[], int limite);

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
 * \param registro eGenerica
 * \return void
 *
 */
void eGenerica_mostrarUno(eGenerica registro);

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
 * \param retorno[] char
 * \return void
 *
 */
int eGenerica_pedirNumero();

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
 * \return int
 *
 */
int eGenerica_modificarUno(eGenerica registro[]);

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

#endif // ESTRUCTURAGENERICA_H_INCLUDED
