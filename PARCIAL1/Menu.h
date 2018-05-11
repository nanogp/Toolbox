#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define MENU_LARGO_DESCRIPCION 100
#define MENU_MAX_OPCIONES 20

typedef struct
{
    int limiteOpciones;
    int codigos[MENU_MAX_OPCIONES];
    char descripciones[MENU_MAX_OPCIONES][MENU_LARGO_DESCRIPCION];
    char titulo[MENU_LARGO_DESCRIPCION];
} eMenu;

/** \brief muestra en pantalla un tipo de dato menu
 *
 * \param menu  eMenu: el menu a mostrar
 * \return void
 *
 */
void mostrarMenu(eMenu menu);


/** \brief pide al usuario que elija una opcion de menu recibido como parametro
 *
 * \param menu  eMenu: el menu de opciones a mostrar al usuario para pedir y validar la opcion seleccionada
 * \return int: el numero de opcion validada
 *
 */
int pedirOpcion(eMenu menu);

#endif // MENU_H_INCLUDED
