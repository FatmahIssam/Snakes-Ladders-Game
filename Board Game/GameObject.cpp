#include "GameObject.h"

GameObject::GameObject()
{

}
GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
	
}

CellPosition GameObject::GetPosition() const
{
	return position;
}


void GameObject::Save(ofstream & OutFile, TYPE a)
{
}

GameObject::~GameObject()
{
}