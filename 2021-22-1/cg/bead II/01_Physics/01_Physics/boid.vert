#version 130

in vec3 vs_in_pos;
in vec3 vs_in_vel;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vs_in_pos, 1);
	gl_PointSize = 2;
}