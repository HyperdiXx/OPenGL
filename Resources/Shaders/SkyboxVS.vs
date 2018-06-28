attribute vec3 a_posL;
attribute vec3 uva;
varying vec3 v_color;
varying vec3 v_pos;
uniform mat4 u_matT;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 m_lookAt;
uniform mat4 view;
uniform mat4 u_mvp;


void main()
{	
	//vec4 pos = u_mvp * vec4(a_posL, 1.0);
	gl_Position = u_mvp * vec4(a_posL, 1.0);
	v_pos = a_posL;	
	//v_pos = uva;
}
   