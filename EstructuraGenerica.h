#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#   define ESTRUCTURAGENERICA_H_INCLUDED
#   define LARGO_NOMBRE_ESTRUCTURA_GENERICA 50
#   define OCUPADO 1
#   define LIBRE 0
#   define NRO_MAX_ESTRUCTURA_GENERICA 10
#   define NOMBRE_ESTRUCTURA GENERICA
#   define TITULO_GESTION DEFINIR_MACRO_STRING("GESTION DE "NOMBRE_ESTRUCTURA)
//#   define TITULO_GESTION DEFINIR_MACRO_STRING("GESTION DE GENERICA")
#   define TITULO_ALTA DEFINIR_MACRO_STRING("ALTA DE GENERICA")
#   define TITULO_BAJA DEFINIR_MACRO_STRING("BAJA DE GENERICA")
#   define TITULO_MODIFICACION DEFINIR_MACRO_STRING("MODIFICACION DE GENERICA")

    typedef struct
    {
        char nombre[LARGO_NOMBRE_ESTRUCTURA_GENERICA];
        //------------
        int idGenerica;
        int estado;
    }eGenerica;
#endif // ESTRUCTURAGENERICA_H_INCLUDED
int eGen_init(eGenerica[], int limite);
int eGen_buscarPorId(eGenerica[], int limite, int id);
int eGen_siguienteId(eGenerica[], int limite);
int eGen_buscarLugarLibre(eGenerica listado[], int limite);

void eGen_mostrarUno(eGenerica parametro);
void eGen_mostrarListado(eGenerica[], int limite);
void eGen_mostrarListadoConBorrados(eGenerica[], int limite);

void eGen_alta(eGenerica[], int limite);
void eGen_baja(eGenerica[], const int limite);
void eGen_modificacion(eGenerica[], int limite);
void eGen_modificarUno(eGenerica[]);

void eGen_ordenar(eGenerica[], int limite, char orden[]);
