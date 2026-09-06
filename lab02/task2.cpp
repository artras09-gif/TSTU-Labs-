#include <iostream>
#include <cmath>

int main()
{
    double arr[7][10];
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(i<j)
            {
                arr[i][j] = sin(i+j);
            }
            else if(i==j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = cos(i-j);
            }
        std::cout << arr[i][j] << " ";
        }
        std::cout <<"\n";
    }
  return 0;
}
