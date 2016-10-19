/*

SourecMeter.h


Created by Janine Müller on 05.10.2016


*/

#ifndef ____gpib__
#define ____gpib__

#include <string>

using namespace std;

int ibwrt_string(int ud, string command);
double ibrd_double(int ud);
string ibrd_string(int ud);
int InitializeMaster();



#endif /* defined(____gpib__) */