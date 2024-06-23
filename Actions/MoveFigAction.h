#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class MoveFigAction :public Action
{
	Point p;               // Point to the center which the figure moves to 
	CFigure* SelectedPtr;  //  pointer on the selected figure
	Point PerviousPoint;   // Point to Center of the figure before moving
public:
	MoveFigAction(ApplicationManager* pApp);
	~MoveFigAction();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};
