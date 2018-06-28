attribute vec3 a_posL;
attribute vec3 a_color;
attribute vec2 a_uv;
varying vec3 v_color;
varying vec2 v_uv;

uniform mat4 u_mvp;


void main()
{
	gl_Position = u_mvp * vec4(a_posL, 1.0);
	v_uv = a_uv * 2.0;	
	v_color = a_color;
}
   