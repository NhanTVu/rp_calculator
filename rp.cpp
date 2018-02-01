
#include "character.hpp"
#include "item.hpp"
#include "world.hpp"
#include "skill.hpp"

int main (void){

	world_builder world;
	equipmentType Weapon = weapon;
	equipment stuff("The First Weapon",
		"The first weapon","The first person",
		100,100,100,100,100,100,100,100,100,100,1,
		"Allstats x1.2 int x1.5", Weapon);

	item rock1("Stone","The first item",
		"", 1,0,6);
	item rock2("Stone2","The first item",
		"", 1,0,7);
	//debugger cde
	//world.DoSomething();
	world.addItem(rock1);
	world.addItem(rock2);
	//world.removeItemById(1);

	std::cout<<"-ran successfully"<<'\n';
}