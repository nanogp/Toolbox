#include "EstructuraGenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "D:\github\Toolbox\General.h"

int eGen_init( eGenerica listado[], int limite)
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

int eGen_mostrarUno(eGenerica parametro)
{
     printf("\n %s - %d - %d",parametro.nombre,parametro.idGenerica,parametro.estado);

}

int eGen_mostrarListado(eGenerica listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int eGen_mostrarListadoConBorrados(eGenerica listado[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eGen_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

int eGen_alta(eGenerica  listado[], int limite)
{
    int retorno = -1;
    char nombre[LARGO_NOMBRE_ESTRUCTURA_GENERICA];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado, limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eGen_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(listado[indice].nombre,"juan ");
                listado[indice].idGenerica = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}

int eGen_baja(eGenerica listado[] ,int limite, int id)
{
    int posicion;

    posicion = eGen_buscarPorId(listado, limite, id);

    listado[posicion].estado = LIBRE;

    return posicion;
}

int eGen_modificacion(eGenerica listado[] ,int limite, int id)
{
    int posicion;

    posicion = eGen_buscarPorId((listado, limite, id);

    pedirString(listado[posicion].nombre, "Ingrese nuevo nombre");

    if(listado[posicion].estado == LIBRE)
    {
        if(pedirConfirmacion("Desea Rehabilitar?") == 'S')
        {
            listado[posicion].estado = OCUPADO;
        }
    }

}

int pedirLegajo()
{
    //por ahora retorna el entero
    //luego puede agregarse validacion
    int retorno;
    retorno = pedirInt("\nIngrese legajo: ");
    return retorno;
}

void pedirNombre(char *retorno)
{
    pedirString(retorno, "Ingrese nombre: ");
}

eAlumno pedirAlumno()
{
    eAlumno retorno;

    retorno.legajo = pedirLegajo();

    pedirNombre((char *)&(retorno.nombre));

    retorno.nota1 = pedirNota(1);

    retorno.nota2 = pedirNota(2);

    retorno.promedio = calcularPromedio(retorno.nota1, retorno.nota2);

    retorno.estado = 1;

    return retorno;
}

int buscarLugarLibre(eAlumno listadoAlumnos[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarAlumno(eAlumno alumnoBuscar, eAlumno listadoAlumnos[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_ALUMNOS ; i++)
    {
        if(listadoAlumnos[i].legajo == alumnoBuscar.legajo)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void ordenarPorPromedio(eAlumno listadoAlumnos[])
{
    int i;
    int j;
    eAlumno aux;

    for(i=0 ; i<CANT_ALUMNOS-1 ; i++)
    {
        for(j=i+1 ; j<CANT_ALUMNOS ; j++)
        {
            if(listadoAlumnos[i].promedio < listadoAlumnos[j].promedio)
            {
                aux = listadoAlumnos[i];
                listadoAlumnos[i] = listadoAlumnos[j];
                listadoAlumnos[j] = aux;
            }
        }
    }

}

void procesarAlta(eAlumno listadoAlumnos[])
{
    eAlumno alumno;
    char confirmacion;
    int posicion;

    posicion = buscarLugarLibre(listadoAlumnos);
    if(posicion != -1)
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        imprimirEnPantalla("+----------------+\n| ALTA DE ALUMNO |\n+----------------+");
        alumno = pedirAlumno();
        mostrarAlumno(alumno);

        confirmacion = pedirConfirmacion("Confirma que los datos ingresados son correctos?");

        if(confirmacion == 'S')
        {
            listadoAlumnos[posicion] = alumno;
            ordenarPorPromedio(listadoAlumnos);
            imprimirEnPantalla("\nEl alumno se dio de alta.");
        }
        else
        {
            imprimirEnPantalla("\nSe cancelà la gestiàn.");
        }
    }
    else
    {
        imprimirEnPantalla("\nNo hay m s lugares disponibles para altas de alumnos.");
    }
    ejecutarEnConsola(HACER_PAUSA);
}
