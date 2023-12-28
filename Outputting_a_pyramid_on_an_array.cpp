#include <iostream>
#include <cmath>
#include <string>

void print_pyramid(int* arr, int size) {
    std::cout << "Исходный масив:";
    for (int i = 0; i < size; ++i) {
        std::cout <<' ' << arr[i] << ' ';
    }
    std::cout << "\n" << "Пирамида:\n";

    int root = 0;
    int counter = 1;
    int deeplevel = 1 ;
   
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            std::cout << "0 root " << arr[0] << "\n";
            root = arr[0];
        }
        
        else if (i % 2 == 0) {
            deeplevel = std::log2(i + 1);
            std::cout << deeplevel << " right(" << root << ") " << arr[i] << "\n";
            root = arr[counter];
            counter++;
        }
        else if (i % 2 != 0) {
            deeplevel = std::log2(i + 1);
            std::cout << deeplevel << " left(" << root << ") " << arr[i] << "\n";
           
        }
        
    }
    

}


void position_in_arr(int* arr, int &position , int size) {
    int deeplevel = 1;
    int root = 1;
    if (position == 0) {
        std::cout << "\nВы находитесь здесь: ";
        std::cout << "0 root " << arr[0] << "\n";
    }
    else if (position % 2 == 0) {
        if (position < size) {
            std::cout << "Вы находитесь здесь: ";
            deeplevel = std::log2(position + 1);
            root = arr[position / 2 - 1];
            std::cout << deeplevel << " right(" << root << ") " << arr[position] << "\n";
        }
        else std::cout << "\nОшибка! Отсутсвует правый потомок\n";
    }
    else if (position % 2 != 0) {
        if (position < size) {
            std::cout << "Вы находитесь здесь: ";
            deeplevel = std::log2(position + 1);
            root = arr[position / 2];
            std::cout << deeplevel << " left(" << root << ") " << arr[position] << "\n";
        }
        else std::cout << "\nОшибка! Отсутсвует левый потомок\n";
    }


}



int main()
{
    setlocale(LC_ALL, "russian");
    const int size1 = 6;
    const int size2 = 8;
    const int size3 = 10;
    int arr1[size1] = { 1, 3, 6, 5, 9, 8 };
    int arr2[size2] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[size3] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    std::string command ;
    int position = 0;



    print_pyramid(arr1, size1);
    
    do {
        
        position_in_arr(arr1, position, size1);
        std::cout << "\nВведите команду: ";
        std::cin >> command;
        if (command == "up") {
            position = 0;
        }
        else if (command == "left") {
            position = 2 * position + 1;

        }
        else if (command == "right") {
            position = 2 * position + 2;

        }
        else if (command != "exit") {
            std::cout << "\nТакой команды не существует\n";
        }

    } while (command != "exit");



    print_pyramid(arr2, size2);
    print_pyramid(arr3, size3);

    return 0;
}

