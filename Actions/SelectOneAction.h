#ifndef SELECT_ONE_H
#define  SELECT_ONE_H

#include"Actions/Action.h"
#include"Figures/CFigure.h"

//Add select one figure class
class SelectOneAction :public Action {
private:
	Point P;        //the clicked point 
	CFigure*FigPtr;  //a pointer on the figure   
	CFigure* Previous; // a pointer to the previously selected figure
	
public:
	SelectOneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};

#endif