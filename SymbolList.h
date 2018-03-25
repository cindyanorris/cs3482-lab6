//SymbolList class encapsulate a linked
//list of Symbol objects
typedef struct
{
   char type;
   std::string name;
} Symbol;

//forward declaration of the Iterator
//class because the SymbolList contains
//references to the Iterator type
class Iterator;

class SymbolList
{
   typedef struct symbolEntry
   {
      Symbol symbol;
      struct symbolEntry * next;
   } symbolEntry; 

   private:
      //points to the first symbolEntry in the linked list
      symbolEntry * first;

   public:
      SymbolList();  //set first to NULL

      //returns true if the symbol with the name symbolName is in the list
      //and sets (*type) to the type of the symbol
      bool getSymbol(std::string symbolName, char * type);
 
      //updates the type of the symbol with name symbolName       
      void updateSymbol(std::string symbolName, char type);

      //inserts a symbol with the name symbolName and the type char
      //at the ***end*** of the linked list
      void insertSymbol(std::string symbolName, char type);

      //removes the symbolEntry node with the name symbolName
      void removeSymbol(std::string symbolName);

      //returns an Iterator that contains a pointer to the first 
      //Symbol in the linked list
      Iterator begin();

      //returns an Iterator that contains a pointer that is NULL
      Iterator end();

      //allow the Iterator class access to the private data
      //in this class
      friend class Iterator;
};

//Iterator class for iterating over the Symbol objects
//in the SymbolList class
class Iterator
{
   public:
      Iterator(SymbolList::symbolEntry *);
      Iterator operator++(int junk);
      bool operator!=(const Iterator & rhs);
      Symbol operator*();
   private:
      SymbolList::symbolEntry * current;
};

