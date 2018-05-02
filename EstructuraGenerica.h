#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#   define ESTRUCTURAGENERICA_H_INCLUDED
#   define LARGO_NOMBRE_ESTRUCTURA_GENERICA 50
#   define OCUPADO 1
#   define LIBRE 0

    typedef struct
    {
        char nombre[LARGO_NOMBRE_ESTRUCTURA_GENERICA];
        //------------
        int idGenerica;
        int estado;
    }eGenerica;

#   define NRO_MAX_ESTRUCTURA_GENERICA 10
#   define TITULO_ALTA DEFINIR_MACRO_STRING("ALTA DE GENERICA")
#   define TITULO_BAJA DEFINIR_MACRO_STRING("BAJA DE GENERICA")
#   define TITULO_MODIFICACION DEFINIR_MACRO_STRING("MODIFICACION DE GENERICA")

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eGen_init(eGenerica[], int limite);
int eGen_buscarPorId(eGenerica[], int limite, int id);
int eGen_siguienteId(eGenerica[], int limite);
int eGen_buscarLugarLibre(eGenerica listado[], int limite);

int eGen_mostrarUno(eGenerica parametro);
int eGen_mostrarListado(eGenerica[], int limite);
int eGen_mostrarListadoConBorrados(eGenerica[], int limite);

int eGen_alta(eGenerica[], int limite);
int eGen_baja(eGenerica[], int limite, int id);
int eGen_modificacion(eGenerica[], int limite, int id);

int eGen_ordenar(eGenerica[], int limite, int orden);
