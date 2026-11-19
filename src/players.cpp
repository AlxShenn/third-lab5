#include "players.h"
#include <iostream>
#include <cstdlib>

Gesture* HumanPlayer::makeMove(Gesture* enemyMove) {
    cout << name << ", enter your move (1 - Rock, 2 - Paper, 3 - Scissors, 4 - Lizard, 5 - Spock): ";
    int choice;
    cin >> choice;
    Gesture* g = GestureFactory::createGestureByIndex(choice);
    if (!g) {
        cout << "Strange choice! Defaulting to Rock" << endl;
        g = new Rock();
    }
    return g;
}

Gesture* BotPlayer::makeMove(Gesture* enemyMove) {
    return strategy->chooseGesture(lastMove, enemyMove);
}

Player* BotFactory::createRandomBot(const string& name) {
    int r = rand() % 4;
    switch (r) {
        case 0: return new BotPlayer(name, new RandomStrategy());
        case 1: return new BotPlayer(name, new WinnerStrategy());
        case 2: return new BotPlayer(name, new CopycatStrategy());
        default: return new BotPlayer(name, new CycleStrategy());
    }
}