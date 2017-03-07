#version 400


in vec3 position;
in mat4 fullTransformMatrix;
in vec3 color;

out vec3 fragmentColor;

void main(){
       vec4 p = vec4(position, 1.0);
	   vec4 transformedPosition=fullTransformMatrix*p;
	   gl_Position=transformedPosition;
		fragmentColor=color;
}

