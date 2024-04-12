/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include "SimpleTest.h"
#include "grid.h"
#include "gridlocation.h"

using namespace std;

/*
 * Max row (Code Write)
 * ----------------------------------
 * Write a function named maxRow that takes in a grid and an in 
 * bounds gridLocation and returns a the maximum value in that 
 * row of the grid.
 */

int maxRow(Grid<int>& grid, GridLocation loc) {
    int Max=grid.get(loc);
    for(int i=loc.col+1;i<grid.numCols();i++){
        if(grid.get(loc.row,i)>=Max){
            Max=grid.get(loc.row,i);
            i++;
        }
    }
    return  Max;
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Test max row") {
    Grid<int> grid = {{0, 9, 1}, {1, 3, 0}, {2, 3, 1}};
    EXPECT_EQUAL(maxRow(grid, {2, 1}), 3);
    EXPECT_EQUAL(maxRow(grid, {0, 1}), 9);
}
//091
//130
//231
STUDENT_TEST("Test max row") {
    Grid<int> grid = {{1,8,5,9}, {2,3,6,4}, {5,0,3,3},{7,3,8,2}};
    EXPECT_EQUAL(maxRow(grid, {3,0}), 8);
    EXPECT_EQUAL(maxRow(grid, {2,0}), 5);
    EXPECT_EQUAL(maxRow(grid, {0,0}), 9);
}
//1859
//2364
//5033
//7382
