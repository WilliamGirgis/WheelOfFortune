#include "players.h"
//
// Created by Samwil on 16/04/2020.
//




void setPlayers(char *num) {
    if(*num == '2') {
        printf("\nPlayer 1:\n");
        p1.score =0;
        gets(p1.name);
        p1.playerTurn = 0;
        p1.playerNum = 1;

        printf("\nPlayer 2:\n");
        gets(p2.name);
        p2.score =0;
        p2.playerTurn = 0;
        p2.playerNum = 2;
    } else if(*num == '3') {

        is3PlayerMode = 1;
        printf("\nPlayer 1:\n");
        p1.score =0;
        gets(p1.name);
        p1.playerTurn = 0;
        p1.playerNum = 1;

        printf("\nPlayer 2:\n");
        gets(p2.name);
        p2.score =0;
        p2.playerTurn = 0;
        p2.playerNum = 2;

        printf("Player 3:\n");
        gets(p3.name);
        p3.score =0;
        p3.playerTurn = 0;
        p3.playerNum = 3;
    }
}

void getPlayers(Player *player) {
    printf("Player : %s | %d\n",player->name,player->score);
}

void getWinner() {
    if(p1.score > p2.score && p1.score > p3.score) {
        printf("Game finished! Winner is :");
        getPlayers(&p1);
    } else if (p2.score > p1.score && p2.score > p3.score) {
        printf("Game finished! Winner is :");
        getPlayers(&p2);
    } else if (p3.score > p2.score && p3.score > p1.score) {
        printf("Game finished! Winner is :");
        getPlayers(&p3);
    } else {
        printf("Game finished! Every one has the same score !");
    }
}