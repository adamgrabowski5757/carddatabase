#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

#ifndef cardcollection_h
#define cardcollection_h

struct card {
  // Name of the card.
  std::string name;

  // Name of illustrator for card art.
  std::string illus;

  // what type of card it is. 
  std::string type;

  // number of copies
  int count;
};

// outer map to hold all the different colors
std::map<std::string, std::map<std::string, std::vector<card*> > >colors;

// maps of every color
std::map<std::string, std::vector<card*> > green;
std::map<std::string, std::vector<card*> > blue;
std::map<std::string, std::vector<card*> > black;
std::map<std::string, std::vector<card*> > white;
std::map<std::string, std::vector<card*> > red;
std::map<std::string, std::vector<card*> > multi;
std::map<std::string, std::vector<card*> > colorless;


// rarity lists for every color
std::vector<card*> g_mythic;
std::vector<card*> g_rare;
std::vector<card*> g_uncommon;
std::vector<card*> g_common;

std::vector<card*> u_mythic;
std::vector<card*> u_rare;
std::vector<card*> u_uncommon;
std::vector<card*> u_common;

std::vector<card*> b_mythic;
std::vector<card*> b_rare;
std::vector<card*> b_uncommon;
std::vector<card*> b_common;

std::vector<card*> w_mythic;
std::vector<card*> w_rare;
std::vector<card*> w_uncommon;
std::vector<card*> w_common;

std::vector<card*> r_mythic;
std::vector<card*> r_rare;
std::vector<card*> r_uncommon;
std::vector<card*> r_common;

std::vector<card*> multi_mythic;
std::vector<card*> multi_rare;
std::vector<card*> multi_uncommon;
std::vector<card*> multi_common;

std::vector<card*> nan_mythic;
std::vector<card*> nan_rare;
std::vector<card*> nan_uncommon;
std::vector<card*> nan_common;



std::map<std::string, std::map<std::string, std::vector<card*> > > removeCard(std::string color, std::string rarity, std::string name, std::map<std::string, std::map<std::string, std::vector<card*> > >colors);

void filterCard(std::string color, std::string rarity, std::string type, std::string illus, std::map<std::string, std::map<std::string, std::vector<card*> > >colors);

std::map<std::string, std::map<std::string, std::vector<card*> > > loadDB(std::string color, std::string rarity, std::string name, std::string type, std::string illus, int count, std::map<std::string, std::map<std::string, std::vector<card*> > >colors);

#endif