#include "RocketSingle.h"


RocketSingle* RocketSingle::m_RocketSingle = NULL;

void RocketLayer::onEnter(){

	CCSprite::onEnter();
	RocketSingle::sharedRocket();

	p_context = Rocket::Core::CreateContext(name.c_str(), Rocket::Core::Vector2i(1024, 768));
	if (p_context == NULL)
	{
		Rocket::Core::Shutdown();

	}

	Rocket::Debugger::Initialise(p_context);

	LoadFonts("./data/");
	// Load and show the inventory document.
	inventory_1 = new Inventory("Inventory 1", Rocket::Core::Vector2f(50, 200), p_context);
	Inventory* inventory_2 = new Inventory("Inventory 2", Rocket::Core::Vector2f(540, 240), p_context);

	// Add items into the inventory.
	inventory_1->AddItem("Mk III L.A.S.E.R.");
	inventory_1->AddItem("Gravity Descender");
	inventory_1->AddItem("Closed-Loop Ion Beam");
	inventory_1->AddItem("5kT Mega-Bomb");
}

void RocketLayer::draw(){
	//CCSprite::draw();
	p_context->Render();
}

void RocketLayer::LoadFonts(const char* directory)
{
	//Notice:Those otf files are copied from the exapmle.
	rocket::core::string font_names[4];
	font_names[0] = "delicious-roman.otf";
	font_names[1] = "delicious-italic.otf";
	font_names[2] = "delicious-bold.otf";
	font_names[3] = "delicious-bolditalic.otf";

	for (int i = 0; i < sizeof(font_names) / sizeof(rocket::core::string); i++)
	{
		rocket::core::fontdatabase::loadfontface(rocket::core::string(directory) + font_names[i]);
	}

	// Rocket::Core::String font_name = "simhei.ttf";
	// Rocket::Core::FontDatabase::LoadFontFace(Rocket::Core::String(directory) + font_name,"Vifnt",Rocket::Core::Font::STYLE_NORMAL,
		// Rocket::Core::Font::WEIGHT_BOLD);
}