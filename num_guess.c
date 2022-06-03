#include <stdio.h>
#include <stdlib.h>

int numbergen(){
    int number;
    int lower = 0, upper = 100;
    
    srand(time(0));

    number = (rand() % (upper-lower + 1)) + lower;
    
    return number;
}


void user_guesses(){
    
    int guess;
    int lower = 0, upper = 100;
    int guesses = 0, limit = 7;
    int number = numbergen();

    printf("\nGuess the integer between 0 and 100: ");
    scanf("%d", &guess);
    guesses ++;
    
    while(guess != number && guesses < limit){

        if(guess < number){
            printf("\nToo low. Try again: ");
            scanf("%d", &guess);
            guesses++;
        } else{
            printf("\nToo high. Try again: ");
            scanf("%d", &guess);
            guesses++;
        }
    }

    if(guess == number){
        printf("\nCorrect: the number was %d", number);
    } else{
        printf("\nYou failed to guess the number within %d guesses. You lose.", limit);
    }
    play_again(user_guesses);
}

void comp_guesses(){

    char done[10];
    int ready = 0;
    
    while(ready == 0){

        printf("\nThink of a number between 0 and 100, typing \'done\' when you\'re done: ");
        scanf("%s", &done);
        while(strcmp(done, "done") != 0){
            printf("\nType \'done\' when you\'re done, nothing else: ");        
            scanf("%s", &done);

        }
    
    ready = 1;

    } //At this point, comnputer is ready to begin guessing

    int lower = 0, upper = 100, guesses = 0;
    
    srand(time(0));
    int guess = (rand() % (upper-lower + 1));

    char ask;
    printf("\nIs %d higher (h), lower (l) or equal (e) to your number? ", guess);
    scanf(" %c", &ask);
    while(ask != 'h' && ask != 'l' && ask != 'e'){
        printf("\nInvalid Input. Try again: ");
        scanf(" %c", &ask);
    }

    while(ask != 'e' && guesses < 10){

        while(ask != 'h' && ask != 'l' && ask != 'e'){
            printf("\nInvalid Input. Try again: ");
            scanf(" %c", &ask);
        
        }

        if(ask == 'h'){
            guesses ++;
            upper = guess - 1;
            guess = (rand() % (upper-lower + 1) + lower);
            printf("\nWhat about %d? ", guess);
            scanf(" %c", &ask);

        }
        
        else if(ask == 'l'){
            guesses ++;
            lower = guess + 1;
            guess = (rand() % (upper-lower + 1) + lower);
            printf("\nWhat about %d? ", guess);
            scanf(" %c", &ask);            
        }


    } //At this point, either number guessed, or guess limit reached

    if(ask == 'e'){
        printf("\nI have guessed your number within %d guesses: %d", guesses, guess);
    } else if(guesses == 10){
        printf("\nI give up. You win.");
    }

    play_again(comp_guesses);



}

void play_again(void mode()){
    char choice;
    printf("\nWould you like to play again? y/n ");
    scanf(" %c", &choice);

    if(choice == 'y'){
        mode();
    } else{
        printf("\nThank you for playing.\n");
    }
}


int main(){

    //user_guesses();
    comp_guesses();

    return 0;
}