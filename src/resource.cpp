#include "resource.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "assert.h"

/* Returns a characters array containing the characters of
 * a file from a file path
 */
const char* loadResourceFromFile(const char* filePath)
{
	std::string fileOutput;
	std::stringstream stream;
	//TODO Check if the file path exists
	std::ifstream resourceFileStream(filePath);
	//TODO Implement error handling for these classes

	stream << resourceFileStream.rdbuf();
	fileOutput = stream.str();

	//Convert to C string before returning
	ASSERT(!resourceFileStream.bad(), "BADBIT ERROR");
	ASSERT(!resourceFileStream.fail(), "FAILBIT ERROR");
	return fileOutput.c_str();
}
	
		



