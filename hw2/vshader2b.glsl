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
    float d = sqrt(p.x*p.x + p.y*p.y);
    float sinTheta = sin(d*u_Theta);
    float cosTheta = cos(d*u_Theta);

    vec2 q = vec2(p.x*cosTheta - p.y*sinTheta, p.x*sinTheta + p.y*cosTheta);
    return q;
}

void main() 
{
    if (bool(u_Twist) == true) {
        vec2 twistPos = rotTwist(a_Position);
        gl_Position = u_Projection * u_Modelview * vec4(twistPos, 0, 1);
    } else {
        gl_Position = u_Projection * u_Modelview * vec4(a_Position, 0, 1);
    }

    // pass color on to fragment shader:
    v_Color = vec4(a_Color, 1.0);
}
// XXX: End PB Code
