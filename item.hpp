#pragma once
#include "header.hpp"

//
//	equipment type enum
//
enum equipmentType{
	helmet,
	cape,
	chest,
	gaunlet,
	leggings,
	shoes,
	weapon,
	secondary,
	offhand,
	backpack,
	ring,
	necklace,
	bracelet,
	belt,
	undergarmet,
	earrings
};

//
//	item class
//
class item{

public:
	item(	std::string _name, 	std::string _description,
			std::string _bind,
			int _stack_limit, int _current_stack, int _id):
			name(_name), description(_description), bind(_bind),
			stack_limit(_stack_limit),	current_stack(_current_stack),
			id(_id){}
	//change field


protected:
	std::string name, description, bind;
	int stack_limit, current_stack, id;
};

//
//	equipment derived item class 
//
class equipment : public item {
public:
	//constructor
	equipment(	std::string _name, 	
				std::string _description,
				std::string _bind,
				double _req_str,
				double _req_int,
				double _req_luck,
				double _req_agi,
				double _req_hp,
				double _req_mp,
				double _req_dmg,
				double _req_def,
				double _req_mdef,
				double _req_stam,
				int _id,
				std::string _modifier,				
				equipmentType _type)
			:	
		item(	name, description, 
				_bind, 1, 0, _id),
				req_str(_req_str), 
				req_int(_req_int), 
				req_luck(_req_luck), 
				req_agi(_req_agi), 
				req_hp(_req_hp), 
				req_mp(_req_mp),
				req_dmg(_req_dmg),
				req_def(_req_def),
				req_mdef(_req_mdef),
				req_stam(_req_stam),
				modifier(_modifier),
				type(_type){}
	//
	//methods for retrieving a field
	//
	std::string get_name(){return name;}
	std::string get_description(){return description;}
	std::string get_modifier(){return modifier;}
	equipmentType get_type(){return type;}
	double get_str(){return req_str;}
	double get_int(){return req_int;}
	double get_luck(){return req_luck;}
	double get_agi(){return req_agi;}
	double	get_hp(){return req_hp;}
	double	get_mp(){return req_mp;}
	double	get_dmg(){return req_dmg;}
	double	get_def(){return req_def;}
	double	get_mdef(){return req_mdef;}
	double	get_stam(){return req_stam;}
	//
	//methods for changing a field
	//
	void change_str(double arg){req_str = arg;}
	void change_int(double arg){req_int = arg;}
	void change_luck(double arg){req_luck = arg;}
	void change_agi(double arg){req_agi = arg;}
	void change_hp(double arg){req_hp = arg;}
	void change_mp(double arg){req_mp = arg;}
	void change_dmg(double arg){req_dmg = arg;}
	void change_def(double arg){req_def = arg;}
	void change_mdef(double arg){req_mdef = arg;}
	void change_stam(double arg){req_stam = arg;}
	void change_name (std::string arg){name = arg;}
	void change_description (std::string arg){description = arg;}
	void change_modifier (std::string arg){modifier = arg;}
	void change_type(equipmentType arg){type = arg;}

protected: 
	std::string modifier;
	equipmentType type;
	double 	req_str,	req_int, 	req_luck, 
			req_agi, 	req_hp, 	req_mp,
			req_dmg,	req_def,	req_mdef,
			req_stam;
};

class consumables : public item {
public:
	consumables(std::string _name, 
				std::string _description,
				std::string _bind,
				int _max_stack, int _id,
				std::string _effect)
			:
				item(_name, _description, 
				_bind, _max_stack, 0, _id),
				effect(_effect){}

protected:
	std::string effect;
};
