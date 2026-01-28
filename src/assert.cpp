#include "assert.h"

/*Displays the assertion error, along with a message about the error caused and the file + line
 * the error occured in, note that the message has a new line character added to it
 */
void reportAssertError(const char* expr, const char* message, const char* file, int line)
{
	std::cerr << expr << " assertion failed in file " 
		<< file << " on line " << line << "\n" << message << "\n";
	exit(1);
}

/* Reports a message, note the message has a newline added to it
 */
void reportLog(const char* message)
{
	std::cout << message << '\n';
}	

/*Log function intended to be used to log values
void reportLogInteger(const char* message, ssize_t value)
{
	std::cout << message << '\n';
}
*/
