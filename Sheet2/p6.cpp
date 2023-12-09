#include <iostream>
class Universe {
    bool possible[22][52], grid[22][52];
public:
    Universe(){
        for (short i = 0; i < 22; ++i) {
            for (short j = 0; j < 52; j++)
            {
                grid[i][j] = 0;
                possible[i][j] = 0;
            }
        }
        for (short i = 1; i <= 20; ++i) {
            for (short j = 1; j <= 50; j++)
            {
                possible[i][j] = 1;
            }
        }
    }
    void reset() {
        for (short i = 0; i < 22; ++i) {
            for (short j = 0; j < 52; j++)
            {
                grid[i][j] = 0;
            }
        }
        
    }
    void initialize() {
        std::cout << "Enter 20*50 grid: \n";
        for (size_t i = 1; i <= 20; i++)
        {
            for (size_t j = 1; j <= 50; j++)
            {
                std::cin >> grid[i][j];
            }
        }
    }
    int count_live() {
        int live{ 0 };
        for (size_t i = 0; i < 22; i++)
        {
            for (size_t j = 0; j < 52; j++)
            {
                if (grid[i][j]) ++live;
            }
        }
        return live;
    }
    int count_neighbors(int row,int col) {

        return (grid[row - 1][col - 1]*possible[row-1][col-1]) + (grid[row - 1][col]*possible[row-1][col]) + (grid[row - 1][col + 1]*possible[row-1][col+1]) + (grid[row][col - 1]*possible[row][col-1]) + (grid[row][col + 1]*possible[row][col+1]) + (grid[row + 1][col - 1]*possible[row+1][col-1]) + (grid[row + 1][col]*possible[row+1][col]) + (grid[row + 1][col + 1]*possible[row+1][col+1]);
    }
    void display() {
        for (size_t i = 1; i <= 20; i++)
        {
            for (size_t j = 1; j <= 50; j++)
            {
                std::cout << grid[i][j];
            }
            std::cout << '\n';
        }
    }
    void next_generation() {
        bool temp[20][50];
        for (size_t i = 1; i <= 20; i++)
        {
            for (size_t j = 1; j <= 50; j++)
            {
                temp[i - 1][j - 1] = grid[i][j];
            }
        }
        for (size_t i = 1; i <= 20; i++)
        {
            for (size_t j = 1; j <= 50; j++)
            {
                if (!grid[i][j] && possible[i][j])
                {
                    if (count_neighbors(i, j) == 3) temp[i-1][j-1] = 1,possible[i][j] = 0;
                }
                else if (grid[i][j]&&possible[i][j])
                {
                    if (count_neighbors(i, j) < 2|| count_neighbors(i, j) > 3) temp[i-1][j-1] = 0;
                }
            }
        }
        for (short i = 1; i <= 20; ++i) {
            for (short j = 1; j <= 50; j++)
            {
                possible[i][j] = 1;
                grid[i][j] = temp[i-1][j-1];
            }
        }
    }
    void run() {
        while (count_live()) {
            std::cout << "\n==================================================\n";
            next_generation();
            display();
        }
    }
};
int main()
{
    Universe obj;
    obj.display();
    obj.initialize();
    obj.run();
}

