precision mediump float;
varying vec3 v_color;
varying vec2 v_uv;
uniform sampler2D u_s_texture;

void main()
{
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	gl_FragColor = texture2D(u_s_texture, v_uv);
}
