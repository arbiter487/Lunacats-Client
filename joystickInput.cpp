//
// Created by Tomas Sandstrom on 10/1/18.
// The primary purpose of this function is to detect controller input and send it to the main class
#include <iostream>
#include <GLFW/glfw3.h>


using namespace std;


//Rounds a float rounded to 2 decimal places
float round(float num) {
    int numInt = (int) (num * 100);
    return ((float) numInt)/100;
}


//This function sets the 4 variables given to it to be the input for the joystick
//Note that the second joystick doesn't actually give you any input until you make sure that mode is red on the controller
void getJoystickAxes(float& joy1X, float& joy1Y, float& joy2X, float& joy2Y) {

    //Count will be 0 if no controller is detected
    //The Axes for GLFW_JOYSTICK_1 gets the input for both joysticks on the controller
    int count;
    const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);

    if(count == 0) {
        return;
    }

    //assigning variables
    joy1Y = axes[0];
    joy1X = axes[1];

    joy2X = axes[3];
    joy2Y = axes[4];
}


void processInput() {
    //Printing Joystick axes
    float joy1X, joy1Y, joy2X, joy2Y = 0;
    getJoystickAxes(joy1X,joy1Y,joy2X,joy2Y);
    cout<<"Joystick Input:"<<round(joy1X)<<" "<<round(joy1Y)<<"\t\t"<<round(joy2X)<<" "<<round(joy2Y)<<endl;


    //This function records the input from the 8 numbered buttons, as well as the D-Pad up and Down, to the controller
    //13 is D-Pad up
    //15 is D-Pad down
    //Printing the buttons
    int buttonCount = 0;
    const unsigned char* buttonAxes = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
    cout<<"Button Presses: ";
    for(int i = 0; i < buttonCount; i++){
        if(buttonAxes[i] != '\u0000') {
            cout<<"Y ";
        }
        else {
            cout<<"N ";
        }
    }
    cout<<endl;
}