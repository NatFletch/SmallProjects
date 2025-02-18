#include <stdio.h>
#include <limits.h>
#include <string.h>
// Function Prototypes
void init_prompt();
void prompt_music_question(int* questions_asked, int* pillar_counter);
void prompt_leader_question(int* questions_asked, int* pillar_counter);
void prompt_brother_question(int* questions_asked, int* pillar_counter);
void prompt_service_question(int* questions_asked, int* pillar_counter);
void guess_prompt(int music, int leader, int brother, int service);

int main(){
    // Declare variables
    int music = 0;
    int leader = 0;
    int brother = 0;
    int service = 0;
    int questions_asked = 0;
    int pillar_counter = 0; // Tracks what pillar questions should be asked.
    int input = 0;

    init_prompt();

    while(pillar_counter <= 3){
        printf("On a scale of 1-10...\n");
        switch(pillar_counter){
            case 0:
                prompt_music_question(&questions_asked, &pillar_counter);
                scanf("%d", &input);
                music += input;
                break;
            case 1:
                prompt_leader_question(&questions_asked, &pillar_counter);
                scanf("%d", &input);
                leader += input;
                break;
            case 2:
                prompt_brother_question(&questions_asked, &pillar_counter);
                scanf("%d", &input);
                brother += input;
                break;
            case 3:
                prompt_service_question(&questions_asked, &pillar_counter);
                scanf("%d", &input);
                service += input;
                break;
        }

        questions_asked++;
        if(questions_asked > 4) questions_asked = 0;
        input = 0;
    }

    guess_prompt(music, leader, brother, service);

    return 0;
}


// Function Declarations
void init_prompt(){
    printf("Welcome to the Kappa Kappa Psi pillar guesser!\n");
    printf("You will be asked a series of questions and you will respond with an answer between on a scale of 0-10.\n");
    printf("Please only enter numbers, do not enter any letters or the program will break!\n");
}

void guess_prompt(int music, int leader, int brother, int service){
    char str_guess_array[4][20] = {
        {"Musicianship"},
        {"Leadership"},
        {"Brotherhood"},
        {"Service"}
    };
    int int_guess_array[4] = {music, leader, brother, service};
    int temp = INT_MIN;

    char guess[20];
    for(int i=0; i<4; i++){
        if(int_guess_array[i] > temp){
            temp = int_guess_array[i];
            strcpy(guess, str_guess_array[i]);
        }
    }

    printf("Your favorite pillar is: %s\n", guess);
}

void prompt_music_question(int* questions_asked, int* pillar_counter){
    switch(*questions_asked){
        case 0:
            printf("How much do you like practicing music?\n");
            break;
        case 1:
            printf("How important is music in your daily life?\n");
            break;
        case 2:
            printf("How often do you find yourself ACTIVELY listening to music?\n");
            break;
        case 3:
            printf("How open are you to exploring new music genres/artists?\n");
            break;
        case 4:
            printf("How much do you enjoy going to band performances and watching other live ensembles?\n");
            *(pillar_counter) = *(pillar_counter) + 1; // Move on to the next pillar
            break;
    }
}

void prompt_leader_question(int* questions_asked, int* pillar_counter){
    switch(*questions_asked){
        case 0:
            printf("I feel energized when I am responsible for guiding a team toward a common goal.\n");
            break;
        case 1:
            printf("I like the challenge of resolving conflicts within a team.\n");
            break;
        case 2:
            printf("I am comfortable being accountable for the success or failure of a group effort.\n");
            break;
        case 3:
            printf("I enjoy motivating others to stay focused and work toward shared objectives.\n");
            break;
        case 4:
            printf("I am confident in my ability to make decisions that benefit the team as a whole.\n");
            *(pillar_counter) = *(pillar_counter) + 1; // Move on to the next pillar
            break;
    }
}

void prompt_brother_question(int* questions_asked, int* pillar_counter){
    switch(*questions_asked){
        case 0:
            printf("I feel a deep sense of connection when I am part of a close-knit group.\n");
            break;
        case 1:
            printf("I am willing to make sacrifices to strengthen the bonds within my friend group or brotherhood.\n");
            break;
        case 2:
            printf("I value open communication and honesty in my friendships, even during difficult times.\n");
            break;
        case 3:
            printf("I enjoy being a source of encouragement and support for those I consider family.\n");
            break;
        case 4:
            printf("I enjoy spending time with friends and creating lasting memories together.\n");
            *(pillar_counter) = *(pillar_counter) + 1; // Move on to the next pillar
            break;
    }
}

void prompt_service_question(int* questions_asked, int* pillar_counter){
    switch(*questions_asked){
        case 0:
            printf("I enjoy volunteering my time or skills to benefit others.\n");
            break;
        case 1:
            printf("I am motivated to take action when I see an opportunity to improve my community.\n");
            break;
        case 2:
            printf("I feel satisfaction knowing my efforts have made someone else's day easier or better.\n");
            break;
        case 3:
            printf("I am willing to put others’ needs before my own to support their well-being.\n");
            break;
        case 4:
            printf("I feel a strong sense of purpose when I am helping people in need.\n");
            *(pillar_counter) = *(pillar_counter) + 1; // Move on to the next pillar
            break;
    }
}
