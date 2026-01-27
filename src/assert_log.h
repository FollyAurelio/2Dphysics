#pragma once
#include <iostream>

#if ASSERTIONS_ENABLED

void reportAssertError(const char* expr, const char* message, const char* file, int line);

#define ASSERT(expr,message)\
	if(expr){}\
	else{\
		reportAssertError(#expr,message,__FILE__,__LINE__);\
	}

#else

#define ASSERT(expr, message)

#endif


