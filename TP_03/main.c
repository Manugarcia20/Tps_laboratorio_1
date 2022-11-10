#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "input.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);

    int option;
    char respuesta;
    int informes;
//    int cantidad;


    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();


    do{
    option = menuOpciones();
        switch(option)
        {
            case 1:
            	printf("\nUsted eligio: CARGA DE ARCHIVOS\n");
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1){
            		printf("\nARCHIVO DE JUGADORES CARGADO CORRECTAMENTE\n\n\n");
            	}else{
            		printf("\nERROR, NO SE PUDO CARGAR EL ARCHIVO DE JUGADORES\n\n\n");
            	}

            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) == 1){
            		printf("\nARCHIVO DE SELECCIONES CARGADO CORRECTAMENTE\n\n");
            	}else{
            		printf("\nERROR, NO SE PUDO CARGAR EL ARCHIVO DE SELECCIONES\n\n");
            	}
                break;
            case 2:
            	printf("\nUsted eligio: ALTA DE JUGADOR\n");
            	controller_agregarJugador(listaJugadores);
                break;
            case 3:
            	printf("\nUsted eligio: MODIFICACION DE JUGADOR\n");
            	controller_editarJugador(listaJugadores);
                break;
            case 4:
            	printf("\nUsted eligio: BAJA DE JUGADOR\n");
            	controller_removerJugador(listaJugadores);
                break;
            case 5:
            	printf("\nUsted eligio: LISTADOS\n");
            	do{
            		informes = subMenuInformes();
            		switch(informes){
            		case 1:
            			printf("\nUsted eligio: TODOS LOS JUGADORES\n");
            			controller_listarJugadores(listaJugadores);
            			break;
            		case 2:
            			printf("\nUsted eligio: TODAS LAS SELECCIONES\n");
            			controller_listarSelecciones(listaSelecciones);
            		    break;
            		case 3:
            			printf("\nUsted eligio: JUGADORES CONVOCADOS\n");

            		    break;
            		case 4:
            		    printf("\nUsted eligio: SALIR\n");
            		    break;
            		}
            	}while(informes != 4);
                break;
            case 6:
            	printf("\nUsted eligio: CONVOCAR JUGADORES\n");
            	convocarJugadores(listaSelecciones,listaJugadores);
                break;
            case 7:
            	printf("\nUsted eligio: ORDENAR Y LISTAR\n");
                break;
            case 8:
            	printf("\nUsted eligio: GENERAR ARCHIVO BINARIO\n");
                break;
            case 9:
            	printf("\nUsted eligio: CARGAR ARCHIVO BINARIO\n");
                break;
            case 10:
            	printf("\nUsted eligio: GUARDAR ARCHIVOS .CSV\n");
                break;
            case 11:
            	printf("\nUsted eligio: SALIR\n");
            	respuesta = getChar("\nEsta seguro de que quiere cerrar el programa? s/n: ");
            		if(respuesta == 's'||respuesta == 's')
            		{
            		printf("\nAdios!!");
            		option = 12;
            		}
                break;
        }
    }while(option != 12);

    return 0;
}

