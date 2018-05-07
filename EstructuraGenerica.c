#include "EstructuraGenerica.h"
#include "General.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eGenerica_init(eGenerica listado[], int limite)
{
	int retorno = -1;
	int i;

	retorno = 0;
	for(i=0 ; i<limite ; i++)
	{
		listado[i].estado= LIBRE;
		listado[i].idGenerica= 0;
	}
	return retorno;
}

int eGenerica_buscarLugarLibre(eGenerica listado[], int limite)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eGenerica_siguienteId(eGenerica listado[], int limite)
{
	int retorno = 0;
	int i;

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
	return retorno+1;
}

int eGenerica_buscarPorId(eGenerica listado[], int limite, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eGenerica_estaVacio(eGenerica listado[], int limite)
{
	int retorno = 1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO)
		{
			retorno = 0;
			break;//con el primer ocupado ya se que no esta vacio
		}
	}
	return retorno;
}

void eGenerica_mostrarUno(eGenerica parametro)
{
	 printf(GENERICA_MASCARA_MOSTRAR_UNO, parametro.idGenerica, parametro.nombre, parametro.estado);

}

void eGenerica_mostrarListado(eGenerica listado[], int limite)
{
	int i;
	int contadorMostrados = 0;

	if(eGenerica_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(GENERICA_MSJ_LISTA_VACIA);
	}
	else
	{
		printf(GENERICA_CABECERA_LISTADO);
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado==OCUPADO)
			{
				eGenerica_mostrarUno(listado[i]);
				contadorMostrados++;

				if(contadorMostrados%20 == 0)
				{
					//cada 20 registros hago una pausa
					ejecutarEnConsola(HACER_PAUSA);
					imprimirEnPantalla(GENERICA_CABECERA_LISTADO);
				}
			}

		}
	}
}

void eGenerica_listar(eGenerica listado[], int limite)
{
	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(GENERICA_TITULO_LISTA);

	eGenerica_mostrarListado(listado, limite);

	ejecutarEnConsola(HACER_PAUSA);
}

void eGenerica_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, GENERICA_MSJ_INGRESE_NOMBRE, GENERICA_MSJ_REINGRESE_NOMBRE, GENERICA_LARGO_NOMBRE);
}

eGenerica eGenerica_pedirIngreso(eGenerica listado[], int limite)
{
	eGenerica retorno;

	retorno.idGenerica = eGenerica_siguienteId(listado, limite);

	eGenerica_pedirNombre((char *)&(retorno.nombre));

	//retorno.demasCampos

	retorno.estado = OCUPADO;

	return retorno;
}

void eGenerica_alta(eGenerica listado[], int limite)
{
	eGenerica registro;
	char confirmacion;
	int posicion;

	posicion = eGenerica_buscarLugarLibre(listado, limite);
	if(posicion < 0)
	{
		imprimirEnPantalla(GENERICA_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(GENERICA_TITULO_ALTA);
		registro = eGenerica_pedirIngreso(listado, limite);
		eGenerica_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;
			eGenerica_ordenar(listado, limite, GENERICA_ORDEN);
			imprimirEnPantalla(GENERICA_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void eGenerica_baja(eGenerica listado[], int limite)
{
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(GENERICA_TITULO_BAJA);

	if(eGenerica_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(GENERICA_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eGenerica_pedirIdYBuscar(listado, limite);

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(GENERICA_TITULO_BAJA);

		eGenerica_mostrarUno(listado[posicion]);

		confirmacion = pedirConfirmacion(GENERICA_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			listado[posicion].estado = LIBRE;
			imprimirEnPantalla(GENERICA_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eGenerica_modificarUno(eGenerica registro[])
{
	eMenu menuModificar = {
							5, //cantidad de opciones
							{1,2,3,4,0}, //codigos
							{"1. Nombre","2. Legajo","3. Edad","4. Nota","0. Cancelar"}, //descripciones
							{"Qu‚ desea modificar?"} //titulo del menu
						   };
	int opcion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo("MODIFICANDO REGISTRO");
	imprimirEnPantalla("\nDatos a modificar:");
	eGenerica_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			eGenerica_pedirNombre((char *)&registro->nombre);
			break;
		case 2:
			eGenerica_pedirNombre((char *)&registro->nombre);
			break;
		case 3:
			//registro->idGenerica;
			break;
		case 4:
			//registro->campoN;
			break;
		case 0:
			break;
	}
}

int eGenerica_pedirIdYBuscar(eGenerica listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eGenerica_mostrarListado(listado, limite);
		id = pedirIntValido(GENERICA_MSJ_INGRESE_ID, GENERICA_MSJ_REINGRESE_ID, GENERICA_ID_MIN, GENERICA_ID_MAX);
		retorno = eGenerica_buscarPorId(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(GENERICA_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

void eGenerica_modificacion(eGenerica listado[], int limite)
{
	eGenerica registro;
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(GENERICA_TITULO_MODIFICACION);

	if(eGenerica_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(GENERICA_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eGenerica_pedirIdYBuscar(listado, limite);
		//traigo el registro del id elegido para no pisar directo sobre el listado
		registro = listado[posicion];

		eGenerica_modificarUno(&registro);
		eGenerica_ordenar(listado, limite, GENERICA_ORDEN);

		/*if(aca se pregunta si hubo cambios que requieran reprocesar)
		{
			se recalcularian promedios por ej.
		}*/

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(GENERICA_TITULO_MODIFICACION);

		imprimirEnPantalla(GENERICA_MSJ_REGISTRO_ACTUAL);
		eGenerica_mostrarUno(listado[posicion]);

		imprimirEnPantalla(GENERICA_MSJ_REGISTRO_MODIFICADO);
		eGenerica_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;

			imprimirEnPantalla(GENERICA_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eGenerica_ordenar(eGenerica listado[], int limite, char orden[])
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

void eGenerica_gestion(eGenerica listado[], int limite)
{
	eMenu menuEstructuraGenerica = {
							4, //limiteidad de opciones
							{1,2,3,9}, //codigos
							{"1. Alta","2. Baja","3. Modificaci¢n","9. Volver al men£ principal"}, //descripciones
							{GENERICA_TITULO_GESTION} //titulo del menu
							};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuEstructuraGenerica);
		switch(opcion)
		{
			case 1:
				eGenerica_alta(listado, limite);
				break;
			case 2:
				eGenerica_baja(listado, limite);
				break;
			case 3:
				eGenerica_modificacion(listado, limite);
				break;
			case 4:
				imprimirEnPantalla(menuEstructuraGenerica.descripciones[opcion-1]);ejecutarEnConsola(HACER_PAUSA);
				break;
			case 9:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}
