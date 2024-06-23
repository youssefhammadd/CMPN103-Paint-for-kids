#include"CHexagon.h"
#include "ApplicationManager.h"
CHexagon::CHexagon(Point p, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p;
}
CHexagon::CHexagon()
{}

void CHexagon::Draw(Output* pOut)const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawHexa(center, FigGfxInfo, Selected);
}
 bool CHexagon::insidefig(int x,int y)
{
 bool inside=0;
 float PI=3.14159265359;
 int x1 = 60, y1 = 80, x2 = sqrt(pow(x1, 2) + pow(y1, 2));

 Point Arr[6];
 Arr[0].x=center.x+x1;
 Arr[0].y=center.y+y1;
 Arr[1].x=center.x+x2;
 Arr[1].y=center.y;
 Arr[2].x= center.x+x1;
 Arr[2].y= center.y-y1;
 Arr[3].x= center.x-x1;
 Arr[3].y=center.y-y1;
 Arr[4].x=center.x-x2;
 Arr[4].y=center.y;
 Arr[5].x=center.x-x1;
 Arr[5].y=center.y+y1;
  
 double radius;
 radius = sqrt(pow(center.y - Arr[1].y, 2) + pow(center.x - Arr[1].x, 2));
 if ((pow(x - center.x, 2) + pow(y - center.y, 2)) <= pow(radius, 2))
    inside=1;
    return inside;
 }
 void CHexagon::Save(ofstream& OutFile) // save Hexagon figure and parameters and drawing and filled color 
 {
	 Output* pOut=NULL;
	 OutFile << "HEXAGON\t" << to_string(ID) << "\t" << center.x << "\t" << center.y << "\t";
	 OutFile << pOut->color_to_string(FigGfxInfo.DrawClr)<<"\t";
	 OutFile << pOut->color_to_string(FigGfxInfo.FillClr)<<" ";
	 OutFile << endl;
 }
 void CHexagon::Load(ifstream& Infile)
 {
	 string Dc, Fc;
	 Output* pOut = NULL;
	 Infile >> ID >> center.x >> center.y >> Dc >> Fc;

	 FigGfxInfo.DrawClr = pOut->String_to_Color(Dc);

	 if (Fc == "NO_FILL")
		 FigGfxInfo.isFilled = false;

	 else
	 {
		 FigGfxInfo.FillClr = pOut->String_to_Color(Fc);
		 FigGfxInfo.isFilled = true;
	 }
 }
 Point CHexagon::GetOldPoint()
 {
	 return center;
 }

 void CHexagon::MoveFig(Point p)
 { 
	 if (Selected)
	 {
		 center = p;
	 }
 }
 void CHexagon::PrintInfo(Output* pOut) 
 {
	 CFigure::PrintInfo(pOut);
	 string centerstrx = to_string(center.x);
	 string centerstry = to_string(center.y);

	 pOut->PrintMessage("center:(" + centerstrx + "," + centerstry + ")" );

 }

