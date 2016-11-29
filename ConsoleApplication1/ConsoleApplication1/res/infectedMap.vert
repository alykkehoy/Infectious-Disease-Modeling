#version 120

attribute  vec3 position;
varying vec4 f_color;

void main(){
	gl_Position = vec4(position.x, position.y, 0, 1.0);

	if(position.z == 0){
		f_color = vec4(1.0f, 1.0f, 1.0f, 1.0);
	}else{
		f_color = vec4(1.0, 1.0f / position.z, 0.0, 1.0);
	}
}