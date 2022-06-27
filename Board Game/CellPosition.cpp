#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) //DONE//
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) //DONE//
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const //DONE//
{
	///TODO: Implement this function as described in the .h file

	return (vCell >= 0 && vCell < NumVerticalCells)
		&& (hCell >= 0 && hCell < NumHorizontalCells); // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition) //DONE//
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file

	int row = cellPosition.HCell();
	int col = cellPosition.VCell();

	return (((8 - col) * 11) + (row + 1)); // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	if (cellNum > 0 && cellNum <= 99)
	{
		CellPosition position;

		/// TODO: Implement this function as described in the .h file
		int row = -1, col = -1, k = 0;
		int cell = 0;
		for (int i = 8; i >= 0; i--)
		{

			cell++;
			if (cell == cellNum)
			{
				row = i;
				if (k == 10 || k == 0)
					col = 0;
				else
					col = k + 1;

				position.SetHCell(col);
				position.SetVCell(row);
				return position;
			}
			k = 0;
			for (int j = 0; j < 10; j++)
			{
				cell++;
				if (cell == cellNum)
				{
					row = i;
					col = j + 1;

					position.SetHCell(col);
					position.SetVCell(row);
					return position;
				}
				k++;
			}
		}
		// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
		//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	}
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int newnum = GetCellNum() + addedNum;
	CellPosition c(newnum);
	c.GetCellPositionFromNum(newnum);
	SetVCell(c.VCell());
	SetHCell(c.HCell());
	GetCellNumFromPosition(c);
	// Note: this function updates the data members (vCell and hCell) of the calling object

}
