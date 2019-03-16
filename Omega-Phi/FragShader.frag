#version 450 core

in vec2 TexPos;
in vec4 Color;
in int TexMap;

out vec4 fragcolor;

void main(){
  if(TexMap != -1){
	
  }
  else{
	fragcolor = vec4(Color.x, Color.y, Color.z, Color.w);
  }
}