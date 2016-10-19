/*

gpibMain.cpp

Created by Janine Müller on 05.10.2016

*/

#include <iostream>

#include "gpib.h"



int main(int argc, char const *argv[])
{

	int masterUD = InitializeMaster();

	cout << masterUD << endl;

	return 0;
}
