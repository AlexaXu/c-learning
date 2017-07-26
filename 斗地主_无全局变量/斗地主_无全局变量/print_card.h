//
//  print_card.h
//  斗地主_无全局变量
//
//  Created by 徐浩森 on 2017/5/20.
//  Copyright © 2017年 徐浩森. All rights reserved.
//

#ifndef print_card_h
#define print_card_h

void print_card(int [], int);                    //按顺序输出地主和农民的牌

void sort_card(int [], int);                     //将数组中数从大到小排序

void tran_chinese(int [], int);                  //将数字转换为对应的牌

void confirm_run(void);                          //确认再来一遍或停止游戏

#endif /* print_card_h */
