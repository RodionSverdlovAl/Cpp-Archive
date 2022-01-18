#include <iostream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "ru");
    while (true)
    {
        std::cout << "[1] задание 1" << std::endl;
        std::cout << "[2] задание 2" << std::endl;
        int chouse;
        std::cin >> chouse;
        switch (chouse)
        {
        case 1: {
            int size;
            std::cout << ("Введите количество элементов первого и второго массива: ");
            std::cin >> size;
            int* arrayPtr = (int*)calloc(size, sizeof(int)); // выделяем память под динамический массив целых чисел

            if (arrayPtr == NULL) exit(1);  // если ошибка с созданием массива то завершить работу программы

            for (int ix = 0; ix < size; ix++)                 // в цикле заполняем массив с клавиатуры
            {
                std::cout << ("Введите число(1массив): ");
                std::cin >> arrayPtr[ix];
            }

            std::cout << "Введённые числа первый массив: ";
            for (int ix = 0; ix < size; ix++)                 // в цикле выводим элементы массива на стандартное устройство вывода
                std::cout << arrayPtr[ix] << " ";

            std::cout << std::endl;

            int* arrayPtr2 = (int*)calloc(size, sizeof(int));
            if (arrayPtr2 == NULL) exit(1);  // если ошибка с созданием массива то завершить работу программы
            for (int ix = 0; ix < size; ix++)                 // в цикле заполняем массив с клавиатуры
            {
                std::cout << ("Введите число(2массив): ");
                std::cin >> arrayPtr2[ix];
            }
            std::cout << "Введённые числа второй массив: ";
            for (int ix = 0; ix < size; ix++)                 // в цикле выводим элементы массива на стандартное устройство вывода
                std::cout << arrayPtr2[ix] << " ";


            int sum1 = 0;
            for (int i = 0; i < size; i++) {
                sum1 += arrayPtr[i];
            }
            float sr_ar_m1 = (float)sum1 / (float)size;


            int sum2 = 0;
            for (int i = 0; i < size; i++) {
                sum2 += arrayPtr2[i];
            }
            float sr_ar_m2 = (float)sum2 / (float)size;

            std::cout << std::endl;
            std::cout << "Среднее арифметическое первого массива " << sr_ar_m1 << std::endl;
            std::cout << "Среднее арифметическое второго массива " << sr_ar_m2 << std::endl;

            free(arrayPtr);
            free(arrayPtr2);// удаляем динамический массив чисел
        }break;
        case 2: {
            int num; // размер массива
            std::cout << "Enter integer value: ";
            std::cin >> num; // получение от пользователя размера массива
            int* p_darr = new int[num]; // Выделение памяти для массива

            for (int i = 0; i < num; i++) {
                // Заполнение массива и вывод значений его элементов
                std::cout << "Введите элемент массива "; std::cin >> p_darr[i];
            }
            std::cout << "исходный массив" << std::endl;
            for (int i = 0; i < num; i++) {

                std::cout << p_darr[i] << " "; ;
            }

            // произведение эллементов массива расположенных между первым и вторым нулевыми значениями

            bool check = false;

            for (int i=0; i < num; i++) {
                if (p_darr[i] == 0)
                    check = true;
            }
            if (check == false) {
                std::cout << std::endl;
                std::cout << "не найдено нулевых значений в массиве!!!" << std::endl;

            }
            if (check == true) {
                int mul = 1, i = 0;
                for (i; i < num; i++)
                    if (p_darr[i] == 0)
                        break;
                for (++i; i < num; i++)
                {
                    if (p_darr[i] == 0)
                        break;
                    mul *= p_darr[i];
                }
                std::cout << std::endl;
                std::cout << "произведение эллементов массива расположенных между первым и вторым нулевыми значениями = " << mul << std::endl;

            }
                
            delete[] p_darr;
        }break;
        default:
            std::cout << "Неверно выбран пункт меню!" << std::endl;
            break;
        }
    }
    return 0;
}