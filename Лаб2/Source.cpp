#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	ArrayList<int> * my_list = new ArrayList<int>(2, 4);
	cout << my_list->is_empty() << "\n";
	cout << my_list->to_string() << "\n";
	for (int i = 0; i < 10; i++)
	{		
		my_list->push(i);
		cout << my_list->to_string() << "\n";
	}
	my_list->insert_at(10, 21);
	cout << my_list->is_empty() << "\n";
	cout << my_list->to_string() << "\n" << my_list->get_size() << "\n";
	my_list->remove_at(5);
	cout << my_list->to_string() << "\n";
	for (int i = 0; i < 10; i++)
		my_list->set(i, 10 - i);
	cout << my_list->to_string() << "\n";
	for (int i = 0; i < 10; i++)
		cout << my_list->get(i) << " ";
	delete my_list;
	system("pause");
}