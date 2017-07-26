
#ifndef distribute_card_h
#define distribute_card_h

#define NUM_CARD 54                                         //总卡牌数54张
#define NUM_LORD 20                                         //地主手牌数20张
#define NUM_FAMER 17                                        //农民手牌数17张
#define NUM_RESERVE 3                                       //预留地主牌数3张

extern int card_order[NUM_CARD];                            //储存随机分发的牌
extern int player1[NUM_FAMER], player2[NUM_FAMER];
extern int player3[NUM_FAMER], reserve[NUM_RESERVE];        //储存3个玩家的牌和地主预留牌

void distribute_card(void);                                 //将54张牌随机填充到card_order数组中

void assigh_array(int [], int [], int);                     //将一个数组的前n个值赋给另一个数组的前n个值

#endif /* distribute_card_h */
