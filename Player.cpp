#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <string>
#include <string>


Player::Player(int money) {
	m_money = money;
}
Player::~Player() {
};

void Player::Lose(int L) {
	m_money -= L;
}

void Player::Win(int W) {
	m_money += W;
}
int Player::Money() {
	return m_money;
}

