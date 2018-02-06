#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	
	srand(time(NULL));
	int player_first_card = rand() % 10 + 1;
	int dealer_first_card = rand() % 10 + 1;
	int player_second_card = rand() % 10 + 1;
	int dealer_second_card = rand() % 10 + 1;
	int player_hit = rand() % 10 + 1;
	int dealer_hit = 0;
	int player_total = 0;
	int dealer_total = 0;
	bool player_stay = false;
	bool dealer_stay = false;
	bool player_bust = false;
	bool dealer_bust = false;
	bool keep_playing = true;
	char stay_hit = 'a';
	char yes_no = 'a';
	
	while (keep_playing) {
		// Deal first cards to player and dealer also displays totals
		//player
		cout << "your first cards are " << player_first_card <<" and " 
		<< player_second_card << endl;
		player_total = player_first_card + player_second_card;
		cout << " for a total of: " << player_total << endl;
		//dealer
		cout << "The dealers first card is " << dealer_first_card << endl;
	
		while ((player_stay == false) && (player_bust == false)) {
			cout << "Do you want to stay or hit? (s or h)" << endl;
			cin >> stay_hit;
			if (stay_hit == 'h'){
				cout << "You chose to hit your new card is a " << player_hit << endl;
				player_total = player_total + player_hit;
				cout << " for a new total of " << player_total << endl;
				if (player_total > 21){
					cout << "You bust!!!" << endl;
					player_bust = true;
				}
				
			}
			/*if (player_bust = true){
				cout << "Would you like to play again? (y or n)" << endl;
				cin >> yes_no;
			}*/
			if (stay_hit == 's'){
				cout << "You chose to stay. Dealer's turn. " << endl;
				player_stay = true;
			}
			
			
		}
		// Dealer's turn
		if ((player_stay == true) && (player_bust == false)) {
			cout << "Dealer's next card is " << dealer_second_card << endl;
			dealer_total = dealer_first_card + dealer_second_card;
			cout << "For a total of " << dealer_total << endl;
							
				if (dealer_total >= 17){
					cout << "Dealer Stays." << endl;
					dealer_stay = true;
				}
				if (dealer_total > 21){
					cout << "Dealer busts YOU WIN!!!"<< endl;
					dealer_bust = true;
				}
				
				
			
		}
		if ((player_bust == false) && (dealer_bust == false)){
			cout << "Your total is: " << player_total << endl;
			cout << "The Dealer's total is: " << dealer_total << endl;
			if (player_total <= dealer_total){
				cout << "DEALER WINS!!!" << endl;
				cout << "Would you like to play again? y or n" << endl;
				cin >> yes_no;
				}
		}
		if (yes_no == 'n'){
			keep_playing = false;
		}
		if (yes_no == 'y'){
			keep_playing = true;
		}
		
	}
	return 0;
}