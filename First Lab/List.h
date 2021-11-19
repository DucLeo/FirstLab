#include<iostream>

using namespace std;

class List {
private:
	class List_Element {
	public:
		int n;
		List_Element* next;
		List_Element* prev;
		List_Element(int n = int(), List_Element* prev = NULL, List_Element* next = NULL) {
			this->n = n;
			this->prev = prev;
			this->next = next;
		}
	};

	List_Element* head;
	List_Element* tail;
	size_t size;

public:
	List();
	~List();

	size_t get_size() {
		return size;
	}

	bool isEmpty() {
		if (head == NULL) return true;
		else return false;
	}

	void push_back(int x) {
		if (isEmpty()) head = tail = new List_Element(x);
		else {
			tail->next = new List_Element(x, tail, NULL);
			tail = tail->next;
		}
		size++;
	}

	void push_front(int x) {
		if (isEmpty()) head = tail = new List_Element(x);
		else {
			head->prev = new List_Element(x, NULL, head);
			head = head->prev;
		}
		size++;
	}

	void pop_back() {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (size == 1) {
				List_Element* temporary = head;
				head = NULL;
				tail = NULL;
				delete temporary;
				size--;
			}
			else {
				List_Element* temporary = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temporary;
				size--;
			}
		}
	}

	void pop_front() {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (size == 1) {
				List_Element* temporary = head;
				head = NULL;
				tail = NULL;
				delete temporary;
				size--;
			}
			else {
				List_Element* temporary = head;
				head->next->prev = NULL;
				head = head->next;
				delete temporary;
				size--;
			}
		}
	}

	void clear() {
		while (head != NULL)
			pop_front();
	}

	void insert(int x, size_t index) {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (index == 0) push_front(x);
			else {
				if (index < 0) throw invalid_argument("Failed to execute the function 'insert'.\n");
				else if (index > size - 1) throw invalid_argument("Failed to execute the function 'insert'.\n");
				else {
					List_Element* current = head;
					size_t count = 0;
					while (count < index ) {
						current = current->next;
						count++;
					}
					List_Element* new_element = new List_Element(x, current->prev, current);
					current->prev->next = new_element;
					current->prev = new_element;
					size++;
				}
			}
		}
	}

	int at(size_t index) {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (index < 0) throw invalid_argument("Failed to execute the function 'at'.\n");
			else if (index > size - 1) throw invalid_argument("Failed to execute the function 'at'.\n");
			else {
				List_Element* current = head;
				size_t count = 0;
				while (count < index) {
					current = current->next;
					count++;
				}
				return current->n;
			}
		}
	}

	void remove(size_t index) {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (index == 0) pop_front();
			else if (index < 0) throw invalid_argument("Failed to execute the function 'remove'.\n");
			else if (index == size - 1) pop_back();
			else if (index > size - 1) throw invalid_argument("Failed to execute the function 'remove'.\n");
			else {
				List_Element* current = head;
				size_t count = 0;
				while (count < index) {
					current = current->next;
					count++;
				}
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
				size--;
			}
		}
	}
	
	void set(size_t index, int x) {
		if (isEmpty()) throw logic_error("List is empty.");
		else {
			if (index < 0) throw invalid_argument("Failed to execute the function 'set'.\n");
			else if (index > size - 1) throw invalid_argument("Failed to execute the function 'set'.\n");
			else {
				List_Element* current = head;
				size_t count = 0;
				while (count < index) {
					current = current->next;
					count++;
				}
				current->n = x;
			}
		}
	}

	int find_first(List& list2) {
		if ((isEmpty()) || (list2.isEmpty())) throw logic_error("List is empty.");
		else {
			List_Element* current = head;
			List_Element* current2 = list2.head;
			int i = 0, i2 = 0;
			while (current != NULL) {
				if (current->n == current2->n) {
					current2 = current2->next;
					if (current2 == NULL) break;
					i2++;
					current = current->next;
					i++;
				}
				else {
					current = current->next;
					i++;
					current2 = list2.head;
					i2 = 0;
				}
			}
			if (i2 == list2.get_size() - 1) return i-i2;
			else throw invalid_argument("The original list does not contain this list.");
		}
	}


	friend ostream& operator<<(ostream& output, List& list)
	{
		if (list.isEmpty()) output << "List is empty.";
		else {
			List_Element* current = list.head;
			while (current != NULL) {
				output << current->n << (current->next == NULL ? "" : ", ");
				current = current->next;
			}
		}
		return output;
	}
};

List::List() {
	size = 0;
	head = NULL;
	tail = NULL;
}

List::~List() {
	clear();
}