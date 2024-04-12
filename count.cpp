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
#include <iostream>
#include "SimpleTest.h"
#include "vector.h"
#include "simpio.h"
#include "strlib.h"
#include "filelib.h"
#include <fstream>
using namespace std;

/*
 * Count Numbers (Code Write)
 * ----------------------------------
 * Write a program to read through a given file and count the
 * the number of times a user inputed number appears in that file. You  
 * can assume that numbers will be composed entirely of numerical digits, 
 * optionally preceded by a single negative sign.
 */
int countNumbers(string num) {
    fstream file;
    int cnt=0;
    file.open("res/numbers.txt");
    if(!file.is_open()){
        cout << "Error: Wrongs while opening" << endl;
        return 0;
    }
    else{
        string word;
        while(file>>word){
            if(word==num){
                cnt++;
            }
        }
    }
    return cnt;
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Count numbers") {
    /* This isn't a full on test, since the results of countNumbers
     * depends on user input. To confirm your solution works, you'd need
    to manually check the print statements in the console. */
    EXPECT_NO_ERROR(countNumbers("res/numbers.txt"));
}

STUDENT_TEST("How many times '9' counts in the file") {
    EXPECT_EQUAL(countNumbers("9"),2);
}

STUDENT_TEST("How many times 'is' counts in the file") {
    EXPECT_EQUAL(countNumbers("is"),2);
}

STUDENT_TEST("How many times 'the' counts in the file") {
    EXPECT_EQUAL(countNumbers("is"),2);
}

STUDENT_TEST("How many times 'to' counts in the file") {
    EXPECT_EQUAL(countNumbers("to"),3);
}

STUDENT_TEST("How many times 'and' counts in the file") {
    EXPECT_EQUAL(countNumbers("and"),2);
}

STUDENT_TEST("How many times 'steep' counts in the file") {
    EXPECT_EQUAL(countNumbers("steep"),0);
}
