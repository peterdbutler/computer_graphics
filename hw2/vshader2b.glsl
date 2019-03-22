#version 330

in vec2 a_Position;         // attribute variable: position vector
in vec3 a_Color;            // attribute variable: color vector

out vec4 v_Color;           // varying variable for passing color to fragment shader

// NOTE: modelview is for transformations
uniform mat4 u_Modelview;   // uniform variable for passing modelview  matrix
// NOTE: projection is for displaying the world coords?
uniform mat4 u_Projection;  // uniform variable for passing projection matrix
uniform float u_Theta;      // Theta parameter
uniform int u_Twist;        // Twist flag

void main() 
{
    // XXX: Code written by PB 2019
    // u_Modelview = u_ModelView * cos(m_theta);
    
    // This should be correct!
    gl_Position = u_Projection * u_Modelview * vec4(a_Position, 0, 1);

    // pass color on to fragment shader:
    // TODO: issues with the color
    v_Color = vec4(1.0, 0, 0, 1);
    //v_Color = vec4(a_Color, 1);

    // XXX: End PB Code
}
