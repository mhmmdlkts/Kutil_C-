#ifndef TEIL_H
#define TEIL_H

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class EOFException {};

class Teil {
public:
  Teil (istream &s)
  {
  	s >> typ >> bez >> einheit >> gewicht >> preis;
  	cout << toString();
    if (!s)  throw EOFException ();  // abort constructor!
  }
  bool operator< (const Teil &a) const  { return true; }
  
  string toString() const
  {
  	return typ + " " + bez + " " + einheit + " " + gewicht + " " + preis + "\n";
  }
  
  void addSchritt() const
  {
  	
  }
  
private:
  string typ, bez, einheit, gewicht, preis;
  set<Teil> needs;
};

class TeilList
{
public:
  TeilList (char *fileName);
private:
  set<Teil> teils;
};


#endif

