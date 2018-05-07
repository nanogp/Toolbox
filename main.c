#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "EstructuraGenerica.h"

#define MAIN_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(MENU GENERICO)
#define MAIN_MENU_GESTION_CANT 4
#define MAIN_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Gestionar Generica)
#define MAIN_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Gestionar Depende)
#define MAIN_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Gestionar Estadisticas)
#define MAIN_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(0. Volver al menu principal)

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MAIN_MENU_GESTION_CANT,
                            /*codigos*/{1,2,3,0},
                            /*descripciones*/{MAIN_MENU_GESTION_DETALLE1,MAIN_MENU_GESTION_DETALLE2,MAIN_MENU_GESTION_DETALLE3,MAIN_MENU_GESTION_DETALLE4},
                            /*titulo del menu*/{MAIN_MENU_GESTION_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    eGenerica listadoGenerica[GENERICA_CANT_MAX] = {};
    eDepende listadoDepende[DEPENDE_CANT_MAX] = {};
    //eEstadisticas listadoEstadisticas[ESTADISTICAS_CANT_MAX] = {};

    //INCIALIZAR
    eGenerica_init(listadoGenerica, GENERICA_CANT_MAX);
    eDepende_init(listadoDepende, DEPENDE_CANT_MAX);
    //eEstadisticas_init(listadoEstadisticas, ESTADISTICAS_CANT_MAX);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                eGenerica_gestion(listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 2:
                eDepende_gestion(listadoDepende, DEPENDE_CANT_MAX, listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 3:
                //eEstadisticas_gestion(listadoEstadisticas, ESTADISTICAS_CANT_MAX);
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
