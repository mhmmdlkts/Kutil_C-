#include "teil.h"
#include <fstream>

TeilList::TeilList (char *fileTeil, char *fileSchritt)
{
  ifstream s1 (fileTeil);
  try  {
  while (!s1.eof())                
  	teils.push_back(s1);
	  } catch (EOFException) {}
  s1.close();
  
  ifstream s2 (fileSchritt);
  try  {
  while (!s2.eof())
  	addSchritt (s2);
	  } catch (EOFException) {}
  s2.close();
}

void TeilList::print (ostream &o) const
{
	vector<Teil> teils = getTeilList();
	for(int i=0; i < teils.size(); i++)
	{
		o << teils.at(i);
	}
}
