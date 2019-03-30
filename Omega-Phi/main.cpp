#include <Omega-Phi/OPInclude.h>
#include "House.h"
#include "StringSprite.h"
std::vector <std::string> House::files;
OP::initializer House::init = OP::initializer(House::setFiles);

std::string lorum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce in neque lobortis, laoreet lacus et, suscipit ipsum. Etiam a tempor ligula, at viverra libero. Curabitur nec massa felis. Sed a lacus eget turpis ullamcorper euismod. Pellentesque ligula urna, commodo quis vulputate vitae, suscipit sed est. Nulla tristique nibh a mattis sollicitudin. Sed et nisl ipsum. Etiam risus libero, condimentum eu consequat sit amet, ultricies et lorem. Nulla purus arcu, eleifend vitae metus eget, vulputate auctor tortor. Maecenas vulputate enim at eros ullamcorper ullamcorper. Pellentesque vitae convallis quam. Aenean tempus feugiat accumsan. Aliquam id enim non dui gravida semper eu sit amet quam. \n Nulla facilisi.Aenean lacinia nibh magna, non elementum lorem laoreet aliquam.Aliquam erat volutpat.Proin interdum leo sed risus pharetra, sed tristique felis pulvinar.Integer porttitor ex leo, eu porttitor mi blandit vel.Nam quis porttitor turpis.Cras sed justo nulla.Phasellus commodo, quam vel iaculis rhoncus, nisl ligula faucibus eros, eu eleifend libero risus eu turpis. Nulla id sollicitudin eros.Proin suscipit dapibus dui.Quisque maximus non ante vel tempus.Phasellus in nibh ut velit tristique bibendum.Praesent vitae augue venenatis tellus faucibus vehicula eget cursus quam.Curabitur et interdum mauris.Integer mauris tortor, vulputate nec tellus sed, finibus efficitur elit.Suspendisse et luctus augue.Suspendisse potenti.Vivamus tincidunt sem ut tempor suscipit.Vestibulum ac luctus felis.Etiam laoreet eleifend augue.Aenean vel sem vel justo rhoncus elementum.Etiam volutpat blandit elit.Ut sagittis mauris sit amet facilisis ornare.Aenean a fringilla lacus.Curabitur porta leo consequat condimentum pharetra.Donec vehicula rhoncus posuere.Sed congue pretium tempus.Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.Mauris bibendum ornare tristique.Cras sollicitudin nibh ac arcu feugiat, ut hendrerit sem dapibus. Donec interdum sem non turpis sodales, quis lobortis est eleifend.Nam aliquet a massa at rhoncus.Nulla pellentesque congue metus.Aenean tincidunt dui eget varius porta.Fusce consectetur nisl id justo volutpat cursus.In maximus nunc nunc, sit amet pretium enim accumsan eget.Suspendisse nec mattis magna, ut interdum lectus.Praesent ultricies lectus vitae vestibulum tempus.Proin ultricies fermentum velit in faucibus.Nulla mollis consectetur est id aliquet. Sed eget magna non risus efficitur iaculis.Nullam tincidunt, risus ut malesuada varius, risus nibh egestas mauris, non mattis sem velit sed leo.Aliquam erat volutpat.In nec ante sit amet dolor scelerisque malesuada nec in tortor.Morbi sodales, quam nec pretium bibendum, magna sem tincidunt augue, eu lacinia felis odio a justo.Aliquam sed dui sed ex placerat condimentum in quis quam.Donec vehicula massa et tellus bibendum, in finibus enim faucibus.In id urna ac metus suscipit efficitur quis non elit.Vestibulum a lorem in dolor placerat feugiat.Praesent mattis magna eu justo pulvinar, a dictum dui condimentum. Nullam auctor sagittis risus et dictum.Vivamus ultrices non ipsum blandit consequat.Nunc ullamcorper ac sapien quis lacinia.Mauris accumsan risus eget pulvinar mollis.Phasellus iaculis luctus nisl sed pretium.Integer congue nibh sed tortor congue, eu vehicula ex volutpat.Nulla turpis tortor, aliquam a orci vitae, condimentum blandit erat.Nullam sit amet lectus odio.Nulla at orci auctor nisl cursus scelerisque.Aliquam scelerisque lorem ut maximus finibus.Nullam nec magna felis.Ut finibus elit urna, eu luctus nunc vestibulum sit amet.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Nulla porttitor est eget nulla tempus vulputate.Sed vulputate libero ut fringilla elementum.Phasellus finibus risus sed elit facilisis suscipit. Vestibulum semper ex nisl, in vehicula massa pretium id.Aliquam eros neque, eleifend eu neque in, vulputate sagittis libero.Nam ut justo tempor, aliquam lacus in, finibus diam.Suspendisse sapien turpis, laoreet egestas vehicula a, convallis vel enim.Maecenas sed tellus dictum, tincidunt turpis vitae, pharetra quam.Aenean pharetra dui sit amet tellus ultrices rutrum.Nulla facilisi.Cras et viverra nisi.Aliquam erat volutpat.Sed eget neque ut sapien blandit egestas vitae sed lacus.In eu commodo urna.Nunc vel pellentesque metus.Duis euismod interdum risus ut luctus.Duis at consequat dui.Morbi eu sapien faucibus, tincidunt augue et, laoreet erat.";


class WoodWall: public OP::Game {

	public:
	WoodWall() : Game("WoodWall", 1920, 1080) { Init(); }

	void Init() override;

};




//Try to keep as few lines in here as possible
int main() {
	//RUN THIS FIRST YOU SHITWARD 
	// 
	InitializeOmegaPhi();
	
	WoodWall TheFirstWall;
	



	TheFirstWall.Start();
	


	return 0;
}

inline void WoodWall::Init() {
	AddLayer(*new OP::Layer(Game::l_Window, (*new OP::Shader("VertexShader.vert", "FragShader.frag")), "WoodWallDefaultLayer", 0));
	int width;
	int height;

	//House * sprite = new House(this, { 0,0,1 }, { 1080,1080 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
	//l_Layers[0]->AddRenderable(*sprite);

	OP::StringSprite * string = new OP::StringSprite(l_Layers[0], { 20,20,20 }, 720, true, lorum.c_str(), 1.25);

	OP::Renderable * sprite2 = new OP::Renderable({ 0,0,2002 }, { 1920,1080 }, OP::Renderable::GetColor(0xFF, 0xFF, 0xFF, 128));
	l_Layers[0]->AddRenderable(*sprite2);
	/*
	int sizeofbackground = width/(10);

	for (int i = 0; i < width/sizeofbackground + 1; i++) {
	for (int v = 0; v < height/sizeofbackground + 1; v++) {
	unsigned int Color = OP::Renderable::GetColor((i * (float) width / 32) / (float) width * 255, (v * (float) height / 200) / (float) height * 255, float(i * v)  / (width*height)  * 255, 0xFF);
	OP::fvec3 pos((i * sizeofbackground), (v *  sizeofbackground),100);
	OP::fvec2 size(sizeofbackground, sizeofbackground);
	l_Layers[0]->AddRenderable(*new OP::SimpleSprite(this,pos , size, Color ));

	}
	std::cout << i << std::endl;
	}
	std::cout << "Sprites: " << (width / (width / (1280 / 2)))* (width / (width / (1280 / 2))) << std::endl;
	}*/
}
