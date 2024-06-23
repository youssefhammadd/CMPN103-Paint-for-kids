#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddSquareAction.h"
#include "AddCircleAction.h"
#include "AddHexagonAction.h"
#include"AddTriangleAction.h"
#include"ChangeDrawingColorAction.h"
#include"ChangeFillColorAction.h"
#include"SelectOneAction.h"
#include"DeleteAction.h"
#include"SaveAction.h"
#include "ClearAllAction.h"
#include"SwitchAction.h"
#include"MoveFigAction.h"
#include"ExitAction.h"
#include"LoadAction.h"
#include"RedoAction.h"
#include"UndoAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	ID = 0;
	FigCount = 0;
	ActionCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	//RY Changed here
	for (int i = 0; i < MaxUndoCount; i++)
		//for (int i = 0; i < MaxFigCount; i++)
		ActionList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	bool CheckEnableActions = 1;
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);///created AddRectAction here
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);///created AddSquareAction here
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);///created AddCircleAction here
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriangleAction(this);///created AddTriangleAction here
		break;
	case DRAW_HEXAGON:
		pAct = new AddHexagonAction(this);///created AddHexagonAction here
		break;
	case SELECT:
		pAct = new SelectOneAction(this);///created SelectOneAction here
		CheckEnableActions = 0;
		break;
	case CHANGE_DRAWING_COLOR:
		pAct = new ChangeDrawingColorAction(this);///created ChangeDrawColorAction here
		break;
	case CHANGE_FILL_COLOR:
		pAct = new ChangeFillColorAction(this);///created ChangeFillColorAction here
		break;
	case DELETE_FIGURE:
		pAct = new DeleteAction(this);///created DeleteAction here
		break;
	case MOVE_FIGURE:
		pAct = new MoveFigAction(this);///created MoveAction here
		break;
	case UNDO:
		pAct = new UndoAction(this);///created UndoAction here
		CheckEnableActions = 0;
		break;
	case REDO:
		pAct = new RedoAction(this);///created RedoAction here
		CheckEnableActions = 0;
		break;
	case CLEAR_ALL:
		pAct = new ClearAllAction(this);///created ClearAllAction here
		CheckEnableActions = 0;
		break;
	case SAVE_GRAPH:
		pAct = new SaveAction(this);///created SaveAction here
		CheckEnableActions = 0;
		break;
	case LOAD_GRAPH:
		pAct = new LoadAction(this);///created LoadAction here
		CheckEnableActions = 0;
		break;
	case EXIT:
		pAct = new ExitAction(this);///created ExitAction here
		CheckEnableActions = 0;
		break;
	case TO_DRAW:
		pAct = new SwitchAction(this);
		CheckEnableActions = 0;
		break;
	case TO_PLAY:
		pAct = new SwitchAction(this);
		CheckEnableActions = 0;
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{

		if (CheckEnableActions)
		{
			if (ActionCount < MaxUndoCount)
			{
				ActionList[ActionCount] = pAct;
				ActionCount++;
			}
			else
			{
				//ActionCount--;
				delete ActionList[0];
				for (int i = 0; i < ActionCount - 1; i++)
				{
					ActionList[i] = ActionList[i + 1];
				}
				ActionList[ActionCount - 1] = pAct;
			}
		}
		pAct->Execute();//Execute
		//RY Changed here
		//	delete pAct;	//You may need to change this line depending to your implementation
		//	pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount++]->SetID(++ID);
	}
}
// Add a figure to the list of Actions
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFigure(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == pFig) {
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount] = NULL;
			FigCount--;
			ID--;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	CFigure* FigPtr = NULL;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->insidefig(x, y) == 1) {
			FigPtr = FigList[i];
			return FigPtr;
		}
	}
	return FigPtr;

}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelectedFigure(CFigure* FigPtr)
{
	SelectedFig = FigPtr;
}
/////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelected()
{
	return SelectedFig;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::unselectall()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetSelected(false);
}
void ApplicationManager::UndoLastAction()
{
	if (ActionCount > 0)
	{
		ActionList[ActionCount - 1]->Undoaction();
		ActionCount--;
	}
	else
	{
		pOut->PrintMessage("There is no Actions to undo.");
	}
}
void ApplicationManager::RedoLastAction()
{
	if (ActionCount < MaxUndoCount)
	{
		Action* pAct = ActionList[ActionCount];
		if (pAct != NULL)
		{
			pAct->Redoaction();
			ActionCount++;
		}
	}
	else
	{
		pOut->PrintMessage("No Action to Redo.");
	}
}
bool ApplicationManager::DeleteLastFig()
{
	if (FigCount == 0)
	{
		return false;
	}
	else
	{
		delete FigList[FigCount - 1];
		FigList[FigCount - 1] = NULL;
		FigCount--;
		return true;
	}
}
void ApplicationManager::IncrementFigCount()
{
	FigCount++;
}
int ApplicationManager::GetActionCount()
{
	return ActionCount;
}
////////////////////////////////////////////////////////////////////////////////////
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::SaveAll(ofstream& OutFile) // Save all figures
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
int ApplicationManager::GetFigCount()
{
	return FigCount;                // Return the number of figures
}
void ApplicationManager::SetFigCount(int NoOfFig)
{
	FigCount = NoOfFig;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
void ApplicationManager::ClearAll()
{

	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;

	}
	FigCount = 0;
	ID = 0;
	for (int i = 0; i < ActionCount; i++)
	{
		delete ActionList[i];
		ActionList[i] = NULL;
	}
	ActionCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];

	for (int i = 0; i < ActionCount; i++)
	{
		if (ActionList[i] != NULL)
		{
			delete ActionList[i];
			ActionList[i] = NULL;
		}
	}
	delete pIn;
	delete pOut;

}