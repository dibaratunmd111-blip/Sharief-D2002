#include <iostream>
#include "GEntry.h"

int main() {
    GEntry game;
    game.addEntry("Farhan", 50);
    game.display();
    game.addEntry("Sharief", 49);
    game.display();
    game.addEntry("Muamar", 51);
    game.display();
    game.addEntry("Nuska", 52);
    game.display();

    game.removeEntry(0);
    game.display();

    game.removeEntry(2);
    game.display();
}