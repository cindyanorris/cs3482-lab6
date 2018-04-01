#include <iostream>
#include <iomanip>
#include "SymbolList.h"

/* Most of the SymbolList methods are missing. */
/* You'll need to add the missing ones.  */
/* See SymbolList.h. */




/* The methods below are complete. */
/* These methods are for iterating through the SymbolList. */
/* They should be used by methods outside of the class. */
/* Methods inside of the class have direct access to the */
/* SymbolList data members to they don't need the iterator. */

/* SymbolList::begin
 * Return an Iterator that contains a pointer to the first
 * symbolEntry in the SymbolList class. 
 */
Iterator SymbolList::begin()
{
   return Iterator(this->first);
}

/* SymbolList::end
 * Return an Iterator that contains a pointer that is NULL.
 */
Iterator SymbolList::end()
{
   return Iterator(NULL);
}

/* Iterator constructor
 * Takes as input a pointer to a symbolEntry within
 * a SymbolList object and initializes the current data 
 * member to the value of the symbolEntry.
 */ 
Iterator::Iterator(SymbolList::symbolEntry * first)
{
   this->current = first;
}

/* Iterator::operator*
 * Returns the Symbol that is contained within the symbolEntry
 * that is pointed to by current.
 */
Symbol Iterator::operator*()
{
   Symbol sym = {' ', ""};
   if (current != NULL)
   {
      sym.name = current->symbol.name;
      sym.type = current->symbol.type;
   }
   return sym;
}
/* Iterator::operator++
 * Updates current so that it points to the next
 * symbolEntry within a SymbolList object.
 */
Iterator Iterator::operator++(int junk)
{
   Iterator iter = (*this);
   if (current != NULL) current = current->next;
   return iter;
}

/* Iterator::operator!=
 * Returns true if two Iterator objects contain current pointers that
 * point to different symbolEntry objects.
 */
bool Iterator::operator!=(const Iterator & rhs) 
{
   return current != rhs.current;
}

