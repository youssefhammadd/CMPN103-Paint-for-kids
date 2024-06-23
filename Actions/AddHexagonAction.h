#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Actions/Action.h"

//Add Hexagon Action Class
class AddHexagonAction :public Action
{
private:
	Point c;  //Hexagon Center
	GfxInfo HexagonGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	//Read Hexagon Parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();

};
#endif