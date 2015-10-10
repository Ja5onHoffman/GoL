//
//  Cell.cpp
//  GameOfLife
//
//  Jason Hoffman
//  9/25/2015
//	Assignment 1, CS162

#include "Cell.h"

// Macro defines height and width for clarity

#define HEIGHT 40
#define WIDTH 60

// Cell initializer sets initial status to false

Cell::Cell() {
    for (int i = 0; i < 2; i++) {
        status[i] = false;
    }
}

void Cell::spawn() {
    status[0] = true;
}

void Cell::spawnTemp() {
    status[1] = true;
}

void Cell::kill() {
    status[0] = false;
}

void Cell::killTemp() {
    status[1] = false;
}

bool Cell::isAlive() {
    return status[0];
}

void Cell::transfer() {
    status[0] = false;
    status[0] = status[1];
    status[1] = false;
}

void Cell::copy() {
    status[1] = status[0];
}

bool Cell::isVisible(int h, int w) {
    if ((h > 20 || h < 10) || (w > 50 || w < 10)) {
        return false;
    } else {
        return true;
    }
}

bool Cell::isInBounds(int h, int w) {
    if ((h >= 0 && w >= 0) && (h < HEIGHT && w < WIDTH)) {
        return true;
    }
    return false;
}
