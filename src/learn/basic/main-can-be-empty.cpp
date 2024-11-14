#include <bits/stdc++.h>
using namespace std;

void func()
{
    // implementation
}

int ignore = (func(), 0); // global variable to call func() at the beginning of the program, ignore is initialized with 0
// In this code, the global variable ignore has to be initialized before entering into main() function. Now in order to initialize the global, func() needs to be executed where you can do anything !!

int main() {}