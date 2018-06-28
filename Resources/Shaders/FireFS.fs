precision mediump float;
varying vec2 utex;
uniform sampler2D displacement;
uniform sampler2D texcoord;
uniform sampler2D alpha;
uniform float time;

void main()
{
	float factor = 0.2;
	vec2 disp = texture2D(alpha, vec2(utex.x, utex.y + time)).rg;
	vec2 offset = (2.0 * disp - 1.0) * factor;

	vec2 new_uv = utex + offset;

	vec4 AlphaValue = texture2D(texcoord, utex);

	gl_FragColor = texture2D(displacement, new_uv) * vec4(1.0, 1.0, 1.0, AlphaValue.r);
}
