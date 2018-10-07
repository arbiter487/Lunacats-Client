//
// Created by Tomas Sandstrom on 10/7/18.
//

#include <iostream>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include "joystickInput.cpp"
#include "sendToArduino.cpp"

using namespace std;




int main() {

    //GLFW needs to be started to get controller input
    cout << "Starting GLFW" << endl;
    if (!glfwInit())
    {
        cout << "GLFW Failed To Start" << endl;
    }

//This is the main loop for the program
//These 2 lines stop an error message caused by an infinite loop from popping up
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true) {


        //In the future whenever a certain input is processed a command should be sent to the arduino
        processInput();
        sendCommand();


        //sleeps for some number of nanoseconds (1000 nanoseconds = 1 millisecond)
        usleep(100000);
    }

//Also used for removing error message
#pragma clang diagnostic pop

}