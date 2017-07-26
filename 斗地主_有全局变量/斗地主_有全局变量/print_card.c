#include <stdio.h>
#include <stdlib.h>
#include "print_card.h"

void print_card(int a[], int n){
    int num_rank;
    int num_suit;
    char rank[13] = {'3', '4', '5', '6', '7', '8',
        '9', 'T', 'J', 'Q', 'K', 'A', '2'};                //由于储存字符型变量，则将‘10’写为‘T’
    
    sort_card(a, n);
    
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
