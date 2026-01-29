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
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
}

/*Prints a formatted log message, will only print if the channel is 
 * enabled and the verbosity is high enough.*/
void logFormat(int verbosity, LogChannel channel, const char* format, ...)
{
	//We keep track of how many logs have occured
	static int logCounter;
	if((verbosity < LOGGING_VERBOSITY) || ((channel & LOG_CHANNELS) == 0))
		return;
	va_list args;
    	va_start(args, format);
	fprintf(stdout, "[%d] : ", logCounter);
	vfprintf(stdout, format, args);
	fprintf(stdout, "\n");
	va_end(args);
	logCounter++;
	return; 
}


