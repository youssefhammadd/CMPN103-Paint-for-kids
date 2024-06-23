#ifndef CHANGE_DRAWING_COLOR_ACTION_H
#define CHANGE_DRAWING_COLOR_ACTION_H

#include"Actions/Action.h"
#include "Figures/CFigure.h"

//Change Drawing Color action class
class ChangeDrawingColorAction :public Action
{
private:
	CFigure* SelectedPtr;  // a pointer on the selected figure
	GfxInfo FigGfxInfo;
	ActionType ClickedColor;
	CFigure* PreviousFigure;
	color oldColor, newColor;
public:
	ChangeDrawingColorAction(ApplicationManager* pApp);

	//Reads Drawing color parameters
	virtual void ReadActionParameters();

	//Change the color of selected figure
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();

};


#endif