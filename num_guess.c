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
    } else if(choice == 'n'){ //User may want to switch between game modes
        char playing_choice;
        printf("\nWould you like to switch to a different game mode? y/n ");
        scanf(" %c", &playing_choice);
        while(playing_choice != 'y' && playing_choice != 'n'){
            printf("\nInvalid Input. Would you like to play again? y/n");
            scanf(" %c", &playing_choice);
        }

        if(playing_choice == 'y'){
            session();
        }else{
            printf("\nThank you for playing.");
        }

    }
}

void session(){ //User interface to pick, and then switch between, game modes
    int choice;
    printf("\nGame 1 is where you guess the computer\'s number.\nGame 2 is where the computer guesses yours.\nSelect mode 1 or 2: ");
    scanf("%d", &choice);

    while(choice != 1 && choice != 2){
        printf("\nInvalid Input. Select mode 1 or 2: ");
        scanf("%d", choice);
    }

    if(choice == 1){
        user_guesses();
    } else{
        comp_guesses();
    }

    
}


int main(){
    
    session();

    return 0;
}