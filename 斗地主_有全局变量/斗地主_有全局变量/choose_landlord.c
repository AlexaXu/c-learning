#include <stdio.h>
#include "distribute_card.h"
#include "choose_landlord.h"

int lord[NUM_LORD], famer1[NUM_FAMER], famer2[NUM_FAMER];

void choose_landlord(void){
    int landlord = 0;
    
    printf("Choose one player to become landlord: ");
    scanf(" %d", &landlord);
    
    for(int i = 0; i < 3; i++){
        lord[i + 17] = reserve[i];
    }
    
    switch(landlord){
        case 1:
            assigh_array(lord, player1, NUM_FAMER);
            assigh_array(famer1, player2, NUM_FAMER);
            assigh_array(famer2, player3, NUM_FAMER);
        case 2:
            assigh_array(lord, player2, NUM_FAMER);
            assigh_array(famer1, player1, NUM_FAMER);
            assigh_array(famer2, player3, NUM_FAMER);
        case 3:
            assigh_array(lord, player3, NUM_FAMER);
            assigh_array(famer1, player1, NUM_FAMER);
            assigh_array(famer2, player2, NUM_FAMER);
        default:
            break;
    }
}

