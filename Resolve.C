#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include "SymbolList.h"
#include "FileHandler.h"
#include "Resolve.h"

/* This code is complete but the calls to the FileHandler methods
 * are commented out in the constructor.
 */

/* Resolve::Resolve
 * Takes as input the command line arguments, which should be
 * .a and .o files, and performs symbol resolution. At the end
 * it checks to see if the main is defined, prints out the undefined
 * symbols, and prints out the defined symbols and their types.
 */
Resolve::Resolve(int argc, char * argv[])
{
   undefined = new SymbolList();
   defined = new SymbolList();
   handler = new FileHandler(defined, undefined);
   for (int i = 1; i < argc; i++)
   {
      
       if (!fileExists(argv[i]) || 
          (!handler->isArchive(argv[i]) && !handler->isObjectFile(argv[i])))
       {
          std::cout << "invalid file: "<< argv[i] << std::endl;
          exit(1);
       }
/* These calls are commented out. You should implement these methods
 * one at a time.
       if (handler->isObjectFile(argv[i])) handler->handleObjectFile(argv[i]);
       if (handler->isArchive(argv[i])) handler->handleArchive(argv[i]);
*/
   }
   printSymbolsAtEnd();
   
}

/* Resolve::printSymbolsAtEnd
 * Checks to see if main is defined and then print the
 * undefined and defined symbols.
 */
void Resolve::printSymbolsAtEnd()
{
   char type;
   std::string name; 
   if (!defined->getSymbol("main", &type) || type != 'T')
   {
      std::cout << ": undefined reference to main\n";
   }
   printUndefined();
   printDefined();
}

/* Resolve::printUndefined
 * Print the list of undefined symbols.
 */
void Resolve::printUndefined()
{
   for (Iterator iter = undefined->begin(); iter != undefined->end(); iter++)
   {
      std::cout << ": undefined reference to " << (*iter).name << std::endl;
   }
}

/* Resolve::printDefined
 * Print the defined symbols and their types.
 */
void Resolve::printDefined()
{
   std::cout << "Defined Symbol Table\n";
   std::cout << "-----------------------\n";
   Symbol symbol;
   for (Iterator iter = defined->begin(); iter != defined->end(); iter++)
   {
      symbol = (*iter);
      std::cout << std::setw(32) << std::left
                << symbol.name << " "
                << symbol.type
                << std::endl;
   }
}

/* Resolve::fileExists
 * Returns true if the file named in the filename argument
 * exists.
 */
bool Resolve::fileExists(std::string filename)
{
   return ( access( filename.c_str(), F_OK ) != -1 );
}

