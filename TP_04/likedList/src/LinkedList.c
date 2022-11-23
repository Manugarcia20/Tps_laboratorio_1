#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;


    this = (LinkedList*)malloc(sizeof(LinkedList)); /// reservo espacio en memoria para una linkedlist

    if(this != NULL){
    this->size = 0;  /// inicializo su tamanio en 0
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux = this->size; /// entra en la variable de tipo linkedlist y se fija su valor para devolverlo
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int tamList;

	Node* pNode = NULL;

	tamList = ll_len(this);

		if(this != NULL && nodeIndex >= 0 && nodeIndex < tamList) /// el indice del nodo no puede ser mayor al tamanio de la lista
		{
			///inicializo el puntero a nodo y lo igualo al primer nodo de this
			pNode = this->pFirstNode; /// --> 0

			for(int i = 0; i < nodeIndex; i++)///itero hasta el indice deseado
			{
				pNode = pNode->pNextNode;///luego cargo la direccion de memoria correspondiente al indice deseado
			}
		}

	    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno = -1;
	int tamList;

	Node* newNode;
	Node* prevNode;

	    tamList = ll_len(this);


	    if(this != NULL && nodeIndex >= 0 && nodeIndex <= tamList)
	    {
	    	newNode = (Node*) malloc(sizeof(Node)); /// asigno espacio en memoria para el nuevo nodo

	    	if(newNode != NULL)
	    	{
	    	newNode->pElement = pElement; ///asigno el elemento de newNode al recibido por parametro

	    	if(nodeIndex == 0) /// si lo quiero en la primera posicion
	    	{
	    		newNode->pNextNode = this->pFirstNode; /// a mi nuevo nodo en el puntero al siguiente nodo le asigno la direccion de memoria
	    											  /// del primer nodo de la lista

	    		this->pFirstNode = newNode; ///el nuevo first node sera el proximo que cree
	    	}
	    	else
	    	{
	    		prevNode = getNode(this, nodeIndex - 1);///busco la ubicacion del nodo previo al que creo

	    		if(prevNode != NULL)
	    		{
	    		newNode->pNextNode = prevNode->pNextNode; /// al nuevo nodo le asigno el puntero al siguiente nodo que tenia el nodo previo.

	    		prevNode->pNextNode = newNode; /// le paso al nodo previo la direccion del nuevo nodo.
	    		 	 	 	 	 	 	 	  /// Ahora el nodo previo apunta al nodo siguiente, el nuevo nodo.
	    		}
	    	}

	    	this->size++; ///le incremento el campo size a la lista
	    	retorno = 0;

	    	}
	    }

	    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largo;

    largo = ll_len(this); /// saco el tamanio de la lista

    if(this != NULL)
    {
     addNode(this,largo,pElement); /// agrego el nodo con la lista, su tamanio calculado y el pElement
     returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int tamanio;
    Node* pNode = NULL;

    tamanio = ll_len(this);/// saco el tamanio de la lista

    if(this != NULL && index >=0 && index < tamanio ){ /// el index debe ser menor al tamanio de la lista y mayor o igual a 0

    pNode = getNode(this,index); /// obtengo el nodo en el index deseado y lo recibo en pNode

    returnAux = pNode->pElement; /// me fijo el valor del elemento del nodo en la posicion indicada

    }

    return returnAux; /// devuelve el valor del elemento del nodo en la posicion indicada
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int tamanio;
    Node* pNode = NULL;


    tamanio = ll_len(this);  /// saco el tamanio de la lista

    if(this != NULL && index >= 0 && index < tamanio){ /// el index debe ser menor al tamanio de la lista y mayor o igual a 0

    	pNode = getNode(this,index); /// obtengo el nodo en el index deseado y lo recibo en pNode
    	pNode->pElement = pElement; /// asigna el valor de pElement pasado por parametro al valor de pElement en la posicion deseada del nodo
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int tamanio;

    Node* pNode = NULL; /// por si es la primer posicion
    Node* pPrevNode = NULL; /// por si lo quiero asignar en otra posicion


        tamanio = ll_len(this); /// saco el tamanio de la lista

        if(this != NULL && index >= 0 && index < tamanio) /// el index no puede ser mayor al tamanio de la lista y debe ser mayor a 0
        {
        	pNode = getNode(this, index);

        	if(index == 0) /// si quiero eliminar la primera posicion
        	{
        		this->pFirstNode = pNode->pNextNode; /// el primer nodo de la lista ahora tiene la direccion de memoria del siguiente nodo
        		this->size--;  /// decremento el tamanio de la lista
        		free(pNode); /// libero el espacio en memoria del nodo

        	}
        	else
        	{
        		pPrevNode = getNode(this,index -1); /// obtengo la posicion del nodo en el index, menos 1, es decir, el previo.

        		if(pPrevNode != NULL)
        		{
        		pPrevNode->pNextNode = pNode->pNextNode; /// ahora el nodo que apuntaba el prevNode va a ser el que apunte este nodo
        		this->size--;  /// decremento el tamanio de la lista
        		free(pNode); /// libero el espacio en memoria del nodo

        		}
        	}

        	returnAux = 0;
        }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int cantidad;

    cantidad = ll_len(this); /// saco el tamanio de la lista

    /// (se puede usar el ll_len en parametros para validar)

    if(this != NULL && ll_len(this) != 0) /// la lista no debe estar vacia
    {
    	for(int i = 0; i < cantidad; i++) /// recorro la lista
    	{
    		ll_remove(this, i); /// voy eliminando cada posicion con la funcion ll_remove que hice
    	}

    	if(ll_len(this) == 0) /// si la lista esta vacia, se borro correctamente.
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
	{
	ll_clear(this); /// borro todos los elementos de la lista
	free(this); /// libero el espacio en memoria de la lista
	returnAux = 0;
	}
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL)
    {

    	for(int i = 0;i < ll_len(this);i++) /// recorro la lista con la i siendo menor al tamanio de la misma
    	{
    		pNode = getNode(this,i); /// obtengo la posicion de cada nodo con el for
    		if(pNode->pElement == pElement) /// si el elemento del nodo es igual al elemento pasado por parametros
    		{
    			returnAux = i; /// devuelvo su posicion en la lista
    		}
    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
        {
        	if(ll_len(this))
        	{
        		returnAux = 0; /// tiene elementos
        	}
        	else
        	{
        		returnAux = 1; ///esta vacia
        	}
        }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    	if(this != NULL && index >= 0 && index <= ll_len(this)) /// el index no puede ser mayor al tamanio de la lista y debe ser mayor a 0
    	    {
    		if(addNode(this, index, pElement) == 0) /// si la funcion de agregar nodo salio bien
    		{
    		returnAux  = 0;
    		}
    	    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;


    if(this != NULL && index >= 0 && index <= ll_len(this))
    {

    	returnAux = ll_get(this,index); /// obtengo el valor del elemento en el indice indicado
    	ll_remove(this,index); /// elimino ese elemento de la lista


    }
    return returnAux; /// devuelvo el valor de ese elemento aunque este ya eliminado de la lista
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    	if (this != NULL)
    		{
    			if (ll_indexOf(this, pElement) > -1) ///si el indice del elemento existe
    			{
    				returnAux = 1;
    			}
    			else /// si no existe
    			{
    				returnAux = 0;
    			}
    		}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	 int returnAux = -1;
	 void* pAuxElement = NULL;

		if(this != NULL && this2 != NULL)
		{
			// asigno returnAux a 1 suponiendo que todos los elementos estan contenidos
			returnAux = 1;
			// itero sobre los elementos de this2
			for(int i=0; i<ll_len(this2); i++)
			{

				pAuxElement = ll_get(this, i);
				// pregunto si el elemento NO esta en la lista this
				if(ll_contains(this, pAuxElement) == 0)
				{
					returnAux = 0;
					break;
				}
			}
		}

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)){ /// si from es mayor o igual a 0, menor al tamanio de la lista
    																						/// y el to es mayor al from y to menor o igual al tamanio de la lista
    cloneArray = ll_newLinkedList(); /// creo el linkedlist clon

    	for(int i = from ; i < to; i++){ /// for desde from hasta to
    		pElement = ll_get(this,i); /// saco los elementos en la lista pasada en los indices deseados
    		ll_add(cloneArray,pElement); /// agrego esos elementos a la lista clonada
    	}
    }




    return cloneArray; /// devuelvo la lista con los elementos agregados deseados
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){

    cloneArray = ll_subList(this, 0, ll_len(this)); /// copio todos los elementos de la lista this a la clon, desde la posicion 0 hasta
     	 	 	 	 	 	 	 	 	 	 	 	/// el tamanio de la lista.

//    cloneArray = ll_newLinkedList(); /// creo el linkedlist clon
//    cloneArray = this;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement1 =NULL;
    void* pElement2 =NULL;

    if(this!= NULL && pFunc!= NULL && (order == 1 || order ==0)){

    	for(int i = 0; i<ll_len(this)-1;i++){
    												/// burbujeo
    		for(int j = i+1;j<ll_len(this);j++){

    			pElement1 = ll_get(this,i); /// traigo elementos de i

    			pElement2 = ll_get(this,j); /// traigo elementos de j


    			if ((order == 1 && pFunc(pElement1,pElement2) == 1)

    			|| (order == 0 && pFunc(pElement1,pElement2)  == -1)){

    				ll_set(this,i,pElement2);
    											/// swap
    				ll_set(this,j,pElement1);
    			}

    		}

    	}
    	returnAux = 0;
    }

    return returnAux;
}

