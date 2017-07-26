#include <stdio.h>
#include "distribute_card.h"
#include "choose_landlord.h"
#include "print_card.h"


int card_order[NUM_CARD];                                       //储存随机分发的牌

int main()
{
    for(; ;){
        distribute_card();                                      //将54张牌随机填充到card_order数组中
        
        printf("Player1's cards:\n");
        print_card(player1, NUM_FAMER);
        printf("Player2's cards:\n");
        print_card(player2, NUM_FAMER);
        printf("Player3's cards:\n");
        print_card(player3, NUM_FAMER);                         //先分别将17张牌分给3个玩家
        
        choose_landlord();                                      //选择1个玩家做地主，并分给reserve中的3张牌
        printf("\n");
        printf("Cards reserved for landlord are: \n");
        print_card(reserve, NUM_RESERVE);                       //显示预留的3张牌
        
        printf("Landlord's cards:\n");
        print_card(lord, NUM_LORD);
        printf("Farmer1's card:\n");
        print_card(famer1, NUM_FAMER);
        printf("Farmer2's card:\n");
        print_card(famer2, NUM_FAMER);                          //显示地主和两个农民的牌
        
        confirm_run();                                          //确认再来一遍或停止游戏
    }
}
