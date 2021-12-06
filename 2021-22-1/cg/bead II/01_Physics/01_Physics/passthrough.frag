#version 130

in vec3 vs_out_pos;

out vec4 fs_out_color;

void main()
{
	fs_out_color = vec4(vs_out_pos, 1);
}