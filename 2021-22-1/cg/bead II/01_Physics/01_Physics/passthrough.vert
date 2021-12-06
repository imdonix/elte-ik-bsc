#version 130

in vec3 vs_in_pos;

out vec3 vs_out_pos;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vs_in_pos, 1) ;
	vs_out_pos	= normalize(vs_in_pos);
}