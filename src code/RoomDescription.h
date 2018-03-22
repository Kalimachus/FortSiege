#pragma once
#ifndef ROOMDESCRIPTION_H
#define ROOMDESCRIPTION_H

#include <iostream>
#include <string>
#include <cstdlib>

class RoomDescription
{
	std::string strRoomDesc;
public:
	//the constructor will take in the room type and the area time
	RoomDescription(const int&, const int&);
	~RoomDescription();
	std::string getRoomDesc() const;
	void setRoomDesc(const std::string& desc);
};

#endif // ROOMDESCRIPTION_H
