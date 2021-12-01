#version 130

in vec4 vs_out_color;

out vec4 fs_out_color;

void main()
{
	fs_out_color = vs_out_color;
}