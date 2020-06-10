#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <vector>
#include <iostream>

Hand::Hand() {
	m_score = 0;
}
Hand::~Hand(){
}

void Hand::addCard(Card x) {
	m_vec.push_back(x);
}

double Hand::Score() {
	m_score = 0;
	for (int i = 0; i < m_vec.size(); i++) {
		m_score += m_vec[i].get_val();
	}
	return m_score;
}

void Hand::Reset() {
	m_vec.clear();
}

void Hand::showHand() {
	for (int i = 0; i < m_vec.size(); i++) {
		std::cout << m_vec[i].get_spanish_rank() << " de " << m_vec[i].get_spanish_suit();
		if (i == m_vec.size()-1) {
			std::cout << " " << std::endl;
		}
		else
			std::cout << ", ";
	}
}
