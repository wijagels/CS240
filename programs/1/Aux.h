#include <stdlib.h>
/**
 * Length of text up until the
 * null terminating character
 *
 * Can't use the real
 * implementation because
 * reasons.
 */
int strlen(const char*);

/**
 * Copies one string into another
 * allocated on the heap.
 */
char* copystr(const char*);

/**
 * Does copystr + "ay"
 */
char* addAy(const char*);

char* addW(const char*);
