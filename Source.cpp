#include "Header.h"
#include <fstream>
#include <list>

//Из подряд идущих оставить один
void unique(LIST& list)
{
	int k = 1;
	ptrNODE p = list.get_head()->next;
	while (p->next)
	{
		if (p->next->info->value == p->info->value)
		{
			list.del_after(p);
			p->info->count++;
			//std::cout << "-" << p->info->count << "-";
		}
		else
			p = p->next;
	}
}

int main()
{
	LIST list;
	std::ifstream file("input.txt");
	std::ifstream field("input.txt");
	std::ofstream fileResult("output1.txt");
	list.create_by_queue(file);
	int k;
	list.sorting();

	unique(list);
	list.print();
	std::cout << '\n';

	list.print(fileResult);

	file.close();
	fileResult.close();

	std::cin.get();
	return 0;
}
