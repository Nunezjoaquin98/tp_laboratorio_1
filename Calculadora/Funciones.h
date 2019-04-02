/** \brief Muestra el menu y devuelve la opcion seleccionada
 *
  * \return Valor entero de la opcion seleccionada.
 *
 */
 int funcion_menu() ;

/** \brief Suma dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la suma de las dos variables.
 *
 */
float funcion_suma (float opc1,float opc2) ;

/** \brief Resta dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la resta de las dos variables.
 *
 */
float funcion_resta (float opc1,float opc2);

/** \brief Multiplica dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve la multiplicacion de las dos variables.
 *
 */
float funcion_multiplicar (float opc1,float opc2) ;

/** \brief Divide dos variables.
 *
 * \param Valor asignado a la variable 1.
 * \param Valor asignado a la variable 2.
 * \return Devuelve el resultado de las dos variables o un error si el divisor es 0.
 *
 */
float funcion_dividir (float opc1,float opc2) ;

/** \brief Calcula el factorial de una variable
 *
 * \param Variable utilizada.
 * \return Factorial de la variable.
 *
 */
int funcion_factorial(int opc1) ;

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void funcion_getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringInt(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringFloat(char mensaje[],char input[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int funcion_ValidarNumero(char str[]);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int funcion_validarNumeroFlotante(char str[]);
