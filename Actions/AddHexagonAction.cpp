#include "AddHexagonAction.h"
#include"Actions/Action.h"
#include "CHexagon.h"
#include"ApplicationManager.h"
#include"GUI/input.h"
#include"GUI/output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action (pApp)
{}

void AddHexagonAction::ReadActionParameters()
{
	//get a pointer to the Input/Output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon :Click at the center");

	//Read the hexagon center and store it in c
	pIn->GetPointClicked(c.x, c.y);

	HexagonGfxInfo.isFilled = pOut->getisfilled();
	//get drawinf ,filling colors and pen width from interface
	HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexagonGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddHexagonAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		pManager->DeleteLastFig();   // To Remove the last figure in the figlist
		pManager->UpdateInterface();     // To update the interface after undo
		pOut->PrintMessage("Undo Drawing Hexagon");
	}
}
void AddHexagonAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		CHexagon* H = new CHexagon(c, HexagonGfxInfo);
		pManager->AddFigure(H);
		pManager->UpdateInterface();
		pOut->PrintMessage("Redo Drawing Hexagon");
	}
	else
	{
		pOut->PrintMessage("No undo action to redo.");
	}

}


//Execute the action 
void AddHexagonAction::Execute()
{
	ReadActionParameters();

	//create hexagon from the parameters read from the user
	CHexagon* H = new CHexagon(c, HexagonGfxInfo);

	//add hexagon to the list of figures
	pManager->AddFigure(H);
}