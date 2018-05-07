#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "EstructuraGenerica.h"
//#include "ESTRUCTURA_1.h"
//#include "ESTRUCTURA_2.h"


int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/4,
                            /*codigos*/{1,2,3,0},
                            /*descripciones*/{"1. Gestionar Generica","2. Gestionar Depende","3. Gestionar Estadisticas","0. Salir"},
                            /*titulo del menu*/{"MENU GENERICO"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    eGenerica listadoGenerica[GENERICA_CANT_MAX] = {};
    eDepende listadoDepende[DEPENDE_CANT_MAX] = {};
    eEstadisticas listadoEstadisticas[ESTADISTICAS_CANT_MAX] = {};

    //INCIALIZAR
    eGenerica_init(listadoGenerica, GENERICA_CANT_MAX);
    eDepende_init(listadoDepende, DEPENDE_CANT_MAX);
    eEstadisticas_init(listadoEstadisticas, DEPENDE_CANT_MAX);

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
                eDepende_gestion(listadoDepende, DEPENDE_CANT_MAX);
                break;
            case 3:
                eEstadisticas_gestion(listadoEstadisticas, ESTADISTICAS_CANT_MAX);
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
