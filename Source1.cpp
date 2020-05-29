#include "Circle.h"
circle* init()
{
	circle* tmp = new circle;
	tmp->head=NULL;
	return (tmp);
}
void add(circle* rr, int ar_begin[], int ar_duraction[], int i)
{
	process* tmp = new process;
	tmp->begin = ar_begin[i];
	tmp->duration = ar_duraction[i];
	tmp->number = i + 1;
	if (rr->head == NULL)
	{
		rr->head = tmp;
		tmp->next = tmp->prev = tmp;
	}
	else
	{
		process* t = rr->head;
		while (t->next != rr->head) t = t->next;
		t->next = tmp;
		tmp->next = rr->head;
		tmp->prev = t;
		rr->head->prev = tmp;
	}

}

/*int NoNull(circle const* rr)
{
	return rr->head == NULL;
}*/

/*void del(circle* rr)
{
	auto tmp = rr->head;
	while (!NoNull(rr))
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp = tmp->next;
		delete(tmp->prev);
	}
	//else exit(1);
}*/