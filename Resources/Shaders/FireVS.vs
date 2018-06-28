attribute vec3 a_posL;
attribute vec3 a_color;
attribute vec2 a_uv;
varying vec2 utex;
uniform mat4 u_mvp;


void main()
{
	gl_Position = u_mvp * vec4(a_posL, 1.0);
	utex = a_uv;	
}
   