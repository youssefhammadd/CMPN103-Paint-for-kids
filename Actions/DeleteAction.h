#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include"Actions/Action.h"
#include"Figures/CFigure.h"
 
class DeleteAction :public Action
{
private:
	CFigure* SelectedPtr;  // a pointer on the selected figure
	CFigure* StoreSelected;
public:
	DeleteAction(ApplicationManager* pApp);

	//Read delete parameters
	virtual void ReadActionParameters();

	//Delete figure from application manager
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};







#endif