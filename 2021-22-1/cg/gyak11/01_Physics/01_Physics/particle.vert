#version 130

in vec3 vs_in_pos;
in vec3 vs_in_vel;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vs_in_pos, 1);

	// így írható felül a pontprimitívek mérete (feltéve ha a kliens oldalon van egy glEnable(GL_PROGRAM_POINT_SIZE);)
	//gl_PointSize = 5;
}