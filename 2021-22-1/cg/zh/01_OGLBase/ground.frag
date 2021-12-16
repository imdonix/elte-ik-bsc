#version 330 core

// pipeline-ból bejövõ per-fragment attribútumok
in vec3 vs_out_pos;
in vec3 vs_out_norm;
in vec2 vs_out_tex;

out vec4 fs_out_col;

// irány fényforrás: fény iránya
uniform vec3 light_dir = vec3(0.2, -0.6, 0.5);

// fénytulajdonságok: ambiens, diffúz, ...
uniform vec3 La = vec3(0.1, 0.1, 0.1);
uniform vec3 Ld = vec3(0.7, 0.7, 0.6);

uniform sampler2D texImage;
uniform sampler2D texImageWin;

uniform vec3 timer = vec3(.5);

void main()
{

	vec3 ambient = La;

	vec3 normal = normalize(vs_out_norm);
	vec3 to_light = normalize(-light_dir);
	
	float cosa = clamp(dot(normal, to_light), 0, 1);

	vec3 diffuse = cosa*Ld;

	vec4 mixed = (texture(texImage, vs_out_tex) * timer.x) + (texture(texImageWin, vs_out_tex) * (1 - timer.x));

	fs_out_col = vec4(ambient + diffuse, 1) * mixed;
}