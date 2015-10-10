//
//  main.cpp
//  GameOfLife
//
//  Jason Hoffman
//	9/25/2015
// 	Assignment 1, CS162

#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include "World.h"
#include "Cell.h"

/*************************************************
 *
 * In main.cpp the user is able to select the shape
 * with which to run the simulation and, if an oscillator
 * or glider is selected, place the shape on screen. The
 * glider gun only fits if precisely placed, and so
 * cannot be placed by the user.
 *
 *************************************************/

int main() {
    
    World *world = new World;
    std::cout << "Welcome to Conway's Game of Life." << "\n"
    << "**********************************\n"
    << "Run the simulation with your choice of a glider, fixed oscillator (blinker), or Gosper Glider Gun." << "\n"
    << "The glider and blinker allow you to choose its starting location, while the glider gun is fixed." << "\n"
    << "Select 1 for the glider \n" << "Select 2 for the blinker \n" << "Select 3 for the Gosper Glider Gun" << std::endl;
    int s;
    std::cin >> s;
    if (s == 1 || s == 2) {
        std::string shape;
        shape = s == 1 ? "glider" : "blinker";
        std::cout << "Where would you like your " << shape <<  " placed?\nCoordinates are from the top left corner.\n" <<
        "The 'world' is 20 squares high and 40 squares wide.\n";
        if (s == 1) {
            std::cout << "Gliders travel left and down, so choose a high X and low Y.\n" <<
            "The glider is three squares high and three wide,\n" <<
            "and your selected coordinate places the top left corner.\n\n";
        } else if (s == 2) {
            std::cout << "The blinker is three squares tall. Your coordinate will place its top cell." << std::endl;
        }
    }
    
    int x = 0, y = 0;
    if (s == 1 || s == 2) {
        bool setup = false;
        while (!setup) {
            std::cout << "Enter an X coordinate between 0 and 39: ";
            std::cin >> x;
            std::cout << "\nEnter a Y coordinate between 0 and 19: ";
            std::cin >> y;
            if (world->board[x][y].isInBounds(x, y)) {
                setup = true;
            } else {
                std::cout << "Oops. That coordinate looks to be out of bounds,\n" <<
                "or places part of your shape out of bounds.\n";
            }
        }
    }
    
    std::cout << "\n++NOTE: Expand your terminal until the line below does not overlap for the board to display properly\n";
    
    for (int c = 0; c < 61; c++) {
        std::cout << " =";
    }
    
    
    int cycles;
    std::cout << "\n\nFor how many cycles would you like to run the simulation?\n"
    << "To end it early, press CTRL+C\n" << "Enter cycles: ";
    std::cin >> cycles;
    

    if (s == 1) {
        world->createGliderAtIndex(x, y);
    } else if (s == 2) {
        world->createFixedOAtIndex(x, y);
    } else if (s == 3) {
        world->createGliderGun();
    }
    
    world->display();
    for (int i = 0; i < cycles; i++) {
        world->evolve();
        world->display();
        sleep(1);
        write(1,"\E[H\E[2J",7); // Method for clearing screen found on StackOverflow
    }
    
    std::cout << "Thanks for playing!\n";
}
