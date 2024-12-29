/* CSCI 200: Lab XX (2B): XXXX 
(This program utilizes pointers to perform complex vector math
 *
 * Author: XXXX (Mike Vergil)
 *
 * More complete description here...
 * When the program runs, a menu is prompted which allows the user to input their coordinates 
 *  and how they want to manipulate their coordinate (i.e. rotate over an angle, etc).
*/
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include "vectorMath.h"


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{

// initializing the pointers and values 
    // initial coordinates and their pointers 
    float xiCord(0), yiCord(0);
    float *ptrXiCord = &xiCord;
    float *ptrYiCord = &yiCord;

    // point coordinates and their pointers
    float xCord(0), yCord(0);
    float *ptrXCord = &xCord;
    float *ptrYCord = &yCord;

    // angle var and ptr
    float angle(0);
    float *ptrAngle = &angle;

    //vector coordinates and their pointers
    float VxCord(0), VyCord(0);
    float *ptrVxCord = &VxCord;
    float *ptrVyCord = &VyCord;

    // initial vector coordinates and their pointers
    float VxiCord(0), VyiCord(0);
    float *ptrVxiCord = &VxiCord;
    float *ptrVyiCord = &VyiCord;

    // declaring a condition for the while loop
    int userChoice = 1;


// beginning of while loop
while (userChoice != 0)
{
    // prompt the menu
    userChoice = prompt_menu();


    if (userChoice == 1) // enter point coordinate
    {
        point_input(ptrXiCord, ptrYiCord);

        *ptrXCord = *ptrXiCord; // passing the initial point values x
        *ptrYCord = *ptrYiCord; // passing the initial point values y

        
    }
    else if (userChoice == 2) // rotate point by angle 
    {
        angle_input(ptrAngle); // get the angle
        angle_to_vector(angle, ptrVxCord, ptrVyCord); //convert the angle into a vector
        vector_normalize(VxCord, VyCord, ptrVxCord, ptrVyCord); // normalize the vector
        rotate_point_by_vector(xiCord, yiCord, VxCord, VyCord, ptrVxCord, ptrVyCord); // rotate the point by the vector and PBP the final coordinates.
        // print the output
        cout << "The point ("<<xiCord<< " , "<<yiCord<<") rotated by "<<angle<<" degrees is now at ("<<VxCord<<" , "<<VyCord<<")\n";

        // changing the value of the initial points
        *ptrXCord = VxCord; 
        *ptrYCord = VyCord; 
    }
    else if (userChoice == 3) // rotate point by vector 
    {
        vector_input(ptrVxiCord, ptrVyiCord); // get the inital vector

        *ptrVxCord = *ptrVxiCord;// passing the value of the initial vector x
        *ptrVyCord = *ptrVyiCord; // passing the value of the initial vector y

        vector_normalize(VxCord, VyCord, ptrVxCord, ptrVyCord); // normalize the vector
        rotate_point_by_vector(xCord, yCord, VxCord, VyCord, ptrVxCord, ptrVyCord); // rotate the point by the vector and PBP the final coordinates.

        float vAngle = vector_to_angle(VxiCord,VyiCord); // get the new angle

        // print the output
        cout << "The point ("<<xCord<< " , "<<yCord<<") rotated by the vector <"<<VxiCord<< " , "<<VyiCord<<"> ("<<vAngle<<" degrees) is now at ("<<VxCord<<" , "<<VyCord<<")\n";

        // changing the value of the initial points
        *ptrXiCord = VxCord; 
        *ptrYiCord = VyCord; 


    }
    else if (userChoice > 3) 
    {
        // invalid option, choose again   
        cout << "Invalid selection, enter a valid option\n";
        

    }

}

    // input was 0 and the while loop terminated
    cout<< "Goodbye!\n";


}

