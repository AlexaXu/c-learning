//
//  main.c
//  扫雷
//
//  Created by 徐浩森 on 2017/6/2.
//  Copyright © 2017年 徐浩森. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROW 8
#define NUM_COL 8

char board[NUM_ROW][NUM_COL];
char show_board[NUM_ROW][NUM_COL];

void re_show(void);
void cre_mine(int);
void judger(void);
void print_board(char board[][NUM_COL]);

int main()
{
    int num_mine = 4;
    
    srand((unsigned) time(NULL));
    
    num_mine += rand() % (NUM_ROW * NUM_COL / 2);
    
    re_show();
    cre_mine(num_mine);
    for(int i = 0; ;i++){
        if(i == NUM_ROW * NUM_COL - num_mine){
            printf("WOW! You win the game!\n");
            return 0;
        }
        judger();
    }
}

void re_show(void){
    for(int i = 0; i < NUM_ROW; i++){
        for(int j = 0; j < NUM_COL; j++){
            board[i][j] = 'N';
        }
    }
    for(int i = 0; i < NUM_ROW; i++){
        for(int j = 0; j < NUM_COL; j++){
            show_board[i][j] = 'N';
        }
    }
    print_board(show_board);
}

void cre_mine(int num_mine){
    int row, col;
    
    for(int i = 0; i < num_mine; ){
        row = rand() % NUM_ROW;
        col = rand() % NUM_COL;
        if(board[row][col] == 'N'){
            board[row][col] = 'M';
            i++;
        }
    }
}

void judger(void){
    int row, col,x, y, n = 0;
    
    printf("Enter a place you want to sweep: ");
    scanf("%d %d", &x, &y);
    
    row = x - 1;
    col = y - 1;
    
    if(board[row][col] == 'M'){
        printf("BOMB! YOU step on a mine!\n");
        print_board(board);
        exit(EXIT_SUCCESS);
    }else{
        if(row == 0 && col == 0){
            for(int i = row; i <= row + 1; i++){
                for(int j = col; j <= col + 1; j++){
                    if(board[i][j] == 'M'){
                        n++;
                    }
                }
            }
        }
        else if(row == 0 && col == NUM_COL -1){
            for(int i = row; i <= row + 1; i++)
                for(int j = col - 1; j <= col; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(row == NUM_ROW - 1 && col == 0){
            for(int i = row - 1; i <= row; i++)
                for(int j = col; j <= col + 1; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(row == NUM_ROW - 1 && col == NUM_COL - 1){
            for(int i = row - 1; i <= row; i++)
                for(int j = col - 1; j <= col; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(row == 0){
            for(int i = row; i <= row + 1; i++)
                for(int j = col - 1; j <= col + 1; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(row == NUM_ROW - 1){
            for(int i = row - 1; i <= row; i++)
                for(int j = col - 1; j <= col + 1; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(col == 0){
            for(int i = row - 1; i <= row + 1; i++)
                for(int j = col; j <= col + 1; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else if(col == NUM_COL - 1){
            for(int i = row - 1; i <= row + 1; i++)
                for(int j = col - 1; j <= col; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        else{
            for(int i = row - 1; i <= row + 1; i++)
                for(int j = col - 1; j <= col + 1; j++)
                    if(board[i][j] == 'M')
                        n++;
        }
        show_board[row][col] = n + 48;
        print_board(show_board);
    }
}

void print_board(char board[][NUM_COL]){
    for(int i = 0; i < NUM_ROW; i++){
        for(int j = 0; j < NUM_COL; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
