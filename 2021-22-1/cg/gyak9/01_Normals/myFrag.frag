#version 140

// pipeline-ból bejövő per-fragment attribútumok
in vec3 vs_out_pos;
in vec3 vs_out_norm;
in vec2 vs_out_tex;

// kimenő érték - a fragment színe
out vec4 fs_out_col;

// irány fényforrás: fény iránya
// Mi a bejövő fénysugarak iránya?
uniform vec3 light_dir = vec3(-1,-1,-1);

// fénytulajdonságok: ambiens, diffúz, spekuláris
// Milyen szinű a fény?
// Külön-külön minden fénykomponensre.
uniform vec3 La = vec3(0.4, 0.4, 0.4);
uniform vec3 Ld = vec3(0.4, 0.6, 0.6);
uniform vec3 Ls = vec3(0.9, 0.9, 0.9);

// anyagtulajdonságok: ambiens, diffúz, spekuláris
// Melyik színt mennyire veri vissza a felület?
// Külön-külön minden fénykomponensre.
// --> Tehát lehet, hogy a tárgyunk más színnel csillan, mint amilyen a diffúz színe.
uniform vec3 Ka = vec3(0.2, 0.4, 0.6);
uniform vec3 Kd = vec3(0.2, 0.4, 0.6);
uniform vec3 Ks = vec3(0.4, 0.8, 1.0);

// Kamera helyzete C++-ból lekérve.
uniform vec3 camera_pos;

//uniform sampler2D texImage;

void main()
{	
	//
	// ambiens szín számítása
	//
	// Az ambiens fény nem függ semmitől, egy állandó megvilágítást ad csak a felületeknek.
	// Célja: az árnyékban lévő részek ne legyenek teljesen feketék.
	vec3 ambient = La * Ka;

	//
	// diffúz szín számítása
	//	
	/* segítség:
	    - normalizálás: http://www.opengl.org/sdk/docs/manglsl/xhtml/normalize.xml
	    - skaláris szorzat: http://www.opengl.org/sdk/docs/manglsl/xhtml/dot.xml
	    - clamp: http://www.opengl.org/sdk/docs/manglsl/xhtml/clamp.xml
	*/

	// A felület normálvektora az adott pontban
	vec3 N = normalize(vs_out_norm);
	// A bejövő fénysugarak irányának ellentéte: a felületi pontból a "fény felé" mutató irány.
	// Párhuzamos sugarak esetén (irányfényforrás) nincs a fényforrásnak pozíciója.
	// Pontfényforrás esetén pl:
	// vec3 L = normalize(point_light_pos - vs_out_pos);
	vec3 L = normalize(-light_dir);
	// A diffúz komponenst az N és L skaláris szorzata határozza meg.
	// Fontos: figyelünk hogy ne legyen negatív a dot(N, L) értéke, 0-ra korlátozzuk.
	vec3 diffuse = clamp(dot(N, L), 0.0, 1.0) * Ld * Kd;

	//
	// fényfoltképző szín
	//
	/* segítség:
		- reflect: http://www.opengl.org/sdk/docs/manglsl/xhtml/reflect.xml
				reflect(beérkező_vektor, normálvektor);
		- pow: http://www.opengl.org/sdk/docs/manglsl/xhtml/pow.xml
				pow(alap, kitevő);
	*/

	// A felületi pontból a kamerába mutató irányvektor.
	// = nézeti irány
	vec3 V = normalize(camera_pos - vs_out_pos);
	// A bejövő fényirányt (-L) egy N normálvektorú felületről "visszapattintjuk".
	// Így megkapjuk az ún. tökéletes visszaverődési irányt.
	vec3 R = reflect(-L, N);
	vec3 specular = pow(clamp(dot(V, R), 0, 1), 16) * Ls * Ks; 
	
	//
	// a fragment végső színének meghatározása
	//

	fs_out_col = vec4(ambient + diffuse + specular, 1);

	// felületi normális
	// fs_out_col = vec4(vs_out_norm, 1);



	// textúrával
	//vec4 textureColor = texture(texImage, vs_out_tex);
	//fs_out_col = vec4(ambient + diffuse + specular, 1) * textureColor;
}
