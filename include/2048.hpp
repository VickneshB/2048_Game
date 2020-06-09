

game addRandomPos(game current){
	std::vector<int> zeros;
	for(int i=0;i<current.values.size();i++){
		if (current.values[i] == 0){
			zeros.push_back(i);
		}
	}
	if (zeros.size() > 0){
		srand(time(0));
		current.values[zeros[rand() % zeros.size()]] = 2;
	}
	return current;
}

cv::Mat displayGame(game current){
	
	cv::Mat templateImg = cv::Mat::zeros( 800, 800, CV_8UC3 ); // + cv::Vec3b(255, 255, 255);
	
	putText(templateImg, "2048", cv::Point(275,90), cv::FONT_HERSHEY_COMPLEX_SMALL, 5, cv::Scalar(0,255,255), 1, CV_AA);

	cv::Point pt1 =  cv::Point(100, 150);
	cv::Point pt2 =  cv::Point(700, 150);
	cv::Point pt3 =  cv::Point(100, 750);
	cv::Point pt4 =  cv::Point(700, 750);
	cv::Point pt5 =  cv::Point(250, 150);
	cv::Point pt6 =  cv::Point(250, 750);
	cv::Point pt7 =  cv::Point(400, 150);
	cv::Point pt8 =  cv::Point(400, 750);
	cv::Point pt9 =  cv::Point(550, 150);
	cv::Point pt10 =  cv::Point(550, 750);
	cv::Point pt11 =  cv::Point(100, 300);
	cv::Point pt12 =  cv::Point(700, 300);
	cv::Point pt13 =  cv::Point(100, 450);
	cv::Point pt14 =  cv::Point(700, 450);
	cv::Point pt15 =  cv::Point(100, 600);
	cv::Point pt16 =  cv::Point(700, 600);

	cv::Scalar color = cv::Scalar(255,255,255);
	int thickness = 5, lineType = 8, shift = 0;
	line(templateImg, pt1, pt2, color, thickness, lineType, shift);
	line(templateImg, pt3, pt4, color, thickness, lineType, shift);
	line(templateImg, pt1, pt3, color, thickness, lineType, shift);
	line(templateImg, pt2, pt4, color, thickness, lineType, shift);
	line(templateImg, pt5, pt6, color, thickness, lineType, shift);
	line(templateImg, pt7, pt8, color, thickness, lineType, shift);
	line(templateImg, pt9, pt10, color, thickness, lineType, shift);
	line(templateImg, pt11, pt12, color, thickness, lineType, shift);
	line(templateImg, pt13, pt14, color, thickness, lineType, shift);
	line(templateImg, pt15, pt16, color, thickness, lineType, shift);

	
	std::string strScore = "Score: " + std::to_string(current.score);
	std::string strUndo = "Undo remaining: " + std::to_string(current.undo);
	putText(templateImg, strScore, cv::Point(100,130), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(0,0,255), 1, CV_AA);
	putText(templateImg, strUndo, cv::Point(480,130), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(255,0,0), 1, CV_AA);

	for(int i = 0; i < 16; i++){
		int x = 165, y = 235, textSize = 2;
		x = x + (i%4)*150;
		y = y + (i/4)*150;
		int value = current.values[i];
		while(value >= 10){
			x = x - 15; 
			value/=10;
		}
		if (current.values[i] > 0){
			putText(templateImg, std::to_string(current.values[i]), cv::Point(x,y), cv::FONT_HERSHEY_COMPLEX_SMALL, textSize, cv::Scalar(0,0,255), 1, CV_AA);
		}
	}

	return templateImg;
}

game startScreen(game current){

	srand(time(0));
	
	int pos = rand() % 16;
	//std::cout<<pos<<std::endl;
	current.values[pos] = 2;

	while(true){
		int pos2 = rand() % 16;
		if (pos != pos2){
			current.values[pos2] = 2;
			break;
		}
	}

	cv::Mat templateImg = displayGame(current);

	cv::Mat overlayImg = cv::Mat::zeros( 800, 800, CV_8UC3 );

	cv::Mat startImg;

	addWeighted( templateImg, 0.2, overlayImg, 1.8, 0.0, startImg);

	putText(startImg, "INSTRUCTIONS:", cv::Point(100,280), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, "USE ARROW KEYS TO MOVE", cv::Point(100,380), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, "GET 2048 ON THE SCREEN", cv::Point(100,430), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, "Press Q to quit the game anytime", cv::Point(100,480), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, "Press any key to continue", cv::Point(100,530), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, "Press Backspace for UNDO (Max:3)", cv::Point(100,580), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.5, cv::Scalar(0,0,255), 1, CV_AA);

	cv::imshow("2048",startImg);

	cv::waitKey(0);

	return current;
}

game endScreen(game current){

	cv::Mat templateImg = displayGame(current);

	cv::Mat overlayImg = cv::Mat::zeros( 800, 800, CV_8UC3 );

	cv::Mat startImg;

	addWeighted( templateImg, 0.2, overlayImg, 1.8, 0.0, startImg);

	std::string finalScore = "Final Score: " + std::to_string(current.score);
	putText(startImg, "GAME OVER", cv::Point(50,400), cv::FONT_HERSHEY_COMPLEX_SMALL, 5, cv::Scalar(0,0,255), 1, CV_AA);
	putText(startImg, finalScore, cv::Point(50,500), cv::FONT_HERSHEY_COMPLEX_SMALL, 3, cv::Scalar(0,255,0), 1, CV_AA);
	cv::imshow("2048",startImg);

	while(true){
		int key_pressed = cv::waitKey(1) & 0xFF;
				
		if (key_pressed == 27 || key_pressed == 'q'){
			break;
		}
	}

	return current;
}

