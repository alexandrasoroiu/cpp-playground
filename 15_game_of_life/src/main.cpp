#include <iostream>
#include <vector>
#include <string>

const int size = 50;

//describe the coorinates of the cell and if is alive
class Point
{
public:
	int x, y;
	bool isAlive;

	Point(int x1, int y1, bool isALive1)
	{
		this->x = x1;
		this->y = y1;
		this->isAlive = isALive1;
	}
};

//to store points
std::vector<Point> changedState;

//describe a cell (alive or not)
class Cell
{
public:
	bool alive;
	Cell()
	{
		alive = 0;
	}

};


class Grid
{
public:
	Cell cells[20][20];

	//search for all neighbours near the cell
	int getNeighbours(int x, int y)
	{
		int countNeigh = 0;

		if (cells[(x - 1)][y].alive == 1 && x != 0)
		{
			countNeigh++;
		}
		if (cells[(x - 1)][y - 1].alive == 1 && x != 0 && y != 0)
		{
			countNeigh++;
		}
		if (cells[(x - 1)][y + 1].alive == 1 && x != 0 && y != size)
		{
			countNeigh++;
		}
		if (cells[(x)][y + 1].alive == 1  && y != size)
		{
			countNeigh++;
		}
		if (cells[(x)][y - 1].alive == 1 && y != 0)
		{
			countNeigh++;
		}
		if (cells[(x + 1)][y + 1].alive == 1 && x != size && y != size)
		{
			countNeigh++;
		}
		if (cells[(x + 1)][y - 1].alive == 1 && x != size && y != 0)
		{
			countNeigh++;
		}
		if (cells[(x + 1)][y].alive == 1 && x != size)
		{
			countNeigh++;
		}
	}

	void updateCell()
	{
		int space[20][20];

		//looks for neighbours; store in the vector of points all the updated cells
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (cells[x][y].alive == 1)
				{
					if (space[x][y] > 3)
					{
						cells[x][y].alive = 0;
						changedState.push_back(Point(x, y, 0));
					}

					if (space[x][y] < 2)
					{
						cells[x][y].alive = 0;
						changedState.push_back(Point(x, y, 0));
					}
				}
				else
				{
					if (space[x][y] == 3)
					{
						cells[x][y].alive = 1;
						changedState.push_back(Point(x, y, 1));
					}
				}
			}
		}
	}
	//to print the cells
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (cells[i][j].alive == 1)
				{
					std::cout << "*" << std::endl;
				}
				else
				{
					std::cout << " " << std::endl;
				}
			}
			std::cout << "\n" << std::endl;
		}
	}

};



int main()
{
	Grid myGrid;
	
	char grid[20][20];



	return 0;
}
