#include "BallMoveButton.h"

using namespace GameEngine;

BallMoveButton::BallMoveButton()
{

}
BallMoveButton::~BallMoveButton()
{

}
void BallMoveButton::OnButtonClicked()
{
	ball->SetActive(!ball->isActive);
}