#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>  

template <typename T>
int checkBigestIndex(std::vector<T> arr);

template <typename T>
void print(std::vector<T> arr);

double fRand(double fMin, double fMax);

int main()
{
    srand(time(NULL));
    std::vector<int> arrInt;
    std::vector<double> arrDouble;

    for (int i = 0; i < 10; i++)
        arrInt.push_back(std::rand() % 50);

    for (int i = 0; i < 10; i++)
        arrDouble.push_back(fRand(0.0, 50.0));

    print(arrInt);
    std::cout << std::endl;
    std::cout << "Index of the largest int element: " << checkBigestIndex(arrInt) << std::endl<<std::endl;

    print(arrDouble);
    std::cout << std::endl;
    std::cout << "Index of the largest double element : " << checkBigestIndex(arrDouble) << std::endl;

    return 0;
}

template <typename T>
int checkBigestIndex(std::vector<T> arr)
{
    T temp = arr[0];
    int max;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
            max = i;
        }
    }
    return max;
}

template <typename T>
void print(std::vector<T> arr)
{

    for (int i = 0; i < arr.size(); i++)
        std::cout << std::setprecision(3)<<arr[i] << " ";
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}