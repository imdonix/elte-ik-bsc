#version 130

uniform vec4 color = vec4(1);

out vec4 fs_out_color;

void main()
{
	fs_out_color = color;
}