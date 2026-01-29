#include "log.h"
#include <stdio.h>
#include <cstdarg>
#include <unistd.h>
#include <fcntl.h>

/*Initilizes logging by replacing stdout with a custom file*/
void initLog()
{
#ifdef MIRROR_FILE
	freopen(MIRROR_FILE, "w", stdout);
#endif
}

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
	fflush(stdout);
	va_end(args);
	return; 
}


