#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
//#include "ESTRUCTURA_1.h"
//#include "ESTRUCTURA_2.h"


int main()
{
    eMenu menuPrincipal = {
                            5, //cantidad de opciones
                            {1,2,3,9}, //codigos
                            {"1. Gesti¢n ESTRUCTURA_1","2. Gesti¢n ESTRUCTURA_2","3. Consultas","9. Salir"}, //descripciones
                            {"MENU GENERICO"} //titulo del menu
                            };
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    eGenerica listaESTRUCTURA_1[LARGO_NOMBRE_ESTRUCTURA_GENERICA];
    eGenerica listaESTRUCTURA_2[LARGO_NOMBRE_ESTRUCTURA_GENERICA];

    //INCIALIZAR

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);ejecutarEnConsola(HACER_PAUSA);
                break;
            case 2:
                imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);ejecutarEnConsola(HACER_PAUSA);
                break;
            case 3:
                imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);ejecutarEnConsola(HACER_PAUSA);
                break;
            case 4:
                imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);ejecutarEnConsola(HACER_PAUSA);
                break;
            case 9:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
