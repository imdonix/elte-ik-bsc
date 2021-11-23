#version 140

in vec3 vs_out_pos;
in vec3 vs_out_norm;
in vec2 vs_out_tex;

out vec4 fs_out_col;

// irány fényforrás: fény iránya
// Mi a bejövő fénysugarak iránya?
uniform vec3 light_dir = vec3(-1,-1,-1);

uniform vec3 La = vec3(1, 1, 0.85);
uniform vec3 Ld = vec3(1, 1, 0.85);
uniform vec3 Ls = vec3(1, 1, 0.85);


uniform vec3 Ka = vec3(0.1, 0.1, 0.1);
uniform vec3 Kd = vec3(1, 1, 1);
uniform vec3 Ks = vec3(2, 2, 2);

// Kamera helyzete C++-ból lekérve.
uniform vec3 camera_pos;

uniform sampler2D texImage;
uniform sampler2D maskImage;

void main()
{	
	vec3 ambient = La * Ka;

	vec3 N = normalize(vs_out_norm);
	vec3 L = normalize(-light_dir);
	vec3 diffuse = clamp(dot(N, L), 0.0, 1.0) * Ld * Kd;

	vec3 V = normalize(camera_pos - vs_out_pos);
	vec3 R = reflect(-L, N);
	vec3 specular = pow(clamp(dot(V, R), 0, 1), 32) * Ls * Ks;


	vec4 maskColor = texture(maskImage, vs_out_tex);
	vec4 textureColor = texture(texImage, vs_out_tex);

	
	if(maskColor.x < .1F)
		fs_out_col = vec4(ambient + diffuse + specular, 1) * textureColor;
	else
		fs_out_col = vec4(ambient + diffuse, 1) * textureColor;
}
