#include "LoadAction.h"
#include "ApplicationManager.h"
#include "CHexagon.h"
#include"CSquare.h"
#include"CTriangle.h"
#include"CCircle.h"
#include"CRectangle.h"
#include <fstream>
LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{

}
LoadAction::~LoadAction()
{

}
void LoadAction::Undoaction()
{

}
void LoadAction::Redoaction()
{

}
void LoadAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();  //get a pointer to the input/output interfaces
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File Name to Load From: ");
	FileName = pIn->GetSrting(pOut); //Get file name from the user
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();  //get a pointer to the output interfaces
	ReadActionParameters();
	std::ifstream Filein(FileName + ".txt");
	if (Filein.is_open())
	{
		string CurrDrawColor, CurrFilledColor;

		Filein >> CurrDrawColor >> CurrFilledColor;

		UI.DrawColor = pOut->String_to_Color(CurrDrawColor);

		if (CurrFilledColor == "NO_FILL")
		{
			UI.isFilled = false;
		}
		else
		{
			UI.FillColor = pOut->String_to_Color(CurrFilledColor);
			UI.isFilled = true;
		}

		pManager->ClearAll();

		int Figcount;
		Filein >> Figcount;

		CFigure* TempFig;
		string type;

		int tempFigCount;
		int MaxFigCount = 0;
		for (int i = 0; i < Figcount; i++)
		{
			Filein >> type;
			if (type == "RECTANGLE")
				TempFig = new CRectangle;

			else if (type == "TRIANGLE")
				TempFig = new CTriangle;

			else if (type == "CIRCLE")
				TempFig = new CCircle;

			else if (type == "HEXAGON")
				TempFig = new CHexagon;
			else if (type == "SQUARE")
				TempFig = new CSquare;

			TempFig->Load(Filein);
			tempFigCount = TempFig->GetID();
			pManager->SetFigCount(tempFigCount - 1);
			if (MaxFigCount < tempFigCount)
				MaxFigCount = tempFigCount;
			pManager->AddFigure(TempFig);
		}
		pManager->SetFigCount(MaxFigCount);
		pOut->ClearStatusBar();

		pOut->PrintMessage("File loaded.");
		Filein.close();
	}
	else
		pOut->PrintMessage("There is no File with that name!");
	}