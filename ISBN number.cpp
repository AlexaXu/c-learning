#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int number[13];
	char isbn[20];
	int index;
	int sum;
	
	for(int i = 0; i < 13; i++) {
		number[i] = 0;
	}
	
	cout<<"Enter ISBN number:"<<endl;
	cin.getline(isbn, 21);
	
	for(int i = 0; isbn[i] != '\0'; i++) {
		if(isbn[i] >= '0' && isbn[i] <= '9') {
			number[index++] = isbn[i] - '0';
		}
	}
	
	if(index != 13 && index != 10) {
		cout<<"ISBN number incorrect"<<endl;
	}
	else if(index == 10) {
		for(int j = 10; j > 0; j--) {
			sum = sum + (j * number[10 - j]);
		}
		
		if(sum % 11 == 0) cout<<"Genuine"<<endl;
		else cout<<"Piracy"<<endl;
		
	}
	else {
		for(int j = 0; j < 13; j++) {
			if(j % 2 == 0) {
				sum += number[j];
			}else {
				sum += (3 * number[j]);
			}
		}
		
		if(sum % 10 == 0) cout<<"Genuine"<<endl;
		else cout<<"Piracy"<<endl;
	}
}