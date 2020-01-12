#ifndef TEIL_H
#define TEIL_H

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

#include <fstream>
#include <cstdlib>

using namespace std;

class EOFException {};

class Teil {
public:
  Teil (string typ, string bez)
  {
  	setTyp(typ);
  	setBez(bez);
  }
  
  void print (ostream &o = cout) const
  { o << typ << " " << bez << " " << einheit << " " << gewicht << " " << preis /*<< " needs:" << needs.size() */<< "\n"; }
  
  Teil (istream &s)
  {
  	s >> typ >> bez >> einheit >> gewicht >> preis;
  	//cout << toString();
    if (!s)  throw EOFException ();  // abort constructor!
  }
  bool operator== (Teil &a) const  { return typ.compare(a.getTyp()) == 0 && bez.compare(a.getBez()) == 0; }
  bool operator< (const Teil &a) const  { return true; }
  
  void setTyp(string typ) { this->typ = typ; }
  string getTyp() { return typ; }
  void setBez(string bez) { this->bez = bez; }
  string getBez() { return bez; } 
  void setEinheit(string einheit) { this->einheit = einheit; }
  string getEinheit() { return einheit; }
  void setGewicht(string gewicht) { this->gewicht = gewicht; }
  string getGewicht() { return gewicht; }
  void setPreis(string preis) { this->preis = preis; }
  string getPreis() { return preis; }
  
  
  void addNeeds(Teil teil)
  {
	  //cout<<"[" << needs.size() << "]"; 
	  needs.push_back(teil);
	  //cout<<"[" << needs.size() << "] \n";
  }
  
  bool isTeilinVector(vector<Teil> teils) const
  {
  	for(int i = 0; i < teils.size(); i++)
  	{
  		Teil teil = teils.at(i);
  		if(teil.getTyp().compare(typ) == 0 && teil.getBez().compare(bez) == 0)
  			return true;
	}
	return false;
  }
  
  bool canTeilBuild(vector<Teil> teils) const {
  	if(needs.size() == 0) {
  		//cout <<"OK " << teils.size() << "\n";
  		return true;
	}
	bool check = true;
	for(int j = 0; j < needs.size(); j++)
	{
		Teil need = needs.at(j);
		for(int i = 0; i < teils.size(); i++)
	  	{
	  	  Teil teil = teils.at(i);
	  	  //cout << "---" << i << "--- " << teil.getTyp() << 	" " << teil.getBez() << "   -   " << need.getTyp() << 	" " << need.getBez() ;
		  if(teil.getTyp().compare(need.getTyp()) == 0 && teil.getBez().compare(need.getBez()) == 0) //TODO this == teils.at(i)
		  {
		  	//cout <<" true\n";
		  	//return true;
		  	check = true;
		  	break;
		  }
		  else { 
		  	check = false;//cout <<" false\n";
		  } 
		}
		if(!check)
			break;
	}
	  
	  
  	
	return check;
  }
	   
	   
  vector<Teil> getNeeds() { return needs; }
  
private:
  string typ, bez, einheit, gewicht, preis;
  vector<Teil> needs;
};

  inline ostream &operator<< (ostream &o, const Teil &t)
  { t.print (o);  return o; }
  
class TeilList
{
public:
  TeilList (char *fileTeil, char *fileSchritt);
  
  TeilList () { }
  
  void addTeil(Teil teil)
  {
  	teils.push_back(teil);
  }
  
  TeilList getSorted () const /////////////////////////////////////////////////////////////////////
  {
  	TeilList tl = TeilList();
  	for(int j = 0; j < teils.size();) 
  	{
	  	for(int i = 0; i < teils.size(); i++) 
	  	{
	  		Teil teil = teils.at(i);
	  		if(teil.isTeilinVector(tl.getTeilList())) continue;
		  	if(teil.canTeilBuild(tl.getTeilList())) {
		  		tl.addTeil(teil);
		  		j++;
			  }
		}
	}
  	return tl;
  }
  
  void addSchritt(istream &s)
  {
  	string z_typ, z_bez, q_typ, q_bez, REMOVEME; 
  	s >> z_typ >> z_bez >> REMOVEME >> q_typ >> q_bez >> REMOVEME >> REMOVEME >> REMOVEME;
  	Teil *teil = findTeil(z_typ, z_bez);
  	Teil quel_teil (q_typ, q_bez);
  	if(teil == nullptr) {
  		//cout << "nullptr\n";
  		return;
	  }
  	(*teil).addNeeds(quel_teil);
  	//cout << (*teil).getTyp() << " " << (*teil).getBez() << " " << quel_teil.getTyp() << " " << quel_teil.getBez() << "\n";
  }
  
  Teil *findTeil (string typ, string bez)
  {
    for(int i = 0; i < teils.size(); i++)
    {
  		if (typ.compare(teils.at(i).getTyp()) == 0 && bez.compare(teils.at(i).getBez()) == 0)
  			return &(teils.at(i));
	}
	return nullptr;
  }
  
  vector<Teil> getTeilList() const 
  {
  	return teils;
  }
  void print (ostream &o = cout) const;
private:
  vector<Teil> teils;
};
  inline ostream &operator<< (ostream &o, const TeilList &tl)
  { tl.print (o);  return o; }


#endif
