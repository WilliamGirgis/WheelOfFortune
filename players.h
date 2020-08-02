
//
// Created by Samwil on 04/04/2020.
//

#ifndef WHEELOFFORTUNEG9_PLAYERS_H
#define WHEELOFFORTUNEG9_PLAYERS_H
typedef struct Player {
    char name[20];
    long score;
    int playerTurn;
    int playerNum; // We wanted to use a reference from players to know which player would play
}Player;

Player p1;
Player p2;
Player p3;
Player *curPlayer;
int is3PlayerMode = 0; // Check whether the game is in 3 player mode or not, by default it is not

void setPlayers(char*);
void getPlayers(Player *player);
void getWinner();


#endif //WHEELOFFORTUNEG9_PLAYERS_H
