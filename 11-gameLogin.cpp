//
// Created by kaung007 on 11/18/22.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int db[100];
int main() {
    srand(time(NULL));
    int userNum;

    int life = 3;
    int key = 10;
    int age = 0;
    int option = 0;
    int userId = 0;
    int userId2 = 0;
    int flag = 0;
    int global_flag=0;
    int dbIndex = 0;

    int ran = (rand()%20)+1;

    while (key <= 10) {
        printf("Welcome to our game!! \n");
        printf("Enter your age : ");
        scanf("%d",&age);

        if(age > 17){
            printf("You can play the game.\n");

            while(true){
                printf("-------------------------------------------->>\n");
                printf("Press 1 to login!\nPress 2 to Register!\nPress 3 to Complete Quit!\nPress 4 to Back : ");
                scanf("%d",&option);

                while(true){

                    if(option == 1){
                        printf("This is Login.\n");
                        printf("Enter your id : ");
                        scanf("%d",&userId);
                        for(int i = 0; i < 100 ; i++){

                            if(db[i] == userId){
                                flag=1;
                            }

                        }

                        if(flag == 1){
                            printf("****************************\n");
                            printf("You can play the Guess My Number Game... \n");
                            printf("Start the game...\n");

                            printf("I have a number between (1 to 20), And then you have 3 chance, Can you guess it!\n");

                            while (1){
                                printf("Enter guess number : ");
                                scanf("%d",&userNum);

                                if(ran == userNum){
                                    printf("****************************\n");
                                    printf("You win the game.\n");
                                    printf("Guess winner number : %d\n",ran);
                                    printf("****************************\n");
                                    exit(1);
                                }else if(ran > userNum){
                                    life--;
                                    printf("Your life - %d\n",life);
                                    printf("Lower Number , try again...\n");
                                    if(life == 0){
                                        printf("****************************\n");
                                        printf("You Lose The Game!!!!!!.\n");
                                        printf("Login and play the game again.\n");
                                        life = 3;
                                        break;
                                    }
                                }else if(ran < userNum){
                                    life--;
                                    printf("Your life - %d\n",life);
                                    printf("Higher Number , try again...\n");
                                    if(life == 0){
                                        printf("****************************\n");
                                        printf("You Lose The Game!!!!!!.\n");
                                        printf("Login and play the game again.\n");
                                        life = 3;
                                        break;
                                    }
                                }
                            }

                        }else{
                            printf("Your id is not valid!! \n");
                            break;
                        }

                    }else if(option == 2){
                        if(global_flag == 1){
                            global_flag--;
                            break;
                        }
                        printf("This is Register.\n");

                        printf("Pls Enter Your ID : ");
                        scanf("%d",&userId);

                        for(int i = 0; i < 100; i++){
                            if(db[i] == userId){
                                flag++;
                            }
                        }

                        while (1){
                            if(flag >= 1){
                                printf("<User Id Is Already Taken!!!>\n");
                                flag--;
                                break;
                            }else{
                                printf("Confirm Your ID : ");
                                scanf("%d",&userId2);

                                if (userId == userId2){
                                    db[dbIndex] = userId;
                                    dbIndex;
                                    printf("Registration Success!!!\n");
                                    global_flag=1;
                                    break;
                                    // Registration success code.
                                }else{
                                    printf("ID Not Same!\n");
                                    break;
                                }
                            }
                        }

                    }else if(option == 3){
                        exit(1);
                    }else if(option == 4){
                        break;
                    }else{
                        printf("Invalid Option!!!\n");
                        break;
                    }

                }

            }

        }else{
            printf("You can't play game!!!\nTry Again...\n");
        }

    }

    return 0;
}