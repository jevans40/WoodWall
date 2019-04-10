#version 450 core

layout(location = 0) uniform sampler2D texture1;
uniform sampler2D texture2;

in vec2 TexPos;
in vec4 Color;
in flat int TexMap;

out vec4 fragcolor;

void main(){
  vec4 texColor = texture(texture1,vec2(1-TexPos.x, 1-TexPos.y));

  if(TexMap > -1 && (texColor.r != float(1)/255 && texColor.g != float(2)/255 && texColor.b != float(3)/255)){
    if(texColor.a != 0){
		fragcolor = texColor;
	}else{
		discard;
	}
  }
  else{
	fragcolor = vec4(Color);
  }
}