#version 330

in vec3 Position;

uniform mat4 mvp;

void main(void)
{
	vec4 positionVector = vec4(Position, 1.0);
	
	gl_Position = mvp*positionVector;
}