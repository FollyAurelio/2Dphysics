#include "rs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "assert_log.h"

/* Returns a characters array containing the characters of
 * a file from a file path
 */
const char* loadResourceFromFile(const char* filePath)
{
	std::string fileOutput;
	std::stringstream stream;
	ASSERT(0, "message2");
	//TODO Check if the file path exists
	std::ifstream resourceFileStream(filePath);
	//TODO Implement error handling for these classes

	stream << resourceFileStream.rdbuf();
	fileOutput = stream.str();

	//Convert to C string before returning
	return fileOutput.c_str();
}
	
		



