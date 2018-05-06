#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "EstructuraGenerica.h"
//#include "ESTRUCTURA_1.h"
//#include "ESTRUCTURA_2.h"


int main()
{
    eMenu menuPrincipal = {
                            5, //limiteidad de opciones
                            {1,2,3,4,0}, //codigos
                            {"1. Alta Generica","2. Baja Generica","3. Modificaci¢n Generica","4. Listado Generica","0. Salir"}, //descripciones
                            {"MENU GENERICO"} //titulo del menu
                            };
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    eGenerica listadoGenerica[GENERICA_CANT_MAX] = {};

    //INCIALIZAR
    eGenerica_init(listadoGenerica, GENERICA_CANT_MAX);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                eGenerica_alta(listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 2:
                eGenerica_baja(listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 3:
                eGenerica_modificacion(listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 4:
                eGenerica_mostrarListado(listadoGenerica, GENERICA_CANT_MAX);
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
