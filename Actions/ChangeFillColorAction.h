#ifndef CHANGE_FILL_COLOR_ACTION_H
#define CHANGE_FILL_COLOR_ACTION_H

#include"Actions/Action.h"
#include "Figures/CFigure.h"

//Change Fill Color action class
class ChangeFillColorAction :public Action
{
private:
	CFigure* SelectedPtr;  // a pointer on the selected figure
	GfxInfo FigGfxInfo;
	ActionType ClickedColor;
	color oldColor, newColor;
public:
	ChangeFillColorAction(ApplicationManager* pApp);

	//Reads fill color parameters
	virtual void ReadActionParameters();

	//Change the color of selected figure
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();

};




#endif