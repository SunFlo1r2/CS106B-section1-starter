# Be sure You aren't enrolling in the course and you must follow Stanford honor code policy!!!

## C++ fundamentals
### This is an exercise of CS106B 2024 Spring

##### 1) Program analysis: C++isms you should know
Topics: Types, References, range based loops, strings, stanford C++ library

In the following, we will analyze a simple program that filters last names whose end match a specific substring. Given an input string of format:

name1,name2, ... 
and a string suffix, the program returns all the names in the input string that ends with the suffix.

#include "SimpleTest.h"
#include "vector.h"
#include "strlib.h"

using namespace std;

/*
   @param input: input string whose last names will be filtered
   @param suffix: the substring which we will filter last names by
   Functionality: this function filters the input string and returns last names
        that end with 'suffix'
*/
Vector<string> filter(string input, string suffix)
{
    Vector<string> filteredNames;
    Vector<string> names = stringSplit(input, ',');

    for (string name: names) {
        // convert to lowercase so we can easily compare the strings
        if (endsWith(toLowerCase(name), toLowerCase(suffix))) {
            filteredNames.add(name);
        }
    }
    return filteredNames;
}

STUDENT_TEST("Filter names") {
    Vector<string> results = filter("Zelenski,Szumlanski,Kwarteng", "Ski");
    EXPECT_EQUAL(results, {"Zelenski","Szumlanski"});

    results = filter("AmbaTi,Szumlanski,Tadimeti", "TI");
    Vector<string> expected = {"AmbaTi", "Tadimeti"};
    EXPECT(results == expected);

    results = filter("Zelenski,Szumlanski,Kwarteng", "NnG");
    EXPECT_EQUAL(results, {});

    // what other tests could you add?
}
##### 2) countNumbers (count.cpp)
Topics: Vectors, strings, file reading, while true, conditional statements, Stanford C+++ library

The function countNumbers reads a text file and prints the number of times a user entered number appears in that text file. A user can continually enter numbers until they hit "Enter" or "Return" on their keyboard. Here are some library functions that will be useful for this task:

readLines, to read all lines from a file stream into a Vector
stringSplit, to divide a string into tokens
getLine, to read a line of text entered by the user
stringIsInteger, to confirm a string of digits is valid integer
In particular you will be asked to write the following function

void countNumbers(string filename)

When given the following file, named numbers.txt, as input, your function should print 1 when a user enters 42. Similarly, when the user enters another number like 9, your function should print 2. Finally, the function ends when the user presses "Return".

42 is the Answer to the Ultimate Question of Life, the Universe, and Everything
This is a negative number: -9
Welcome to CS106B!
I want to own 9 cats and 9 dogs.
##### 3) Debugging Deduplicating (deduplicate.cpp)
Topics: Vector, strings, debugging

Consider the following incorrect C++ function, which accepts as input a Vector<string> and tries to modify it by removing adjacent duplicate elements:

⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
```
void deduplicate(Vector<string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == vec[i + 1]) { 
            vec.remove(i);
        }
    }
}
```
⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️

The intent behind this function is that we could do something like this:

```
Vector<string> hiddenFigures = {
    "Katherine Johnson",
    "Katherine Johnson",
    "Katherine Johnson",
    "Mary Jackson",
    "Dorothy Vaughan",
    "Dorothy Vaughan"
};
```

deduplicate(hiddenFigures);
// hiddenFigures = ["Katherine Johnson", "Mary Jackson", "Dorothy Vaughan”]
The problem is that the above implementation of deduplicate does not work correctly. In particular, it contains three bugs. First, find these bugs by writing test cases that pinpoint potentially erroneous situations in which the provided code might fail, then explain what the problems are, and finally fix those errors in code.

##### 4) Grid Basics (grid.cpp)
Topic: Grids
Write a function names maxRow that takes a grid of non-negative integers(numbers from 0 to infinity) and an in-bounds grid location and returns the maximum value in the row of that grid location.

### If you wanna do this exercise by youself, please visit [https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1244/assignments/1-cpp/](https://web.stanford.edu/class/cs106b/section/section1/)
### If you are looking for testing framework or you want to figure out some header files, please visit https://github.com/zelenski/stanford-cpp-library and thankfully, he is the assignment maker!
### The origin website is here https://web.stanford.edu/class/cs106b/

