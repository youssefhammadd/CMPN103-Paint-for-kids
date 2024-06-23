#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Actions/Action.h"

//Add Circle Action Class
class AddCircleAction :public Action
{
private:
	Point c; //circle's center 
	Point p; //a point on the circle's circomference
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};
#endif