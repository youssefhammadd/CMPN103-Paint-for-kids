#ifndef CTRI_H
#define CTRI_H

#include"DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"

class CTriangle :public CFigure
{
private:
	Point corner1;
	Point corner2;
	Point corner3;
public:
	CTriangle( Point, Point , Point , GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool insidefig(int x,int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point GetOldPoint();
	virtual void MoveFig(Point p);
	void PrintInfo(Output* pOut) ;
};




#endif