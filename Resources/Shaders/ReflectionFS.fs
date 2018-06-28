precision mediump float;
varying vec3 v_color;
varying vec2 v_uv;
varying vec3 normal;
varying vec3 pos;

uniform samplerCube sky;
uniform vec3 camPos;

void main()
{
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);

	vec3 I = normalize(pos - camPos);
	vec3 Ref = reflect(I, normalize(normal));

	//gl_FragColor = texture2D(u_s_texture, v_uv);

	gl_FragColor = vec4(textureCube(sky, Ref).rgb, 1.0);
}
