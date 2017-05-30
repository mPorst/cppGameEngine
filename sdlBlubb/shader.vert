#version 330

in vec3 Position;

uniform mat4 trans;

void main(void)
{

	gl_Position.xy = Position.xy;

	gl_Position.z = 0.0;

	gl_Position.w = 1.0;

}