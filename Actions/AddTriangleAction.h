#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Actions/Action.h"
//Add Triangle Action Class
class AddTriangleAction :public Action
{
private:
	Point p1; //triangle's first corner 
	Point p2; //triangle's second corner 
	Point p3; //triangle's third corner 
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};



#endif