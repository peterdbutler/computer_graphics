#version 330
// XXX: Full code written by PB

in vec4 v_Color;      // varying variable for passing color from vertex shader
out vec4 fragColor;

void main() 
{
    fragColor = v_Color;
}
