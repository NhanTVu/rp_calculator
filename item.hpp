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
	//method to retrieve field
	std::string getName(){return name;}
	std::string getDescription(){return description;}
	std::string getBind(){return bind;}
	int getStackLimit(){return stack_limit;}
	int getStack(){return current_stack;}
	int getId(){return id;}

	//method to change field
	void changeName(std::string input){name = input;}
	void changeDescription(std::string input){description = input;}
	void changeBind(std::string input){bind = input;}
	void changeStackLimit(int input){stack_limit = input;}
	void changeStack(int input){current_stack = input;}
	void changeId(int input){id = input;}

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
		item(	_name, _description,_bind,1,0,_id),
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
	std::string getName(){return name;}
	std::string getDescription(){return description;}
	std::string getModifier(){return modifier;}
	equipmentType getType(){return type;}
	double getStr(){return req_str;}
	double getInt(){return req_int;}
	double getLuck(){return req_luck;}
	double getAgi(){return req_agi;}
	double	getHp(){return req_hp;}
	double	getMp(){return req_mp;}
	double	getDmg(){return req_dmg;}
	double	getDef(){return req_def;}
	double	getMdef(){return req_mdef;}
	double	getStam(){return req_stam;}
	//
	//methods for changing a field
	//
	void changeStr(double arg){req_str = arg;}
	void changeInt(double arg){req_int = arg;}
	void changeLuck(double arg){req_luck = arg;}
	void changeAgi(double arg){req_agi = arg;}
	void changeHp(double arg){req_hp = arg;}
	void changeMp(double arg){req_mp = arg;}
	void changeDmg(double arg){req_dmg = arg;}
	void changeDef(double arg){req_def = arg;}
	void changeMdef(double arg){req_mdef = arg;}
	void changeStam(double arg){req_stam = arg;}
	void changeName (std::string arg){name = arg;}
	void changeDescription (std::string arg){description = arg;}
	void changeModifier (std::string arg){modifier = arg;}
	void changeType(equipmentType arg){type = arg;}

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
