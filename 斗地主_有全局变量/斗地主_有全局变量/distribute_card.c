#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "distribute_card.h"

int player1[NUM_FAMER], player2[NUM_FAMER];
int player3[NUM_FAMER], reserve[NUM_RESERVE];

void distribute_card(void){
    int cur_block = 0;
    int cur_card;
    bool bad_card[NUM_CARD];                         //判断无重复牌
    
    srand((unsigned) time(NULL));
    
    for(int i = 0; i < NUM_CARD; i++){
        bad_card[i] = false;                         //将bad_card数组元素初始化为false
    }
    
    while (cur_block < NUM_CARD) {
        cur_card = rand() % NUM_CARD;
        
        if(!bad_card[cur_card]){                    //若未出现过该牌，执行语句
            card_order[cur_block] = cur_card;
            cur_block++;
            bad_card[cur_card] = true;              //该牌出现后将相应的bad_card赋值为true
        }
    }
    
    for(int i = 0; i < 17; i++){
        player1[i] = card_order[i];
    }
    for(int i = 0; i < 17; i++){
        player2[i] = card_order[i + 17];
    }
    for(int i = 0; i < 17; i++){
        player3[i] = card_order[i + 34];
    }
    for(int i = 0; i < 3; i++){
        reserve[i] = card_order[i + 51];
    }                                              //将51张牌分给3个玩家
}

void assigh_array(int a[], int b[], int n)
{
    for(int i = 0; i < n; i++){
        a[i] = b[i];
    }
}
