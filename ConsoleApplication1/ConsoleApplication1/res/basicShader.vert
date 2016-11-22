#version 120

attribute  vec3 position;
varying vec4 f_color;

void main(){
	gl_Position = vec4(position.x, position.y, 0, 1.0);
	if(position.z == 'S'){
		f_color = vec4(0.0, 1.0, 0.0, 1.0);
	} else if(position.z == 'I'){
		//f_color = vec4(1.0, 0.0, 0.0, 1.0);
	} else if(position.z == 'E'){
		f_color = vec4(1.0, 1.0, 1.0, 1.0);
	} else {
		f_color = vec4(0.0, 0.0, 1.0, 1.0);
	}
}