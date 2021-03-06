#include "location.h"

location::location() : occ_{ occupier::empty }, tp_{ type::ground } {

}

location::location(occupier occ, type tp, int locx, int locy) : occ_{ occ }, tp_{ tp },xlocation_{ locx }, 
ylocation_{locy} {

}

void location::setoccupier(occupier occ) {
    occ_ = occ;
}


occupier location::getoccupier() const {
	return occ_;
}

void location::setsmalloccupier(std::string occ) {
	int begin = 0;
	int current = occ.find('|');

	while (current != std::string::npos) {
		smallocc_.push_back((smallocc)std::stoi(occ.substr(begin, current - 1)));
		begin = current;
		current = occ.find('|', begin);
	}
	
}


std::string location::getoccupiers() const {
	std::string out = std::to_string((int) smallocc_[0]);
	for (int i = 1; i < smallocc_.size(); i++) {
		//while ((int)occ_[i] >= pow)
		//	pow *= 10;
		out = out + std::to_string((int) smallocc_[0]) + "|";
	}
	return out;
}

int location::addsmalloccupier(smallocc socc) {
	//returns index of occupier
	smallocc_.push_back(socc);
	return smallocc_.size();
}

void location::removesmalloccupier(int index) {
	smallocc_.erase(smallocc_.begin() + index);
}

type location::gettype() const {
	return tp_;
}

void location::settype(type tp) {
	tp_ = tp;
}

void location::setxlocation(int locx)
{
    xlocation_ = locx;
}

void location::setylocation(int locy)
{
    ylocation_ = locy;
}

bool location::ispassibleground() {

//	for (int i = 0; i < occ_.size(); i++) {
    if (occ_ == occupier::empty || occ_ == occupier::item || occ_ == occupier::vegetation) {
        return true;
    }
	//}
	return false;
}

bool location::ispassibleair() {
	//for (int i = 0; i < occ_.size(); i++) {
    if (occ_ == occupier::wall || occ_ == occupier::tree || occ_ == occupier::flyingplayer) {
        return false;
    }
	//}
	return true;
}

int location::getxlocation()
{
    return xlocation_;
}

int location::getylocation()
{
    return ylocation_;
}
