#pragma once
#include <string>
#include <iostream>

class Player {
public:
    // Constructor. 
    //    Assigns initial amount of money
    Player(int m);
    ~Player();
    int Money();
    void Lose(int L);
    void Win(int W);
    Hand m_hand;

private:
    int m_money;
};