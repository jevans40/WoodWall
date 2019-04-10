#version 450 core

layout(location = 0) uniform sampler2D texture1;
uniform sampler2D texture2;

in vec2 TexPos;
in vec4 Color;
in flat int TexMap;

out vec4 fragcolor;

void main(){
  vec4 texColor = texture(texture1,vec2(1-TexPos.x, 1-TexPos.y));
  if(false ){//&& (texColor.r != 1 && texColor.g != 2 && texColor.b != 3)){
    if(texColor.a != 0){
		fragcolor = texColor;
	}else{
		discard;
	}
  }
  else{
	fragcolor = vec4(255,255,255,255);
  }
}