#ifndef ESTRUCTURAPROPIETARIO_H_INCLUDED
#define ESTRUCTURAPROPIETARIO_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0

#define MSJ_CONFIRMA_CORRECTOS "Confirma que los datos ingresados son correctos?"
#define MSJ_CANCELO_GESTION "\nSe cancelo la gestion"
#define MSJ_MODIFICANDO_REGISTRO "MODIFICANDO REGISTRO"
#define MSJ_DATOS_A_MODIFICAR "\n\nDatos a modificar:\n"

#define PROPIETARIO_CANT_MAX 10
#define PROPIETARIO_LARGO_NOMBRE 50
#define PROPIETARIO_NUMERO_MIN 1
#define PROPIETARIO_NUMERO_MAX 1000
#define PROPIETARIO_ID_MIN 1
#define PROPIETARIO_ID_MAX 1000000
#define PROPIETARIO_ORDEN "nombreAsc"
#define PROPIETARIO_TITULO_GESTION "GESTION DE PROPIETARIO"
#define PROPIETARIO_TITULO_ALTA "ALTA DE PROPIETARIO"
#define PROPIETARIO_TITULO_BAJA "BAJA DE PROPIETARIO"
#define PROPIETARIO_TITULO_MODIFICACION "MODIFICACION DE PROPIETARIO"
#define PROPIETARIO_TITULO_LISTA "LISTADO DE PROPIETARIO"
#define PROPIETARIO_MASCARA_MOSTRAR_UNO "\n %-3d - %-25s - %-5d"
#define PROPIETARIO_CABECERA_LISTADO "\n ID  - nombre                    - numero"
#define PROPIETARIO_MSJ_LISTA_VACIA "\n\nLa lista esta vacia o todos los registros se dieron de baja"
#define PROPIETARIO_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Propietario"
#define PROPIETARIO_MSJ_INGRESE_ID "\n\nIngrese el ID de Propietario: \0"
#define PROPIETARIO_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define PROPIETARIO_MSJ_ID_NO_EXISTE "\nEl ID de Propietario ingresado no existe"
#define PROPIETARIO_MSJ_NOMBRE_NO_EXISTE "\nEl nombre ingresado no existe"
#define PROPIETARIO_MSJ_INGRESE_NOMBRE "\nIngrese nombre: \0"
#define PROPIETARIO_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_INGRESE_NUMERO "\nIngrese numero: \0"
#define PROPIETARIO_MSJ_REINGRESE_NUMERO "\nNumero no valido. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_REINTENTAR_GESTION "Desea reintentar la gestion?"
#define PROPIETARIO_MSJ_ALTA_OK "\nEl Propietario se dio de alta"
#define PROPIETARIO_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Propietario?"
#define PROPIETARIO_MSJ_BAJA_OK "\nEl Propietario se dio de baja"
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL "\n\nPropietario actual: \0"
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO "\n\nPropietario modificado: \0"
#define PROPIETARIO_MSJ_MODIFICACION_OK "\nEl Propietario se modifico"
#define PROPIETARIO_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PROPIETARIO_MENU_MODIFICAR_UNO_CANT 5
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1 "1. Nombre"
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE2 "2. Numero"
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE3 "3. Edad"
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE4 "4. Nota"
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE5 "0. Cancelar"
#define PROPIETARIO_MENU_GESTION_TITULO "GESTION DE PROPIETARIO"
#define PROPIETARIO_MENU_GESTION_CANT 5
#define PROPIETARIO_MENU_GESTION_DETALLE1 "1. Alta"
#define PROPIETARIO_MENU_GESTION_DETALLE2 "2. Baja"
#define PROPIETARIO_MENU_GESTION_DETALLE3 "3. Modificacion"
#define PROPIETARIO_MENU_GESTION_DETALLE4 "4. Listar"
#define PROPIETARIO_MENU_GESTION_DETALLE5 "0. Volver al menu principal"

typedef struct
{
    char nombre[PROPIETARIO_LARGO_NOMBRE];
    int numero;
    //------------
    int idPropietario;
    int estado;
}ePropietario;

void ePropietario_initHardcode(ePropietario listado[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_init(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_siguienteId(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param id int
 * \return int
 *
 */
int ePropietario_buscarPorId(ePropietario listado[], int limite, int id);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_pedirIdYBuscar(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param nombre[] char
 * \return int
 *
 */
int ePropietario_buscarPorNombre(ePropietario listado[], int limite, char nombre[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_pedirNombreYBuscar(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_buscarLugarLibre(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return int
 *
 */
int ePropietario_estaVacio(ePropietario listado[], int limite);

/** \brief
 *
 * \param registro ePropietario
 * \return void
 *
 */
void ePropietario_mostrarUno(ePropietario registro);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_mostrarListado(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_listar(ePropietario listado[], int limite);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
void ePropietario_pedirNombre(char retorno[]);

/** \brief
 *
 * \param retorno[] char
 * \return void
 *
 */
int ePropietario_pedirNumero();

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return ePropietario
 *
 */
ePropietario ePropietario_pedirIngreso(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_alta(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_baja(ePropietario listado[], int limite);

/** \brief
 *
 * \param registro[] ePropietario
 * \return int
 *
 */
int ePropietario_modificarUno(ePropietario registro[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_modificacion(ePropietario listado[], int limite);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \param orden[] char
 * \return void
 *
 */
void ePropietario_ordenar(ePropietario listado[], int limite, char orden[]);

/** \brief
 *
 * \param listado[] ePropietario
 * \param limite int
 * \return void
 *
 */
void ePropietario_gestion(ePropietario listado[], int limite);

#endif // ESTRUCTURAPROPIETARIO_H_INCLUDED
