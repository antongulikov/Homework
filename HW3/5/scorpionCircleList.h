#ifndef SCORPIONCIRCLELIST_H
#define SCORPIONCIRCLELIST_H

#pragma once

namespace scorpion
{

	struct CircleListElement{
		int value;
		CircleListElement *next;
	};

	struct CircleList{
		CircleListElement *first;
	};

	CircleListElement* createCircleElement(int value);

	CircleList* createCircleList();

	void removeFromCircleList(CircleListElement* position);

	void addToCircleList(CircleListElement* position, CircleListElement* newElement);

	CircleListElement* next(CircleListElement* position);

	bool hasOneElement(CircleListElement* position);

}

#endif // SCORPIONCIRCLELIST_H
