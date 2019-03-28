#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texPos;
layout(location = 2) in vec4 color;
layout(location = 3) in int texMap;

uniform mat4x4 MVT;

out vec2 TexPos;
out vec4 Color;
out flat int TexMap;




void main(){
	Color = color;
	TexPos = texPos;
	TexMap = texMap;
	gl_Position = MVT * vec4(position.xy,-(((1/position.z)+(1))/(1+1)), 1.0);

/**
// End of VertexShader.vert
 */

}