#include <stdio.h>
#include <string.h>
#include "players.h"
#include "words.h"
#include "words.c"
#include "wheels.c"
#include "players.c"
#include <unistd.h>
// Input-related global variable
char *letter; // letter input to guess a letter
char word[20]; // user input to guess a word
char choice; // Player's choice before each round
char *numPlayers; // How many players

int playable = 1; // Check if the player can still play the wheel

int onBet = 0;// The variable that will hold the value (int) hit

int main()
{
    //                                                    Set up start
    printf("Enter the 3 secrets words to be guessed to start:\n");
    curSecretWord = malloc(sizeof(secretWord1)/sizeof(char));
    curSecretWord = allocating(); // First word allocated will be the one in game
    allocating();// Store the second word
    allocating();// Store the third word

    hideWord(*curSecretWord);// Copying the word in parameter into a global variable define into words.h (hideWord), and then replace letters by a '-'
    printf("Enter the number of players :");
    numPlayers = malloc(20);
    gets(numPlayers);
    setPlayers(numPlayers);
    //                                                    Set up end
    printf("\nLet us start! ");

while(s2 <3 ) { // While the index is less or equal to 3 (last secret word) we keep playing
//                                       Player 1 block (START)
        playable = 1;
        curPlayer = &p1;
        printf("\nRound : %d\nCurrent word state : %s\n",rounds,wordToGuess);
        do {
            printf("Player 1 (%s | %d) Playing wheel..",curPlayer->name,curPlayer->score);
            sleep(2);// Needed since the random number generator in the playWheel function depend on the current time
            if (atoi(playWheel()) && playable) {
                onBet = atoi(playWheel());

            printf("\nYou have hit : %d, now choose what to do : l = searchLetter(or buy vowel), g = guessPhrase", onBet);
            gets(&choice);
            switch(choice) {
                case 'l': printf("\nYou choose guess a letter:\n");
                    letter = malloc(1);
                    if(searchLetter(letter,*curSecretWord,curPlayer)){
                    curPlayer->score += onBet;
                        printf("\nYou found a letter! New score: ");
                        getPlayers(curPlayer);
                        printf("\nPlay the wheel again.. %s!\n",curPlayer->name);
                    } else {
                        playable--;
                        printf("\nYou finished your turn %s !",curPlayer->name);
                        curPlayer->playerTurn++;
                    }
                    free(letter);
                    break;
                case 'g':
                printf("You choose Search for a word:\n");
                    gets(word);
                    if (guessPhrase(word,*curSecretWord)) {
                        curPlayer->score +=2000;
                        printf("New score :");
                        getPlayers(curPlayer);
                        printf("\nNext word to guess now! %s",wordToGuess);
                        curPlayer->playerTurn++;
                        playable = 0;
                    } else {
                        playable--;
                    }
                    break;
                }
            }  else if(playWheel() == "Bankrupt") {
                printf("\nBankrupt!");
                curPlayer->score = 0;
                playable =0;
            } else if(playWheel() == "Lose a Turn") {
                printf("\nYou hit Lose a turn!");
                playable =0;
            } else if(playWheel() == "Extra Turn") {
                printf("\nExtra turn!");
                playable++;
            }
        } while(playable > 0);
//                                       Player 1 block (END)

//                                       Player 2 block (START)
if(s2 <3) {
    playable = 1;
    curPlayer = &p2;
    printf("\nRound : %d\nCurrent word state : %s\n", rounds, wordToGuess);
    do {
        printf("\nPlayer 2 (%s | %d) Playing wheel..", curPlayer->name, curPlayer->score);
        sleep(2);
        if (atoi(playWheel()) && playable) {
            onBet = atoi(playWheel());
            printf("\nYou have hit : %d, now choose what to do : l = searchLetter(or buy vowel), g = guessPhrase",
                   onBet);
            gets(&choice);
            switch (choice) {
                case 'l':
                    printf("\nYou choose guess a letter (or enter a vowel to buy):\n");
                    letter = malloc(1);
                    if (searchLetter(letter, *curSecretWord, curPlayer)) {
                        curPlayer->score += onBet;
                        printf("\nYou found a letter! New score: ");
                        getPlayers(curPlayer);
                        printf("\nPlay the wheel again.. %s!\n", curPlayer->name);
                    } else {
                        playable--;
                        printf("\nYou finished your turn %s !", curPlayer->name);
                    }
                    free(letter);
                    break;
                case 'g':
                    printf("\nYou choose Search for a word: \n");
                    gets(word);
                    if (guessPhrase(word, *curSecretWord)) {
                        curPlayer->score += 2000;
                        printf("New score :");
                        getPlayers(curPlayer);
                        printf("\nNext word to guess now! %s", wordToGuess);
                        playable = 0;
                    } else {
                        playable--;
                    }
                    break;
            }
        } else if (playWheel() == "Bankrupt") {
            printf("\nBankrupt!");
            curPlayer->score = 0;
            playable = 0;
        } else if (playWheel() == "Lose a Turn") {
            printf("\nYou hit Lose a turn!");
            playable = 0;
        } else if (playWheel() == "Extra Turn") {
            printf("\nExtra turn!");
            playable++;
        }
    } while (playable > 0);
}

//                                       Player 2 block (END)

//                                       Player 3 block (START)
    if((is3PlayerMode) && s2 <3) {// The p3.PlayerNum here is just for testing if p3 exists
        playable = 1;
        curPlayer = &p3;
        printf("\nRound : %d\nCurrent word state : %s\n",rounds,wordToGuess);
        do{
            printf("\nPlayer 3 (%s | %d) Playing wheel..",curPlayer->name,curPlayer->score);
            sleep(2);
            if(atoi(playWheel()) && playable) {
                onBet = atoi(playWheel());
                printf("\nYou have hit : %d, now choose what to do : l = searchLetter(or buy vowel), g = guessPhrase",
                       onBet);
                gets(&choice);
                switch (choice) {
                    case 'l':
                        printf("\nYou choose guess a letter:\n");
                        letter = malloc(1);
                        if (searchLetter(letter, *curSecretWord, curPlayer)) {
                            curPlayer->score += onBet;
                            printf("\nYou found a letter! New score: ");
                            getPlayers(curPlayer);
                            printf("\nPlay the wheel again.. %s!\n", curPlayer->name);
                        } else {
                            playable--;
                            printf("\nYou finished your turn %s !", curPlayer->name);
                        }
                        free(letter);
                        break;
                    case 'g':
                        printf("\nYou choose Search for a word:\n");
                        gets(word);
                        if (guessPhrase(word, *curSecretWord)) {
                            curPlayer->score += 2000;
                            printf("New score :");
                            getPlayers(curPlayer);
                            printf("\nNext word to guess now! %s", wordToGuess);
                            playable =0;
                        } else {
                            playable--; // We decrease it, in case of he previously hit an Extra Turn, he would keep playing 1 more time
                        }
                        break;
                }
            }else if(playWheel() == "Bankrupt") {
                printf("\nBankrupt!");
                curPlayer->score = 0;
                playable =0;
            } else if(playWheel() == "Lose a Turn") {
                printf("\nYou hit Lose a turn!");
                playable =0;
            } else if(playWheel() == "Extra Turn") {
                printf("\nExtra turn!");
                playable++;// We just increase the variable that allows to keep playing
            }
        }while(playable > 0);
    }
//                                       Player 3 block (END)
}
getWinner();
    return 0;
}
