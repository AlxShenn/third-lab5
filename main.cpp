#include <iostream>
#include <ctime>
#include "players.h"

using namespace std;

int main() {
    srand(time(0));
    cout << "Rock, Paper, Scissors, Lizard, Spock" << endl;

    Player* players[3];
    players[0] = new HumanPlayer("Human");
    players[1] = BotFactory::createRandomBot("Bot1");
    players[2] = BotFactory::createRandomBot("Bot2");

    bool gameOn = true;
    Gesture* lastHumanMove = nullptr;

    while (gameOn) {
        cout << "\n    New Round" << endl;
        Gesture* moves[3];

        moves[0] = players[0]->makeMove(lastHumanMove);

        moves[1] = players[1]->makeMove(lastHumanMove);
        moves[2] = players[2]->makeMove(lastHumanMove);

        cout << "\n    Results:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << players[i]->getName() << " chose " << moves[i]->getName() << endl;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                int res = moves[i]->compare(moves[j]);
                if (res == 1) players[i]->addScore();
                else if (res == -1) players[j]->addScore();
            }
        }

        delete lastHumanMove;
        // копия хода человека
        int humanChoiceIdx = 1;
        string hName = moves[0]->getName();
        if (hName == "Paper") humanChoiceIdx = 2;
        else if (hName == "Scissors") humanChoiceIdx = 3;
        else if (hName == "Lizard") humanChoiceIdx = 4;
        else if (hName == "Spock") humanChoiceIdx = 5;
        lastHumanMove = GestureFactory::createGestureByIndex(humanChoiceIdx);

        // передача прошлых ходов
        for (int i = 1; i < 3; ++i) {
            players[i]->setLastMove(moves[i]);
            moves[i] = nullptr; 
        }

        delete moves[0]; 



        cout << "\nScores: " << players[0]->getName() << ": " << players[0]->getScore()
             << " | " << players[1]->getName() << ": " << players[1]->getScore()
             << " | " << players[2]->getName() << ": " << players[2]->getScore() << endl;

        cout << "\nContinue? (1-Yes, 0-No): ";
        int cont;
        cin >> cont;
        if (cont == 0) gameOn = false;
    }


    cout << "============" << endl;
    cout << endl << "GAME IS OVER" << endl << endl;

    int maxScore = -1;
    int winnerIdx = -1;
    for (int i = 0; i < 3; ++i) {
        if (players[i]->getScore() > maxScore) {
            maxScore = players[i]->getScore();
            winnerIdx = i;
        }
    }

    cout << "Final Scores:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "- " << players[i]->getName() << ": " << players[i]->getScore() << " points" << endl;
    }

    cout << endl << endl;
    if (winnerIdx != -1) {
        cout << "WINNER: " << players[winnerIdx]->getName() << "!" << endl;
    }

    cout << "\nRevealing bot strategies:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "- " << players[i]->getName() << " was playing as: " << players[i]->getInfo() << endl;
    }
    cout << endl << endl;



    for (int i = 0; i < 3; ++i) delete players[i];
    delete lastHumanMove;
    return 0;
}