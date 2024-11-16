// Задание.
// Дан вектор случайных чисел. Создайте ещё один вектор, в котором будут все элементы исходного,
// но без повторений и в отсортированном по убыванию виде. Для выполнения задания необходимо
// использовать промежуточный объект класса map. Использовать обычные алгоритмы сортировки нельзя.

#include<iostream>
#include<vector>
#include<map>
#include<random>
#include<ctime>

void print(const std::vector<int>& x) {
	for (auto& el : x)
		std::cout << el << ' ';
	std::cout << std::endl;
}
// ф-ия заполнения вектора случайными числами:
std::vector<int> rand_vec(const int length) {
	std::vector<int> tmp(length);
	for (auto& el : tmp)
		el = rand() % 10;
	return tmp;
}

// ф-ия сортировки вектора в обратном порядке и без повторения элементов (с помощью контейнера - map):
std::vector<int> sort_vec(const std::vector<int>& x) {
	std::map<int, int> m_map;
	for (auto& el : x)
		m_map.insert(std::make_pair(el, 0));	// закидываем все элементы в map, 
	// а он в свою очередь отсортирует все элементы по возрастанию.
	std::vector<int> tmp;
	std::map<int, int>::reverse_iterator it;
	for (it = m_map.rbegin(); it != m_map.rend(); ++it)		// закидываем из map в новый vector ключи, только в обратном порядке
		tmp.push_back(it->first);
	return tmp;
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	std::cout << "Исходный вектор из 10-ти случайных чисел:\n";
	std::vector<int> v1(10);
	v1 = rand_vec(10);
	print(v1);
	std::cout << "Отсортируем исходный вектор по убыванию и без повторений элементов, получим:\n";
	std::vector<int> v2;
	v2 = sort_vec(v1);
	print(v2);

	return 0;
}