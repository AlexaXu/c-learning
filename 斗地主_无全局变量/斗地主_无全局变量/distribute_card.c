#include <stdlib.h>
#include <time.h>
#include "distribute_card.h"

void distribute_card(int card_order[], int num_card){
    int cur_card;                                       //当前正在发的卡牌
    int min_block = 0;                                  //未填充的空格最小值
    int gap_block, random_num;                          //从最小空格随机向后面的空格分牌
    
    srand((unsigned) time(NULL));
    
    for(cur_card = 0; cur_card < num_card; ){
        random_num = rand() % (54 - cur_card);
        gap_block = min_block;
        
        if(random_num == 0){                            //若随机数为0，则发牌到min_block
            min_block++;
        }else{
            while(random_num){
                if(card_order[gap_block] == -1){
                    random_num--;
                }
                gap_block++;
            }
        }
        
        if(card_order[gap_block] == -1){                //防止重复发牌到统一格
            card_order[gap_block] = cur_card;
            cur_card++;
        }else {
            continue;
        }
    }
}
