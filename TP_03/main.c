#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);

    int option;
    char respuesta;
    int informes;
    int opcion;
    int flagBinario = 0;
    int flagGuardarJug = 0;
    int flagGuardarSelec = 0;
    char guardar;



    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaConvocadosPorConf = ll_newLinkedList();


    do{
    option = menuOpciones();
        switch(option)
        {
            case 1:
            	printf("\nUsted eligio: CARGA DE ARCHIVOS\n");
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1){
            		printf("\nARCHIVO DE JUGADORES CARGADO CORRECTAMENTE\n");
            	}else{
            		printf("\nERROR, NO SE PUDO CARGAR EL ARCHIVO DE JUGADORES\n");
            	}

            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) == 1){
            		printf("\nARCHIVO DE SELECCIONES CARGADO CORRECTAMENTE\n");
            	}else{
            		printf("\nERROR, NO SE PUDO CARGAR EL ARCHIVO DE SELECCIONES\n");
            	}
                break;
            case 2:
            	printf("\nUsted eligio: ALTA DE JUGADOR\n");
            	if(controller_agregarJugador(listaJugadores) == 1){
            		printf("\nALTA EXITOSA");
            	}else{
            		printf("\nERROR EN LA BAJA");
            	}
                break;
            case 3:
            	printf("\nUsted eligio: MODIFICACION DE JUGADOR\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){

            	if(controller_editarJugador(listaJugadores) == 1){
            		printf("\nMODIFICACION EXITOSA");
            	}else{
            		printf("\nERROR EN LA MODIFICACION");
            	}
            	}else{
            		printf("\nError. Se deben cargar los archivos de jugadores y selecciones o dar de alta un jugador para modificarlo\n ");
            	}
                break;

            case 4:
            	printf("\nUsted eligio: BAJA DE JUGADOR\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){
            	if(controller_removerJugador(listaJugadores) == 1){
            		printf("\nBAJA EXITOSA");
            	}else{
            		printf("\nERROR EN LA BAJA");
            	}
            	}else{
            		printf("\nError. Se deben cargar los archivos de jugadores y selecciones o dar de alta un jugador para darlo de baja\n");
            	}
                break;
            case 5:
            	printf("\nUsted eligio: LISTADOS\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){
            	do{
            		informes = subMenuInformes();
            		switch(informes){
            		case 1:
            			printf("\nUsted eligio: TODOS LOS JUGADORES\n");
            			if(controller_listarJugadores(listaJugadores) != 1){
            				printf("\nError. No se pudieron listar los jugadores.\n");
            			}
            			break;
            		case 2:
            			printf("\nUsted eligio: TODAS LAS SELECCIONES\n");
            			if(controller_listarSelecciones(listaSelecciones) != 1){
            				printf("\nError. No se pudieron listar las selecciones.\n");
            			}
            		    break;
            		case 3:
            			printf("\nUsted eligio: JUGADORES CONVOCADOS\n");
            			if(listarJugadoresConvocados(listaJugadores) != 1){
            				printf("\nError. No se pudieron listar los jugadores convocados.\n");
            			}
            		    break;
            		case 4:
            		    printf("\nUsted eligio: SALIR\n");
            		    break;
            		}
            	}while(informes != 4);
            	}else{
            		printf("\nError. Se deben cargar los archivos de jugadores y selecciones o dar de alta un jugador para realizar los listados\n");
            	}
                break;
            case 6:
            	printf("\nUsted eligio: CONVOCAR JUGADORES\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){
            		controller_convocarJugadores(listaJugadores,listaSelecciones);
            	}else{
            		printf("\nError. Se deben cargar los archivos de jugadores y selecciones o dar de alta un jugador para convocarlo\n");
            	}
                break;
            case 7:
            	printf("\nUsted eligio: ORDENAR Y LISTAR\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){
            	opcion = getValidInt("\nQUE DESEA ORDENAR Y LISTAR?: \n1- JUGADORES\n2- SELECCIONES\nopcion:","\nError. Ingrese un numero: ",1,2);
            	if(opcion == 1){
            	if(controller_ordenarJugadores(listaJugadores) != 1){
            		printf("\nError. No se pueden ordenar y listar los jugadores.\n");
            	}

            	}else
            	{
            		if(opcion == 2)
            		{
            	if(controller_ordenarSelecciones(listaSelecciones) != 1)
            	{
            		printf("\nError. No se pueden ordenar y listar las selecciones.\n");
            	}
            		}
            	}
            	}else{
            		printf("\nError. Se deben cargar los archivos de jugadores y selecciones o dar de alta un jugador para ordenar y listar\n");
            	}
            	break;
            case 8:
            	printf("\nUsted eligio: GENERAR ARCHIVO BINARIO\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0)){
            	if(controller_generarJugadoresModoBinario("JugadoresBinarios.dat",listaJugadores,listaSelecciones) == 0){
            		printf("\nArchivo binario generado correctamente. \n");
            	}else{
            		printf("\nError. El archivo binario no se pudo generar correctamente. \n");
            	}
            	flagBinario =1;
            	}else{
            		printf("\nNo se puede generar el archivo binario sin antes cargar los archivos de jugadores y selecciones.\n");
            	}
                break;
            case 9:
            	printf("\nUsted eligio: CARGAR ARCHIVO BINARIO\n");
            	if(flagBinario ==1){
            		if(controller_cargarJugadoresDesdeBinario("JugadoresBinarios.dat",listaConvocadosPorConf) == 0){
            			printf("\nArchivo cargado correctamente. \n");
            		}else{
            			printf("\nError. No se pudo cargar el archivo. \n");
            		}
            	}else{
            		printf("\nNo se puede cargar el archivo binario sin antes haberlo generado\n");
            	}
                break;
            case 10:
            	printf("\nUsted eligio: GUARDAR ARCHIVOS .CSV\n");
            	if((ll_isEmpty(listaJugadores) == 0) && (ll_isEmpty(listaJugadores) == 0))
            	{
            		if(controller_guardarJugadoresModoTexto("jugadores.csv" ,listaJugadores) == 1)
            		{
            			printf("\nDATOS DE JUGADORES GUARDADOS CORRECTAMENTE\n");
            			flagGuardarJug = 1;
            		}

            		 if(controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones) == 1)
            		 {
            			 printf("\nDATOS DE SELECCIONES GUARDADOS CORRECTAMENTE");
            			 flagGuardarSelec = 1;
            		 }

            	}
            	else
            	{
            		printf("\nNo se pueden guardar los archivos .CSV sin antes cargar los archivos de jugadores y selecciones.\n");
            	}
                break;
            case 11:
            	printf("\nUsted eligio: SALIR\n");
            	if(flagGuardarJug == 1 && flagGuardarSelec == 1){
            	respuesta = getChar("\nEsta seguro de que quiere cerrar el programa? s/n: ");
            		if(respuesta == 's'||respuesta == 's')
            		{
            		printf("\nAdios!!");
            		option = 12;
            		}
            	}else{
            		guardar = getChar("\nATENCION! No se guardaron los cambios en los archivos. Desea salir igualmente? s/n: ");
            		if(guardar == 's' || guardar == 'S'){
            			option = 12;
            		}
            	}
                break;
        }
    }while(option != 12);

    return 0;
}

