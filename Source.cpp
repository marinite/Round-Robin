#include "Circle.h"

int main()
{
	double Q = 4;        //квант
	const int N = 4;     //количество поцессов
	int ar_begin[N] = { 1,5,8,11 };  //время начала каждого процесса
	int ar_duration[N] = { 10,7,6,4 };  //длины процессов
	circle* rr = init();
	int time = 1;
	int alltime = 27; //всё время занимаемое процессами
	int current = 1;
	bool exit = 0;
	bool choice = 0;

	for (int i = 0; i < N; i++)
	{
		add(rr, ar_begin, ar_duration, i);
	}

	/*process* p=rr->head;
	for (int i=0; i<N;i++)
	{
		cout << p->begin << endl;
		p = p->next;
	}*/

	while (!exit)
	{
		for (int i = 0; i < Q; i++)
		{
			choice = false;
			process* p = rr->head;
			cout << "takt " << time << ":" << endl;
			for (int i = 0; i < N; i++)
			{
				if ((p->begin <= time) && (p->duration != 0) && (current == p->number))
				{
					p->duration -= 1;
					cout << "process " << p->number << ": +" << endl;
				}
				else if ((p->begin <= time) && (p->duration != 0)) cout << "process " << p->number << ": -" << endl;
				else if ((p->begin > time) || (p->duration == 0)) cout << "process " << p->number << ": 0" << endl;
				
				if ((current == p->number) && (p->duration == 0))
				{
					choice = true;
				}
				p = p->next;
			}
			time++;
			if (time > alltime)
			{
				exit = true;
				break;
			}
			if (choice) break;
		}
		process* p = rr->head;
		for (int i = 0; i < N; i++)
		{
			choice = false;
			if ((current == p->number))
			{
				for (auto k = p->next; k!=p; k = k->next)
				{
					if ((k->begin-1 <= time) && (k->duration != 0))
						current = k->number;
					if (current != p->number)
					{
						choice = true;
						break;
					}
				}
			}
			else p = p->next;
			if (choice) break;
		}
	}

	//del(rr);

	return 0;
}