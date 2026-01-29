#include "resource.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "assert.h"
#include "log.h"

/* Reads a file from a file path*/
std::string loadResourceFromFile(const char* filePath)
{
	std::ifstream resourceFileStream{filePath};
	std::string fileOutput;
	std::stringstream stream;
	stream << resourceFileStream.rdbuf();
	fileOutput = stream.str();
	LOG(3, LOG_MISC, "Reading from file at path : %s", filePath);
	ASSERT(!resourceFileStream.bad(), "BADBIT ERROR");
	ASSERT(!resourceFileStream.fail(), "FAILBIT ERROR");

	//Convert to C string before returning
	return fileOutput;
}
	
		



