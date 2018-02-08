
#include "character.hpp"
#include "item.hpp"
#include "world.hpp"
#include "skill.hpp"

int main (void){

	world_builder world;
	equipmentType Weapon = weapon;
	equipment First_Weapon("The First Weapon",
		"The first weapon","The first person",
		1,100,100,100,100,100,100,100,100,100,100,
		"Allstats x1.2 int x1.5", Weapon);

	item rock1("Stone1","The first item",
		"", 1,0,6, BaseItem);
	item rock2("Stone2","The first item",
		"", 1,0,6, BaseItem);
	
	//Test case code
	//world.DoSomething();
	world.addItem(rock1);
	world.addItem(rock2);
	world.addItem(First_Weapon);
	world.removeItemById(6);
	world.addItem(rock2);

	//using static cast, req u to know what you are doing
	//alternatively use dynamic_cast, but require class to have virtual destructor
	equipment* temp = static_cast<equipment*>(world.getItemPtrById(1));
	equipment a = *temp;
	//temp.getStr();

	std::cout<<"-----------------"<<'\n'
	<<"-program ran successfully"<<'\n';
}