#include "AddSquareAction.h"
#include"Actions/Action.h"
#include "Csquare.h"
#include"ApplicationManager.h"
#include"GUI/input.h"
#include"GUI/output.h"


AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddSquareAction::ReadActionParameters()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("NEW Square: Click at the center");

	//Read the center and store it in c
	pIn->GetPointClicked(c.x, c.y);


	SquareGfxInfo.isFilled = pOut->getisfilled();
	//get drawing, filling colors and pen width from the interafce
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddSquareAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		pManager->DeleteLastFig();  // To Remove the last figure in the figlist
		pManager->UpdateInterface();     // To update the interface after undo
		pManager->GetOutput()->PrintMessage("Undo Drawing Square");
	}
}
void AddSquareAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		CSquare* S = new CSquare(c, SquareGfxInfo);
		pManager->AddFigure(S);
		pManager->UpdateInterface();
		pOut->PrintMessage("Redo Drawing Square");
	}
	else
	{
		pOut->PrintMessage("No undo action to redo.");
	}
}


//execute the action
void AddSquareAction::Execute()
{
	ReadActionParameters();
	//create a square with the parameters read from the user
	CSquare* S = new CSquare(c, SquareGfxInfo);
	//add the square to the list of figures
	pManager->AddFigure(S);
}