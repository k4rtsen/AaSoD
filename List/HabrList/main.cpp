#include "list.h"

int main()
{
	int n = 1;
	list l;
	cout << "Input value in the list... (0 for exit) \n";
	while (n != 0)
	{
		cout << "Enter: ";
		cin >> n;
		if (n != 0)
			l.push_back(n);
	}
	list l2(l);
	l.show_all();
	l2.show_all();
	l.clear();
	l.show_all();
	l2.show_all();
	cout << l.is_empty() << "; " << l2.is_empty() << endl;
	system("pause");
}
