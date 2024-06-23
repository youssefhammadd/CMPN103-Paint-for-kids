#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Actions/Action.h"

//Add Square Action Class
class AddSquareAction :public Action
{
private:
	Point c; //Square's center 
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};



#endif