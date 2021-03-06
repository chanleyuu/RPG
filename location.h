#pragma once

#include <string>
#include <vector>

//#include "world.h"

enum class occupier { empty, item, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

enum class smallocc { none, weapon, ditem, chair, candle, lamp };

enum class type { ground, air, water };

class location
{
public:
    
	
	location();

    location(occupier occ, type tp, int locx, int locy);

	std::string getoccupiers() const;

	occupier getoccupier() const;
    
    void setoccupier(occupier occ);

    smallocc getsmalloccupier(int index) const;
    
	void setsmalloccupier(int occ);

	void setsmalloccupier(std::string occ);

	void removesmalloccupier(int index);
        
    void setxlocation(int xloc);
    
    void setylocation(int yloc);

	int addsmalloccupier(smallocc socc);
    
    int getxlocation();
    
    int getylocation();

	type gettype() const;
    
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();

private:
    int xlocation_;
    int ylocation_;
    
    std::vector<smallocc> smallocc_;
	occupier occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

