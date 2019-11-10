#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "map.h"

class Gameloop
{
public:
    Gameloop() : speed(200), key(1), score(0) {}
    void Start();
    int Select1();
	void Select2();
	int Score_list(int key);
	int Explain();
    void DrawGame();
    int PlayGame();
    void UpdateScore(const int&);
    void RewriteScore();
    int Menu();
    void Game();
    int GameOver();
private:
    int speed;
    int key;
    int score;
	Map *wall;
};
#endif // GAMELOOP_H
