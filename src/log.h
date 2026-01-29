#pragma once

#if LOGGING_ENABLED

#ifndef LOGGING_VERBOSITY

#define LOGGING_VERBOSITY 1

#endif

enum LogChannel
{
	LOG_GRAPHICS = 1,
	LOG_PHYSICS = 2,
	LOG_MISC = 4,
};

#define LOG_CHANNELS (LOG_GRAPHICS | LOG_MISC | LOG_PHYSICS)

void logFormat(int verbosity, LogChannel channel, const char* format, ...);

#define LOG(verbosity,channel,format,...) \
	logFormat(verbosity,channel,format,##__VA_ARGS__);\

	


#else

#define LOG(verbosity, channel, format, ...)

#endif
