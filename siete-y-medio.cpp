#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Card.h"
#include "Hand.h"
#include "Player.h"

int main() {

	Player tu(100);
	Player casa(900);
	int bet = 0;
	char hit = 'x';
	int gameNum = 0;
	std::ofstream myFile;

	myFile.open("gamelog.txt");
	while (tu.Money() > 0 && casa.Money() > 0) {

		std::cout << std::endl << "cuanto quieres apostar? ";
		std::cin >> bet;
		if (bet > tu.Money()) {
			std::cout << "No tienes " << bet << "!" << std::endl;
		}
		else if (bet <= tu.Money()) {
			gameNum++;
			Card x;
			tu.m_hand.addCard(x);
			std::cout << "Tienes: ";
			tu.m_hand.showHand();
			std::cout << "Con: " << tu.m_hand.Score() << " puntos" << std::endl;
			std::cout << "Queres otra carta? (s/n): ";
			std::cin >> hit;

			while (hit == 'S' || hit == 's') { // player turn
				Card y;
				tu.m_hand.addCard(y); // player always draws at least 1 card
				std::cout << "Tienes: ";  
				tu.m_hand.showHand();
				std::cout << "Con: " << tu.m_hand.Score() << " puntos" << std::endl;
				std::cout << "Queres otra carta? (s/n): ";
				std::cin >> hit;
				std::cout << std::endl;
			}

			Card xx;                // CPU draws
			casa.m_hand.addCard(xx);

			while (casa.m_hand.Score() <= 5.5) { // CPU turn, draws while hand score is less than 5.5
				Card z;
				casa.m_hand.addCard(z);
			}

			// cases covered by result
			if (tu.m_hand.Score() > 7.5) {// regardless of if the CPU busts, the player loses when he busts
				tu.Lose(bet);
				std::cout << std::endl;
				std::cout << "ahh perdiste!" << std::endl;
			}
			else if (tu.m_hand.Score() < 7.5 && casa.m_hand.Score() > 7.5) {
				tu.Win(bet);
				casa.Lose(bet);
				std::cout << std::endl;
				std::cout << "Ganaste!" << std::endl;
			}

			else if ((tu.m_hand.Score() < 7.5) && (tu.m_hand.Score() > casa.m_hand.Score())) { // neither go over, player is higher
				tu.Win(bet);
				casa.Lose(bet);
				std::cout << std::endl;
				std::cout << "Ganaste!" << std::endl;
			}

			else if ((casa.m_hand.Score() < 7.5) && (tu.m_hand.Score() < casa.m_hand.Score())) { // neither go over, CPU is higher
				tu.Lose(bet);
				std::cout << std::endl; // displays the details of the game to the player
				std::cout << "ahh perdiste!" << std::endl;
			}

			else if (casa.m_hand.Score() == tu.m_hand.Score()) { // Neither bust, both tie, no money is exchanged
				std::cout << std::endl;
				std::cout << "Empataron!" << std::endl;
				std::cout << "Los dos con: " << tu.m_hand.Score() << " puntos!" << std::endl;
			}

			std::cout << "Tu tenias: "; // show players hand
			tu.m_hand.showHand();
			std::cout << "con: " << tu.m_hand.Score() << " punots";
			std::cout << "La computadora tenia: " << std::endl;
			casa.m_hand.showHand();
			std::cout << "con: " << casa.m_hand.Score() << " punots";
			std::cout << std::endl;

			if (gameNum == 1) { // Writing details of game to gamelog start
				myFile << "---------------------------------------------" << std::endl;
			}
			myFile << "Game number: " << gameNum << "           Money left: " << tu.Money() << std::endl;
			myFile << "Bet: " << bet << std::endl << std::endl;
			myFile << "Your Cards: " << std::endl;
			for (int i = 0; i < tu.m_hand.m_vec.size(); i++) {
				myFile << "   " << tu.m_hand.m_vec[i].get_spanish_rank() << " de " << tu.m_hand.m_vec[i].get_spanish_suit() << "      ";
				myFile << "   (" << tu.m_hand.m_vec[i].get_english_rank() << " of " << tu.m_hand.m_vec[i].get_english_suit() << ")" << std::endl;
			}
			myFile << "Your total is: " << tu.m_hand.Score() << std::endl << std::endl;
			myFile << "Dealers Cards:" << std::endl;
			for (int i = 0; i < casa.m_hand.m_vec.size(); i++) {
				myFile << "   " << casa.m_hand.m_vec[i].get_spanish_rank() << " de " << casa.m_hand.m_vec[i].get_spanish_suit() << "      ";
				myFile << "   (" << casa.m_hand.m_vec[i].get_english_rank() << " of " << casa.m_hand.m_vec[i].get_english_suit() << ")" << std::endl;
			}
			myFile << "Dealers total is: " << casa.m_hand.Score() << std::endl;
			myFile << "---------------------------------------------" << std::endl; // writing details of game to gamelog end
			tu.m_hand.Reset();
			casa.m_hand.Reset();
		}
	}
	myFile.close();
	
		if (tu.Money() <= 0) {
			std::cout << "ahhh perdiste todo tu dinero!";
		}

		if (casa.Money() <= 0) {
			std::cout << "Ganaste! Eres el gran campeon!";
		}
}

