#include <stdio.h>
#include "stm32f407xx.h"

/**
  * @brief  Redirección de salida
  * 
  * @note   Esta función es invocada directamente desde printf()
  *         una vez configuramos uVision para redireccionar
  *         la entrada/salida estándar al bloque ITM
  *         (Instrumentation Trace Macrocell)
  *
  * Esta función envía un caracter ch al bloque ITM
  * para que pueda ser mostrado en la ventana de depuración correspondiente
  * 
  * @param  ch El carácter a enviar
  * @param  f  El "fichero" de salida (stdout o stderr). Ignorado
  * 
  * @retval El propio carácter ch
  */
int fputc(int ch, FILE *f)
{
  ITM_SendChar(ch);
  return(ch);
}
