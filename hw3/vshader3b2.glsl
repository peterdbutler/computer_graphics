#version 330
// TODO: WIRE_SHADER

in vec2 a_Position;
in vec3 a_Color;                // TODO: Needed???

uniform mat4 u_Modelview;       // TODO: u_View       == VIEW
uniform mat4 u_Projection;      // TODO: u_Projection == PROJ

out vec3 vColor;                // TODO: Needed???

void main() 
{
	// TODO: PUT YOUR CODE HERE
    gl_Position = u_Projection * u_Modelview * vec4(a_Position, 0, 1);
    vColor = a_Color;
}
