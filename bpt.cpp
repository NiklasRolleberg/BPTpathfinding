#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct position
{
	int x;
	int y;
	std::string path;
};

int main(int argc, char **argv)
{
	int height = 0;
	int width = 0;
	
	int goalX;
	int goalY;
		
    // Read the board
    std::vector<std::string> board;
    for (std::string line; std::getline(std::cin, line);)
	{
        board.push_back(line);
		height++;
		
		if (line.length()-1>width)
			width = line.length()-1;
	}
	
	//write map
	/*
	std::cout << "inlasning klar \n H ="<< height  << ", W="<< width << std::endl;
	for (int i=0; i<board.size();i++)
		std::cout << board[i] << std::endl;
	*/
	//Create char array as map
	/*
	0 = ' ' free space
	1 = #   wall
	2 = .   goal
	3 = @   sokoban player
	4 = +   sokoban player goal
	5 = $   Box
	6 = *   Box on goal
	-1=  Error
	*/
	int map[width][height];
	position startpos;
	startpos.x = -1;
	startpos.y = -1;
	for (int y=0; y < board.size();y++)
	{
		std::string rad = board[y];
		
		for(int x =0; x < rad.length(); x++)
		{
			char c = rad[x];
			
			if (c == ' ')
				map[x][y] = 0;
			else if (c == '#')
				map[x][y] = 1;
			else if (c == '.') //goal
			{
				map[x][y] = 2;
				//std::cout << "goal at: " << x << ',' << y << std::endl;
				goalX = x;
				goalY = y;
			}
			else if (c == '@') //starting point
			{
				map[x][y] = 3;
				startpos.x = x;
				startpos.y = y;
			}
			else if (c == '+')
				map[x][y] = 4;
			else if (c == '$')
				map[x][y] = 5;
			else if (c == '*')
				map[x][y] = 6;
			else
				map[x][y] = -1;
			//std::cout << map[x][y];
		}
		//std::cout << std::endl;
	}
	
	if (startpos.x == -1 && startpos.y == -1)
		return 0;
	
	
    // TODO: Find path to goal
	position current;
	std::queue<	position> Q;
	Q.push (startpos);
	
	while (!Q.empty()) 
	{
		current = Q.front();
		Q.pop();
		
		/* x-1 ,y*/
		if(map[current.x-1][current.y] == 0 || map[current.x-1][current.y] == 2 && current.x-1 >= 0) {
			if (map[current.x-1][current.y] == 2)
			{
				current.x--;
				current.path+="L";
				//std::cout << "Goal found at "<< current.x << ',' << current.y <<" -L-"<< std::endl;
				break;
			}
			else
			{
				map[current.x-1][current.y] = 9;
				position temp;
				temp.x = current.x-1;
				temp.y = current.y;
				temp.path = current.path + "L";
				
				Q.push(temp);
			}
		}
		
		/* x+1 ,y*/
		if(map[current.x+1][current.y] == 0 || map[current.x+1][current.y] == 2 && current.x+1 < width) {
			if (map[current.x-1][current.y] == 2)
			{
				current.x++;
				current.path+="R";
				//std::cout << "Goal found at "<< current.x << ',' << current.y <<" -R-"<< std::endl;
				break;
			}
			else
			{
				map[current.x+1][current.y] = 9;
				position temp;
				temp.x = current.x+1;
				temp.y = current.y;
				temp.path = current.path + "R";
				
				Q.push(temp);
			}
		}
		
		/* x ,y-1*/
		if(map[current.x][current.y-1] == 0 || map[current.x][current.y-1] == 2 && current.y-1 >= 0) {
			if (map[current.x][current.y-1] == 2)
			{
				current.y--;
				current.path+="U";
				//std::cout << "Goal found at "<< current.x << ',' << current.y <<" -U-"<< std::endl;
				break;
			}
			else
			{
				map[current.x][current.y-1] = 9;
				position temp;
				temp.x = current.x;
				temp.y = current.y-1;
				temp.path = current.path + "U";
				
				Q.push(temp);
			}
		}
		
		/* x ,y+1*/
		if(map[current.x][current.y+1] == 0 || map[current.x][current.y+1] == 2 && current.y+1 < height) {
			if (map[current.x][current.y+1] == 2)
			{
				current.y++;
				current.path+="D";
				//std::cout << "Goal found at "<< current.x << ',' << current.y <<" -D-"<< std::endl;
				break;
			}
			else
			{
				map[current.x][current.y+1] = 9;
				position temp;
				temp.x = current.x;
				temp.y = current.y+1;
				temp.path = current.path + "D";
				
				Q.push(temp);
			}
		}
	}
	
	//whrite map
	/*
	for(int y = 0; y < height;y++) {
		for (int x = 0; x < width; x++) {
			std::cout << map[x][y];
		}
		std::cout << std::endl;
	}
	*/	
	
    // Output answer
	if (current.x == goalX && current.y == goalY)
		std::cout << current.path << std::endl;
	else
		std::cout << "no path" << std::endl;
	
    //std::cout << "U R R U" << std::endl;
    return 0;
}





