#include "EstructuraGenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "D:\github\Toolbox\General.h"

int eGen_init(eGenerica listado[], int limite)
{
	int retorno = -1;
	int i;

	if(limite > 0 && listado != NULL)
	{
		retorno = 0;
		for(i=0 ; i<limite ; i++)
		{
			listado[i].estado= LIBRE;
			listado[i].idGenerica= 0;
		}
	}
	return retorno;
}

int eGen_buscarLugarLibre(eGenerica listado[], int limite)
{
	int retorno = -1;
	int i;

	if(limite > 0 && listado != NULL)
	{
		retorno = -2;
		for(i=0 ; i<limite ; i++)
		{
			if(listado[i].estado == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eGen_siguienteId(eGenerica listado[], int limite)
{
	int retorno = 0;
	int i;

	if(limite > 0 && listado != NULL)
	{
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado == OCUPADO)
			{
				if(listado[i].idGenerica > retorno)
				{
					 retorno = listado[i].idGenerica;
				}
			}
		}
	}

	return retorno+1;
}

int eGen_buscarPorId(eGenerica listado[], int limite, int id)
{
	int retorno = -1;
	int i;

	if(limite > 0 && listado != NULL)
	{
		retorno = -2;
		for(i=0 ; i<limite ; i++)
		{
			if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eGen_mostrarUno(eGenerica parametro)
{
	 printf("\n %s - %d - %d", parametro.nombre, parametro.idGenerica, parametro.estado);

}

void eGen_mostrarListado(eGenerica listado[], int limite)
{
	int i;
	if(limite > 0 && listado != NULL)
	{
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado==OCUPADO)
			{
				eGen_mostrarUno(listado[i]);
			}
		}
	}
}

void eGen_mostrarListadoConBorrados(eGenerica listado[], const int limite)
{
	int i;
	if(limite > 0 && listado != NULL)
	{
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado == LIBRE)
			{
				printf("\n[LIBRE]");
			}
			eGen_mostrarUno(listado[i]);
		}
	}
}

void pedirNombre(char *retorno)
{
	char mensajeReingreso[100];
    strcat(mensajeReingreso, "\nReingrese un nombre de hasta ");
	strcat(mensajeReingreso, LARGO_NOMBRE_ESTRUCTURA_GENERICA);
	strcat(mensajeReingreso, " caracteres");

	pedirStringValido(retorno, "\nIngrese nombre: ", mensajeReingreso, LARGO_NOMBRE_ESTRUCTURA_GENERICA);
}

eGenerica eGen_pedirIngreso(eGenerica listado[], const int limite)
{
	eGenerica retorno;

	retorno.idGenerica = eGen_siguienteId(listado, limite);

	pedirNombre((char *)&(retorno.nombre));

    //retorno.demasCampos

	retorno.estado = OCUPADO;

	return retorno;
}

void eGen_alta(eGenerica listado[], int limite)
{
	eGenerica registro;
	char confirmacion;
	int posicion;

	posicion = eGen_buscarLugarLibre(listado, limite);
	if(posicion < 0)
	{
		imprimirEnPantalla("\nNo hay m s lugares disponibles para altas de EstructuraGenerica.");
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(TITULO_ALTA);
		registro = eGen_pedirIngreso(listado, limite);
		eGen_mostrarUno(registro);

		confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;
			ordenarPorPromedio(listado);
			imprimirEnPantalla("\nEl EstructuraGenerica se dio de alta.");
		}
		else
		{
			imprimirEnPantalla("\nSe cancelà la gestiàn.");
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void eGen_baja(eGenerica listado[], const int limite)
{
    int id;
    char confirmacion;
    char continuarGestion = 'N';
    int posicion;

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        imprimirTitulo(TITULO_BAJA);

        eGen_mostrarListado(listado, limite);
        id = pedirInt("\n\nIngrese el ID a dar de baja: ");

        posicion = eGen_buscarPorId(listado, limite, id);
        if(posicion < 0)
        {
            if(listado[posicion].estado == LIBRE)
            {
                imprimirEnPantalla("\nEl EstructuraGenerica ya se encontraba dado de baja");
            }
            else
            {
                eGen_mostrarUno(listado[posicion]);

                confirmacion = pedirConfirmacion("Confirma que desea dar de baja dicho EstructuraGenerica?");

                if(confirmacion == 'S')
                {
                    listado[posicion].estado = LIBRE;
                    imprimirEnPantalla("\nEl EstructuraGenerica se dio de baja.");
                    continuarGestion = 'N';
                }
                else
                {
                    imprimirEnPantalla("\nSe cancelà la gestiàn.");
                }
            }
        }
        else
        {
            imprimirEnPantalla("\nEl ID de EstructuraGenerica ingresado por par metro no existe.");
            continuarGestion = pedirConfirmacion("Desea reintentar la gesti¢n?");
        }
    }
    while(continuarGestion =='S');

    ejecutarEnConsola(HACER_PAUSA);
}

void eGen_modificarUno(eGenerica *registro)
{
    eMenu menuModificar = {
                            6, //cantidad de opciones
                            {1,2,3,4,5,9}, //codigos
                            {"1. Legajo","2. Nombre","3. Nota 1","4. Nota 2","5. Rehabilitar","9. Cancelar"}, //descripciones
                            {"\nQu‚ desea modificar?"} //titulo del menu
                           };
    int opcion;
    char

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("MODIFICANDO REGISTRO");
    imprimirEnPantalla("\nDatos a modificar:");
    eGen_mostrarUno(*registro);

    if(registro->estado == 0)
    {
        imprimirEnPantalla("El EstructuraGenerica se encuentra dado de baja.");
    }

    opcion = pedirOpcion(menuModificar);
    switch(opcion)
    {
        case 1:
            registro->idGenerica = pedirInt();
            break;
        case 2:
            pedirNombre((char *)&registro->nombre);
            break;
        /*
        case 3:
            registro->campoM
            break;
        case 4:
            registro->campoN
            break;
        */
        case 5:
            registro->estado = 1;
            break;
        case 9:
            break;
    }
}

void eGen_modificacion(eGenerica listado[], const int limite)
{
    eGenerica registro;
    char confirmacion;
    int posicion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(TITULO_MODIFICACION);

    registro.idGenerica = pedirIntValido("\n\nIngrese el ID de EstructuraGenerica a modificar: ", "El ID debe ser un n¡mero mayor que cero", 1, 99999999);

    posicion = eGen_buscarPorId(listado, listado, registro.idGenerica);
    if(posicion != -1)
    {
        //traigo el registro del id elegido para no pisar directo sobre el listado
        registro = listado[posicion];

        eGen_modificarUno(&alumnoModificar);

        if(listado[posicion].estado != alumnoModificar.estado)
        {
            confirmacion = pedirConfirmacion("Confirma que desea rehabilitar al EstructuraGenerica?");
        }
        else
        {
            /*
            if(aca se pregunta si hubo cambios que requieran reprocesos)
            {
                aca se recalcularian promedios y reordenaria la lista por ej.
            }
            */
            ejecutarEnConsola(LIMPIAR_PANTALLA);

            imprimirEnPantalla("EstructuraGenerica actual:");
            eGen_mostrarUno(listado[posicion]);

            imprimirEnPantalla("EstructuraGenerica nuevo:");
            eGen_mostrarUno(registro);

            confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");
        }

        if(confirmacion == 'S')
        {
            listado[posicion] = registro;
            ordenarPorPromedio(listado);
            imprimirEnPantalla("\nEl EstructuraGenerica se modificà.");
        }
        else
        {
            imprimirEnPantalla("\nSe cancelà la gestiàn.");
        }
    }
    else
    {
        imprimirEnPantalla("\nEl ID de EstructuraGenerica ingresado por par metro no existe.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}

void eGen_ordenar(eGenerica listado[], int limite, int orden);
{
	int i;
	int j;
	eGenerica aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idGenerica > listado[j].idGenerica)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "idDesc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idGenerica < listado[j].idGenerica)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreDesc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmp(listado[i].nombre, listado[j].nombre) < 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
}
