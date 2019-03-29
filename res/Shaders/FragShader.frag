#version 450 core

layout(location = 0) uniform sampler2D texture1;
uniform sampler2D texture2;

in vec2 TexPos;
in vec4 Color;
in flat int TexMap;

out vec4 fragcolor;

void main(){

  if(TexMap > -1 && TexMap < 32){
    if(texture(texture1,vec2(1-TexPos.x,1-TexPos.y)).a != 0){
		fragcolor = texture(texture1,vec2(1-TexPos.x, 1-TexPos.y));
	}else{
		discard;
	}
  }
  else{
	fragcolor = vec4(Color);
  }
}