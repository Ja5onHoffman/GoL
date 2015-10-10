//
//  World.cpp
//  GameOfLife
//
//  Jason Hoffman
//	9/25/2015
//	Assignment 1, CS162

#include "World.h"
#include <iostream>
#include <iomanip>

// WIDTH and HEIGHT macro for clarity

#define HEIGHT 40
#define WIDTH 60

// createGliderAtIndex adds 10 to i and j to
// translate the users coordinates to the visible board

void World::createGliderAtIndex(int i, int j) {
    int x = i + 10;
    int y = j + 10;
    board[y][x].spawn();
    board[y+1][x].spawn();
    board[y+2][x].spawn();
    board[y+2][x+1].spawn();
    board[y+1][x+2].spawn();
}

// createGliderGun translates a 2D array describing the glider to
// coordinates on the board

void World::createGliderGun() {
#define _ 0
    // Glider Gun 2d array taken from http://www.cplusplus.com/forum/lounge/75168/
    bool glider_gun[11][38] =
    {
        { _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,1,_,1,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,_,1,1,_,_,_,_,_,_,1,1,_,_,_,_,_,_,_,_,_,_,_,_,1,1,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,1,_,_,_,1,_,_,_,_,1,1,_,_,_,_,_,_,_,_,_,_,_,_,1,1,_ },
        { _,1,1,_,_,_,_,_,_,_,_,1,_,_,_,_,_,1,_,_,_,1,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,1,1,_,_,_,_,_,_,_,_,1,_,_,_,1,_,1,1,_,_,_,_,1,_,1,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,1,_,_,_,_,_,1,_,_,_,_,_,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,1,_,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,_,1,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ },
        { _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ },
    };
    
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 38; j++) {
            if (glider_gun[i][j] == 1) {
                board[i+10][j+10].spawn();
            }
        }
    }
}

// createFixedOAtIndex creates a simple oscillator
// by spawning the necessary cells

void World::createFixedOAtIndex(int i, int j) {
    int x = i + 10;
    int y = j + 10;
    board[y][x].spawn();
    board[y+1][x].spawn();
    board[y+2][x].spawn();
}

// evolve loops through the board and applies GoL rules to
// each cell's 'standby' status using its 'active' status
// then uses the Cell object's transfer() function to make
// the 'standby' active

void World::evolve() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = 0;
            
            if (board[i+1][j].isInBounds((i+1), j))
                count += board[i+1][j].isAlive() ? 1 : 0;
            
            if (board[i-1][j].isInBounds((i-1), j))
                count += board[i-1][j].isAlive() ? 1 : 0;
            
            if (board[i][j+1].isInBounds(i, (j+1)))
                count += board[i][j+1].isAlive() ? 1 : 0;
            
            if (board[i][j-1].isInBounds(i, (j-1)))
                count += board[i][j-1].isAlive() ? 1 : 0;
            
            if (board[i+1][j+1].isInBounds((i+1), (j+1)))
                count += board[i+1][j+1].isAlive() ? 1 : 0;
            
            if (board[i+1][j-1].isInBounds((i+1), (j-1)))
                count += board[i+1][j-1].isAlive() ? 1 : 0;
            
            if (board[i-1][j+1].isInBounds((i-1), (j+1)))
                count += board[i-1][j+1].isAlive() ? 1 : 0;
            
            if (board[i-1][j-1].isInBounds((i-1), (j-1)))
                count += board[i-1][j-1].isAlive() ? 1 : 0;
            
            if (count < 2 || count > 3) {
                board[i][j].killTemp();
            }
            
            if (count == 2){
                board[i][j].copy();
            }
                            
            if (count == 3) {
                board[i][j].spawnTemp();
            }
            
            count = 0;
        }
    }
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j].transfer();
        }
    }
}

// prints the board to console, clearing the previous output

void World::display() {
    std::cout << "  ";
    for (int x = 0; x < 40; x++)
        std::cout << std::setw(3) << x;
    
    std::cout << std::endl;
    
    for (int i = 10; i < HEIGHT - 10; i++) {
        std::cout << std::setw(2) << i - 10;
        for (int j = 10 ; j < WIDTH - 10; j++) {
            std::setw(2);
            board[i][j].isAlive() ? std::cout << std:: setw(3) << "0" : std::cout << std::setw(3) << "-";
        }
        std::cout << std::endl;
    }
    
    for (int c = 0; c < 61; c++) {
        std::cout << " =";
    }
    
    std::cout << std::endl;
}
