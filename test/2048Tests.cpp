#include "../include/2048.h"
#include "../include/2048.hpp"
#include "../include/Moves.hpp"
#include <gtest/gtest.h>


TEST(Tests2048, UpTests) { 
	game upTest;

	upTest.values = {2,4,8,16,
		             2,4,8,16,
		             2,4,8,16,
		             2,4,8,16};
	ASSERT_EQ(moveUp(upTest).values[0], 4);
	ASSERT_EQ(moveUp(upTest).values[1], 8);
	ASSERT_EQ(moveUp(upTest).values[2], 16);
	ASSERT_EQ(moveUp(upTest).values[3], 32);
	ASSERT_EQ(moveUp(upTest).values[4], 4);
	ASSERT_EQ(moveUp(upTest).values[5], 8);
	ASSERT_EQ(moveUp(upTest).values[6], 16);
	ASSERT_EQ(moveUp(upTest).values[7], 32);

	upTest.values = {2,4,8,16,
		             2,4,8,16,
		             4,8,16,32,
		             4,8,16,32};
	ASSERT_EQ(moveUp(upTest).values[0], 4);
	ASSERT_EQ(moveUp(upTest).values[1], 8);
	ASSERT_EQ(moveUp(upTest).values[2], 16);
	ASSERT_EQ(moveUp(upTest).values[3], 32);
	ASSERT_EQ(moveUp(upTest).values[4], 8);
	ASSERT_EQ(moveUp(upTest).values[5], 16);
	ASSERT_EQ(moveUp(upTest).values[6], 32);
	ASSERT_EQ(moveUp(upTest).values[7], 64);

	upTest.values = {2,0,0,2,
					 2,2,0,0,
					 4,0,0,0,
					 0,0,0,4};
	ASSERT_EQ(moveUp(upTest).values[0], 4);
	ASSERT_EQ(moveUp(upTest).values[1], 2);
	ASSERT_EQ(moveUp(upTest).values[3], 2);
	ASSERT_EQ(moveUp(upTest).values[4], 4);
	ASSERT_EQ(moveUp(upTest).values[7], 4);


}

TEST(Tests2048, DownTests) { 
	game downTest;

	downTest.values = {2,4,8,16,
		               2,4,8,16,
		               2,4,8,16,
		               2,4,8,16};
	ASSERT_EQ(moveDown(downTest).values[8], 4);
	ASSERT_EQ(moveDown(downTest).values[9], 8);
	ASSERT_EQ(moveDown(downTest).values[10], 16);
	ASSERT_EQ(moveDown(downTest).values[11], 32);
	ASSERT_EQ(moveDown(downTest).values[12], 4);
	ASSERT_EQ(moveDown(downTest).values[13], 8);
	ASSERT_EQ(moveDown(downTest).values[14], 16);
	ASSERT_EQ(moveDown(downTest).values[15], 32);

	downTest.values = {2,4,8,16,
		               2,4,8,16,
		               4,8,16,32,
		               4,8,16,32};
	ASSERT_EQ(moveDown(downTest).values[8], 4);
	ASSERT_EQ(moveDown(downTest).values[9], 8);
	ASSERT_EQ(moveDown(downTest).values[10], 16);
	ASSERT_EQ(moveDown(downTest).values[11], 32);
	ASSERT_EQ(moveDown(downTest).values[12], 8);
	ASSERT_EQ(moveDown(downTest).values[13], 16);
	ASSERT_EQ(moveDown(downTest).values[14], 32);
	ASSERT_EQ(moveDown(downTest).values[15], 64);

	downTest.values = {2,0,0,2,
					   2,2,0,0,
					   4,0,0,0,
					   0,0,0,4};
	ASSERT_EQ(moveDown(downTest).values[8], 4);
	ASSERT_EQ(moveDown(downTest).values[11], 2);
	ASSERT_EQ(moveDown(downTest).values[12], 4);
	ASSERT_EQ(moveDown(downTest).values[13], 2);
	ASSERT_EQ(moveDown(downTest).values[15], 4);


}

TEST(Tests2048, LeftTests) { 
	game leftTest;

	leftTest.values = {2,2,2,2,
		              4,4,4,4,
		              8,8,8,8,
		              16,16,16,16};
	ASSERT_EQ(moveLeft(leftTest).values[0], 4);
	ASSERT_EQ(moveLeft(leftTest).values[1], 4);
	ASSERT_EQ(moveLeft(leftTest).values[4], 8);
	ASSERT_EQ(moveLeft(leftTest).values[5], 8);
	ASSERT_EQ(moveLeft(leftTest).values[8], 16);
	ASSERT_EQ(moveLeft(leftTest).values[9], 16);
	ASSERT_EQ(moveLeft(leftTest).values[12], 32);
	ASSERT_EQ(moveLeft(leftTest).values[13], 32);

	leftTest.values = {2,2,4,4,
		               4,4,8,8,
		               8,8,16,16,
		               16,16,32,32};
	ASSERT_EQ(moveLeft(leftTest).values[0], 4);
	ASSERT_EQ(moveLeft(leftTest).values[1], 8);
	ASSERT_EQ(moveLeft(leftTest).values[4], 8);
	ASSERT_EQ(moveLeft(leftTest).values[5], 16);
	ASSERT_EQ(moveLeft(leftTest).values[8], 16);
	ASSERT_EQ(moveLeft(leftTest).values[9], 32);
	ASSERT_EQ(moveLeft(leftTest).values[12], 32);
	ASSERT_EQ(moveLeft(leftTest).values[13], 64);

	leftTest.values = {2,0,0,2,
				 	   2,2,4,0,
				  	   4,0,0,0,
					   0,0,0,4};
	ASSERT_EQ(moveLeft(leftTest).values[0], 4);
	ASSERT_EQ(moveLeft(leftTest).values[4], 4);
	ASSERT_EQ(moveLeft(leftTest).values[5], 4);
	ASSERT_EQ(moveLeft(leftTest).values[8], 4);
	ASSERT_EQ(moveLeft(leftTest).values[12], 4);

}

TEST(Tests2048, RightTests) { 
	game rightTest;

	rightTest.values = {2,2,2,2,
		                4,4,4,4,
		                8,8,8,8,
		                16,16,16,16};
	ASSERT_EQ(moveRight(rightTest).values[2], 4);
	ASSERT_EQ(moveRight(rightTest).values[3], 4);
	ASSERT_EQ(moveRight(rightTest).values[6], 8);
	ASSERT_EQ(moveRight(rightTest).values[7], 8);
	ASSERT_EQ(moveRight(rightTest).values[10], 16);
	ASSERT_EQ(moveRight(rightTest).values[11], 16);
	ASSERT_EQ(moveRight(rightTest).values[14], 32);
	ASSERT_EQ(moveRight(rightTest).values[15], 32);

	rightTest.values = {2,2,4,4,
		                4,4,8,8,
		                8,8,16,16,
		                16,16,32,32};
	ASSERT_EQ(moveRight(rightTest).values[2], 4);
	ASSERT_EQ(moveRight(rightTest).values[3], 8);
	ASSERT_EQ(moveRight(rightTest).values[6], 8);
	ASSERT_EQ(moveRight(rightTest).values[7], 16);
	ASSERT_EQ(moveRight(rightTest).values[10], 16);
	ASSERT_EQ(moveRight(rightTest).values[11], 32);
	ASSERT_EQ(moveRight(rightTest).values[14], 32);
	ASSERT_EQ(moveRight(rightTest).values[15], 64);

	rightTest.values = {2,0,0,2,
					    2,2,4,0,
					    4,0,0,0,
					    0,0,0,4};
	ASSERT_EQ(moveRight(rightTest).values[3], 4);
	ASSERT_EQ(moveRight(rightTest).values[6], 4);
	ASSERT_EQ(moveRight(rightTest).values[7], 4);
	ASSERT_EQ(moveRight(rightTest).values[11], 4);
	ASSERT_EQ(moveRight(rightTest).values[15], 4);

}

TEST(Tests2048, NonMovableTests) { 
	game upTest;

	upTest.values = {2,2,0,2,
					 4,0,0,4,
					 8,0,0,0,
					 0,0,0,0};
	ASSERT_EQ(moveUp(upTest).values, upTest.values);
	ASSERT_EQ(moveUp(upTest).score, upTest.score);
	ASSERT_EQ(moveUp(upTest).undo, upTest.undo);

	game downTest;

	downTest.values = {2,0,0,0,
					   4,0,0,0,
					   8,0,0,2,
					   16,4,4,8};
	ASSERT_EQ(moveDown(downTest).values, downTest.values);
	ASSERT_EQ(moveDown(downTest).score, downTest.score);
	ASSERT_EQ(moveDown(downTest).undo, downTest.undo);

	game leftTest;

	leftTest.values = {2,0,0,0,
					   4,0,0,0,
					   8,2,0,0,
					   16,4,8,0};
	ASSERT_EQ(moveLeft(leftTest).values, leftTest.values);
	ASSERT_EQ(moveLeft(leftTest).score, leftTest.score);
	ASSERT_EQ(moveLeft(leftTest).undo, leftTest.undo);

	game rightTest;

	rightTest.values = {0,0,0,2,
					   0,0,0,16,
					   0,0,0,4,
					   16,4,8,2};
	ASSERT_EQ(moveRight(rightTest).values, rightTest.values);
	ASSERT_EQ(moveRight(rightTest).score, rightTest.score);
	ASSERT_EQ(moveRight(rightTest).undo, rightTest.undo);

}

TEST(Tests2048, GameOverTest) { 
	game checkTest;

	checkTest.values = {2,2,0,2,
	 				    4,0,0,4,
					    8,0,0,0,
					    0,0,0,0};
	ASSERT_EQ(checkNext(checkTest), true);

	checkTest.values = {2,8,16,2048,
	 				    4,512,256,4,
					    8,2,16,2,
					    2,8,16,4};
	ASSERT_EQ(checkNext(checkTest), true);

	checkTest.values = {2,4,8,16,
	 				    16,8,4,2,
					    8,32,64,128,
					    128,8,32,256};
	ASSERT_EQ(checkNext(checkTest), false);

	checkTest.values = {1024,512,256,128,
	 				    8,16,32,64,
					    16,8,16,8,
					    32,2,8,4};
	ASSERT_EQ(checkNext(checkTest), false);

}

TEST(Tests2048, RandomInsertion){
	game add;

	add.values = {2,2,2,2,
	 			  4,4,4,4,
				  8,8,8,0,
				  8,8,8,8};
	
	ASSERT_EQ(addRandomPos(add).values[11], 2);

	add.values = {2,2,2,2,
	 			  4,4,0,4,
				  8,8,8,8,
				  8,8,8,8};
	
	ASSERT_EQ(addRandomPos(add).values[6], 2);

	add.values = {2,2,2,2,
	 			  4,4,4,4,
				  8,8,8,8,
				  0,8,8,8};
	
	ASSERT_EQ(addRandomPos(add).values[12], 2);

	add.values = {2,0,2,2,
	 			  4,4,4,4,
				  8,8,8,8,
				  8,8,8,8};
	
	ASSERT_EQ(addRandomPos(add).values[1], 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
