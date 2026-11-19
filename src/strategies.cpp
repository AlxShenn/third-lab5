#include "strategies.h"
#include "players.h"

Gesture* RandomStrategy::chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) {
    return GestureFactory::createRandomGesture();
}

Gesture* WinnerStrategy::chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) {
    if (!myLastMove) return GestureFactory::createRandomGesture();
    int res = myLastMove->compare(enemyLastMove);
    if (res == 1) {
        return GestureFactory::createGestureByIndex(
            (myLastMove->getName() == "Rock") ? 1 :
            (myLastMove->getName() == "Paper") ? 2 :
            (myLastMove->getName() == "Scissors") ? 3 :
            (myLastMove->getName() == "Lizard") ? 4 : 5
        );
    }
    return GestureFactory::createRandomGesture();
}

Gesture* CopycatStrategy::chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) {
    if (!enemyLastMove) return GestureFactory::createRandomGesture();
    return GestureFactory::createGestureByIndex(
        (enemyLastMove->getName() == "Rock") ? 1 :
        (enemyLastMove->getName() == "Paper") ? 2 :
        (enemyLastMove->getName() == "Scissors") ? 3 :
        (enemyLastMove->getName() == "Lizard") ? 4 : 5
    );
}

Gesture* CycleStrategy::chooseGesture(Gesture* myLastMove, Gesture* enemyLastMove) {
    if (!myLastMove) return GestureFactory::createRandomGesture();
    int res = myLastMove->compare(enemyLastMove);
    
    if (res == 1) { 
        return GestureFactory::createGestureByIndex(
            (myLastMove->getName() == "Rock") ? 1 :
            (myLastMove->getName() == "Paper") ? 2 :
            (myLastMove->getName() == "Scissors") ? 3 :
            (myLastMove->getName() == "Lizard") ? 4 : 5
        );
    } else if (res == -1) { 
        int next = 1;
        if (myLastMove->getName() == "Rock") next = 2;
        else if (myLastMove->getName() == "Paper") next = 3;
        else if (myLastMove->getName() == "Scissors") next = 4;
        else if (myLastMove->getName() == "Lizard") next = 5;
        else next = 1;
        return GestureFactory::createGestureByIndex(next);
    }
    return GestureFactory::createRandomGesture();
}