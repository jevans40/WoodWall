#version 450 core

in vec2 TexPos;
in vec4 Color;
in flat int TexMap;

out vec4 fragcolor;

void main(){
  if(TexMap != -1){
	fragcolor = vec4(Color);
  }
  else{
	fragcolor = vec4(Color);
  }
}