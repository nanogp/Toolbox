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

int eGenerica_buscarPorNombre(eGenerica listado[], int limite, char nombre[])
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && strcmpi(listado[i].nombre, nombre) == 0)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eGenerica_pedirNombreYBuscar(eGenerica listado[], int limite)
{
	int retorno;
	char nombre[GENERICA_LARGO_NOMBRE];

	do
	{
		eGenerica_mostrarListado(listado, limite);
		eGenerica_pedirNombre(nombre);
		retorno = eGenerica_buscarPorNombre(listado, limite, nombre);
		if(retorno < 0)
		{
			imprimirEnPantalla(GENERICA_MSJ_NOMBRE_NO_EXISTE);
		}
	}
	while(retorno < 0);

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

void eGenerica_pedirClave(char retorno[])
{
	pedirStringValido(retorno, GENERICA_MSJ_INGRESE_CLAVE, GENERICA_MSJ_REINGRESE_CLAVE, GENERICA_LARGO_CLAVE);
}

int eGenerica_validarClave(eGenerica registro[], char claveIngresada[])
{
	int clavesCoinciden = 0;

	if(strcmp(registro->clave, claveIngresada) != 0)
	{
		imprimirEnPantalla(GENERICA_MSJ_CLAVE_NO_COINCIDE);
	}
	else
	{
		clavesCoinciden = 1;
	}
	return clavesCoinciden;
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
	eMenu menuModificar = {/*cantidad de opciones*/GENERICA_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,2,3,4,0},
							/*descripciones*/{GENERICA_MENU_MODIFICAR_UNO_DETALLE1,GENERICA_MENU_MODIFICAR_UNO_DETALLE2,GENERICA_MENU_MODIFICAR_UNO_DETALLE3,GENERICA_MENU_MODIFICAR_UNO_DETALLE4,GENERICA_MENU_MODIFICAR_UNO_DETALLE5},
							/*titulo del menu*/{GENERICA_MENU_MODIFICAR_UNO_TITULO}};
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) > 0)
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) < 0)
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
	eMenu menuGestion = {/*cantidad de opciones*/GENERICA_MENU_GESTION_CANT,
						/*codigos*/{1,2,3,4,0},
						/*descripciones*/{GENERICA_MENU_GESTION_DETALLE1,GENERICA_MENU_GESTION_DETALLE2,GENERICA_MENU_GESTION_DETALLE3,GENERICA_MENU_GESTION_DETALLE4,GENERICA_MENU_GESTION_DETALLE5},
						/*titulo del menu*/{GENERICA_MENU_GESTION_TITULO}};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuGestion);
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
				eGenerica_listar(listado, limite);
				break;
			case 0:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}

/************************************************************************************************************************/

int eDepende_init(eDepende listado[], int limite)
{
	int retorno = -1;
	int i;

	retorno = 0;
	for(i=0 ; i<limite ; i++)
	{
		listado[i].estado= LIBRE;
		listado[i].idDepende= 0;
	}
	return retorno;
}

int eDepende_buscarLugarLibre(eDepende listado[], int limite)
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

int eDepende_siguienteId(eDepende listado[], int limite)
{
	int retorno = 0;
	int i;

	for(i=0; i<limite; i++)
	{
		if(listado[i].estado == OCUPADO)
		{
			if(listado[i].idDepende > retorno)
			{
				 retorno = listado[i].idDepende;
			}
		}
	}
	return retorno+1;
}

int eDepende_buscarPorId(eDepende listado[], int limite, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idDepende == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eDepende_pedirIdYBuscar(eDepende listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eDepende_mostrarListado(listado, limite);
		id = pedirIntValido(DEPENDE_MSJ_INGRESE_ID, DEPENDE_MSJ_REINGRESE_ID, DEPENDE_ID_MIN, DEPENDE_ID_MAX);
		retorno = eDepende_buscarPorId(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(DEPENDE_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

int eDepende_buscarPorIdGenerica(eDepende listado[], int limite, int IdGenerica)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idGenerica == IdGenerica)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eDepende_pedirIdGenericaYBuscar(eDepende listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eDepende_mostrarListado(listado, limite);
		id = pedirIntValido(GENERICA_MSJ_INGRESE_ID, GENERICA_MSJ_REINGRESE_ID, GENERICA_ID_MIN, GENERICA_ID_MAX);
		retorno = eDepende_buscarPorIdGenerica(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(GENERICA_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}



int eDepende_estaVacio(eDepende listado[], int limite)
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

void eDepende_mostrarUno(eDepende parametro)
{
	 printf(DEPENDE_MASCARA_MOSTRAR_UNO, parametro.idDepende, parametro.nombre, parametro.estado);

}

void eDepende_mostrarListado(eDepende listado[], int limite)
{
	int i;
	int contadorMostrados = 0;

	if(eDepende_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		printf(DEPENDE_CABECERA_LISTADO);
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado==OCUPADO)
			{
				eDepende_mostrarUno(listado[i]);
				contadorMostrados++;

				if(contadorMostrados%20 == 0)
				{
					//cada 20 registros hago una pausa
					ejecutarEnConsola(HACER_PAUSA);
					imprimirEnPantalla(DEPENDE_CABECERA_LISTADO);
				}
			}

		}
	}
}

void eDepende_listar(eDepende listado[], int limite)
{
	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_LISTA);

	eDepende_mostrarListado(listado, limite);

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, DEPENDE_MSJ_INGRESE_NOMBRE, DEPENDE_MSJ_REINGRESE_NOMBRE, DEPENDE_LARGO_NOMBRE);
}

eDepende eDepende_pedirIngreso(eDepende listado[], int limite)
{
	eDepende retorno;

	retorno.idDepende = eDepende_siguienteId(listado, limite);

	eDepende_pedirNombre((char *)&(retorno.nombre));

	//retorno.demasCampos

	retorno.estado = OCUPADO;

	return retorno;
}

void eDepende_alta(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	eDepende registro;
	char confirmacion;
	int posicion;

	posicion = eDepende_buscarLugarLibre(listadoDepende, limiteDepende);
	if(posicion < 0)
	{
		imprimirEnPantalla(DEPENDE_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_ALTA);
		registro = eDepende_pedirIngreso(listadoDepende, limiteDepende);
		eDepende_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoDepende[posicion] = registro;
			eDepende_ordenar(listadoDepende, limiteDepende, DEPENDE_ORDEN);
			imprimirEnPantalla(DEPENDE_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_baja(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_BAJA);

	if(eDepende_estaVacio(listadoDepende, limiteDepende) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eDepende_pedirIdYBuscar(listadoDepende, limiteDepende);

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_BAJA);

		eDepende_mostrarUno(listadoDepende[posicion]);

		confirmacion = pedirConfirmacion(DEPENDE_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			listadoDepende[posicion].estado = LIBRE;
			imprimirEnPantalla(DEPENDE_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_modificarUno(eDepende registro[])
{
	eMenu menuModificar = {/*cantidad de opciones*/DEPENDE_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,2,3,4,0},
							/*descripciones*/{DEPENDE_MENU_MODIFICAR_UNO_DETALLE1,DEPENDE_MENU_MODIFICAR_UNO_DETALLE2,DEPENDE_MENU_MODIFICAR_UNO_DETALLE3,DEPENDE_MENU_MODIFICAR_UNO_DETALLE4,DEPENDE_MENU_MODIFICAR_UNO_DETALLE5},
							/*titulo del menu*/{DEPENDE_MENU_MODIFICAR_UNO_TITULO}};
	int opcion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo("MODIFICANDO REGISTRO");
	imprimirEnPantalla("\nDatos a modificar:");
	eDepende_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			eDepende_pedirNombre((char *)&registro->nombre);
			break;
		case 2:
			eDepende_pedirNombre((char *)&registro->nombre);
			break;
		case 3:
			//registro->idDepende;
			break;
		case 4:
			//registro->campoN;
			break;
		case 0:
			break;
	}
}

void eDepende_modificacion(eDepende listado[], int limite)
{
	eDepende registro;
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(DEPENDE_TITULO_MODIFICACION);

	if(eDepende_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(DEPENDE_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eDepende_pedirIdYBuscar(listado, limite);
		//traigo el registro del id elegido para no pisar directo sobre el listado
		registro = listado[posicion];

		eDepende_modificarUno(&registro);
		eDepende_ordenar(listado, limite, DEPENDE_ORDEN);

		/*if(aca se pregunta si hubo cambios que requieran reprocesar)
		{
			se recalcularian promedios por ej.
		}*/

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(DEPENDE_TITULO_MODIFICACION);

		imprimirEnPantalla(DEPENDE_MSJ_REGISTRO_ACTUAL);
		eDepende_mostrarUno(listado[posicion]);

		imprimirEnPantalla(DEPENDE_MSJ_REGISTRO_MODIFICADO);
		eDepende_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;

			imprimirEnPantalla(DEPENDE_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eDepende_ordenar(eDepende listado[], int limite, char orden[])
{
	int i;
	int j;
	eDepende aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idDepende > listado[j].idDepende)
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
				if(listado[i].idDepende < listado[j].idDepende)
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) > 0)
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) < 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
}

void eDepende_gestion(eDepende listadoDepende[], int limiteDepende, eGenerica listadoGenerica[], int limiteGenerica)
{
	eMenu menuGestion = {/*cantidad de opciones*/DEPENDE_MENU_GESTION_CANT,
						/*codigos*/{1,2,3,4,0},
						/*descripciones*/{DEPENDE_MENU_GESTION_DETALLE1,DEPENDE_MENU_GESTION_DETALLE2,DEPENDE_MENU_GESTION_DETALLE3,DEPENDE_MENU_GESTION_DETALLE4,DEPENDE_MENU_GESTION_DETALLE5},
						/*titulo del menu*/{DEPENDE_MENU_GESTION_TITULO}};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuGestion);
		switch(opcion)
		{
			case 1:
				eDepende_alta(listadoDepende, limiteDepende, listadoGenerica, limiteGenerica);
				break;
			case 2:
				eDepende_baja(listadoDepende, limiteDepende, listadoGenerica, limiteGenerica);
				break;
			case 3:
				eDepende_modificacion(listadoDepende, limiteDepende);
				break;
			case 4:
				eDepende_listar(listadoDepende, limiteDepende);
				break;
			case 0:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}

/************************************************************************************************************************/

int eEstadisticas_init(eEstadisticas listado[], int limite)
{
	int retorno = -1;
	int i;

	retorno = 0;
	for(i=0 ; i<limite ; i++)
	{
		listado[i].estado= LIBRE;
		listado[i].idEstadisticas= 0;
	}
	return retorno;
}

int eEstadisticas_buscarLugarLibre(eEstadisticas listado[], int limite)
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

int eEstadisticas_siguienteId(eEstadisticas listado[], int limite)
{
	int retorno = 0;
	int i;

	for(i=0; i<limite; i++)
	{
		if(listado[i].estado == OCUPADO)
		{
			if(listado[i].idEstadisticas > retorno)
			{
				 retorno = listado[i].idEstadisticas;
			}
		}
	}
	return retorno+1;
}

int eEstadisticas_buscarPorId(eEstadisticas listado[], int limite, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idEstadisticas == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eEstadisticas_pedirIdYBuscar(eEstadisticas listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eEstadisticas_mostrarListado(listado, limite);
		id = pedirIntValido(ESTADISTICAS_MSJ_INGRESE_ID, ESTADISTICAS_MSJ_REINGRESE_ID, ESTADISTICAS_ID_MIN, ESTADISTICAS_ID_MAX);
		retorno = eEstadisticas_buscarPorId(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(ESTADISTICAS_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}

int eEstadisticas_buscarPorIdDepende(eEstadisticas listado[], int limite, int IdDepende)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<limite ; i++)
	{
		if(listado[i].estado == OCUPADO && listado[i].idDepende == IdDepende)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int eEstadisticas_pedirIdDependeYBuscar(eEstadisticas listado[], int limite)
{
	int retorno;
	int id;

	do
	{
		eEstadisticas_mostrarListado(listado, limite);
		id = pedirIntValido(DEPENDE_MSJ_INGRESE_ID, DEPENDE_MSJ_REINGRESE_ID, DEPENDE_ID_MIN, DEPENDE_ID_MAX);
		retorno = eEstadisticas_buscarPorIdDepende(listado, limite, id);
		if(retorno < 0)
		{
			imprimirEnPantalla(DEPENDE_MSJ_ID_NO_EXISTE);
		}
	}
	while(retorno < 0);

	return retorno;
}



int eEstadisticas_estaVacio(eEstadisticas listado[], int limite)
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

void eEstadisticas_mostrarUno(eEstadisticas parametro)
{
	 printf(ESTADISTICAS_MASCARA_MOSTRAR_UNO, parametro.idEstadisticas, parametro.nombre, parametro.estado);

}

void eEstadisticas_mostrarListado(eEstadisticas listado[], int limite)
{
	int i;
	int contadorMostrados = 0;

	if(eEstadisticas_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(ESTADISTICAS_MSJ_LISTA_VACIA);
	}
	else
	{
		printf(ESTADISTICAS_CABECERA_LISTADO);
		for(i=0; i<limite; i++)
		{
			if(listado[i].estado==OCUPADO)
			{
				eEstadisticas_mostrarUno(listado[i]);
				contadorMostrados++;

				if(contadorMostrados%20 == 0)
				{
					//cada 20 registros hago una pausa
					ejecutarEnConsola(HACER_PAUSA);
					imprimirEnPantalla(ESTADISTICAS_CABECERA_LISTADO);
				}
			}

		}
	}
}

void eEstadisticas_listar(eEstadisticas listado[], int limite)
{
	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(ESTADISTICAS_TITULO_LISTA);

	eEstadisticas_mostrarListado(listado, limite);

	ejecutarEnConsola(HACER_PAUSA);
}

void eEstadisticas_pedirNombre(char retorno[])
{
	pedirStringValido(retorno, ESTADISTICAS_MSJ_INGRESE_NOMBRE, ESTADISTICAS_MSJ_REINGRESE_NOMBRE, ESTADISTICAS_LARGO_NOMBRE);
}

eEstadisticas eEstadisticas_pedirIngreso(eEstadisticas listado[], int limite)
{
	eEstadisticas retorno;

	retorno.idEstadisticas = eEstadisticas_siguienteId(listado, limite);

	eEstadisticas_pedirNombre((char *)&(retorno.nombre));

	//retorno.demasCampos

	retorno.estado = OCUPADO;

	return retorno;
}

void eEstadisticas_alta(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende)
{
	eEstadisticas registro;
	char confirmacion;
	int posicion;

	posicion = eEstadisticas_buscarLugarLibre(listadoEstadisticas, limiteEstadisticas);
	if(posicion < 0)
	{
		imprimirEnPantalla(ESTADISTICAS_MSJ_NO_MAS_LUGAR);
	}
	else
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(ESTADISTICAS_TITULO_ALTA);
		registro = eEstadisticas_pedirIngreso(listadoEstadisticas, limiteEstadisticas);
		eEstadisticas_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listadoEstadisticas[posicion] = registro;
			eEstadisticas_ordenar(listadoEstadisticas, limiteEstadisticas, ESTADISTICAS_ORDEN);
			imprimirEnPantalla(ESTADISTICAS_MSJ_ALTA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}
	ejecutarEnConsola(HACER_PAUSA);
}

void eEstadisticas_baja(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende)
{
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(ESTADISTICAS_TITULO_BAJA);

	if(eEstadisticas_estaVacio(listadoEstadisticas, limiteEstadisticas) == 1)
	{
		imprimirEnPantalla(ESTADISTICAS_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eEstadisticas_pedirIdYBuscar(listadoEstadisticas, limiteEstadisticas);

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(ESTADISTICAS_TITULO_BAJA);

		eEstadisticas_mostrarUno(listadoEstadisticas[posicion]);

		confirmacion = pedirConfirmacion(ESTADISTICAS_MSJ_CONFIRMAR_BAJA);

		if(confirmacion == 'S')
		{
			listadoEstadisticas[posicion].estado = LIBRE;
			imprimirEnPantalla(ESTADISTICAS_MSJ_BAJA_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eEstadisticas_modificarUno(eEstadisticas registro[])
{
	eMenu menuModificar = {/*cantidad de opciones*/ESTADISTICAS_MENU_MODIFICAR_UNO_CANT,
							/*codigos*/{1,2,3,4,0},
							/*descripciones*/{ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE1,ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE2,ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE3,ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE4,ESTADISTICAS_MENU_MODIFICAR_UNO_DETALLE5},
							/*titulo del menu*/{ESTADISTICAS_MENU_MODIFICAR_UNO_TITULO}};
	int opcion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo("MODIFICANDO REGISTRO");
	imprimirEnPantalla("\nDatos a modificar:");
	eEstadisticas_mostrarUno(*registro);

	opcion = pedirOpcion(menuModificar);
	switch(opcion)
	{
		case 1:
			eEstadisticas_pedirNombre((char *)&registro->nombre);
			break;
		case 2:
			eEstadisticas_pedirNombre((char *)&registro->nombre);
			break;
		case 3:
			//registro->idEstadisticas;
			break;
		case 4:
			//registro->campoN;
			break;
		case 0:
			break;
	}
}

void eEstadisticas_modificacion(eEstadisticas listado[], int limite)
{
	eEstadisticas registro;
	char confirmacion;
	int posicion;

	ejecutarEnConsola(LIMPIAR_PANTALLA);
	imprimirTitulo(ESTADISTICAS_TITULO_MODIFICACION);

	if(eEstadisticas_estaVacio(listado, limite) == 1)
	{
		imprimirEnPantalla(ESTADISTICAS_MSJ_LISTA_VACIA);
	}
	else
	{
		posicion = eEstadisticas_pedirIdYBuscar(listado, limite);
		//traigo el registro del id elegido para no pisar directo sobre el listado
		registro = listado[posicion];

		eEstadisticas_modificarUno(&registro);
		eEstadisticas_ordenar(listado, limite, ESTADISTICAS_ORDEN);

		/*if(aca se pregunta si hubo cambios que requieran reprocesar)
		{
			se recalcularian promedios por ej.
		}*/

		ejecutarEnConsola(LIMPIAR_PANTALLA);
		imprimirTitulo(ESTADISTICAS_TITULO_MODIFICACION);

		imprimirEnPantalla(ESTADISTICAS_MSJ_REGISTRO_ACTUAL);
		eEstadisticas_mostrarUno(listado[posicion]);

		imprimirEnPantalla(ESTADISTICAS_MSJ_REGISTRO_MODIFICADO);
		eEstadisticas_mostrarUno(registro);

		confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

		if(confirmacion == 'S')
		{
			listado[posicion] = registro;

			imprimirEnPantalla(ESTADISTICAS_MSJ_MODIFICACION_OK);
		}
		else
		{
			imprimirEnPantalla(MSJ_CANCELO_GESTION);
		}
	}

	ejecutarEnConsola(HACER_PAUSA);
}

void eEstadisticas_ordenar(eEstadisticas listado[], int limite, char orden[])
{
	int i;
	int j;
	eEstadisticas aux;

	if(strcmp(orden, "idAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(listado[i].idEstadisticas > listado[j].idEstadisticas)
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
				if(listado[i].idEstadisticas < listado[j].idEstadisticas)
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) > 0)
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
				if(strcmpi(listado[i].nombre, listado[j].nombre) < 0)
				{
					aux = listado[i];
					listado[i] = listado[j];
					listado[j] = aux;
				}
			}
		}
	}
}

void eEstadisticas_gestion(eEstadisticas listadoEstadisticas[], int limiteEstadisticas, eDepende listadoDepende[], int limiteDepende)
{
	eMenu menuGestion = {/*cantidad de opciones*/ESTADISTICAS_MENU_GESTION_CANT,
						/*codigos*/{1,2,3,4,0},
						/*descripciones*/{ESTADISTICAS_MENU_GESTION_DETALLE1,ESTADISTICAS_MENU_GESTION_DETALLE2,ESTADISTICAS_MENU_GESTION_DETALLE3,ESTADISTICAS_MENU_GESTION_DETALLE4,ESTADISTICAS_MENU_GESTION_DETALLE5},
						/*titulo del menu*/{ESTADISTICAS_MENU_GESTION_TITULO}};
	int opcion;
	char volverAlMain = 'N';

	do
	{
		ejecutarEnConsola(LIMPIAR_PANTALLA);
		opcion = pedirOpcion(menuGestion);
		switch(opcion)
		{
			case 1:
				eEstadisticas_alta(listadoEstadisticas, limiteEstadisticas, listadoDepende, limiteDepende);
				break;
			case 2:
				eEstadisticas_baja(listadoEstadisticas, limiteEstadisticas, listadoDepende, limiteDepende);
				break;
			case 3:
				eEstadisticas_modificacion(listadoEstadisticas, limiteEstadisticas);
				break;
			case 4:
				eEstadisticas_listar(listadoEstadisticas, limiteEstadisticas);
				break;
			case 0:
				volverAlMain = 'S';
				break;
		}
	}
	while(volverAlMain == 'N');
}
