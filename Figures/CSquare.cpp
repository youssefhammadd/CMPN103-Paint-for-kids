#include"CSquare.h"
#include"ApplicationManager.h"
CSquare::CSquare(Point p, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p;
}
CSquare::CSquare()
{}

void CSquare::Draw(Output* pOut)const
{

	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawSquare(center, FigGfxInfo, Selected);
}

bool CSquare::insidefig(int x,int y)
{
    bool inside=0;
     Point P3, P4;
     int a = 75;
     P3.x = center.x - a;
     P3.y = center.y - a;
     P4.x = center.x + a;
     P4.y = center.y + a;
if(x>=P3.x && y>=P3.y && x<=P4.x &&y <=P4.y)
inside=1;
 return inside;
}
void CSquare::Save(ofstream& OutFile)  // save Triangle parameters and drawing &filling color 
{
	Output* pOut=NULL;
	OutFile << "SQUARE\t" << to_string(ID) << "\t" << center.x<< "\t" << center.y << "\t";
	OutFile << pOut->color_to_string(FigGfxInfo.DrawClr)<<"\t";
	OutFile << pOut->color_to_string(FigGfxInfo.FillClr)<<"\t";
	OutFile << endl;
}
void CSquare::Load(ifstream& Infile) // Load Triangle parameters and drawing &filling color 
{
	string Dc, Fc;
	Output* pOut = NULL;
	Infile >> ID >> center.x >>  center.y >> Dc >> Fc;

	FigGfxInfo.DrawClr = pOut->String_to_Color(Dc);

	if (Fc == "NO_FILL")
		FigGfxInfo.isFilled = false;

	else
	{
		FigGfxInfo.FillClr = pOut->String_to_Color(Fc);
		FigGfxInfo.isFilled = true;
	}
}
Point CSquare::GetOldPoint()
{
	return center;
}
void CSquare::MoveFig(Point p)
{
	
	if (Selected)
	{
		center = p;
	}
}
void CSquare::PrintInfo(Output* pOut) 
{
	CFigure::PrintInfo(pOut);

	string centerstrx = to_string(center.x);
	string centerstry = to_string(center.y);

	pOut->PrintMessage("center:(" + centerstrx + "," + centerstry + ")" );
	
}
