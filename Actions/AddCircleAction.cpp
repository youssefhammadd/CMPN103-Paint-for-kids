#include "AddCircleAction.h"
#include"Actions/Action.h"
#include "CCircle.h"
#include"ApplicationManager.h"
#include"GUI/input.h"
#include"GUI/output.h"

AddCircleAction ::AddCircleAction(ApplicationManager *pApp):Action(pApp)
{}
void AddCircleAction::ReadActionParameters()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("NEW Circle: Click at the center");

	//Read the center and store it in c
	pIn->GetPointClicked(c.x, c.y);

	pOut->PrintMessage("New Circle: click at a point on the circomference");

	//Read the second point and store it in p
	pIn->GetPointClicked(p.x, p.y);

	CircleGfxInfo.isFilled = pOut->getisfilled();
	//get drawing, filling colors and pen width from the interafce
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddCircleAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		int Reference;
		Reference = pManager->DeleteLastFig();   // To Remove the count of the last figure in the figlist
		if (Reference)
		{
			pManager->UpdateInterface();     // To update the interface after undo
			pOut->PrintMessage("Undo Drawing Circle");
		}
	}
	else
	{
		pOut->PrintMessage("No actions to undo");
	}
}
void AddCircleAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		CCircle* C = new CCircle(c, p, CircleGfxInfo);
		pManager->AddFigure(C);
		pManager->UpdateInterface();
		pOut->PrintMessage("Redo Drawing Circle");
	}
}

//execute the action
void AddCircleAction::Execute()
{
	ReadActionParameters();
	//create a circle with the parameters read from the user
	CCircle* C = new CCircle(c, p, CircleGfxInfo);
	//add the circle to the list of figures
	pManager->AddFigure(C);
}