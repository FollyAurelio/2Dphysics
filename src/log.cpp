#include "log.h"
#include <stdio.h>
#include <cstdarg>

/*Prints a formatted log message, will only print if the channel is 
 * enabled and the verbosity is high enough.*/
void logFormat(int verbosity, LogChannel channel, const char* format, ...)
{
	if((verbosity < LOGGING_VERBOSITY) || ((channel & LOG_CHANNELS) == 0))
		return;
	va_list args;
    	va_start(args, format);
	
	vfprintf(stdout, format, args);
	fprintf(stdout, "\n");

	va_end(args);
	return; 
}


