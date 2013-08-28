#include "game.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

//this is going to give us 30 FPS
#define GAME_SPEED 33.33

bool Game::run(void)
{
	char key = ' ';

	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	while(key != 'q')
	{
		while(!getInput(&key))
		{
			timerUpdate();
		}
	cout << "you are pressing " << key << endl;
	}

	cout << frameCount / ((timeGetTime() - startTime) / 1000)  << "fps" << endl;
	cout << timeGetTime() - startTime <<endl;

	cout <<"test"<< endl;

	return true;
}

bool Game::getInput(char *c)
{
	if (kbhit())
	{
		*c = getch();

		return true;
	}
	return false;
}

void Game::timerUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;
	if (currentTime < GAME_SPEED)
	{
		return;
	}
	frameCount ++;
	lastTime = timeGetTime();

}