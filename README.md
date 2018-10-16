************

MTG Card Database

************

Run through command line:
./cardcollection
Running without any arguments is equivalent to running:
filter all all all all 

Commands are:

        "add"
        args: Color, Rarity, Name, Illustrator, Amount Owned
        Use add to insert a new card into collection or update the Amount owned of an existing card.
        Example: ./cardcolletion add Green Common LanowarElves Creature AdamGrabowski 4

        "remove" 
        args: Color, Rarity, Name
        Use to remove a card from the collection.
        Example: ./cardcollection remove Green Common LanowarElves

        "filter"
        args: Color, Rarity, Card Type, Illustrator
        Use to print a list of all cards in collection that match criteria." << endl;
        Use 'all' as arg to see all colors, rarities, card types, or illustrators." << endl;
        Example: 'filter all all all all' would print out every card in the collection.

        "help"
        Gives list of commands   