
class Resolve
{
   private:
      SymbolList * defined;
      SymbolList * undefined;
      FileHandler * handler;
      bool fileExists(std::string filename);
      void printSymbolsAtEnd();   
      void printUndefined();
      void printDefined();
   public:
      Resolve(int argc, char * argv[]);
};
