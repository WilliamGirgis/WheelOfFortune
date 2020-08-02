#include <stdlib.h>
//
// Created by Samwil on 04/04/2020.
//

#ifndef WHEELOFFORTUNEG9_WORDS_H
#define WHEELOFFORTUNEG9_WORDS_H


typedef char *secretWord; //Preprocessing Variable pointer to char
secretWord secretWord1;// First secret word to be allocated
secretWord secretWord2;// Second..
secretWord secretWord3;// Third..
secretWord *curSecretWord;// Global variable that will hold the current secret word into the wordToGuess variable
secretWord *secretWords[4];// array of secretWord pointer, where each slot is pointing to one of the secret word

char wordToGuess[30];// The transformed secret word , that will be replaced and compared with the current secret word in game(curSecretWord)


secretWord  *allocating(); // Function to allocate user input into a secret word variable
void hideWord(secretWord secret);// function to set up the wordToGuess variable with the secret word
int searchLetter(char *letter,secretWord secret,Player *);
int guessPhrase(char wordToGuessT[],secretWord secret);



typedef char Vowels[];
Vowels vowels = {'a','e','i','o','u','y'};

#endif //WHEELOFFORTUNEG9_WORDS_H
