
// include section
#include "vectorMath.h"
#include <iostream>
#include <cmath>

using namespace std;


// angle input function
void angle_input(float *ptrAngle) 
    // prompts the user to enter an angle and updates the parameter. Include units
{
    cout << "Enter angle in degrees: ";
    cin >> *ptrAngle;
    cout << "\n";
}


//angle to vector function
void angle_to_vector(float angle,float *ptrRESUVx, float *ptrRESUVy) 
    // Converts an angle with the positive x-axis to the resultant vector on the unit circle.
{
    angle = angle * (M_PI/180);
    *ptrRESUVx = cos(angle);
    *ptrRESUVy = sin(angle);

}

// point input function
void point_input(float *ptrXiCord, float *ptrYiCord) 
    // prompts the user to enter the (x,y) coordinate and updates the parameters
{
    cout << "Enter point x coordinate: ";
    cin >> *ptrXiCord;
     cout << "\n";
    cout << "Enter point y coordinate: ";
    cin >> *ptrYiCord;
    cout << "\n";

}

// vector input function
void vector_input(float *ptrVxCord, float *ptrVyCord) 
    // prompts the user to enter the <x,y> coordinate and updates the parameters
{
    cout << "Enter vector x coordinate: ";
    cin >> *ptrVxCord;
    cout << "\n";
    cout << "Enter vector y coordinate: ";
    cin >> *ptrVyCord;
    cout << "\n";

}

// vector normalize function
void vector_normalize(float VxCord, float VyCord, float *ptrNORMx, float *ptrNORMy) 
    // Normalizes the input vector setting the corresponding pointer parameters to the output normalized vector
{
     // Calculate the length of the input vector
    float length = sqrt(VxCord * VxCord + VyCord * VyCord);

    // Check for division by zero
    if (length != 0) {
        // Normalize the vector
        *ptrNORMx = VxCord / length;
        *ptrNORMy = VyCord / length;
    } else {
        // If the input vector is already a zero vector, set the output to (0, 0)
        *ptrNORMx = 0;
        *ptrNORMy = 0;
    }
    
}

// vector to angle function
float vector_to_angle(float VxCord, float VyCord)
{
    // Determines the angle of the vector forms
    // Angle is computed by taking the arctan of y/x
    // Make sure to properly handle edge cases
    // OUTPUT: A float corresponding to the angle the vector forms with the positive x-axis

      // Check for special cases
    if (VxCord == 0 && VyCord == 0) {
        // The vector is at the origin
        return 0.0;
    } else if (VxCord == 0) {
        // The vector is along the y-axis
        if (VyCord > 0) {
            return 90.0;
        } else {
            return -90.0;
        }
    } else {
        // Calculate angle using arctan by transforming the value back into degrees
        float angle = atan(VyCord / VxCord) * 180.0 / M_PI;

        // Adjust angle for quadrant
        if (VxCord < 0) {
            // Quadrant II or III
            angle += 180.0;
        } else if (VyCord < 0) {
            // Quadrant IV
            angle += 360.0;
        }
        return angle;
    }



}

// rotate point by vector function
void rotate_point_by_vector(float PxCord, float PyCord, float VxCord, float VyCord, float *ptrROTpx, float *ptrROTpy)
{
    // performs the roation by multiplying complex numbers
    // form a complex number using the point (px, py) coordinate: px + pyi
    // form a second complex number using the vector <vx, vy> coordinate: vx + vyi
    // multiply these two complex numbers to compute the resultant point:
    // (px + pyi) * (vx + vyi) 
    // = (pxvx - pyvy) + (pxvy + pyvx)i
    // can be converted back to a point:
    // (pxvx - pyvy, pxvy + pyvx)

    *ptrROTpx = (PxCord * VxCord) - (PyCord * VyCord);
    *ptrROTpy = (PxCord * VyCord) + (PyCord * VxCord);

}


int prompt_menu()
{
    // prompt the menu
    cout << "Menu:\n";
    cout << "\n 1) Enter point (x,y) coordinate\n";
    cout << "\n 2) Rotate point by angle\n";
    cout << "\n 3) Rotate point by vector\n";
    cout << "\n 0) Quit\n";

    // getting the user's choice
    int userChoice;
    cout << "Choice: ";
    cin >> userChoice;
    cout << "\n";

    return userChoice;
}

