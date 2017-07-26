#include <stdio.h>    
#include "distribute_card.h"
#include "print_card.h"

int main()
{
    int card_order[54];                                   //储存分发的牌序
    int num_card = 54;                                    //卡牌的总数
    
    for(int i = 0; i < 54; i++){                          //初始化为-1以防重复
        card_order[i] = -1;
    }
    
    for(;;){
        distribute_card(card_order, num_card);            //将54张牌按顺序随机发到空位中
        print_card(card_order, num_card);                 //将牌分给地主和农民并输出
        confirm_run();                                    //确认是否再运行一次
    }
    return 0;
}
