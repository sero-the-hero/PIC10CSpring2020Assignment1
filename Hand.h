#pragma once
#include <string>
#include <vector>
#include <fstream>


class Hand {
public:
    // A vector of Cards
    Hand();
    ~Hand();
    void addCard(Card x);
    double Score();
    void Reset();
    void showHand();
    double m_score;
    std::vector<Card> m_vec;

private:
};