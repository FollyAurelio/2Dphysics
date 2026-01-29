#pragma once

#if LOGGING_ENABLED

//Log calls with a verbosity lower than this value will not be printed
#ifndef LOGGING_VERBOSITY

//Default value if ommitted from the command line defines
#define LOGGING_VERBOSITY 1

#endif

enum LogChannel
{
	LOG_GRAPHICS = 1,
	LOG_PHYSICS = 2,
	LOG_MISC = 4,
};

// This bitmask determines which log channels are ennabled enabled channels are logged
#define LOG_CHANNELS (LOG_GRAPHICS | LOG_MISC | LOG_PHYSICS)

void initLog();
void logFormat(int verbosity, LogChannel channel, const char* format, ...);

#define LOG(verbosity,channel,format,...) \
	logFormat(verbosity,channel,format,##__VA_ARGS__);\

	


#else

#define LOG(verbosity, channel, format, ...)

#endif
