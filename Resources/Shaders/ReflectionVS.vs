attribute vec3 a_posL;
attribute vec2 a_uv;
attribute vec3 a_normal;
varying vec3 normal;
varying vec3 pos;
varying vec3 v_color;
varying vec2 v_uv;
uniform mat4 u_mvp;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;


void main()
{
	//normal = mat3(transpose(inverse(model))) * a_normal;

	gl_Position = u_mvp * vec4(a_posL, 1.0);

	normal = vec3(view * model * vec4(a_normal, 1.0));
	pos = vec3(model * vec4(a_posL, 1.0));

	//v_uv = a_uv;	
	//v_color = a_color;
}
   