#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <stdlib.h>


struct game {
	int score = 0, undo = 3;
	std::vector<int> values = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};

game addRandomPos(game current);
cv::Mat displayGame(game current);
game startScreen(game current);
game endScreen(game current);
game moveUp(game current);
game moveDown(game current);
game moveRight(game current);
game moveLeft(game current);
bool checkNext(game current);
