#include "AddTriangleAction.h"
#include"Actions/Action.h"
#include "CTriangle.h"
#include"ApplicationManager.h"
#include"GUI/input.h"
#include"GUI/output.h"


AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddTriangleAction::ReadActionParameters()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("NEW Triangle: Click at the first corner");

	//Read the first corner and store it in p1
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("New Triangle: click at the second corner");

	//Read the second corner and store it in p2
	pIn->GetPointClicked(p2.x, p2.y);

	pOut->PrintMessage("New Triangle: click at the third corner");

	//Read the third corner and store it in p3
	pIn->GetPointClicked(p3.x, p3.y);

	TriangleGfxInfo.isFilled = pOut->getisfilled();  
	//get drawing, filling colors and pen width from the interafce
    TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddTriangleAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		
		pManager->DeleteLastFig();   // To Remove the count of the last figure in the figlist
		pManager->UpdateInterface();     // To update the interface after undo
		pOut->PrintMessage("Redo Drawing Triangle");
	}
}
void AddTriangleAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		CTriangle* T = new CTriangle(p1, p2, p3, TriangleGfxInfo);
		pManager->AddFigure(T);
		pManager->UpdateInterface();
		pOut->PrintMessage("Redo Drawing Triangle");
	}
	else
	{
		pOut->PrintMessage("No undo action to redo.");
	}

}

//execute the action
void AddTriangleAction::Execute()
{
	ReadActionParameters();
	//create a circle with the parameters read from the user
	CTriangle* T = new CTriangle(p1, p2,p3, TriangleGfxInfo);
	//add the circle to the list of figures
	pManager->AddFigure(T);
}