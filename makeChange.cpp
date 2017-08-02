#include <iostream>
#include <cmath>

#define differentCoin 5

using namespace std;

int coins[differentCoin] = {1, 5, 10, 21, 25};

void makeChange(int maxChange, int coinUsed[]);

int main(int argc, char *argv[]) {
	int maxChange = 249;
	int coinUsed[maxChange + 1];
	
	makeChange(maxChange, coinUsed);
	
	for(int i = 0; i <= maxChange; i++) {
		cout<<i<<"\t";
		for(int j = 0; j < 5; j++) {
			cout<<coins[j]<<" "<<(static_cast<int> (coinUsed[i] / pow(10, j + 3)) % 10)<<"\t";
		}
		cout<<coinUsed[i] % 1000<<endl;
	}
}

void makeChange(int maxChange, int coinUsed[]) {
	coinUsed[0] = 0;
	
	for(int coin = 1; coin <= maxChange; coin++) {
		int minCoin = coin;
		if(coin < 5) minCoin += 1000 * coin;
				
		for(int i = 1; i < differentCoin; i++) {
			if(coins[i] > coin) continue;
			
			int preCoin = coinUsed[coin - coins[i]];
			if((preCoin % 1000 + 1) < minCoin % 1000) {
				minCoin = preCoin + 1 + pow(10, i + 3);
			}
		}
		
		coinUsed[coin] = minCoin;
	}
}