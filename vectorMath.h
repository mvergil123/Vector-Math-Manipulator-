
#ifndef VECTOR_MATH_H

#define VECTOR_MATH_H

// angle input function
void angle_input(float *ptrAngle);
    // prompts the user to enter an angle and updates the parameter. Include units


//angle to vector function
void angle_to_vector(float angle,float *ptrRESUVx, float *ptrRESUVy);
    // Converts an angle with the positive x-axis to the resultant vector on the unit circle.


// point input function
void point_input(float *ptrXiCord, float *ptrYiCord);
    // prompts the user to enter the (x,y) coordinate and updates the parameters


// vector input function
void vector_input(float *ptrVxCord, float *ptrVyCord);
    // prompts the user to enter the <x,y> coordinate and updates the parameters


// vector normalize function
void vector_normalize(float VxCord, float VyCord, float *ptrNORMx, float *ptrNORMy);
    // Normalizes the input vector setting the corresponding pointer parameters to the output normalized vector


// vector to angle function
float vector_to_angle(float VxCord, float Vycord);
    // Determines the angle of the vector forms
    // Angle is computed by taking the arctan of y/x
    // Make sure to properly handle edge cases
    // OUTPUT: A float corresponding to the angle the vector forms with the positive x-axis


// rotate point by vector function
void rotate_point_by_vector(float PxCord, float PyCord, float VxCord, float VyCord, float *ptrROTpx, float *ptrROTpy);
    // performs the roation by multiplying complex numbers
    // form a complex number using the point (px, py) coordinate: px + pyi
    // form a second complex number using the vector <vx, vy> coordinate: vx + vyi
    // multiply these two complex numbers to compute the resultant point:
    // (px + pyi) * (vx + vyi) 
    // = (pxvx - pyvy) + (pxvy + pyvx)i
    // can be converted back to a point:
    // (pxvx - pyvy, pxvy + pyvx)

// menu function
int prompt_menu();



#endif


