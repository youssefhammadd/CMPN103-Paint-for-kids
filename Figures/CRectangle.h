#ifndef CRECT_H
#define CRECT_H

#include"Figures/CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool insidefig(int x, int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point GetOldPoint();
	virtual void MoveFig(Point p);
	void PrintInfo(Output* pOut);
};

#endif

