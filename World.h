//
//  World.h
//  GameOfLife
//
//  Jason Hoffman
//	9/25/2015
//	Assignment 1, CS162

#ifndef __GameOfLife__World__
#define __GameOfLife__World__

#include <stdio.h>
#include "Cell.h"

/****************************************
 *
 * The World class will represent the game board with its 
 * member variable 'board'.
 *
 ****************************************/

class World {
public:
    Cell board[40][60]; // Board is public for program access without using getter
    Cell getBoard(); // returns board
    void evolve(); // Applies Game of Life rules to the cells in board
    void createGliderAtIndex(int, int); // Create glider at coordinates
    void createGliderGun(); // Create glider gun
    void createFixedOAtIndex(int, int); // Create fixed oscillator. A blinker in this program
    void display(); // Prints the board to the console
};

#endif /* defined(__GameOfLife__World__) */
