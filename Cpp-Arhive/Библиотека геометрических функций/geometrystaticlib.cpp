#include <iostream>
#include "areageometry.h" // библиотека для вычисления площадей
#include "volume_figures.h" // библиотека для вычисления объемов
#include "generalformulas.h" // библиотека общих геометрических формул
#include <iomanip>
#include <string>



bool CheckNum(string str) {	// проверка строки на ввод числа
    if (!str.empty()) {
        try {
            int num = stoi(str);
            return true;
        }
        catch (invalid_argument)
        {
            // если введено не число
            cout << "Only numbers are allowed! \n";
        }
        catch (out_of_range)
        {
            //Если число слишком большое
            cout << "Can't convert into int! \n";
        }
        catch (...)
        {
            //Если будет выброшено неизвестное исключение
            cout << "Unknown error! \n";
        }
    }
    return false;
}


using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    areageometry ag;
    volume_figures vf;
    generalformulas gf;


    bool sostoyanie = true;
    while (sostoyanie)
    {
        cout << "_________МЕНЮ________" << endl;
        cout << "[1] Вычисление площадей (использование библиотеки << areageometry.h >>)" << endl;
        cout << "[2] Вычисление обьемов (использование библиотеки << volume_figures.h >>)" << endl;
        cout << "[3] Общие геометрические формулы (использование библиотеки << generalformulas.h >>)" << endl;
        cout << "[0] Выход из программы" << endl;


        int chouse_menu;
        cin >> chouse_menu;

        system("cls");

        switch (chouse_menu)
        {
        case 1: {
            cout << "ВЫЧИСЛЕНИЕ ПЛОЩАДЕЙ ГЕОМЕТРИЧЕСКИХ ФИГУР" << endl;
            cout << "[1] Площадь треугольника по двум сторонам и углу между ними" << endl;
            cout << "[2] Площадь треугольника через его основание и высоту" << endl;
            cout << "[3] Площадь треугольника по трем сторонам и радиусу описанной окружности" << endl;
            cout << "[4] Площадь треугольника формула Герона" << endl;
            cout << "[5] Площадь трапеции" << endl;
            cout << "[6] Площадь параллелограмма через сторону и высоту" << endl;
            cout << "[7] Площадь параллелограмма через две стороны и угол между ними " << endl;
            cout << "[8] Площадь круга" << endl;
            cout << "[9] Площадь кругового сектора" << endl;
            cout << "[10] Площадь боковой поверхности конуса" << endl;
            cout << "[11] Площадь боковой поверхности цилиндра" << endl;
            cout << "[12] Площадь сферы" << endl;

            int chouse_first_nemu;
            cin >> chouse_first_nemu;
            

            system("cls");

            switch (chouse_first_nemu)
            {
            case 1: {
                double a, b, angle;

                string k;
                k.clear();
                cout << "Введите первую сторону: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                a = stoi(k);
                k.clear();
                cout << "Введите вторую сторону: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                b = stoi(k);
                k.clear();
                cout << "Введите угол между этими сторонами: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                angle = stoi(k);
                k.clear();


                cout << "Площадь треугольника S = " << ag.Area_of_​​a_triangle_across_two_sidesand_angle_between_them(a, b, angle) << endl;
                system("pause");
                system("cls");
            }break;
            case 2: {
                double height, base_of_triangle;
                string k;
                k.clear();
                cout << "Введите высоту треугольника: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                height = stoi(k);
                k.clear();
                cout << "Введите основание треугольника: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                base_of_triangle = stoi(k);
                k.clear();
                cout << "Площадь треугольника S = " << ag.The_area_of_​​the_triangle_through_the_baseand_the_height(height, base_of_triangle) << endl;
                system("pause");
                system("cls");
            }break;
            case 3: {
                double a, b, c, r;

                string k;

                k.clear();
                cout << "Введите первую сторону: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                a = stoi(k);

                cout << "Введите вторую сторону: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                b = stoi(k);
                k.clear();

                cout << "Введите третью сторону: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                c = stoi(k);
                k.clear();

                cout << "Введите радиус описанной окружности: ";
                while (!CheckNum(k)) {	// проверка на ввод
                    cin >> k;
                }
                r = stoi(k);
                k.clear();

                if (ag.Area_of_​​a_triangle_in_terms_of_radius_circumscribed_circle(a, b, c, r) == -1.0) {
                    cout << "Треугольник с такими сторонами не может существовать или радиус описанной окружности с такими параметрами не может существовать!" << endl;
                }
                else {
                    cout << "Площадь треугольника S = " << ag.Area_of_​​a_triangle_in_terms_of_radius_circumscribed_circle(a, b, c, r) << endl;
                }
                system("pause");
                system("cls");
            }break;
            case 4: {
                double a, b, c;
                cout << "Введите первую сторону: "; cin >> a;
                cout << "Введите вторую сторону: "; cin >> b;
                cout << "Введите третью сторону: "; cin >> c;
                if (ag.Area_of_​​a_triangle_Herons_formula(a, b, c) == -1.0) {
                    cout << "Треугольник с такими сторонами не может существовать!" << endl;
                }
                else {
                    cout << "Площадь треугольника S = " << ag.Area_of_​​a_triangle_Herons_formula(a, b, c) << endl;
                }
                system("pause");
                system("cls");
            }break;
            case 5: {
                double a, b, h;
                cout << "Введите первую сторону: "; cin >> a;
                cout << "Введите вторую сторону: "; cin >> b;
                cout << "Введите высоту трапеции: "; cin >> h;
                cout << "S = " << ag.Trapezium_area(a, b, h) << endl;
                system("pause");
                system("cls");
            }break;
            case 6: { // Площадь параллелограмма через сторону и высоту
                double b, h;
                cout << "Введите сторону параллелограмма: "; cin >> b;
                cout << "Введите высоту параллелограмма: "; cin >> h;
                cout << "S = " << ag.The_area_of_​​the_parallelogram_across_the_sideand_height(b, h) << endl;
                system("pause");
                system("cls");
            }break;
            case 7: { //Площадь параллелограмма через две стороны и угол между ними
                double a, b, angle;
                cout << "Введите первую сторону: "; cin >> a;
                cout << "Введите вторую сторону: "; cin >> b;
                cout << "Введите угол между этими сторонами: "; cin >> angle;
                cout << "S = " << ag.Parallelogram_area_across_two_sides_and_the_angle_between_them(a, b, angle) << endl;
                system("pause");
                system("cls");
            }break;
            case 8: { // площадь круга
                double R;
                cout << "Введите радиус круга "; cin >> R;
                cout << "S = " << ag.Area_circle(R) << endl;
                system("pause");
                system("cls");
            }break;
            case 9: { // площадь кругового сектора
                double R, angle;
                cout << "Введите радиус круга "; cin >> R;
                cout << "Введите угол"; cin >> angle;
                cout << "S = " << ag.Circular_sector_area(R, angle) << endl;
                system("pause");
                system("cls");
            };
            case 10: { // Площадь боковой поверхности конуса
                double R, h;
                cout << "Введите радиус: "; cin >> R;
                cout << "Введите высоту: "; cin >> h;
                cout << "S = " << ag.The_lateral_surface_area_of_the_cone(R, h) << endl;
                system("pause");
                system("cls");
            }break;
            case 11: { //Площадь боковой поверхности цилиндра
                double R, h;
                cout << "Введите радиус: "; cin >> R;
                cout << "Введите высоту: "; cin >> h;
                cout << "S = " << ag.Cylinder_lateral_surface_area(R, h) << endl;
                system("pause");
                system("cls");
            }break;
            case 12: { //площадь сферы
                double R;
                cout << "Введите радиус: "; cin >> R;
                cout << "S = " << ag.Sphere_area(R) << endl;
                system("pause");
                system("cls");
            }break;

            default:
                break;
            }
        }break;
        case 2: { // вычисление объемов фигур
            cout << "ВЫЧИСЛЕНИЕ ОБЪЕМОВ ГЕОМЕТРИЧЕСКИХ ФИГУР" << endl;
            cout << "[1] Обьем призмы " << endl;
            cout << "[2] Объем цилиндра " << endl;
            cout << "[3] Объем пирамиды " << endl;
            cout << "[4] Объем конуса" << endl;
            cout << "[5] Объем шара" << endl;
            int chouse_second_menu;
            cin >> chouse_second_menu;
            system("cls");

            switch (chouse_second_menu)
            {
            case 1: // обьем призмы
            {
                double S, h;
                cout << "Введите площадь основания призмы: "; cin >> S;
                cout << "Введите высоту призмы: "; cin >> h;
                if (vf.Prism_volume(S, h) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "V = " << vf.Prism_volume(S, h) << endl;
                }
            }break;
            case 2: // объем цилиндра
            {
                double R, h;
                cout << "Введите радиус цилиндра: "; cin >> R;
                cout << "Введите высоту цилиндра: "; cin >> h;
                if (vf.Cylinder_volume(R, h) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "V = " << vf.Cylinder_volume(R, h) << endl;
                }
            }break;
            case 3: //Объем пирамиды
            {
                double S, h;
                cout << "Введите площадь основания пирамиды: "; cin >> S;
                cout << "Введите высоту цилиндра: "; cin >> h;
                if (vf.Pyramid_volume(S, h) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "V = " << vf.Pyramid_volume(S, h) << endl;
                }
            }break;
            case 4: // объем конуса
            {
                double R, h;
                cout << "Введите радиус основания конуса: "; cin >> R;
                cout << "Введите высоту конуса: "; cin >> h;
                if (vf.Cone_volume(R, h) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "V = " << vf.Cone_volume(R, h) << endl;
                }
            }break;
            case 5: // Объем шара
            {
                double R;
                cout << "Введите радиус: "; cin >> R;
                if (vf.Ball_volume(R) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "V = " << vf.Ball_volume(R) << endl;
                }
            }break;
            default:
                break;
            }


        }break;
        case 3: {

            cout << "Общие геометрические формулы" << endl;
            cout << "[1] Радиус окружности, описанной около правильного треугольника " << endl;
            cout << "[2] Радиус окружности, вписанной в прямоугольный треугольник " << endl;
            cout << "[3] Радиус окружности, описанной около прямоугольного треугольника " << endl;
            cout << "[4] Длина окружности" << endl;
            cout << "[5] Длина дуги окружности" << endl;
            cout << "[6] Главная диагональ куба" << endl;

            int chouse_menu_3;
            cin >> chouse_menu_3;
            system("cls");

            switch (chouse_menu_3)
            {
            case 1: { // Радиус окружности, описанной около правильного треугольника

                double a;
                cout << "Введите сторону треугольника: "; cin >> a;

                if (gf.radius_circle_circumscribed_about_regular_triangle(a) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "R = " << gf.radius_circle_circumscribed_about_regular_triangle(a) << endl;
                }
                system("pause");
                system("cls");

            }break;
            case 2: { // Радиус окружности, вписанной в прямоугольный треугольник

                double a, b, c;
                cout << "Введите 1 сторону треугольника: "; cin >> a;
                cout << "Введите 2 сторону треугольника: "; cin >> b;
                cout << "Введите 3 сторону треугольника: "; cin >> c;

                if (gf.radius_circle_inscribed_in_right_triangle(a, b, c) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "R = " << gf.radius_circle_inscribed_in_right_triangle(a, b, c) << endl;
                }
                system("pause");
                system("cls");

            }break;
            case 3: { // Радиус окружности, описанной около прямоугольного треугольника

                double с;
                cout << "Введите гипотенузу треугольника: "; cin >> с;

                if (gf.radius_circle_circumscribed_about_right_triangle(с) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "R = " << gf.radius_circle_circumscribed_about_right_triangle(с) << endl;
                }
                system("pause");
                system("cls");

            }break;
            case 4: { // Длина окружности
                double R;
                cout << "Введите радиус: "; cin >> R;
                if (gf.Circumference(R) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "L = " << gf.Circumference(R) << endl;
                }
                system("pause");
                system("cls");
            }break;
            case 5: { // Длина дуги окружности
                double R, angle;
                cout << "Введите радиус: "; cin >> R;
                cout << "Введите угол: "; cin >> angle;

                if (gf.Circular_arc_length(R,angle) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "L = " << gf.Circular_arc_length(R,angle) << endl;
                }
                system("pause");
                system("cls");

            }break;
            case 6: { // Главная диагональ куба
                double a;
                cout << "Введите сторону куба: "; cin >> a;

                if (gf.Main_diagonal_of_a_cube(a) == -1.0) {
                    cout << "Ошибка неверно введены параметры" << endl;
                }
                else {
                    cout << "d = " << gf.Main_diagonal_of_a_cube(a) << endl;
                }
                system("pause");
                system("cls");
            }break;


            default:
                cout << "Ошибка введите 1-6!!!" << endl;
                system("pause");
                system("cls");
                break;
            }
        }break;
        case 0:
            sostoyanie = false; break;
        default:
            break;
        }
    }
}