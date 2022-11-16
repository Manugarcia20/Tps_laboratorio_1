


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* le paso el nombre del archivo
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador); ///

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* le paso el nombre del archivo
 * \param pArrayListJugador LinkedList*
 * \return int  devuelve 1 si salio bien
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);///

/** \brief Alta de jugadores
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador); ///

/** \brief Modificar datos del jugador
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_editarJugador(LinkedList* pArrayListJugador); ///

/** \brief Baja del jugador
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_removerJugador(LinkedList* pArrayListJugador); ///

/** \brief Listar jugadores
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int  devuelve 1 si salio bien
 */
int controller_listarJugadores(LinkedList* pArrayListJugador); ///

/** \brief Ordenar jugadores
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int  devuelve 1 si salio bien
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador); ///

/// @brief Convocacion de jugadores
/// @param pArrayListJugador le paso la lista de jugadores
/// @param pArrayListSeleccion le paso la lista de selecciones
/// @return int  devuelve 1 si salio bien
int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);///

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 * \param path char* le paso el nombre del archivo
 * \param pArrayListSeleccion LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);///

/// @brief Genera una lista de jugadores convocados por confederacion en binario
/// @param path le paso el nombre del archivo
/// @param pArrayListJugador le paso la lista de jugadores
/// @param pArrayListSeleccion le paso la lista de selecciones
/// @return devuelve 1 si salio bien
int controller_generarJugadoresModoBinario(char* path,LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);///

/// @param path
/// @param pArrayListJugador
/// @return
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 * \param path char* le paso el nombre del archivo
 * \param pArrayListSeleccion LinkedList* le paso la lista de selecciones
 * \return int devuelve 1 si salio bien
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion); ///

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 * \param path char* le paso el nombre del archivo
 * \param pArrayListSeleccion LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);///

/** \brief Listar selecciones
 * \param pArrayListSeleccion LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion); ///

/** \brief Ordenar selecciones
 * \param pArrayListSeleccion LinkedList* le paso la lista de selecciones
 * \return int devuelve 1 si salio bien
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion); ///






