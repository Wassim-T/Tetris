#include "Player.h"


namespace model {

    void Player::setScore(int nbL, int hDrop, int niveau) {
        int score = 0;

        switch (nbL) {
            case 0:
                score += (40 * nbL + hDrop) * niveau;
                break;

            case 1:
                score += (40 * nbL + hDrop) * niveau;
                break;

            case 2:
                score += (100 * nbL + hDrop) * niveau;
                break;

            case 3:
                score += (300 * nbL + hDrop) * niveau;
                break;
            case 4:
                score += (1200 * nbL + hDrop) * niveau;
                break;
        }

        _score += score;
    }

    int Player::getScore() const {
        return _score;
    }

    std::string Player::getName() const {
        return _name;
    }

    Player::Player(std::string &name) : _score(0),_name(name) {}

    void Player::setName(std::string name){
        _name=name;
    }


};
