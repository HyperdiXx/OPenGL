precision mediump float;
varying vec3 v_pos;
uniform samplerCube sky;

void main()
{
	gl_FragColor = textureCube(sky, v_pos);
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
