#version 400

out vec4 outColor;
in vec3 worldNormal;
in vec3 worldPosition;
in vec3 fragmentColor;
uniform vec3 ambientLight;
uniform vec3 worldLightPosition;

void main(){

       vec3 lightVector=normalize(worldLightPosition-worldPosition);
       float diffuseBrightness=dot(lightVector,normalize(worldNormal));
       vec3 diffuseLight=vec3(diffuseBrightness,diffuseBrightness,diffuseBrightness);
       vec3 color=fragmentColor*clamp(diffuseLight,0,1)+fragmentColor*ambientLight;
       outColor = vec4(color, 1.0);
}