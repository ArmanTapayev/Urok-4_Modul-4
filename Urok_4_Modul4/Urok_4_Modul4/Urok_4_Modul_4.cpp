#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

void main()
{
	system("color 1A");
	setlocale(LC_ALL, "Rus");

	int number = 0;
	int i, j;

	cout << "\nТЕМА. Циклы, использование отладчика\n";
	cout << "\nЗадание содержит 7 задач.\n";

start:

	cout << "\nВведите номер задачи.\n";
	cout << "n = ";

	cin >> number;

	do
	{
		switch (number)
		{

#pragma region Task1

		case 1:

			int count1, count2;
			int a, number_of_cons;

			cout << "\nЗадача №1\n";

			cout << "\n1.Написать программу поиска чисел, лежащих в интервале от -5\n";
			cout << "до 5, в последовательности чисел, вводимых с клавиатуры, \n";
			cout << "предшествующих первому введенному нулю . Контрольный \n";
			cout << "пример: 1,10,-4,5,-16,-5,0.\n" << endl;

			cout << "Введите число an" << endl;

			number_of_cons = 1; // номер числа в последовательности

			do
			{
				count1 = 0, count2 = 0;

				cout << "a" << number_of_cons << "=";

				cin >> a;

				if (a == -5)
				{

					cout << "Начало последовательности от -5 до 5: " << endl;

					do
					{
						cout << "a" << ++number_of_cons << "=";
						cin >> a;
						count1++; // количество чисел в последовательности

					} while (a != 5);

					cout << "Конец последовательности." << endl;
					cout << "Количество чисел в последовательности от -5 до 5 равно " << count1 + 1 << endl;

				}
				else if (a == 5)
				{
					cout << "Начало последовательности от 5 до -5: " << endl;

					do
					{
						cout << "a" << ++number_of_cons << "=";
						cin >> a;
						count2++; // количество чисел в последовательности

					} while (a != -5);

					cout << "Конец последовательности." << endl;
					cout << "Количество чисел в последовательности от 5 до -5 равно " << count2 + 1 << endl;

				}

				number_of_cons++;

			} while (a != 0);

			cout << "Конец ввода последовательности." << endl;

			system("pause");
			system("cls");

			goto start;

		break;

#pragma endregion

#pragma region Task2

		case 2:

			cout << "\nЗадача №2\n";

			cout << "\n2.Вычислить сумму чисел от 1 до N, возведенных в степень M.\n";
			cout << "Возведение в степень оформить как многократное умножение\n" << endl;

			int Number, Power, Sum_of_power, power_of_number;

mark2:

			cout << "Введите челое число N>1:\n";
			cout << "N = ";

			cin >> Number;

				if (Number <= 1)
				{
					cout << "По условию N>1.\n";
					cout << "Введите N еще раз.\n";

					goto mark2;
				}

			cout << endl;

mark3:

			cout << "Введите степень чисел М:\n";
			cout << "М = ";

			cin >> Power;

			cout << endl;

				if (Power < 1)
				{
					cout << "По условию M>=1.\n";
					cout << "Введите M еще раз.\n";
					goto mark3;
				}

				for (Sum_of_power = 0, i = 1; i <= Number; i++)
				{
					for (power_of_number = 1, j = 1; j <= Power; j++)
					{
						power_of_number = power_of_number*i;
					}

					Sum_of_power += power_of_number;
				}

				cout << "Сумма чисел возведенных в степень " << Power << " составляет " << Sum_of_power << endl;

				cout << endl;

				system("pause");
				system("cls");

			goto start;

		break;
#pragma endregion

#pragma region Task3
		case 3:
			cout.precision(5);

			double remain_on_end_of_month, Saving, scholarship, expenses, power_end;

			cout << "\nЗадача №3\n";

			cout << "\n3.У студента имеются накопления S тенге. Ежемесячная стипендия составляет А тенге,\n";
			cout << "а расходы на проживание превышают ее и составляют B тенге в месяц.\n";
			cout << "Рост цен ежемесячно увеличивает расходы на 3%.\n";
			cout << "Определить, сколько месяцев сможет прожить студент, используя только накопления и стипендию.\n" << endl;

			cout << "Введите количество накоплений:\n";
			cout << "Накопления =";
			cin >> Saving;

			cout << "Введите размер стипендии:\n";
			cout << "Стипендия =";
			cin >> scholarship;

			cout << "Введите размер расходов:\n";
			cout << "Расходы =";
			cin >> expenses;

			i = 0;

			cout << "\nМесяц" << "\t" << "Сбережения" << "\t" << "Расходы" << "\t\t" << "Проценты" << endl;
			cout << "---------------------------------------------------------------" << endl;

				while (Saving > 0)
				{
					power_end = pow(1.03, i); //проценты на конец текущего месяца
					remain_on_end_of_month = expenses*power_end - scholarship; //(расходы - степендия) на конец текущего месяца
					Saving = Saving - remain_on_end_of_month; // остаток сбережений на начало следующего месяца
					cout << "  " << ++i << "\t" << Saving << "\t\t" << remain_on_end_of_month << "\t\t" << power_end << endl;
				}

			cout << endl;

			cout << "Количество месяцев " << --i << endl;

			system("pause");
			system("cls");

			goto start;

		break;
#pragma endregion

#pragma region Task4
		case 4:

			int Last_numbers, Number_4, first_number, temp_number, sum_of_last_numbers, final_sum;

			cout << "\nЗадача №4\n\n";

			cout << "4.Дано натуральное число n (n<9999) и число m.\n";
			cout << "Найти сумму m-последних цифр числа n.\n" << endl;

mark4:
			cout << "Введите число n<9999:\n";
			cout << "n=";
			cin >> Number_4;

				if (Number_4 >= 9999)
				{
					cout << "Число должно быть меньше 9999.\n";
					cout << "Введите число еще раз.\n";
					goto mark4;
				}

				cout << "Введите число m:\n";
				cout << "m=";
				cin >> Last_numbers;

				first_number = Number_4 % 10;//последнее число, единичный разряд 
				temp_number = Number_4;

				for (sum_of_last_numbers = 0, i = 1; i < Last_numbers; i++)
				{
					temp_number = temp_number / 10;
					sum_of_last_numbers += temp_number % 10;
				}

				final_sum = first_number + sum_of_last_numbers;

				cout << "Сумма последних " << Last_numbers << " равна " << final_sum << endl;

				cout << endl;

			system("pause");
			system("cls");

			goto start;

		break;
#pragma endregion

#pragma region Task5
		case 5:

			int temp_num1, temp_num2, Power_number, remain_num, res;

			cout << "\nЗадача №5\n";

			cout << "5.Натуральное число из n цифр является число Армстронга,\n";
			cout << "если сумма его цифр возведенных в n-ую степень равна\n";
			cout << "самому числу. Получите все  эти числа состоящие из трех\n";
			cout << "и четырех цифр (пример 1³ + 5³ + 3³ = 153 ).\n" << endl;

			Power_number = 0;
			res = 0;

			for (i = 100; i <= 9999; i++)
			{
				temp_num1 = i;
				temp_num2 = i;

				while (temp_num1 != 0)
				{
					temp_num1 /= 10;
					Power_number++; //количество цифр, она же степень числа
				}

				while (temp_num2 != 0)
				{
					remain_num = temp_num2 % 10;
					res += pow(remain_num, Power_number);//сумма чисел в степени Power_number					
					temp_num2 /= 10;
				}

				if (res == i)
				{
					cout << i << endl;
				}

				Power_number = 0; // сбрасываем значение
				res = 0;//сбрасываем значение

			}

			cout << endl;

			system("pause");
			system("cls");

			goto start;

		break;

#pragma endregion

#pragma region Task6
		case 6:

			int remainder, temp_6, remainder_next, High;

			cout << "\nЗадача №6\n";

			cout << "6.Найти все числа кратные семи, и сумма цифр которых также кратна семи\n";
			cout << "Введите верхнюю границу N\n";
			cout << "N=";
			cin >> High;

			for (i = 7; i <= High; i++)
			{
				temp_6 = i;

				if (i % 7 == 0)
				{

					remainder = i % 10;

					while (temp_6 >= 1)
					{
						temp_6 = temp_6 / 10;
						remainder_next = temp_6 % 10;
						remainder += remainder_next;
					}

					if (remainder % 7 == 0)
					{
						cout << "i=" << i << "\t" << i / 7 << "\t" << "s=" << remainder << endl;
					}
				}
			}

			cout << endl;

			system("pause");
			system("cls");

			goto start;

		break;
#pragma endregion

#pragma region Task7
		case 7:

			int decimal, ostatok, celoe, itog, decimall;

			cout << "\nЗадача №7\n";

			cout << "\n7. Перевести целое число из десятичной системы счисления в \n";
			cout << "восьмеричную, используя алгоритм деления на 8.\n";

			cout << endl;

			cout << "Введите десятичное число х:\n";
			cout << "х = ";

			cin >> decimall;

			decimal = decimall;
			i = 10;

			itog = decimal % 8;

				while (decimal >= 8)
				{

					decimal = decimal / 8;
					ostatok = (decimal % 8) * i;
					i = i * 10;
					itog += ostatok;

				}

			cout << endl;

			cout << "Число " << decimall << " в восьмиричной систиеме равно " << itog << endl;

			cout << endl;

			system("pause");
			system("cls");

			goto start;

		break;
#pragma endregion

#pragma region Default

		default:

mark_def:
			int z;

			cout << "\nДля выхода из задания нажмите 0.\n";
			cout << "Для продолжения введите 1.\n";

			cin >> z;

				if (z == 0)
				{
					goto end;
				}
				else if (z == 1)
				{
					goto start;
				}

			goto mark_def;

		break;
#pragma endregion

		}

	} while (number);

end:

	cout << "\nСпасибо!\n";
	system("pause");
}