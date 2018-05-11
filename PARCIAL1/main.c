#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Propietario.h"
#include "Automovil.h"

#define MAIN_MENU_GESTION_TITULO DEFINIR_MACRO_STRING(MENU ESTACIONAMIENTO)
#define MAIN_MENU_GESTION_CANT 8
#define MAIN_MENU_GESTION_DETALLE1 DEFINIR_MACRO_STRING(1. Alta Propietario)
#define MAIN_MENU_GESTION_DETALLE2 DEFINIR_MACRO_STRING(2. Modificacion Propietario)
#define MAIN_MENU_GESTION_DETALLE3 DEFINIR_MACRO_STRING(3. Baja Propietario)
#define MAIN_MENU_GESTION_DETALLE4 DEFINIR_MACRO_STRING(4. Ingreso del Automovil)
#define MAIN_MENU_GESTION_DETALLE5 DEFINIR_MACRO_STRING(5. Egreso del Automovil)
#define MAIN_MENU_GESTION_DETALLE6 DEFINIR_MACRO_STRING(6. )
#define MAIN_MENU_GESTION_DETALLE7 DEFINIR_MACRO_STRING(7. )
#define MAIN_MENU_GESTION_DETALLE8 DEFINIR_MACRO_STRING(8. Listar Automoviles)
#define MAIN_MENU_GESTION_DETALLE9 DEFINIR_MACRO_STRING(9. Listar Propietarios)
#define MAIN_MENU_GESTION_DETALLE0 DEFINIR_MACRO_STRING(0. Salir del programa)

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MAIN_MENU_GESTION_CANT,
                            /*codigos*/{1,2,3,4,5,8,9,0},
                            /*descripciones*/{MAIN_MENU_GESTION_DETALLE1,MAIN_MENU_GESTION_DETALLE2,MAIN_MENU_GESTION_DETALLE3,MAIN_MENU_GESTION_DETALLE4,MAIN_MENU_GESTION_DETALLE5,MAIN_MENU_GESTION_DETALLE8,MAIN_MENU_GESTION_DETALLE9,MAIN_MENU_GESTION_DETALLE0},
                            /*titulo del menu*/{MAIN_MENU_GESTION_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';
    int idPropietario;

    //ARRAYS DE ESTRUCTURAS
    ePropietario listadoPropietarios[PROPIETARIO_CANT_MAX] = {};
    eAutomovil listadoAutomoviles[AUTOMOVIL_CANT_MAX] = {};

    //INCIALIZAR
    ePropietario_init(listadoPropietarios, PROPIETARIO_CANT_MAX);
    eAutomovil_init(listadoAutomoviles, AUTOMOVIL_CANT_MAX);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    ePropietario_initHardcode(listadoPropietarios);
    eAutomovil_initHardcode(listadoAutomoviles);


    do
    {
        limpiarPantalla();
        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                ePropietario_alta(listadoPropietarios,PROPIETARIO_CANT_MAX);
                break;
            case 2:
                ePropietario_modificacion(listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 3:
                idPropietario = ePropietario_baja(listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 4:
                eAutomovil_alta(listadoAutomoviles, AUTOMOVIL_CANT_MAX, listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 5:
                eAutomovil_baja(listadoAutomoviles, AUTOMOVIL_CANT_MAX, listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 6:
                limpiarPantalla();imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 7:
                limpiarPantalla();imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 8:
                eAutomovil_mostrarListado(listadoAutomoviles, AUTOMOVIL_CANT_MAX);
                pausa();
                break;
            case 9:
                ePropietario_mostrarListado(listadoPropietarios, PROPIETARIO_CANT_MAX);
                pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
