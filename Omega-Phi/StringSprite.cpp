#include "StringSprite.h"
#include "EventListener.h"
#include "FontLoader.h"



OP::StringSprite::StringSprite(OP::Layer * Layer, OP::fvec3 pos, int MaxSize, bool wordWrap, std::string string, float scale) : l_Sprites()
{
	p_Layer = Layer;
	l_Pos = pos;
	l_MaxSize = MaxSize;
	l_wordWrap = wordWrap;
	l_String = string;
	l_Scale = scale;
	makeStringSprite();
}

void OP::StringSprite::makeStringSprite()
{
	int wordAdvance = 0;
	int currentOffsetx = 0;
	int currentOffsety = 0;
	for (int i = 0; i < l_String.size(); i++) {
		if (l_String[i] == ' ') {
			for (int k = i + 1; k < l_String.size(); k++) {
				wordAdvance += OP::FontLoader::Charlist[l_String[i]]->advancex;
				if (l_String[k] == ' ') {
					break;
				}
			}
		}

		OPchar * tmpChar = nullptr;
		tmpChar = OP::FontLoader::Charlist[l_String[i]];

		if (currentOffsetx + wordAdvance / 64 * l_Scale > l_MaxSize || l_String[i] == '\n') {
			currentOffsety += tmpChar->advancey / 26.6;
			currentOffsetx = 0;
			wordAdvance = 0;
		}

		if (l_String[i] != '\n') {
			SimpleSprite *newSprite = new SimpleSprite({ l_Pos.x + (float(tmpChar->xbearing) * l_Scale) + float(currentOffsetx) ,l_Pos.y - (float(tmpChar->ybearing) *l_Scale) - float(currentOffsety),float(l_Pos.z) }, { float(tmpChar->width) * l_Scale, float(tmpChar->height) * l_Scale }, 0xffffffff);
			newSprite->setSprite(std::string(1,tmpChar->name));
			currentOffsetx += tmpChar->advancex/64 * l_Scale;
		
			l_Sprites.push_back(newSprite);
			p_Layer->AddRenderable(*newSprite);
		}
	}
}

