#include <iostream>
#include "Player.h"

#define BACKGROUND_Y 13
#define BACKGROUND_X 21

using namespace std;

//Constructeur par défaut
Player::Player() {
    posPlayer.x = 1;
    posPlayer.y = 1;
    nbBomb = 1;
    nbBombPut = 0;
    rangeBomb = 1;
    hasThrewBomb = false;
    hasPressedKey = false;
    canMove = true;
    playerDirection = Player::Down;
    isAlive = true;
    nbLives = 1;
    delayBomb = 3;
}

//Accesseurs et Mutateurs
int Player::getRangeBomb() {
    return rangeBomb;
}

void Player::setRangeBomb(int newRange){
        rangeBomb = newRange;
}

int Player::getNbBomb() {
    return nbBomb;
}

void Player::setNbBomb(int newNbBomb) {
    nbBomb = newNbBomb;
}

int Player::getNbBombPut() {
    return nbBombPut;
}

void Player::setNbBombPut(int newNbBombPut) {
    nbBombPut = newNbBombPut;
}

int Player::getPosXPlayer() {
    return posPlayer.x;
}

int Player::getPosYPlayer() {
    return posPlayer.y;
}

void Player::setPosPlayer(int x, int y) {
    posPlayer.x = x;
    posPlayer.y = y;
}

bool Player::getThrewBombState() {
    return hasThrewBomb;
}

void Player::setThrewBombState(bool value) {
    hasThrewBomb = value;
}


bool Player::getMoveState() {
	return canMove;
}

void Player::setMoveState(bool value) {
	canMove = value;
}

int Player::getPlayerDirection() {
    return playerDirection;
}

void Player::setPlayerDirection(int value) {
    playerDirection = value;
}

bool Player::getAliveState() {
    return isAlive;
}

void Player::setAliveState(bool value) {
    isAlive = value;
}

int Player::getDelayBomb() {
    return delayBomb;
}

void Player::setDelayBomb(int value) {
    delayBomb = value;
}

int Player::getNbLives() {
    return nbLives;
}

void Player::setNbLives(int value) {
    nbLives = value;
}
