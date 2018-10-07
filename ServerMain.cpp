//
// Created by Tomas Sandstrom on 10/7/18.
//

using namespace std;

#include <iostream>
#include <unistd.h>
#include "Recieve.cpp"
#include "sendToArduino.cpp"

using namespace std;




int main() {



//This is the main loop for the program
//These 2 lines stop an error message caused by an infinite loop from popping up
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true) {


        //In the future whenever a certain message is recieved a certain command should be sent to the arduino
        getMessage();
        sendCommand();


        //sleeps for some number of nanoseconds (1000 nanoseconds = 1 millisecond)
        usleep(100000);
    }

//Also used for removing error message
#pragma clang diagnostic pop

}