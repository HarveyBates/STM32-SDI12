#ifndef SDI12_DEBUG_
#define SDI12_DEBUG_

#include <stdio.h>
#include <string.h>

#include "main.h"

/*
 * Send message over UART2 for debugging
 */
void debug_output(uint8_t *data, uint8_t size);

#endif // SDI12_DEBUG_
