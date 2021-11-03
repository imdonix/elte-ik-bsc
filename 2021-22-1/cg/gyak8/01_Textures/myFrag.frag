#version 140

// pipeline-ból bejövő per-fragment attribútumok
in vec3 vs_out_pos;
in vec2 vs_out_tex0;

// kimenő érték - a fragment színe
out vec4 fs_out_col;

uniform sampler2D texImage;
uniform sampler2D texImage2;

void main()
{
	if(vs_out_tex0.x < .5f && vs_out_tex0.y > .5f || vs_out_tex0.y < .5f && vs_out_tex0.x > .5f)
		fs_out_col =  texture(texImage2, vs_out_tex0);
	else
		fs_out_col =  texture(texImage, vs_out_tex0);
}