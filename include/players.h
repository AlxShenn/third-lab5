#pragma once
#include <string>
#include "gestures.h"
#include "strategies.h"

using namespace std;

class Player {
protected:
    string name;
    int score;
    Gesture* lastMove;
public:
    Player(const string& n) : name(n), score(0), lastMove(nullptr) {}
    virtual ~Player() { delete lastMove; }
    virtual Gesture* makeMove(Gesture* enemyMove) = 0;
    virtual string getInfo() const = 0;
    
    string getName() const { return name; }
    void addScore() { score++; }
    int getScore() const { return score; }
    void setLastMove(Gesture* g) { delete lastMove; lastMove = g; }
    Gesture* getLastMove() const { return lastMove; }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const string& n) : Player(n) {}
    Gesture* makeMove(Gesture* enemyMove) override;
    string getInfo() const override { return "Human Player"; }
};

class BotPlayer : public Player {
private:
    MoveStrategy* strategy;
public:
    BotPlayer(const string& n, MoveStrategy* s) : Player(n), strategy(s) {}
    ~BotPlayer() override { delete strategy; }
    Gesture* makeMove(Gesture* enemyMove) override;
    string getInfo() const override { return strategy->getStrategyName(); }
};