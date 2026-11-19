#pragma once
#include "gestures.h"
#include <string>

using namespace std;

class MoveStrategy {
public:
    virtual ~MoveStrategy() {}
    virtual Gesture* chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) = 0;
    virtual string getStrategyName() const = 0;
};



class RandomStrategy : public MoveStrategy {
public:
    Gesture* chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) override;
    string getStrategyName() const override { return "Random"; }
};

class WinnerStrategy : public MoveStrategy {
public:
    Gesture* chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) override;
    string getStrategyName() const override { return "Winner"; }
};

class CopycatStrategy : public MoveStrategy {
public:
    Gesture* chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) override;
    string getStrategyName() const override { return "Copycat"; }
};

class CycleStrategy : public MoveStrategy {
public:
    Gesture* chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) override;
    string getStrategyName() const override { return "Cycle"; }
};

class Player;
class BotFactory {
public:
    static Player* createRandomBot(const string& name);
};