#include "words.h"
#include "ctype.h"
//
// Created by Samwil on 04/04/2020.
int s2 = 0;
int rounds = 1;// If s2 increased, that means that the round is finished, so each time we increase s2, we increase rounds
secretWord  *allocating() {
    if ((secretWord1 == NULL)) {
        printf("First word:\n");
        secretWord1 = (char *) calloc(20, sizeof(char));
// note: fgets add new line at the end of the string, that's why we are not using it
        gets(secretWord1);
        printf("First Word allocated!\n");
        secretWords[0] = &secretWord1;
        return &secretWord1;
    }
    if ((secretWord2 == NULL)) {
        printf("\nSecond word:\n");
        secretWord2 = (char *) calloc(20, sizeof(char));
        gets(secretWord2);
        printf("Second Word allocated!\n");
        secretWords[1] = &secretWord2;
        return &secretWord2;
    } if((secretWord3 == NULL))  {
        printf("\nThird word:\n");
        secretWord3 = (char *) calloc(20, sizeof(char));
        gets(secretWord3);
        printf("Third Word allocated!\n\n");
        secretWords[2] = &secretWord3;
        return &secretWord3;
    }
    return NULL;
}
void hideWord(secretWord secret){
    strcpy(wordToGuess,secret);
    for(int i = 0; wordToGuess[i] != '\0';i++) {
        wordToGuess[i] ='-';
        if(secret[i] == ' ') {
            wordToGuess[i] = ' ';
        }
    };
}
int searchLetter(char *letter,secretWord secret,Player *player){
    printf("\nSearch for a letter : %s ",wordToGuess);
    letter = malloc(20);
    gets(letter);
    int letterCount = 0;
    int isVowel = 0;

    if(strchr(wordToGuess, *letter) != NULL) { // Check if the letter has already been found
        printf("Letter already found");
        return 0;
    }

    for (int i = 0;i < strlen(vowels);i++) { // We check if the letter is a vowel..
        if(*letter == vowels[i]) {
            isVowel = 1;
            if(player->score < 200) {
                printf("You cannot buy a vowel you dont have enough points!");
                return 0;
            }
            printf("You bought a vowel");
        }
    }

    if(isVowel) {// We return 0 to stop the loop in the main function since the player buys a vowel
        for(int i = 0;i < strlen(wordToGuess);i++) {// We do normal check as normal letter, but instead we return 0
            if(secret[i] == *letter || _tolower(secret[i]) == *letter) {
                wordToGuess[i] = secret[i];
                letterCount++;
            }

        }

        if(!strcmp(wordToGuess,secret)) {
            printf("\nYou won! The word was: %s",wordToGuess);
            player->score-=200;

            ++s2;// we increment the global index for secretWords[]
            rounds++;
            if(secretWords[s2] == NULL) {// We check here if after incrementing, if there is not out-of-bounds exception
                return 0;
            }
            curSecretWord = malloc(sizeof(secretWords[s2])/sizeof(char));
            curSecretWord = secretWords[s2];// Since the word has been found, curSecretWord will now hold the next word allocated
            hideWord(*curSecretWord);
            printf("\nNext word to guess now! %s \new score : %d",wordToGuess,player->score);
            return 0;
        }
        player->score-=200;
        printf("\nYou found %d letters! Word state: %s \nYour new score : %d",letterCount,wordToGuess,player->score);
        return 0; // return 1 to keep playing after having bought a vowel
    }


// We do normal check as normal..
    for(int i = 0;i < strlen(wordToGuess);i++) {
        if(secret[i] == *letter || _tolower(secret[i]) == *letter) {
            wordToGuess[i] = secret[i];
            letterCount++;
        }
    }
    if(!strcmp(wordToGuess,secret)) {
        printf("\nYou won! The word was: %s",wordToGuess);

        // Since the word has been found, curSecretWord will now hold the next word allocated
        ++s2;
        rounds++;
        if(secretWords[s2] == NULL) {// We check here if after incrementing, if there is not out-of-bounds exception
            return 0;
        }
        curSecretWord = malloc(sizeof(secretWords[s2])/sizeof(char));
        curSecretWord = secretWords[s2];
        hideWord(*curSecretWord);
        printf("\nNext word to guess now! %s",wordToGuess);
        return 0;
    }
    if(letterCount == 0) {
        printf("\nNo letters found\n");
        return 0;
    } else {
        printf("\nYou found %d letters : %s\n",letterCount,wordToGuess);
        return 1;
    }
}
int guessPhrase(char userinput[],secretWord secret){
    if(!strcmp(userinput,secret)) { // we check a first time
        printf("You found the secret word !\n");
        //We switch to the next word..
        free(curSecretWord);
        ++s2;
        rounds++;
        if(secretWords[s2] == NULL) { // We check here if after incrementing, if there is not out-of-bounds exception
            return 0;
        }
        curSecretWord = malloc(sizeof(secretWords[s2])/sizeof(char));
        curSecretWord = secretWords[s2];
        hideWord(*curSecretWord);
        return 1;
    } else { // Otherwise it is maybe because of the sensitive cases
        for ( int i = 0; userinput[i] != '\0';i++) {
            if((_toupper(userinput[i]) == secret[i])) {// Check if the current index is a match between lower and upper
               userinput[i] = _toupper(userinput[i]);
            } else if((_tolower(userinput[i]) == secret[i])) {// Check if the current index is a match between upper and lower
                userinput[i] = _tolower(userinput[i]);
            }
        }
        if(!strcmp(userinput,secret)) { // We try one last time with case non-sensitive.
            printf("You found the secret word !\nNew score :");
            getPlayers(curPlayer);
            //We switch to the next word..
            free(curSecretWord);
            ++s2;
            rounds++;
            if(secretWords[s2] == NULL) {// We check here if after incrementing, if there is not out-of-bounds exception
                return 0;
            }
            curSecretWord = malloc(sizeof(secretWords[s2])/sizeof(char));
            curSecretWord = secretWords[s2];
            hideWord(*curSecretWord);

            return 1;
        } else { // And finally if the input is not correct even with the non-sensitive case, the turn would be lost
            printf("You did not find it!");
            return 0;
        }
    }
}

