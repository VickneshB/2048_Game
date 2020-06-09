game moveUp(game current){

	game result = current;

	for(int i=4;i<16;i++){
		if(current.values[i] != 0){
			if(i-12 >= 0){
				if(current.values[i-4] == 0 && current.values[i-8] == 0 && (current.values[i-12] == 0 || current.values[i-12] == current.values[i])){
					if (current.values[i-12] == 0 || (result.values[i-8] != current.values[i]/2 && result.values[i-4] != current.values[i]/2)){
						current.score = current.score + current.values[i] + current.values[i-12];
						current.values[i-12] = current.values[i-12] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-8] == 0 && current.values[i-4] == 0){
						current.score = current.score + current.values[i] + current.values[i-8];
						current.values[i-8] = current.values[i-8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-4] == 0){
						current.score = current.score + current.values[i] + current.values[i-4];
						current.values[i-4] = current.values[i-4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i-4] == 0 && (current.values[i-8] == 0 || current.values[i-8] == current.values[i])){
					if (current.values[i-8] == 0 || result.values[i-4] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i-8];
						current.values[i-8] = current.values[i-8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-4] == 0){
						current.score = current.score + current.values[i] + current.values[i-4];
						current.values[i-4] = current.values[i-4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i-4] == 0 || current.values[i-4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-4];
					current.values[i-4] = current.values[i-4] + current.values[i];
					current.values[i] = 0;
				}
			}
			else if(i-8 >= 0){
				if(current.values[i-4] == 0 && (current.values[i-8] == 0 || current.values[i-8] == current.values[i])){
					if (current.values[i-8] == 0 || result.values[i-4] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i-8];
						current.values[i-8] = current.values[i-8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-4] == 0){
						current.score = current.score + current.values[i] + current.values[i-4];
						current.values[i-4] = current.values[i-4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i-4] == 0 || current.values[i-4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-4];
					current.values[i-4] = current.values[i-4] + current.values[i];
					current.values[i] = 0;
				}
			}
			else{
				if(current.values[i-4] == 0 || current.values[i-4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-4];
					current.values[i-4] = current.values[i-4] + current.values[i];
					current.values[i] = 0;
				}
			}
		}
	}

	if (result.values != current.values){
		result = addRandomPos(current);
	}
	return result;
}


game moveDown(game current){

	game result = current;

	for(int i=11;i>=0;i--){
		if(current.values[i] != 0){
			if(i+12 < 16){
				if(current.values[i+4] == 0 && current.values[i+8] == 0 && (current.values[i+12] == 0 || current.values[i+12] == current.values[i])){
					if (current.values[i+12] == 0 || (result.values[i+8] != current.values[i]/2 && result.values[i+4] != current.values[i]/2)){
						current.score = current.score + current.values[i] + current.values[i+12];
						current.values[i+12] = current.values[i+12] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+8] == 0 && current.values[i+4] == 0){
						current.score = current.score + current.values[i] + current.values[i+8];
						current.values[i+8] = current.values[i+8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+4] == 0){
						current.score = current.score + current.values[i] + current.values[i+4];
						current.values[i+4] = current.values[i+4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i+4] == 0 && (current.values[i+8] == 0 || current.values[i+8] == current.values[i])){
					if (current.values[i+8] == 0 || result.values[i+4] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i+8];
						current.values[i+8] = current.values[i+8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+4] == 0){
						current.score = current.score + current.values[i] + current.values[i+4];
						current.values[i+4] = current.values[i+4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i+4] == 0 || current.values[i+4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+4];
					current.values[i+4] = current.values[i+4] + current.values[i];
					current.values[i] = 0;
				}
			}
			else if(i+8 < 16){
				if(current.values[i+4] == 0 && (current.values[i+8] == 0 || current.values[i+8] == current.values[i])){
					if (current.values[i+8] == 0 || result.values[i+4] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i+8];
						current.values[i+8] = current.values[i+8] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+4] == 0){
						current.score = current.score + current.values[i] + current.values[i+4];
						current.values[i+4] = current.values[i+4] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if(current.values[i+4] == 0 || current.values[i+4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+4];
					current.values[i+4] = current.values[i+4] + current.values[i];
					current.values[i] = 0;
				}
			}
			else{
				if(current.values[i+4] == 0 || current.values[i+4] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+4];
					current.values[i+4] = current.values[i+4] + current.values[i];
					current.values[i] = 0;
				}
			}
		}
	}

	if (result.values != current.values){
		result = addRandomPos(current);
	}
	return result;
}

game moveLeft(game current){

	game result = current;

	for(int i=0;i<16;i++){
		if(i%4 != 0 && current.values[i] != 0){
			if (i%4 == 3){
				if (current.values[i-1] == 0 && current.values[i-2] == 0 && (current.values[i-3] == 0 || current.values[i-3] == current.values[i])){
					if (current.values[i-3] == 0 || (result.values[i-2] != current.values[i]/2 && result.values[i-1] != current.values[i]/2)){
						current.score = current.score + current.values[i] + current.values[i-3];
						current.values[i-3] = current.values[i-3] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-2] == 0 && current.values[i-1] == 0){
						current.score = current.score + current.values[i] + current.values[i-2];
						current.values[i-2] = current.values[i-2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-1] == 0){
						current.score = current.score + current.values[i] + current.values[i-1];
						current.values[i-1] = current.values[i-1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i-1] == 0 && (current.values[i-2] == 0 || current.values[i-2] == current.values[i])){
					if (current.values[i-2] == 0 || result.values[i-1] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i-2];
						current.values[i-2] = current.values[i-2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-1] == 0){
						current.score = current.score + current.values[i] + current.values[i-1];
						current.values[i-1] = current.values[i-1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i-1] == 0 || current.values[i-1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-1];
					current.values[i-1] = current.values[i-1] + current.values[i];
					current.values[i] = 0;
				}
			}
			else if (i%4 == 2){
				if (current.values[i-1] == 0 && (current.values[i-2] == 0 || current.values[i-2] == current.values[i])){
					if (current.values[i-2] == 0 || result.values[i-1] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i-2];
						current.values[i-2] = current.values[i-2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i-1] == 0){
						current.score = current.score + current.values[i] + current.values[i-1];
						current.values[i-1] = current.values[i-1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i-1] == 0 || current.values[i-1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-1];
					current.values[i-1] = current.values[i-1] + current.values[i];
					current.values[i] = 0;
				}
			}
			else{
				if (current.values[i-1] == 0 || current.values[i-1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i-1];
					current.values[i-1] = current.values[i-1] + current.values[i];
					current.values[i] = 0;
				}
			}
		}
	}

	
	if (result.values != current.values){
		result = addRandomPos(current);
	}
	return result;
}


game moveRight(game current){

	game result = current;

	for(int i=14;i>=0;i--){
		if(i%4 != 3 && current.values[i] != 0){
			if (i%4 == 0){
				if (current.values[i+1] == 0 && current.values[i+2] == 0 && (current.values[i+3] == 0 || current.values[i+3] == current.values[i])){
					if (current.values[i+3] == 0 || (result.values[i+2] != current.values[i]/2 && result.values[i+1] != current.values[i]/2)){
						current.score = current.score + current.values[i] + current.values[i+3];
						current.values[i+3] = current.values[i+3] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+2] == 0 && current.values[i+1] == 0){
						current.score = current.score + current.values[i] + current.values[i+2];
						current.values[i-2] = current.values[i-2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+1] == 0){
						current.score = current.score + current.values[i] + current.values[i+1];
						current.values[i+1] = current.values[i+1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i+1] == 0 && (current.values[i+2] == 0 || current.values[i+2] == current.values[i])){
					if (current.values[i+2] == 0 || result.values[i+1] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i+2];
						current.values[i+2] = current.values[i+2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+1] == 0){
						current.score = current.score + current.values[i] + current.values[i+1];
						current.values[i+1] = current.values[i+1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i+1] == 0 || current.values[i+1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+1];
					current.values[i+1] = current.values[i+1] + current.values[i];
					current.values[i] = 0;
				}
			}
			else if (i%4 == 1){
				if (current.values[i+1] == 0 && (current.values[i+2] == 0 || current.values[i+2] == current.values[i])){
					if (current.values[i+2] == 0 || result.values[i+1] != current.values[i]/2){
						current.score = current.score + current.values[i] + current.values[i+2];
						current.values[i+2] = current.values[i+2] + current.values[i];
						current.values[i] = 0;
					}
					else if(current.values[i+1] == 0){
						current.score = current.score + current.values[i] + current.values[i+1];
						current.values[i+1] = current.values[i+1] + current.values[i];
						current.values[i] = 0;
					}
				}
				else if (current.values[i+1] == 0 || current.values[i+1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+1];
					current.values[i+1] = current.values[i+1] + current.values[i];
					current.values[i] = 0;
				}
			}
			else{
				if (current.values[i+1] == 0 || current.values[i+1] == current.values[i]){
					current.score = current.score + current.values[i] + current.values[i+1];
					current.values[i+1] = current.values[i+1] + current.values[i];
					current.values[i] = 0;
				}
			}
		}
	}

	
	if (result.values != current.values){
		result = addRandomPos(current);
	}
	return result;
}


bool checkNext(game current){

	if (std::count(current.values.begin(), current.values.end(), 0) > 0){
		return true;
	}
	game left = moveLeft(current);
	game right = moveRight(current);
	game up = moveUp(current);
	game down = moveDown(current);
	if (left.values == current.values && right.values == current.values && down.values == current.values && up.values == current.values){return false;}
	else{return true;}

}