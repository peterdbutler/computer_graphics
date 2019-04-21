#version 330
// Written by: Peter Butler, 2019

in vec2 a_Position;         // attribute variable
uniform mat4 u_Projection;  // uniform variable for passing projection matrix

void main() 
{
    // XXX: PB Code:
    //  multiply each vertex by the projection matrix
    gl_Position = u_Projection* vec4(a_Position, 0, 1);
    // XXX: End PB Code
}
