#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "Player.h"

#define MAX_PLAYERS 4
#define BACKGROUND_X 21
#define BACKGROUND_Y 13
#define SPRITE_SCALE 4
#define WINDOW_X 336 * SPRITE_SCALE
#define WINDOW_Y 208 * SPRITE_SCALE

using namespace std;
using namespace sf;


//Gestion des variables
int backgroundMap[BACKGROUND_X][BACKGROUND_Y] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 20, 0, 0, 0, 0, 0, 23, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 22, 0, 0, 0, 0, 0, 21, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},

    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}};

int foregroundMap[BACKGROUND_X][BACKGROUND_Y] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},

    {0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},

    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},

    {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},

    {0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0},

    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},

    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},

    {0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},

    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int bombMap[BACKGROUND_X][BACKGROUND_Y][2];

int explosionMap[BACKGROUND_X][BACKGROUND_Y];

int gameType = 1;

Player playerA;
Player playerB;

Texture swapPlayersTexture, explosionTexture, grassTexture, wallTexture, wallBorderTexture, boxTexture, playerAFrontTexture, playerABackTexture, playerALeftTexture, playerARightTexture, playerBFrontTexture, playerBBackTexture, playerBLeftTexture, playerBRightTexture, playerCTexture, playerDTexture, bombTexture, extraBombTexture, healTexture, rangeUpTexture, reductionExplodeTexture, redTeleporterTexture, blueTeleporterTexture, freezeTexture;
Sprite swapPlayersSprite, explosionSprite, grassSprite, wallSprite, wallBorderSprite, boxSprite, playerAFrontSprite, playerABackSprite, playerALeftSprite, playerARightSprite, playerBFrontSprite, playerBBackSprite, playerBLeftSprite, playerBRightSprite, playerCSprite, playerDSprite, bombSprite, extraBombSprite, healSprite, rangeUpSprite, reductionExplodeSprite, redTeleporterSprite, blueTeleporterSprite, freezeSprite;

RenderWindow mainWindow(VideoMode(WINDOW_X, WINDOW_Y), "Alien Bombs Fight v2.8");

//Gestion des fonctions
void debugMap() {
    for (int i = 0; i < BACKGROUND_Y; i++) {
        for (int j = 0; j < BACKGROUND_X; j++) {
            cout << backgroundMap[j][i] << " ";
        }

        cout << endl;
    }
}

void freezeTimer() {
    sleep(milliseconds(2500));
    playerA.setMoveState(true);
    playerB.setMoveState(true);
}

//Création et lancement du thread du Freeze
    Thread freezeManagerThread(&freezeTimer);

void powerUp(int positionX, int positionY, int prePosX, int prePosY) {

    // 8 = nbBombes | 9 = RangeBombes | 10 = nbLive | 11 = explodeTime | 12 = freeze | 13 = swap
    switch(foregroundMap[positionX][positionY]) {
        case 8:

            //Sélection du joueur
            switch (bombMap[positionX][positionY][1]) {
                case Player::PlayerA:
                    playerA.setNbBomb(playerA.getNbBomb() + 1);
                    break;

                case Player::PlayerB:
                    playerB.setNbBomb(playerB.getNbBomb() + 1);
                    break;
            }

            break;

        case 9:

            //Sélection du joueur
            switch (bombMap[positionX][positionY][1]) {
                case Player::PlayerA:
                    playerA.setRangeBomb(playerA.getRangeBomb() + 1);
                    break;

                case Player::PlayerB:
                    playerB.setRangeBomb(playerB.getRangeBomb() + 1);
                    break;
            }

            break;

        case 10:
            //Sélection du joueur
            switch (bombMap[positionX][positionY][1]) {
                case Player::PlayerA:
                    playerA.setNbLives(playerA.getNbLives() + 1);
                    break;

                case Player::PlayerB:
                    playerB.setNbLives(playerB.getNbLives() + 1);
                    break;
            }

            break;

        case 11:

            //Sélection du joueur
            switch (bombMap[positionX][positionY][1]) {

                case Player::PlayerA:
                    if (playerA.getDelayBomb() > 1) {
                        playerA.setDelayBomb(playerA.getDelayBomb() - 1);
                    }
                    break;

                case Player::PlayerB:
                    if (playerB.getDelayBomb() > 1) {
                        playerB.setDelayBomb(playerB.getDelayBomb() - 1);
                    }
                    break;
            }

        case 12:
            //Sélection du joueur
            switch(bombMap[positionX][positionY][1]) {
                case Player::PlayerA:
                    cout << "A FREEZE B" << endl;
                    playerB.setMoveState(false);
                    freezeManagerThread.launch();
                    break;

                case Player::PlayerB:
                    cout << "B FREEZE A" << endl;
                    playerA.setMoveState(false);
                    freezeManagerThread.launch();
                    break;
            }

        case 13:
            //Sélection du joueur
            switch(bombMap[positionX][positionY][1]) {
                case Player::PlayerA:
                    //foregroundMap[positionX][positionY] = 0;
                    foregroundMap[prePosX][prePosY] = 0;
                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;

                    playerA.setPosPlayer(playerB.getPosXPlayer(), playerB.getPosYPlayer());
                    playerB.setPosPlayer(positionX, positionY);

                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;

                    break;

                case Player::PlayerB:
                    //foregroundMap[positionX][positionY] = 0;
                    foregroundMap[prePosX][prePosY] = 0;
                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;

                    playerB.setPosPlayer(playerA.getPosXPlayer(), playerA.getPosYPlayer());
                    playerA.setPosPlayer(positionX, positionY);

                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;

                    break;
            }

        break;
    }

    bombMap[positionX][positionY][1] = -1;

}

void lootOrNot(int bombX, int bombY) {
    int lootRate = rand() % 100 + 1;

    //Drop de Bomb++
	if (lootRate <= 8) {
        foregroundMap[bombX][bombY] = 8;

	//Drop de Range++
	} else if (lootRate <= 18) {
        foregroundMap[bombX][bombY] = 9;

	//Drop de Timer++
	} else if (lootRate <= 25) {
        foregroundMap[bombX][bombY] = 10;

	//Drop de Life++
	} else if (lootRate <= 29) {
        foregroundMap[bombX][bombY] = 11;

	//Freeze pour l'autre joueur
	} else if (lootRate <= 30){
	    foregroundMap[bombX][bombY] = 12;

    //Swap pour les joueurs
	} else if (lootRate <= 38) {
        foregroundMap[bombX][bombY] = 13;

	//Pas de drop
	} else {
        foregroundMap[bombX][bombY] = 7;
	}
}

void cleanUpExplosions() {
    while (true) {
        for (int i = 0; i < BACKGROUND_X; i++) {
            for (int j = 0; j < BACKGROUND_Y; j++) {

                if (explosionMap[i][j] != 0) {
                    explosionMap[i][j]--;

                //Les cases contenant des explosions sont nettoyées
                } else if (!(foregroundMap[i][j] == 8 || foregroundMap[i][j] == 9 || foregroundMap[i][j] == 10 || foregroundMap[i][j] == 11 || foregroundMap[i][j] == 12 || foregroundMap[i][j] == 13 || foregroundMap[i][j] == 1 || foregroundMap[i][j] == 2 || foregroundMap[i][j] == 3 || foregroundMap[i][j] == 4 || foregroundMap[i][j] == 5 || foregroundMap[i][j] == 6)) {
                    foregroundMap[i][j] = 0;
                }
            }
        }

        sleep(milliseconds(550));
    }
}

void drawGraphicalsArray() {
    //Affichage de background
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 13; j++) {
            switch (backgroundMap[i][j]) {
                case 0:
                    grassSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    grassSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(grassSprite);
                    break;

                case 1:
                    wallSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    wallSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(wallSprite);
                    break;

                case 2:
                    wallBorderSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    wallBorderSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(wallBorderSprite);
                    break;

                case 20:
                    redTeleporterSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    redTeleporterSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(redTeleporterSprite);
                    break;

                case 21:
                    redTeleporterSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    redTeleporterSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(redTeleporterSprite);
                    break;


                case 22:
                    blueTeleporterSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    blueTeleporterSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(blueTeleporterSprite);
                    break;

                case 23:
                    blueTeleporterSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    blueTeleporterSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(blueTeleporterSprite);
                    break;
            }
        }
    }

    //Affichage du foreground
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 13; j++) {

            switch (foregroundMap[i][j]) {

                case 1:
                    boxSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    boxSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(boxSprite);
                    break;

                case 2:
                    if (playerA.getAliveState()) {
                        //Switch selon l'orientation du personnage
                        switch (playerA.getPlayerDirection()) {
                            case Player::Up:
                                playerABackSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerABackSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerABackSprite);
                                break;

                            case Player::Down:
                                playerAFrontSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerAFrontSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerAFrontSprite);
                                break;

                            case Player::Right:
                                playerARightSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerARightSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerARightSprite);
                                break;

                            case Player::Left:
                                playerALeftSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerALeftSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerALeftSprite);
                                break;
                        }
                    }

                    break;

                case 3:
                    if (playerB.getAliveState()) {
                        //Switch selon l'orientation du personnage
                        switch (playerB.getPlayerDirection()) {
                            case Player::Up:
                                playerBBackSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerBBackSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerBBackSprite);
                                break;

                            case Player::Down:
                                playerBFrontSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerBFrontSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerBFrontSprite);
                                break;

                            case Player::Right:
                                playerBRightSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerBRightSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerBRightSprite);
                                break;

                            case Player::Left:
                                playerBLeftSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                                playerBLeftSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                                mainWindow.draw(playerBLeftSprite);
                                break;
                        }
                    }

                    break;

                case 4:
                    playerCSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    playerCSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(playerCSprite);
                    break;

                case 5:
                    playerDSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    playerDSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(playerDSprite);
                    break;

                case 6:
                    if (bombMap[i][j][0] != -1) {
                        bombSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                        bombSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                        mainWindow.draw(bombSprite);
                    }
                    break;

                case 7:
                    explosionSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    explosionSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(explosionSprite);
                    break;

                case 8:
                    extraBombSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    extraBombSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(extraBombSprite);
                    break;

                case 9:
                    rangeUpSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    rangeUpSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(rangeUpSprite);
                    break;

                case 10:
                    healSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    healSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(healSprite);
                    break;

                case 11:
                    reductionExplodeSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    reductionExplodeSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(reductionExplodeSprite);
                    break;

                case 12:
                    freezeSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    freezeSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(freezeSprite);
                    break;

                case 13:
                    swapPlayersSprite.setPosition(SPRITE_SCALE * 16 * i, SPRITE_SCALE * 16 * j);
                    swapPlayersSprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
                    mainWindow.draw(swapPlayersSprite);
                    break;
            }
        }
    }
}

void fillTextures() {
    grassTexture.loadFromFile("assets/grass.png");
    wallTexture.loadFromFile("assets/wall1.png");
    wallBorderTexture.loadFromFile("assets/wall2.png");
    boxTexture.loadFromFile("assets/box.png");
    bombTexture.loadFromFile("assets/bomb.png");
    explosionTexture.loadFromFile("assets/explosion.png");

    extraBombTexture.loadFromFile("assets/extraBomb.png");
    healTexture.loadFromFile("assets/heal.png");
    rangeUpTexture.loadFromFile("assets/range.png");
    reductionExplodeTexture.loadFromFile("assets/explodeReduction.png");
    swapPlayersTexture.loadFromFile("assets/swap.png");

    blueTeleporterTexture.loadFromFile("assets/blue_teleporter.png");
    redTeleporterTexture.loadFromFile("assets/red_teleporter.png");

    playerAFrontTexture.loadFromFile("assets/playerA_front.png");
    playerABackTexture.loadFromFile("assets/playerA_back.png");
    playerALeftTexture.loadFromFile("assets/playerA_left.png");
    playerARightTexture.loadFromFile("assets/playerA_right.png");

    playerBFrontTexture.loadFromFile("assets/playerB_front.png");
    playerBBackTexture.loadFromFile("assets/playerB_back.png");
    playerBLeftTexture.loadFromFile("assets/playerB_left.png");
    playerBRightTexture.loadFromFile("assets/playerB_right.png");

    playerCTexture.loadFromFile("assets/playerC_front.png");
    playerDTexture.loadFromFile("assets/playerD_front.png");

    freezeTexture.loadFromFile("assets/freeze.png");
}

void settingUpExplosions(int bombX, int bombY) {
    int maxRange = 1;

    //Switch gérant la portée max du joueur
    switch(bombMap[bombX][bombY][1]) {
        case Player::PlayerA:
            maxRange = playerA.getRangeBomb();
            break;

        case Player::PlayerB:
            maxRange = playerB.getRangeBomb();
            break;
    }

    //Explosions du haut
    for (int i = 1; i <= maxRange; i++) {

        //S'il y a un mur du background
        if (backgroundMap[bombX][bombY - i] == 2 || backgroundMap[bombX][bombY - i] == 1) {
            explosionMap[bombX][bombY - i] = 0;
            break;

        //S'il y a une caisse
        } else if (foregroundMap[bombX][bombY - i] == 1){
            lootOrNot(bombX, bombY - i);
            explosionMap[bombX][bombY - i] = 1;
            break;

        //S'il y a du vide
        } else if (foregroundMap[bombX][bombY - i] == 0) {
            foregroundMap[bombX][bombY - i] = 7;
            explosionMap[bombX][bombY - i] = 1;

        //S'il y a un joueur
        } else if (foregroundMap[bombX][bombY - i] == 2 || foregroundMap[bombX][bombY - i] == 3 || foregroundMap[bombX][bombY - i] == 4 || foregroundMap[bombX][bombY - i] == 5) {

            //Selon le joueur dans l'explosion
            if (foregroundMap[bombX][bombY - i] == 2) {
                playerA.setNbLives(playerA.getNbLives() - 1);

                if(playerA.getNbLives() == 0) {
                    playerA.setAliveState(false);
                }
            } else if (foregroundMap[bombX][bombY - i] == 3) {
                playerB.setNbLives(playerB.getNbLives() - 1);

                if(playerB.getNbLives() == 0) {
                    playerB.setAliveState(false);
                }
            }

            foregroundMap[bombX][bombY - i] = 7;
            explosionMap[bombX][bombY - i] = 1;
        }
    }

    //Explosions du bas
    for (int i = 1; i <= maxRange; i++) {

        //S'il y a un mur du background
        if (backgroundMap[bombX][bombY + i] == 2 || backgroundMap[bombX][bombY + i] == 1) {
            foregroundMap[bombX][bombY + i] = 0;
            break;

        //S'il y a une caisse
        } else if (foregroundMap[bombX][bombY + i] == 1){
            lootOrNot(bombX, bombY + i);
            explosionMap[bombX][bombY + i] = 1;
            break;

        //S'il y a du vide
        } else if (foregroundMap[bombX][bombY + i] == 0) {
            foregroundMap[bombX][bombY + i] = 7;
            explosionMap[bombX][bombY + i] = 1;

        //S'il y a un joueur
        } else if (foregroundMap[bombX][bombY + i] == 2 || foregroundMap[bombX][bombY + i] == 3 || foregroundMap[bombX][bombY + i] == 4 || foregroundMap[bombX][bombY + i] == 5) {

            //Selon le joueur dans l'explosion
            if (foregroundMap[bombX][bombY + i] == 2) {
                playerA.setNbLives(playerA.getNbLives() - 1);

                if(playerA.getNbLives() == 0) {
                    playerA.setAliveState(false);
                }
            } else if (foregroundMap[bombX][bombY + i] == 3) {
                playerB.setNbLives(playerB.getNbLives() - 1);

                if(playerB.getNbLives() == 0) {
                    playerB.setAliveState(false);
                }
            }

            foregroundMap[bombX][bombY + i] = 7;
            explosionMap[bombX][bombY + i] = 1;
        }
    }


    //Explosions de la gauche
    for (int i = 1; i <= maxRange; i++) {

        //S'il y a un mur du background
        if (backgroundMap[bombX - i][bombY] == 2 || backgroundMap[bombX - i][bombY] == 1) {
            explosionMap[bombX - i][bombY] = 1;
            break;

        //S'il y a une caisse
        } else if (foregroundMap[bombX - i][bombY] == 1){
            lootOrNot(bombX - i, bombY);
            explosionMap[bombX - i][bombY] = 1;
            break;

        //S'il y a du vide
        } else if (foregroundMap[bombX - i][bombY] == 0) {
            foregroundMap[bombX - i][bombY] = 7;
            explosionMap[bombX - i][bombY] = 1;

        //S'il y a un joueur
        } else if (foregroundMap[bombX - i][bombY] == 2) {
            playerA.setNbLives(playerA.getNbLives() - 1);

                if(playerA.getNbLives() == 0) {
                    playerA.setAliveState(false);
                }
        } else if (foregroundMap[bombX - i][bombY] == 3) {
            playerB.setNbLives(playerB.getNbLives() - 1);

                if(playerB.getNbLives() == 0) {
                    playerB.setAliveState(false);
                }
        }

        foregroundMap[bombX - i][bombY] = 7;
        explosionMap[bombX - i][bombY] = 1;
    }

    //Explosions de la droite
    for (int i = 1; i <= maxRange; i++) {

        //S'il y a un mur du background
        if (backgroundMap[bombX + i][bombY] == 2 || backgroundMap[bombX + i][bombY] == 1) {
            explosionMap[bombX + i][bombY] = 1;
            break;

        //S'il y a une caisse
        } else if (foregroundMap[bombX + i][bombY] == 1){
            lootOrNot(bombX + i, bombY);
            explosionMap[bombX + i][bombY] = 1;
            break;

        //S'il y a du vide
        } else if (foregroundMap[bombX + i][bombY] == 0) {
            foregroundMap[bombX + i][bombY] = 7;
            explosionMap[bombX + i][bombY] = 1;

        //S'il y a un joueur
        } else if (foregroundMap[bombX + i][bombY] == 2) {
            playerA.setNbLives(playerA.getNbLives() - 1);

                if(playerA.getNbLives() == 0) {
                    playerA.setAliveState(false);
                }
        } else if (foregroundMap[bombX + i][bombY] == 3) {
            playerB.setNbLives(playerB.getNbLives() - 1);

                if(playerB.getNbLives() == 0) {
                    playerB.setAliveState(false);
                }
        }

        foregroundMap[bombX + i][bombY] = 7;
        explosionMap[bombX + i][bombY] = 1;
    }

    //Mise en place d'une explosion à la place de la bombe
    foregroundMap[bombX][bombY] = 7;
    explosionMap[bombX][bombY] = 1;
}

void fillSprites() {
    grassSprite.setTexture(grassTexture);
    wallBorderSprite.setTexture(wallBorderTexture);
    wallSprite.setTexture(wallTexture);
    boxSprite.setTexture(boxTexture);
    bombSprite.setTexture(bombTexture);
    explosionSprite.setTexture(explosionTexture);

    blueTeleporterSprite.setTexture(blueTeleporterTexture);
    redTeleporterSprite.setTexture(redTeleporterTexture);

    extraBombSprite.setTexture(extraBombTexture);
    healSprite.setTexture(healTexture);
    rangeUpSprite.setTexture(rangeUpTexture);
    reductionExplodeSprite.setTexture(reductionExplodeTexture);
    swapPlayersSprite.setTexture(swapPlayersTexture);

    playerAFrontSprite.setTexture(playerAFrontTexture);
    playerABackSprite.setTexture(playerABackTexture);
    playerALeftSprite.setTexture(playerALeftTexture);
    playerARightSprite.setTexture(playerARightTexture);

    playerBFrontSprite.setTexture(playerBFrontTexture);
    playerBBackSprite.setTexture(playerBBackTexture);
    playerBLeftSprite.setTexture(playerBLeftTexture);
    playerBRightSprite.setTexture(playerBRightTexture);

    playerCSprite.setTexture(playerCTexture);
    playerDSprite.setTexture(playerDTexture);

    freezeSprite.setTexture(freezeTexture);

}

void bombTimer() {
    while (true) {
      for (int i = 0; i < BACKGROUND_X; i++) {
            for (int j = 0; j < BACKGROUND_Y; j++) {
                    //s'il y a une bombe sur la case
                if (bombMap[i][j][0] != -1) {
                    //on actualise le timer
                    bombMap[i][j][0]--;
                    //si en plus le timer arrive à la fin
                    if (bombMap[i][j][0] == -1) {
                        //on met du vide niveau graphisme et on met une explosion
                        foregroundMap[i][j] = 0;
                        settingUpExplosions(i, j);
                    }
                }
                //s'il n'y pas de bombe sur la case
                if (bombMap[i][j][0] == -1) {

                    //Switch qui sélectionne le joueur qui a posé la bombe
                    switch (bombMap[i][j][1]) {

                        //JoueurA
                        case Player::PlayerA:
                            bombMap[i][j][1] = -1;

                            if (playerA.getNbBombPut() > 0) {
                                playerA.setNbBombPut(playerA.getNbBombPut() - 1);
                            }

                            break;

                        //JoueurB
                        case Player::PlayerB:
                            bombMap[i][j][1] = -1;

                            if (playerB.getNbBombPut() > 0) {
                                playerB.setNbBombPut(playerB.getNbBombPut() - 1);
                            }

                            break;
                    }
                }
            }
        }
        sleep(seconds(1));
    }
}

void fillBombMap() {
    for (int i = 0; i < BACKGROUND_X; i++) {
        for (int j = 0; j < BACKGROUND_Y; j++) {
            bombMap[i][j][0] = -1;
            bombMap[i][j][1] = -1;
        }
    }
}

int main() {
    //Modification de la génération aléatoire
    srand(time(NULL));

    //Remplissage du tableaux des bombes
    fillBombMap();

    //Création et lancement du thread du timer pour les bombes
    Thread bombManagerThread(&bombTimer);

    bombManagerThread.launch();

    //Création et lancement du thread des explosions
    Thread explosionsManagerThread(&cleanUpExplosions);

    explosionsManagerThread.launch();

    //Mise en place des textures et des sprites
    fillTextures();
    fillSprites();

    //Sélection des modes de jeu
    if (gameType == 1) {
        playerA.setPosPlayer(1, 1);
        playerB.setPosPlayer(19, 11);

        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;
    }

    Event actualEvent;

    //Boucle de jeu principale
    while (mainWindow.isOpen()) {

        //Tant qu'il y a des évenements en attente
        while (mainWindow.pollEvent(actualEvent)) {

            switch (actualEvent.type) {

                //Quand la fenêtre est fermée
                case Event::Closed:
                    mainWindow.close();

                    return EXIT_SUCCESS;

                //Si on appuie sur une touche
                case Event::KeyPressed:

                    //On teste la touche pressée
                    switch (actualEvent.key.code) {

                    //PlayerA
                        //Touche Z
                        case Keyboard::Z:
                            if (playerA.getAliveState() && playerA.getMoveState()) {
                                if (foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 8 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 9 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 10 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 11 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 12 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 13) {
                                    bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1][1] = Player::PlayerA;
                                    powerUp(playerA.getPosXPlayer(), playerA.getPosYPlayer() - 1, playerA.getPosXPlayer(), playerA.getPosYPlayer());
                                }

                                if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 1 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 2 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 6 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 1 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 7 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 20 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 21 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 22 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] != 23) {
                                    if (playerA.getThrewBombState()) {

                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 6;
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][0] = playerA.getDelayBomb();
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                        playerA.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    }

                                    playerA.setPosPlayer(playerA.getPosXPlayer(), playerA.getPosYPlayer() - 1);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 20) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 21) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 22) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() - 1] == 23) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                }

                                playerA.setPlayerDirection(Player::Up);
                            }

                            break;

                        //Touche Q
                        case Keyboard::Q:
                            if (playerA.getAliveState() && playerA.getMoveState()) {
                                if (foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 8 || foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 9 || foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 10 || foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 11 || foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 12 || foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 13) {
                                    bombMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                    powerUp(playerA.getPosXPlayer() - 1, playerA.getPosYPlayer(), playerA.getPosXPlayer(), playerA.getPosYPlayer());
                                }

                                if (backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 1 && backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 2 && foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 6 && foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 1 && foregroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 7 && backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 20 && backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 21 && backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 22 && backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] != 23) {

                                    if (playerA.getThrewBombState()) {

                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 6;
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][0] = playerA.getDelayBomb();
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                        playerA.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    }

                                    playerA.setPosPlayer(playerA.getPosXPlayer() - 1, playerA.getPosYPlayer());
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 20) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 21) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 22) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() - 1][playerA.getPosYPlayer()] == 23) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                }

                                playerA.setPlayerDirection(Player::Left);
                            }

                            break;

                        //Touche S
                        case Keyboard::S:
                            if (playerA.getAliveState() && playerA.getMoveState()) {
                                if (foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 8 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 9 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 10 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 11 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 12 || foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 13) {
                                    bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1][1] = Player::PlayerA;
                                    powerUp(playerA.getPosXPlayer(), playerA.getPosYPlayer() + 1, playerA.getPosXPlayer(), playerA.getPosYPlayer());
                                }

                                if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 1 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 2 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 6 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 1 && foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 7 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 20 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 21 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 22 && backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] != 23) {
                                    if (playerA.getThrewBombState()) {

                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 6;
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][0] = playerA.getDelayBomb();
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                        playerA.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    }

                                    playerA.setPosPlayer(playerA.getPosXPlayer(), playerA.getPosYPlayer() + 1);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 20) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;

                                }else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 21) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 22) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer() + 1] == 23) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                }

                                playerA.setPlayerDirection(Player::Down);
                            }

                            break;

                        //Touche D
                        case Keyboard::D:
                            if (playerA.getAliveState() && playerA.getMoveState()) {
                                if (foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 8 || foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 9 || foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 10 || foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 11 || foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 12 || foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 13) {
                                    bombMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                    powerUp(playerA.getPosXPlayer() + 1, playerA.getPosYPlayer(), playerA.getPosXPlayer(), playerA.getPosYPlayer());
                                }

                                if (backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 1 && backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 2 && foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 6 && foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 1 && foregroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 7 && backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 20 && backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 21 && backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 22 && backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] != 23) {
                                    if (playerA.getThrewBombState()) {

                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 6;
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][0] = playerA.getDelayBomb();
                                        bombMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()][1] = Player::PlayerA;
                                        playerA.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    }

                                    playerA.setPosPlayer(playerA.getPosXPlayer() + 1, playerA.getPosYPlayer());
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 20) {

                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 21) {
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 22) {
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(5, 9);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerA.getPosXPlayer() + 1][playerA.getPosYPlayer()] == 23) {
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 0;
                                    playerA.setPosPlayer(15, 3);
                                    foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
                                }

                                playerA.setPlayerDirection(Player::Right);
                            }

                            break;

                        //Touche Espace
                        case Keyboard::Space:
                            if (playerA.getNbBomb() - playerA.getNbBombPut() > 0 && playerA.getAliveState() && playerA.getMoveState()) {
                                playerA.setThrewBombState(true);
                                playerA.setNbBombPut(playerA.getNbBombPut() + 1);
                            }

                            break;

                    //Player B
                        //Touche Haut
                        case Keyboard::Up:
                            if (playerB.getAliveState() && playerB.getMoveState()) {
                                if (foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 8 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 9 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 10 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 11 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 12 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 13) {
                                    bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1][1] = Player::PlayerB;
                                    powerUp(playerB.getPosXPlayer(), playerB.getPosYPlayer() - 1, playerB.getPosXPlayer(), playerB.getPosYPlayer());
                                }

                                if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 1 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 2 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 6 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 1 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 7 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 20 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 21 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 22 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] != 23) {
                                    if (playerB.getThrewBombState()) {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 6;
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][0] = playerB.getDelayBomb();
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                        playerB.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    }

                                    playerB.setPosPlayer(playerB.getPosXPlayer(), playerB.getPosYPlayer() - 1);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;
                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 20) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 21) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 22) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                } else if (foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() - 1] == 23) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                }

                                playerB.setPlayerDirection(Player::Up);
                            }

                            break;

                        //Touche Gauche
                        case Keyboard::Left:
                            if (playerB.getAliveState() && playerB.getMoveState()) {
                                if (foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 8 || foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 9 || foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 10 || foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 11 || foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 12 || foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 13) {
                                   bombMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                   powerUp(playerB.getPosXPlayer() - 1, playerB.getPosYPlayer(), playerB.getPosXPlayer(), playerB.getPosYPlayer());
                                }

                                if (backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 1 && backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 2 && foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 6 && foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 1 && foregroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 7 && backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 20 && backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 21 && backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 22 && backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] != 23) {
                                    if (playerB.getThrewBombState()) {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 6;
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][0] = playerB.getDelayBomb();
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                        playerB.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    }

                                    playerB.setPosPlayer(playerB.getPosXPlayer() - 1, playerB.getPosYPlayer());
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;

                                } else if (backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 20) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 21) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 22) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() - 1][playerB.getPosYPlayer()] == 23) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                }

                                playerB.setPlayerDirection(Player::Left);
                            }

                            break;

                        //Touche Bas
                        case Keyboard::Down:
                            if (playerB.getAliveState() && playerB.getMoveState()) {
                                if (foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 8 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 9 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 10 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 11 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 12 || foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 13) {
                                    bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1][1] = Player::PlayerB;
                                    powerUp(playerB.getPosXPlayer(), playerB.getPosYPlayer() + 1, playerB.getPosXPlayer(), playerB.getPosYPlayer());
                                }

                                if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 1 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 2 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 6 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 1 && foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 7 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 20 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 21 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 22 && backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] != 23) {
                                   if (playerB.getThrewBombState()) {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 6;
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][0] = playerB.getDelayBomb();
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                        playerB.setThrewBombState(false);
                                    } else {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    }

                                    playerB.setPosPlayer(playerB.getPosXPlayer(), playerB.getPosYPlayer() + 1);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;

                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 20) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 21) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 22) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer() + 1] == 23) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                }

                                playerB.setPlayerDirection(Player::Down);
                            }

                            break;

                        //Touche Droite
                        case Keyboard::Right:
                            if (playerB.getAliveState() && playerB.getMoveState()) {
                                if (foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 8 || foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 9 || foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 10 || foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 11 || foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 12 || foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 13) {
                                   bombMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                   powerUp(playerB.getPosXPlayer() + 1, playerB.getPosYPlayer(), playerB.getPosXPlayer(), playerB.getPosYPlayer());
                                }

                                if (backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 1 && backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 2 && foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 6 && foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 1 && foregroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 7 && backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 20 && backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 21 && backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 22 && backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] != 23) {
                                    if (playerB.getThrewBombState()) {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 6;
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][0] = playerB.getDelayBomb();
                                        bombMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()][1] = Player::PlayerB;
                                        playerB.setThrewBombState(false);

                                    } else {
                                        foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    }

                                    playerB.setPosPlayer(playerB.getPosXPlayer() + 1, playerB.getPosYPlayer());
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;

                                } else if (backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 20) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 21) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 22) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(5, 9);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;

                                } else if (backgroundMap[playerB.getPosXPlayer() + 1][playerB.getPosYPlayer()] == 23) {
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 0;
                                    playerB.setPosPlayer(15, 3);
                                    foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 2;
                                }

                                playerB.setPlayerDirection(Player::Right);
                            }

                            break;

                        //Touche Ctrl
                        case Keyboard::RControl:
                            if (playerB.getNbBomb() - playerB.getNbBombPut() > 0 && playerB.getAliveState() && playerB.getMoveState()) {
                                playerB.setThrewBombState(true);
                                playerB.setNbBombPut(playerB.getNbBombPut() + 1);
                            }
                            break;

                    }
            }
        }

        //Clean de la fenêtre
        mainWindow.clear();

        //Actualisation des joueurs
        if (foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] != 6) {
            if (playerA.getAliveState()) {
                foregroundMap[playerA.getPosXPlayer()][playerA.getPosYPlayer()] = 2;
            }

            if (playerB.getAliveState()) {
                foregroundMap[playerB.getPosXPlayer()][playerB.getPosYPlayer()] = 3;
            }
        }

        //Drawing graphicals arrays
        drawGraphicalsArray();

        //Updating screen
        mainWindow.display();
    }

    return EXIT_SUCCESS;
}
