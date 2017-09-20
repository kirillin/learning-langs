/*
 *	Linked list from my memory :)
 *	simple stack
 */
#include <iostream>
#include <iomanip>

using namespace std;

struct Data {
	float x;
	float y;
	float z;
};

struct Element {
  Data pos;
  Element* next;
  Element* prev;
};

Element* getLast(Element &listheader) {
  Element* last = &listheader;
  while ((*last).next != &listheader) {
	last = getLast(*(*last).next);
  }
  return last;
}

void addLast(Element &listheader, Data pos) {
  Element* last = getLast(listheader);
  cout <<  pos  << " : "<< (*last).next << endl;
  Element newelement;
  newelement.pos = pos;
  newelement.next = &listheader;
  newelement.prev = last;
  (*last).next = &newelement;
}

void printList(Element &listheader) {
  if (listheader.next != &listheader) {
	int count = 0;
	Element current_element = *listheader.next;
	while (current_element.next != &listheader) {
	  cout << count << setw(3) << current_element.pos << endl;
	  count++;
	}
  } else {
	  cout << "List is empty!" << endl;
  }
}


int main2(int argc, char **argv) {
  Element listheader = {{0, 0, 0}, &listheader, &listheader};
  cout << "header: " << &listheader << endl;

  Data pos = {1,2,3};
  addLast(listheader, pos);
  addLast(listheader, pos);
  addLast(listheader, pos);

  printList(listheader);

  return 0;
}
