#include "header.hpp"

class skill{
public:
	skill(	double _mag_dmg, double _phy_dmg,
			std::string _enemy_effect,
			std::string _ally_effect,
			std::string _personal_effect,
			std::string _other_effect)
		:
			mag_dmg(_mag_dmg), phy_dmg(_phy_dmg),
			enemy_effect(_enemy_effect), 
			ally_effect(_ally_effect),
			personal_effect(_personal_effect),
			other_effect(_other_effect){}

protected:
	double mag_dmg, phy_dmg;
	std::string enemy_effect, ally_effect, 
	personal_effect, other_effect; 
};