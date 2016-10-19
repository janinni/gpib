/*

SourceMeter.cpp


Created by Janine Müller on 05.10.2016

*/

#include <gpib/ib.h>
#include <gpib/gpib_user.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

// GPIB stuff //
int ibwrt_string(int ud, string command){

	command = command + "\n";
	int returnval = ibwrt(ud, command.c_str(), command.size());

	return returnval;
}

double ibrd_double(int ud){

	char read[40];
	int returnval = ibrd(ud, read, 40);

	//cout << read << endl;

	stringstream ss(read);
	double readvalue = 0;
	ss >> readvalue;

	return readvalue;
}

string ibrd_string(int ud){

	char read[40];
	int returnval = ibrd(ud, read, 40);

	//cout << read << endl;

	stringstream ss(read);

	return ss.str();

}

int InitializeMaster(){

	// The configuration file must contain one or more 'interface' entries, and can contain zero or more 'device' entries. 
	//'device' entries are only required if you wish to open device descriptors with ibfind() instead of using ibdev().

	// -t, --board-type board_type
	//Set board type to board_type. driver gpib adapter: ni_usb_b
	cout << "\"gpib_config -t ni_usb_b\"" << endl;
	int returnval = system("gpib_config -t ni_usb_b");

	// ibfind() returns a board or device descriptor based on the information found in the configuration file.
	// This is the gpid adapter
	// interface {
	//         minor = 0       /* board index, minor = 0 uses /dev/gpib0, minor = 1 uses /dev/gpib1, etc. */
	//         board_type = "ni_usb_b" /* type of interface board being used */
	//         name = "violet" /* optional name, allows you to get a board descriptor using ibfind() */
	//         pad = 0 /* primary address of interface             */
	//         sad = 0 /* secondary address of interface           */
	//         timeout = T3s   /* timeout for commands */

	//         eos = 0x0a      /* EOS Byte, 0xa is newline and 0xd is carriage return */
	//         set-reos = yes  /* Terminate read if EOS */
	//         set-bin = no    /* Compare EOS 8-bit */
	//         set-xeos = no   /* Assert EOI whenever EOS byte is sent */
	//         set-eot = yes   /* Assert EOI with last byte on writes */

	// /* settings for boards that lack plug-n-play capability */
	//         base = 0        /* Base io ADDRESS                  */
	//         irq  = 0        /* Interrupt request level */
	//         dma  = 0        /* DMA channel (zero disables)      */

	// /* pci_bus and pci_slot can be used to distinguish two pci boards supported by the same driver */
	// /*      pci_bus = 0 */
	// /*      pci_slot = 7 */

	//         master = yes    /* interface board is system controller */
	// }
	int masterUd=ibfind("violet");
	if(iberr==0){
		cout << "masterUd= " << masterUd << endl;
		return masterUd;

	}
	else
	{  
	  cout << "Initialization FAILED! Could not find Master: " << returnval << endl;
	  exit(EXIT_FAILURE);
	}

}















