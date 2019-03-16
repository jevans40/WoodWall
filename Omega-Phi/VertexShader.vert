#version 450 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texPos;
layout(location = 2) in vec4 color;
layout(location = 3) in int texMap;


out vec2 TexPos;
out vec4 Color;
out int TexMap;

void main(){
	Color = color;
	TexPos = texPos;
	TexMap = texMap;
	gl_Position = vec4(position, 0.0, 1.0);

/**
// End of VertexShader.vert
 */

}