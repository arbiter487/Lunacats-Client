#include <iostream>
#include <GLFW/glfw3.h>
#include <unistd.h>

using namespace std;



int main() {


    cout << "Starting GLFW" << endl;
    if (!glfwInit())
    {
        cout << "GLFW Failed To Start" << endl;
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true) {
        int count;
        const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);

        cout<<"Count of axes:"<<count-1<<" axes are:";
        for(int i =0; i < count; i++){
            cout<<axes[i]<< " ";
        }
        cout<<endl;

        usleep(500000);
    }
#pragma clang diagnostic pop


}

