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
	
	char map[width][height];
	position startpos;
	startpos.x = -1;
	startpos.y = -1;
	for (int y=0; y < board.size();y++)
	{
		std::string rad = board[y];
		
		for(int x =0; x < rad.length(); x++)
		{
			char c = rad[x];
			map[x][y] = c;

			if (c == '@') //starting point
			{
				startpos.x = x;
				startpos.y = y;
			}		
			//std::cout << map[x][y];
		}
		//std::cout << std::endl;
	}
	
	if (startpos.x == -1 && startpos.y == -1)
	{
		std::cout << std::endl;
		return 0;
	}	
    // TODO: Find path to goal
	position current;
	std::queue<	position> Q;
	Q.push (startpos);
	
	while (!Q.empty()) 
	{
		current = Q.front();
		Q.pop();
		
		/* x-1 ,y*/
		if(map[current.x-1][current.y] == ' ' || map[current.x-1][current.y] == '.' && current.x-1 >= 0) {
			if (map[current.x-1][current.y] == '.')
			{
				current.x--;
				current.path+="L";				
				break;
			}
			else
			{
				map[current.x-1][current.y] = 'o';
				position temp;
				temp.x = current.x-1;
				temp.y = current.y;
				temp.path = current.path + "L";
				Q.push(temp);
			}
		}
		
		/* x+1 ,y*/
		if(map[current.x+1][current.y] == ' ' || map[current.x+1][current.y] == '.' && current.x+1 < width) {
			if (map[current.x-1][current.y] == '.')
			{
				current.x++;
				current.path+="R";
				break;
			}
			else
			{
				map[current.x+1][current.y] = 'o';
				position temp;
				temp.x = current.x+1;
				temp.y = current.y;
				temp.path = current.path + "R";
				Q.push(temp);
			}
		}
		
		/* x ,y-1*/
		if(map[current.x][current.y-1] == ' ' || map[current.x][current.y-1] == '.' && current.y-1 >= 0) {
			if (map[current.x][current.y-1] == '.')
			{
				current.y--;
				current.path+="U";
				break;
			}
			else
			{
				map[current.x][current.y-1] = 'o';
				position temp;
				temp.x = current.x;
				temp.y = current.y-1;
				temp.path = current.path + "U";
				Q.push(temp);
			}
		}
		
		/* x ,y+1*/
		if(map[current.x][current.y+1] == ' ' || map[current.x][current.y+1] == '.' && current.y+1 < height) {
			if (map[current.x][current.y+1] == '.')
			{
				current.y++;
				current.path+="D";
				//std::cout << "Goal found at "<< current.x << ',' << current.y <<" -D-"<< std::endl;
				break;
			}
			else
			{
				map[current.x][current.y+1] = 'o';
				position temp;
				temp.x = current.x;
				temp.y = current.y+1;
				temp.path = current.path + "D";
				
				Q.push(temp);
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
	if (map[current.x][current.y] == '.')
	{
		//std::cout << current.path << std::endl;
		for(int i = 0; i < current.path.length()-1;i++)
			std::cout << current.path[i] << " ";
		std::cout << current.path[current.path.length()-1];
	}
	else
		std::cout << "no path";
	
    //std::cout << "U R R U" << std::endl;
    return 0;
}





