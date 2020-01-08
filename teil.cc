#include "teil.h"
#include <fstream>

TeilList::TeilList (char *fileName)
{
  ifstream s (fileName);
  try  { for (;;) teils.insert (s); }
  catch (EOFException) {}
}

