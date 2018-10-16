
#include "cardcollection.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>



using namespace std;


int main(int argc, char** argv){
    int vectsize;
    bool addremove = false;
    fstream cardDB; 
    string name;
    string illus;
    string line;
    string type;
    string rarity;
    string color;
    int count;

// populate maps
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Green", green) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Blue", blue) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Black", black) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("White", white) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Red", red) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Multi", multi) );
    colors.insert( std::pair<std::string, std::map<std::string, std::vector<card*> > >("Colorless", colorless) );

    green.insert( std::pair<std::string, std::vector<card*> >("Green", g_mythic) );
    green.insert( std::pair<std::string, std::vector<card*> >("Green", g_rare) );
    green.insert( std::pair<std::string, std::vector<card*> >("Green", g_uncommon) );
    green.insert( std::pair<std::string, std::vector<card*> >("Green", g_common) );

    blue.insert( std::pair<std::string, std::vector<card*> >("Blue", u_mythic));
    blue.insert( std::pair<std::string, std::vector<card*> >("Blue", u_rare));
    blue.insert( std::pair<std::string, std::vector<card*> >("Blue", u_uncommon));
    blue.insert( std::pair<std::string, std::vector<card*> >("Blue", u_common));

    black.insert( std::pair<std::string, std::vector<card*> >("Black", b_mythic));
    black.insert( std::pair<std::string, std::vector<card*> >("Black", b_rare));
    black.insert( std::pair<std::string, std::vector<card*> >("Black", b_uncommon));
    black.insert( std::pair<std::string, std::vector<card*> >("Black", b_common));

    white.insert( std::pair<std::string, std::vector<card*> >("White", w_mythic));
    white.insert( std::pair<std::string, std::vector<card*> >("White", w_rare));
    white.insert( std::pair<std::string, std::vector<card*> >("White", w_uncommon));
    white.insert( std::pair<std::string, std::vector<card*> >("White", w_common));

    red.insert( std::pair<std::string, std::vector<card*> >("Red", r_mythic));
    red.insert( std::pair<std::string, std::vector<card*> >("Red", r_rare));
    red.insert( std::pair<std::string, std::vector<card*> >("Red", r_uncommon));
    red.insert( std::pair<std::string, std::vector<card*> >("Red", r_common));

    multi.insert( std::pair<std::string, std::vector<card*> >("Multi", multi_mythic));
    multi.insert( std::pair<std::string, std::vector<card*> >("Multi", multi_rare));
    multi.insert( std::pair<std::string, std::vector<card*> >("Multi", multi_uncommon));
    multi.insert( std::pair<std::string, std::vector<card*> >("Multi", multi_common));

    colorless.insert( std::pair<std::string, std::vector<card*> >("Colorless", nan_mythic));
    colorless.insert( std::pair<std::string, std::vector<card*> >("Colorless", nan_rare));
    colorless.insert( std::pair<std::string, std::vector<card*> >("Colorless", nan_uncommon));
    colorless.insert( std::pair<std::string, std::vector<card*> >("Colorless", nan_common));

    cardDB.open("CardDB.txt", ios::in);


    // read current card collection from file
    if (cardDB.is_open()){
    
    // load in prexisting DB
    while ( getline(cardDB, line) ){
        
        stringstream ss(line);
        ss >> name >> type >> illus >> count;

        if (name == "White:"){
            color = "White";
        } else if (name == "Blue:"){
            color = "Blue";
        } else if (name == "Black"){
            color = "Black";
        } else if (name == "Green:"){
            color = "Green";
        } else if (name == "Red:"){
            color = "Red";
        } else if (name == "Colorless:"){
            color = "Colorless";
        } else if (name == "Multi:"){
            color = "Multi";
        } 

        if (name == "Common:"){
            rarity = "Common";
        } else if (name == "Uncommon:"){
            rarity = "Uncommon";
        } else if (name == "Rare:"){
            rarity = "Rare";
        } else if (name == "Mythic:"){
            rarity = "Mythic";
        } 

        if (name != "Green:" && name != "Blue:" && name != "Black:" && name != "White:" && name != "Red:" && name != "Multi:" && name != "Colorless:" && name != "Common:" && name != "Uncommon:" && name != "Rare:" && name != "Mythic:") {
            colors = loadDB(color, rarity, name, type, illus, count, colors);
        }
    }
        
    cardDB.close();
    }

    // Check command line arguments
    if (argc==1){
        cout << "" << endl;
        cout << "No arguments, or incorrect arguments." << endl;
        cout << "Run: './cardcollection help' for a list of commands and usage." << endl;
        cout << "" << endl;
        cout << "Showing entire collection:" << endl;
        filterCard("all", "all", "all", "all", colors);
        return 0;
    }
    if (!strcmp(argv[1],"add")){
        
        if (argc <8){
            cout << "Not enough arg's to add a card brah. Give me more deets on the card." << endl;
            cout << "put arg's in order: Color, Rarity, Name, Type, Illustrator, Amount Owned" << endl;
        } else if (argc > 8){
            cout << "too many args, names should be one word." << endl;
            cout << "For example, 'LanowarElves', not 'Lanowar Elves'." << endl;
        } 
        else {
            addremove = true;
            count = strtol(argv[7], NULL, 10);
            colors = loadDB(argv[2], argv[3], argv[4], argv[5], argv[6], count, colors);
        }
    }
    else if (!strcmp(argv[1],"remove")){
        if (argc <4){
            cout << "Not enough arg's to remove a card brah. Give me more deets on the card." << endl;
            cout << "put arg's in order: Color, Rarity, Name" << endl;
        } 
        else {
            addremove = true;
            count = strtol(argv[6], NULL, 10);
            colors = removeCard(argv[2], argv[3], argv[4], colors);
        }
    }
    else if (!strcmp(argv[1],"filter")) {
        if (argc<5){
            cout << "Not enough arg's to filter the collection brah. Give me more deets." << endl;
            cout << "put arg's in order: Color, Rarity, Type, Illustrator" << endl;
        } 
        else {
            filterCard(argv[2], argv[3], argv[4], argv[5], colors);
        }
    }
    else if (!strcmp(argv[1],"help")){
        cout << "***********************" << endl;  
        cout << "Commands are:" << endl;
        cout << "      add" << endl;
        cout << "      args: Color, Rarity, Name, Illustrator, Amount Owned" << endl;
        cout << "      Use add to insert a new card into collection or update the Amount owned of an existing card." << endl;
        cout << " " << endl;
        cout << "      remove" << endl;
        cout << "      args: Color, Rarity, Name" << endl;
        cout << "      Use to remove a card from the collection." << endl;
        cout << " " << endl;
        cout << "      filter" << endl;
        cout << "      args: Color, Rarity, Card Type, Illustrator" << endl;
        cout << "      Use to print a list of all cards in collection that match criteria." << endl;
        cout << "      Use 'all' as arg to see all colors, rarities, card types, or illustrators." << endl;
        cout << "      For example, 'filter all all all all' would print out every card in the collection." << endl;
        cout << "***********************" << endl;   
    } 
    
    // after any operations are done, write card collection to txt file
    if (addremove){
    std::vector<std::string> colorlist;
    colorlist.push_back("White");
    colorlist.push_back("Blue");
    colorlist.push_back("Black");
    colorlist.push_back("Red");
    colorlist.push_back("Green");
    colorlist.push_back("Multi");
    colorlist.push_back("Colorless");

    std::vector<std::string> raritylist;
    raritylist.push_back("Common");
    raritylist.push_back("Uncommon");
    raritylist.push_back("Rare");
    raritylist.push_back("Mythic");

    cardDB.open("CardDB.txt", std::ofstream::out | std::ofstream::trunc);

    for (int x = 0; x<7; x++){
        for (int y = 0; y<4; y++){
            vectsize = colors[colorlist[x]][raritylist[y]].size();
            if (vectsize > 0){
                cardDB << colorlist[x] << ":" << endl;
                cardDB << raritylist[y] << ":" << endl;
            }
            for (int z = 0; z < vectsize; z++){
                cardDB << colors[colorlist[x]][raritylist[y]][z]->name << " " << colors[colorlist[x]][raritylist[y]][z]->type << " " << colors[colorlist[x]][raritylist[y]][z]->illus << " " << colors[colorlist[x]][raritylist[y]][z]->count << endl;
            }
        }
    }
    cardDB.close();
    cout << "Updated cardDB.txt." << endl;
    }
    return 0;
}

// Load Database Function
std::map<std::string, std::map<std::string, std::vector<card*> > > loadDB(std::string color, std::string rarity, string name, string type, string illus, int count, std::map<std::string, std::map<std::string, std::vector<card*> > >colors){
    bool found = false;
    int spot = 0;
    card* newcard = new card;
    newcard->count = count;
    newcard->name = name;
    newcard->illus = illus;
    newcard->type = type;
    int vectlen = colors[color][rarity].size();
    for (int x = 0; x<vectlen; x++){
        // if card already exists
        if (colors[color][rarity][x]->name == name){
            found = true;
            spot = x;
            cout << "You already own this card!" << endl;
            break;
        } 
    }
    if (found == true){
        //possibly update count
        if (colors[color][rarity][spot]->count != count){
            cout << "Difference in number of copies, updating..." << endl;
            colors[color][rarity][spot]->count = count;
            cout << "Now have " << count << " copies of: " << name << endl;
        } 
        else {
            cout << "Nothing new, nothing to do" << endl;
            return colors;
        }
    } 
    else {
        colors[color][rarity].push_back(newcard);
    }

    return colors;
}

// Remove a card from the Database Function
std::map<std::string, std::map<std::string, std::vector<card*> > > removeCard(std::string color, std::string rarity, string name, std::map<std::string, std::map<std::string, std::vector<card*> > >colors){
    bool found = false;
    int spot = 0;
    int vectlen = colors[color][rarity].size();
    for (int x = 0; x<vectlen; x++){
        // if card already exists
        if (colors[color][rarity][x]->name == name){
            found = true;
            spot = x;
            cout << "This card is in your collection" << endl;
            break;
        } 
    }
    if (found == true){
        //remove the card
        colors[color][rarity].erase(colors[color][rarity].begin()+ spot);
        cout << "Removed " << name << endl;
        return colors;
        // if card isnt already in collection, add it.
    } 
    else {
        cout << "Card isn't in collection" << endl;
        cout << "Nothing to do" << endl;
        return colors;
    }

    return colors;
}

// Filter though Database function
void filterCard(std::string color, std::string rarity, std::string type, std::string illus, std::map<std::string, std::map<std::string, std::vector<card*> > > colors){
    int vectsize;
    cout << "" << endl;
    cout << "Search Results:" << endl;
    cout << "" << endl;
    std::vector<std::string> colorlist;
    colorlist.push_back("White");
    colorlist.push_back("Blue");
    colorlist.push_back("Black");
    colorlist.push_back("Red");
    colorlist.push_back("Green");
    colorlist.push_back("Multi");
    colorlist.push_back("Colorless");

    std::vector<std::string> raritylist;
    raritylist.push_back("Common");
    raritylist.push_back("Uncommon");
    raritylist.push_back("Rare");
    raritylist.push_back("Mythic");

    // see every color
    if (color == "all"){
        // see every rarity
        if (rarity == "all"){
            // see every card type
            if (type == "all"){
                // see every illustrator
                if (illus == "all"){
                    // we seeing everything, baby
                    for (int x = 0; x<7; x++){
                        for (int y = 0; y<4; y++){
                            vectsize = colors[colorlist[x]][raritylist[y]].size();
                            if (vectsize > 0){
                                cout << colorlist[x] << " " << raritylist[y] << ":" << endl;
                            }
                            for (int z = 0; z < vectsize; z++){
                                cout << colors[colorlist[x]][raritylist[y]][z]->name << "|" << colors[colorlist[x]][raritylist[y]][z]->type << "|" << colors[colorlist[x]][raritylist[y]][z]->illus << "|" << colors[colorlist[x]][raritylist[y]][z]->count << endl;
                            }
                        }
                    }

                // every color, rarity, and type. Specific illus
                } else {
                    for (int x = 0; x<7; x++){
                        for (int y = 0; y<4; y++){
                            vectsize = colors[colorlist[x]][raritylist[y]].size();
                            for (int z = 0; z < vectsize; z++){
                                if (colors[colorlist[x]][raritylist[y]][z]->illus == illus){
                                    cout << colors[colorlist[x]][raritylist[y]][z]->name << "|" << colors[colorlist[x]][raritylist[y]][z]->type << "|" << colors[colorlist[x]][raritylist[y]][z]->illus << "|" << colors[colorlist[x]][raritylist[y]][z]->count << endl;
                                }
                            }
                        }
                    }

                
                }

            // all colors and rarity, specfic type and maybe specific illus
            } else {

                // all colors, rarities, and illus. specific type.
                if (illus == "all"){
                    for (int x = 0; x<7; x++){
                        for (int y = 0; y<4; y++){
                            vectsize = colors[colorlist[x]][raritylist[y]].size();
                            for (int z = 0; z < vectsize; z++){
                                if (colors[colorlist[x]][raritylist[y]][z]->type == type){
                                    cout << colors[colorlist[x]][raritylist[y]][z]->name << "|" << colors[colorlist[x]][raritylist[y]][z]->type << "|" << colors[colorlist[x]][raritylist[y]][z]->illus << "|" << colors[colorlist[x]][raritylist[y]][z]->count << endl;
                                }
                            }
                        }
                    }

                // all colors and rarities. specific illus and type.
                } else {
                    for (int x = 0; x<7; x++){
                        for (int y = 0; y<4; y++){
                            vectsize = colors[colorlist[x]][raritylist[y]].size();
                            for (int z = 0; z < vectsize; z++){
                                if (colors[colorlist[x]][raritylist[y]][z]->illus == illus && colors[colorlist[x]][raritylist[y]][z]->type == type){
                                    cout << colors[colorlist[x]][raritylist[y]][z]->name << "|" << colors[colorlist[x]][raritylist[y]][z]->type << "|" << colors[colorlist[x]][raritylist[y]][z]->illus << "|" << colors[colorlist[x]][raritylist[y]][z]->count << endl;
                                }
                            }
                        }
                    }
                }
            }
        } // otherwise specific rarity
        else {
            // all colors, all types. specific rarity and maybe specific illus
            if (type == "all"){

                // all colors, types, and illus. specific rarity
                if (illus == "all"){
                    for (int x = 0; x<7; x++){
                    vectsize = colors[colorlist[x]][rarity].size();
                        if (vectsize > 0){
                            cout << colorlist[x] << " " << rarity << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            cout << colors[colorlist[x]][rarity][z]->name << "|" << colors[colorlist[x]][rarity][z]->type << "|" << colors[colorlist[x]][rarity][z]->illus << "|" << colors[colorlist[x]][rarity][z]->count << endl;
                        }
                    }
                // all colors and types. specific rarity and illus
                } else {
                    for (int x = 0; x<7; x++){
                        vectsize = colors[colorlist[x]][rarity].size();
                        if (vectsize > 0){
                            cout << colorlist[x] << " " << rarity << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[colorlist[x]][rarity][z]->illus == illus){
                            cout << colors[colorlist[x]][rarity][z]->name << "|" << colors[colorlist[x]][rarity][z]->type << "|" << colors[colorlist[x]][rarity][z]->illus << "|" << colors[colorlist[x]][rarity][z]->count << endl;
                            }
                        }
                    }
                }
            // all colors, specific rarity, type, and maybe illus
            } else {
                // all colors and illus, specific type and rarity
                if (illus == "all"){
                    for (int x = 0; x<7; x++){

                    vectsize = colors[colorlist[x]][rarity].size();
                        if (vectsize > 0){
                            cout << colorlist[x] << " " << rarity << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[colorlist[x]][rarity][z]->type == type){
                                cout << colors[colorlist[x]][rarity][z]->name << "|" << colors[colorlist[x]][rarity][z]->type << "|" << colors[colorlist[x]][rarity][z]->illus << "|" << colors[colorlist[x]][rarity][z]->count << endl;
                            }
                        }
                    }
                }
                // all colors. specific rarity, type, and illus
                else {
                    for (int x = 0; x<7; x++){

                    vectsize = colors[colorlist[x]][rarity].size();
                        if (vectsize > 0){
                            cout << colorlist[x] << " " << rarity << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[colorlist[x]][rarity][z]->illus == illus && colors[colorlist[x]][rarity][z]->type == type){
                                cout << colors[colorlist[x]][rarity][z]->name << "|" << colors[colorlist[x]][rarity][z]->type << "|" << colors[colorlist[x]][rarity][z]->illus << "|" << colors[colorlist[x]][rarity][z]->count << endl;
                            }
                        }
                    }
                }
            }
        }

    // otherwise, specific color
    } 
    else {
        // all rarities
        if (rarity == "all"){
            // all types
            if (type == "all"){
                
                // specific color. all rarities, types, and illus
                if (illus == "all"){
    
                    for (int y = 0; y<4; y++){
                        vectsize = colors[color][raritylist[y]].size();
                        if (vectsize > 0){
                            cout << color << " " << raritylist[y] << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            cout << colors[color][raritylist[y]][z]->name << "|" << colors[color][raritylist[y]][z]->type << "|" << colors[color][raritylist[y]][z]->illus << "|" << colors[color][raritylist[y]][z]->count << endl;
                        }
                    }
                }
                // specific color and illus. all rarties and types
                else {
                    for (int y = 0; y<4; y++){
                        vectsize = colors[color][raritylist[y]].size();
                        if (vectsize > 0){
                            cout << color << " " << raritylist[y] << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[color][raritylist[y]][z]->illus == illus){
                                cout << colors[color][raritylist[y]][z]->name << "|" << colors[color][raritylist[y]][z]->type << "|" << colors[color][raritylist[y]][z]->illus << "|" << colors[color][raritylist[y]][z]->count << endl;                                }
                        }
                    }
                }
            }

            // specific color, type, and maybe illus. all rarity
            else {

                // specific color, type. all illus and rarity
                if (illus == "all"){
                    for (int y = 0; y<4; y++){
                        vectsize = colors[color][raritylist[y]].size();
                        if (vectsize > 0){
                            cout << color << " " << raritylist[y] << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[color][raritylist[y]][z]->type == type){
                                cout << colors[color][raritylist[y]][z]->name << "|" << colors[color][raritylist[y]][z]->type << "|" << colors[color][raritylist[y]][z]->illus << "|" << colors[color][raritylist[y]][z]->count << endl;
                            }
                        }
                    }
                } 
                // specific color, type, and illus. all rarity
                else {
                    for (int y = 0; y<4; y++){
                        vectsize = colors[color][raritylist[y]].size();
                        if (vectsize > 0){
                            cout << color << " " << raritylist[y] << ":" << endl;
                        }
                        for (int z = 0; z < vectsize; z++){
                            if (colors[color][raritylist[y]][z]->illus == illus && colors[color][raritylist[y]][z]->type == type){
                                cout << colors[color][raritylist[y]][z]->name << "|" << colors[color][raritylist[y]][z]->type << "|" << colors[color][raritylist[y]][z]->illus << "|" << colors[color][raritylist[y]][z]->count << endl;
                            }
                        }
                    }
                }
            }
        }
        // specific color, rarity. maybe type or illus
        else {
            //specific color and rarity. all type.
            if (type == "all"){

                // specific color and rarity. all type and illus
                if (illus == "all"){
                    vectsize = colors[color][rarity].size();
                    if (vectsize > 0){
                        cout << color << " " << rarity << ":" << endl;
                    }
                    for (int z = 0; z < vectsize; z++){
                        cout << colors[color][rarity][z]->name << "|" << colors[color][rarity][z]->type << "|" << colors[color][rarity][z]->illus << "|" << colors[color][rarity][z]->count << endl;
                    }
                }
                // specific color, rarity, and illus. all type
                else {
                    vectsize = colors[color][rarity].size();
                    if (vectsize > 0){
                        cout << color << " " << rarity << ":" << endl;
                    }
                    for (int z = 0; z < vectsize; z++){
                        if (colors[color][rarity][z]->illus == illus){
                            cout << colors[color][rarity][z]->name << "|" << colors[color][rarity][z]->type << "|" << colors[color][rarity][z]->illus << "|" << colors[color][rarity][z]->count << endl;
                        }
                    }
                }
            }
            // specific color, rarity, type. maybe illus
            else {
                // specific color, rarity, type. all illus
                if (illus == "all"){
                    vectsize = colors[color][rarity].size();
                    if (vectsize > 0){
                        cout << color << " " << rarity << ":" << endl;
                    }
                    for (int z = 0; z < vectsize; z++){
                        if (colors[color][rarity][z]->type == type){
                            cout << colors[color][rarity][z]->name << "|" << colors[color][rarity][z]->type << "|" << colors[color][rarity][z]->illus << "|" << colors[color][rarity][z]->count << endl;
                        }
                    }
                } 
                // specific color, rarity, type and illus
                else {
                    vectsize = colors[color][rarity].size();
                    if (vectsize > 0){
                        cout << color << " " << rarity << ":" << endl;
                    }
                    for (int z = 0; z < vectsize; z++){
                        if (colors[color][rarity][z]->illus == illus && colors[color][rarity][z]->type == type){
                            cout << colors[color][rarity][z]->name << "|" << colors[color][rarity][z]->type << "|" << colors[color][rarity][z]->illus << "|" << colors[color][rarity][z]->count << endl;
                        }
                    }
                }
            }
        }
    }
    cout << "" << endl;
    return;
}