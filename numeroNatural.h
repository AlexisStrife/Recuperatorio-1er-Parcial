/**
 * Estructura de numeroNatural
 */
typedef struct {

    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
    int estado;

}numeroNatural;

/**
 * Ingresa un nuevo elemento en la lista
 * @param num el array se pasa como parametro, int cantidad de elementos en el array.
 */
void altaNum(numeroNatural num[], int);

/**
 * imprime en pantalla el numero recibido
 * @param num el numero a imprimir.
 */
void mostrarNumero(numeroNatural num);

/**
 * inhabilita un elemento de la lista
 * @param num el array se pasa como parametro, int cantidad de elementos en el array.
 */
void bajaNum(numeroNatural num[], int);

/**
 * modifica un elemento de la lista
 * @param num el array se pasa como parametro, int cantidad de elementos en el array.
 */
void modificarNum(numeroNatural num[], int);

/**
 * inicializa en estado 0(sin datos) todos los elementos de la lista
 * @param num el array se pasa como parametro, int cantidad de elementos en el array.
 */
void inicializarNum(numeroNatural num[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param num el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibreNum(numeroNatural num[], int cantidad);

/**
 * Obtiene el indice que coincide con el numero pasado por parametro.
 * @param num el array se pasa como parametro.
 * @param numero el numero a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro codigo
 */
int buscarPorNumero(numeroNatural num[], int cant, int numero);

/**
 * calcula los datos par, impar y primo del array enviado
 * @param num el array se pasa como parametro.
* @param cantidad la cantidad de elementos en el array.
 */
void calculaDatos(numeroNatural num[], int cantidad);

/**
 * Informa distintos datos del array
 * @param num el array se pasa como parametro
 * @param cantidad de productos en el array
 */
void informarNum(numeroNatural num[], int cantidad);

/**
 * ingresa datos hardcodeados en cada elemento de la lista para pruebas
 * @param lista el array que se llena con datos hardcodeados.
 */
void hardCodeNum(numeroNatural num[], int cantidad);
