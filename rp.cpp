
#include "character.hpp"
#include "item.hpp"
#include "world.hpp"
#include "skill.hpp"

int main (void){

	world_builder world;
	equipmentType wand = weapon;
	equipment stuff("The First Wand",
		"The first wand","The Choosen one",
		100,100,100,100,100,100,100,100,100,100,1,
		"Allstats x1.2 int x1.5", wand);

	item rock("Philosopher's Stone","The first item",
		"", 1,0,0);
	//debugger code
	//world.DoSomething();
	std::cout<<"-ran successfully"<<'\n';
}