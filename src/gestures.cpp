#include "gestures.h"
#include <cstdlib>

string Rock::getName() const { return "Rock"; }
int Rock::compare(const Gesture* other) const {
    string o = other->getName();
    if (o == "Rock") return 0;
    if (o == "Scissors" || o == "Lizard") return 1;
    return -1;
}

string Paper::getName() const { return "Paper"; }
int Paper::compare(const Gesture* other) const {
    string o = other->getName();
    if (o == "Paper") return 0;
    if (o == "Rock" || o == "Spock") return 1;
    return -1;
}

string Scissors::getName() const { return "Scissors"; }
int Scissors::compare(const Gesture* other) const {
    string o = other->getName();
    if (o == "Scissors") return 0;
    if (o == "Paper" || o == "Lizard") return 1;
    return -1;
}

string Lizard::getName() const { return "Lizard"; }
int Lizard::compare(const Gesture* other) const {
    string o = other->getName();
    if (o == "Lizard") return 0;
    if (o == "Paper" || o == "Spock") return 1;
    return -1;
}

string Spock::getName() const { return "Spock"; }
int Spock::compare(const Gesture* other) const {
    string o = other->getName();
    if (o == "Spock") return 0;
    if (o == "Scissors" || o == "Rock") return 1;
    return -1;
}

Gesture* GestureFactory::createRandomGesture() {
    int r = rand() % 5;
    switch (r) {
        case 0: return new Rock();
        case 1: return new Paper();
        case 2: return new Scissors();
        case 3: return new Lizard();
        default: return new Spock();
    }
}

Gesture* GestureFactory::createGestureByIndex(int idx) {
    switch (idx) {
        case 1: return new Rock();
        case 2: return new Paper();
        case 3: return new Scissors();
        case 4: return new Lizard();
        case 5: return new Spock();
        default: return nullptr;
    }
}