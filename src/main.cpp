#include "../include/2048.h"
#include "../include/2048.hpp"
#include "../include/Moves.hpp"

int main(){
	
	game current, previous;
	current = startScreen(current);

	cv::Mat currentImg;

	while(true){
		currentImg = displayGame(current);

		if (!checkNext(current)){
			endScreen(current);
			break;
		}

		int key_pressed = cv::waitKey(1) & 0xFF; //Left: 81 Up: 82 Right: 83 Down: 84

		
		if (key_pressed == 27 || key_pressed == 'q'){
			break;
		}
		else if(key_pressed == 81){
			previous = current;
			current = moveLeft(current);
			currentImg = displayGame(current);
		}
		else if(key_pressed == 82){
			previous = current;
			current = moveUp(current);
			currentImg = displayGame(current);
		}
		else if(key_pressed == 83){
			previous = current;
			current = moveRight(current);
			currentImg = displayGame(current);
		}
		else if(key_pressed == 84){
			previous = current;
			current = moveDown(current);
			currentImg = displayGame(current);
		}
		else if (key_pressed == 8){
			if (current.values != previous.values && current.undo > 0){
				current.values = previous.values;
				current.score = previous.score;
				current.undo--;
			}
		}

		cv::imshow("2048",currentImg);
	}
	
	return 0;	
}
