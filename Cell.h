//
//  Cell.h
//  GameOfLife
//
//  Jason Hoffman
//	9/25/2015
//	Assignment 1, CS162

#ifndef __GameOfLife__Cell__
#define __GameOfLife__Cell__

#include <stdio.h>
#include <string>

/*******************************************************
 *
 * Each cell on the game board is represented by
 * the Cell class. A cell's 'alive' or 'dead' status
 * is determinded by a boolean value. For the purposes
 * of applying the game's rules without affecting the
 * current board, each cell has an 'active' and 'standby'
 * status. After the rules are applied to each cell on the
 * board, the 'standby' becomes active and the game continues.
 *
 *********************************************************/

class Cell {
private:
    bool status[2]; // Array containing active and standby
public:
    Cell();
    void spawn(); // Bring a cell to life
    void spawnTemp(); // Bring a cell's standby to life
    void kill(); // Kill a cell
    void killTemp(); // Kill a cell's standby
    bool isAlive(); // Boolean returns status of active
    void transfer(); // Transfer standby status to active then reset standby
    void copy(); // Transfer to standby with no reset
    bool isVisible(int, int); // Cell is in visible portion of board
    bool isInBounds(int, int); // Prevent segmentation fault
};

#endif
