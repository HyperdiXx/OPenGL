precision mediump float;
varying vec3 v_color;
varying vec2 v_uv;
uniform sampler2D u_s_texture;
uniform sampler2D text1;
uniform sampler2D text2;
uniform sampler2D text3;

uniform vec3 camPos;


void main()
{
	vec4 tex1, tex2, tex3, res, tex4;

	float fogRange = 100.0;
	float fogStart = 10.0;
	vec4 fogColor = vec4(0.5, 0.5, 0.5, 1.0);

	float dist = length(fogStart - camPos);
	float fog_factor = (fogRange - dist) / (fogRange - fogStart);
	fog_factor = clamp(fog_factor, 0.0, 1.0);

	//outputColor = mix(fog_colour, shadedColor, fog_factor);

	tex1 = texture2D(u_s_texture, v_uv); //grass
	tex2 = texture2D(text1, v_uv); // dirt
	tex3 = texture2D(text2, v_uv);	//rock
	tex4 = texture2D(text3, v_uv); //blendmap

	vec4 terrainColor = (tex1 * tex4.x + tex2 * tex4.y + tex3 * tex4.z) / (tex4.x + tex4.y + tex4.z);

	vec4 final = terrainColor * vec4(v_color, 1.0);
	//vec4 f = mix(terrainColor, fogColor, fog_factor);

	//res = mix(tex1, tex2, tex3);
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);

	//float lerpval = clamp(fogStart - camPos - fogStart/,0.0, 1.0);
	
	//float fog_coord = (gl_FragCoord.z / gl_FragCoord.w) / 2000.0;
	//float fog = fog_coord * denst;
	//vec4 c = v_color * pixel;

	//float d = length(fogStart - campos);
	//float factor = clamp(fog, 0.0f, 1.0f);


	//gl_FragColor = mix(terrainColor, fogColor, fog_factor);
	//gl_FragColor = vec4(0.0, 0.3, 0.0, 1.0);
	gl_FragColor = terrainColor;
}
