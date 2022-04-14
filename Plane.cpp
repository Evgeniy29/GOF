
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    /*MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
    GotoXY(x - 2, y - 1);
    cout << "===";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";*/

    DrawBody();
    DrawWings();
    DrawTail();
}

void Plane::DrawBody() const 
{               
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
}
void Plane::DrawWings() const 
{               
    GotoXY(x - 2, y - 1);
    cout << "===";
}
void Plane::DrawTail() const 
{                
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}

void ColorPlane::DrawBody() const
{
    SetColor(CC_White);
    GotoXY(x, y);
    cout << "=========>";
}
void ColorPlane::DrawWings() const
{
    SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    cout << "===";
}
void ColorPlane::DrawTail() const
{
    SetColor(CC_Red);
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
void BigPlane::DrawBody() const
{
    SetColor(CC_White);
    GotoXY(x, y);
    cout << "=========>";
    GotoXY(x - 7, y );
    cout << "========";
}
void BigPlane::DrawWings() const 
{
    SetColor(CC_LightBlue);
    GotoXY(x - 10, y - 1);
    cout << "======";
}
void BigPlane::DrawTail() const
{
    SetColor(CC_Red);
    GotoXY(x , y - 1);
    cout << "\\\\\\\\";
    GotoXY(x , y + 1);
    cout << "////";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
