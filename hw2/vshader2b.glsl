#version 330

in vec2 a_Position;         // attribute variable: position vector
in vec3 a_Color;            // attribute variable: color vector

out vec4 v_Color;           // varying variable for passing color to fragment shader

// NOTE: modelview is for transformations
uniform mat4 u_Modelview;   // uniform variable for passing modelview  matrix
uniform mat4 u_Projection;  // uniform variable for passing projection matrix
uniform float u_Theta;      // Theta parameter
uniform int u_Twist;        // Twist flag

// XXX: Code written by PB 2019
vec2 rotTwist(vec2 p) {
    float d_Theta = u_Theta * sqrt(p.x*p.x + p.y*p.y);  // distance scaler
    float sinTheta = sin(d_Theta);    // find the sine of distance*theta 
    float cosTheta = cos(d_Theta);    // find the cosing of distance*theta

    //  create and return a new vector containing the new positions based on the
    //  rotation and distance from the origin
    vec2 q = vec2(p.x*cosTheta - p.y*sinTheta, p.x*sinTheta + p.y*cosTheta);
    return q;
}

void main() 
{
    if (bool(u_Twist) == true) {
        vec2 twistPos = rotTwist(a_Position);
        gl_Position = u_Projection * vec4(twistPos, 0, 1);
    } else {
        gl_Position = u_Projection * u_Modelview * vec4(a_Position, 0, 1);
    }

    // pass color on to fragment shader:
    v_Color = vec4(a_Color, 1.0);
}
// XXX: End PB Code
