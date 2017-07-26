#include <stdio.h>
#include <stdlib.h>
#include "print_card.h"

void print_card(int card_order[], int num_card){
    int lord_card[20];
    int fa1_card[17];
    int fa2_card[17];
    
    /*for(int i = 0; i < 20; i++){                          //从0到53的分牌方式会使大的牌很大概率上分配到后面
        lord_card[i] = card_order[i];                       //几个空格上，如果这样分配，农民2总会获得很大的牌。
    }
    for(int i = 0; i < 17; i++){
        fa1_card[i] = card_order[i + 20];
    }
    for(int i = 0; i < 17; i++){
        fa2_card[i] = card_order[i + 37];
    }*/
    for(int i = 0; i < num_card; i++){                      //为使牌分发的更随机而不是农民2拥有更多大牌，选择
        if(i >= 0 && i <= 2){                               //逐个分牌的方式
            lord_card[i] = card_order[i];
        }else{
            if((i % 3) == 0){
                lord_card[(i / 3) + 2] = card_order[i];
            }
            if((i % 3) == 1){
                fa1_card[(i / 3) - 1] = card_order[i];
            }
            if((i % 3) == 2){
                fa2_card[(i / 3) - 1] = card_order[i];
            }
        }
    }
    
    sort_card(lord_card, 20);
    sort_card(fa1_card, 17);
    sort_card(fa2_card, 17);
    
    printf("地主的卡为：\n");
    tran_chinese(lord_card, 20);
    printf("农民1的卡为：\n");
    tran_chinese(fa1_card, 17);
    printf("农民2的卡为：\n");
    tran_chinese(fa2_card, 17);
}

void sort_card(int a[], int n){
    int t;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] < a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void tran_chinese(int a[], int n){
    int num_rank;
    int num_suit;
    char rank[13] = {'3', '4', '5', '6', '7', '8',
                    '9', 'T', 'J', 'Q', 'K', 'A', '2'};
    
    for(int i = 0; i < n; i++){
        num_suit = a[i] % 4;
        num_rank = a[i] / 4;
        
        if(num_rank == 13){
            if(num_suit == 0){
                printf("小王 ");
            }else{
                printf("大王 ");
            }
        }
        else if(num_suit == 0){
            printf("红桃%c ", rank[num_rank]);
        }
        else if(num_suit == 1){
            printf("方块%c ", rank[num_rank]);
        }
        else if(num_suit == 2){
            printf("黑桃%c ", rank[num_rank]);
        }
        else{
            printf("梅花%c ", rank[num_rank]);
        }
        
    }
    printf("\n");
}

void confirm_run(void)
{
    int n;
    
    printf("\nEnter 0 to exit or enter 1 to play again: ");
    scanf("%d", &n);
    printf("\n");
    
    if(!n){
        exit(EXIT_SUCCESS);
    }
}
