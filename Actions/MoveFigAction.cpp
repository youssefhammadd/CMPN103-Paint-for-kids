#include "MoveFigAction.h"
#include"Figures/CFigure.h"
MoveFigAction::MoveFigAction(ApplicationManager* pApp) :Action(pApp)
{

}
MoveFigAction::~MoveFigAction()
{
}
void MoveFigAction::ReadActionParameters()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//get the selected figure and store it in SelectedPtr
	SelectedPtr = pManager->GetSelected();

	if (SelectedPtr == NULL)
	{
		pOut->PrintMessage("No figure was selected");
	}
	else
	{
		pOut->PrintMessage("Click to Move.");
		//Read the point fig moved to and store it 
		pIn->GetPointClicked(p.x, p.y);
	}
}
void MoveFigAction::Undoaction()
{
	CFigure* pFig = NULL;
	pFig= pManager->GetSelected();
	Output* pOut = pManager->GetOutput();
	if (pFig!=NULL)
	{
			pFig->MoveFig(PerviousPoint);
			pOut->PrintMessage("Undo the Figure to Created Point");
	}
	else
	{
		pOut->PrintMessage("There is no Figures or Selected Figures to Undo  ");
	}

}
void MoveFigAction::Redoaction()
{
	CFigure* pFig = NULL;
	pFig = pManager->GetSelected();
	Output* pOut = pManager->GetOutput();
	if ( pFig != NULL)
	{
		pFig->MoveFig(p);
		pOut->PrintMessage("Redo the Figure to Moved Point");
	}
}

void MoveFigAction::Execute()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();

	if (SelectedPtr == NULL)
	{
		pOut->PrintMessage("No figure was selected");
	}
	else
	{
		PerviousPoint = SelectedPtr->GetOldPoint();
		SelectedPtr->MoveFig(p);
		pManager->UpdateInterface();
	}
	pOut->ClearStatusBar();
}