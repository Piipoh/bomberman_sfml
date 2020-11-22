#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

#define BACKGROUND_X 21
#define BACKGROUND_Y 13

typedef struct {
    int x;
    int y;
}Pos;


class Player {
    public:
        Player();

        enum PlayerID {
            PlayerA,
            PlayerB,
            PlayerC,
            PlayerD,
        };

        enum PlayerDirection {
            Up,
            Down,
            Left,
            Right,
        };

        //Accesseurs et Mutateurs
        int getRangeBomb();
        void setRangeBomb(int newRange);

        int getNbBomb();
        void setNbBomb(int newNbBomb);

        int getNbBombPut();
        void setNbBombPut(int newNbBombPut);

        int getPosXPlayer();
        int getPosYPlayer();
        void setPosPlayer(int x, int y);

        bool getThrewBombState();
        void setThrewBombState(bool value);

        bool getMoveState();
        void setMoveState(bool value);

        bool getPressedKeyState();
        void setPressedKeyState(bool value);

        int getPlayerDirection();
        void setPlayerDirection(int value);

        bool getAliveState();
        void setAliveState(bool value);

        int getDelayBomb();
        void setDelayBomb(int value);

        int getNbLives();
        void setNbLives(int value);

    private:
        int nbBomb;
        int nbBombPut;
        int rangeBomb;
        Pos posPlayer;
        bool isAlive;
        bool hasThrewBomb;
        bool hasPressedKey;
        bool canMove;
        int playerDirection;
        int delayBomb;
        int nbLives;
};

#endif // PLAYER_H_INCLUDED
