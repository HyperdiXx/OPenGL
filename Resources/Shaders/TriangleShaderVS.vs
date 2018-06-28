attribute vec3 a_posL;
attribute vec3 a_color;
attribute vec2 a_uv;
varying vec3 v_color;
varying vec2 v_uv;
uniform mat4 u_matT;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 m_lookAt;
uniform mat4 view;
uniform mat4 u_mvp;


void main()
{
	//gl_Position = projection * m_lookAt * model * vec4(a_posL, 1.0);

	gl_Position = u_mvp * vec4(a_posL, 1.0);

	//gl_Position = model * m_lookAt * projection * vec4(a_posL, 1.0);
	//gl_Position = projection * view * model * vec4(a_posL, 1.0);
	//gl_Position = vec4(a_posL, 1.0);

	v_uv = a_uv;	
	v_color = a_color;
}
   