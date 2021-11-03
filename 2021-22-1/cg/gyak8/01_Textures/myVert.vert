#version 140

// VBO-ból érkező változók
in vec3 vs_in_pos;
in vec2 vs_in_tex0;

// a pipeline-ban tovább adandó értékek
out vec3 vs_out_pos;
out vec2 vs_out_tex0;

// shader külső paraméterei
uniform mat4 MVP;

uniform mat4 world;

void main()
{
	gl_Position = MVP * vec4( vs_in_pos, 1 );
	vs_out_pos  = (world * vec4( vs_in_pos, 1 )).xyz;
	vs_out_tex0 = vs_in_tex0;
}
