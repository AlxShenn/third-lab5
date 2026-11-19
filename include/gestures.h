#pragma once
#include <string>
#include <iostream>

using namespace std;

class Gesture {
public:
    virtual ~Gesture() {}
    virtual string getName() const = 0;
    virtual int compare(const Gesture* other) const = 0;
};

class Rock : public Gesture {
public:
    string getName() const override;
    int compare(const Gesture* other) const override;
};

class Paper : public Gesture {
public:
    string getName() const override;
    int compare(const Gesture* other) const override;
};

class Scissors : public Gesture {
public:
    string getName() const override;
    int compare(const Gesture* other) const override;
};

class Lizard : public Gesture {
public:
    string getName() const override;
    int compare(const Gesture* other) const override;
};

class Spock : public Gesture {
public:
    string getName() const override;
    int compare(const Gesture* other) const override;
};

class GestureFactory {
public:
    static Gesture* createRandomGesture();
    static Gesture* createGestureByIndex(int idx);
};