#version 130

uniform mat4 mvp;
uniform vec3 points[10];

void main()
{
	gl_Position = mvp * vec4(points[gl_VertexID], 1) ;
}