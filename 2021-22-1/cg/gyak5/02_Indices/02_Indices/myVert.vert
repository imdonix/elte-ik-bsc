#version 130

// VBO-ból érkező változók
in vec3 vs_in_pos;
in vec3 vs_in_col;

// a pipeline-ban tovább adandó értékek
out vec3 vs_out_col;

// shader külső paraméterei - most a három transzformációs mátrixot egyben vesszük át
uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4( vs_in_pos, 1 );
	vs_out_col = vs_in_col;
}