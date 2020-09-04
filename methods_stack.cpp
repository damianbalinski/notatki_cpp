// metody zdefiniowne dla stack
#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::stack <int, std::deque<int>> s;
	std::stack <int, std::deque<int>> stack;
	auto val = 10;
	int rval = 10;

	s.size();		// OK (size_type) liczba elementow
	s.empty();		// OK (bool) sprawdza, czy stos jest pusty

	s.top();		// OK (reference) referencja do elementu z wierzchu stosu (dodanego jako ostatni)

	s.push(val);	// OK (void) dodaje element na wierzch stosu
	s.push(rval);
	s.pop();		// OK (void) zdejmuje element z wierzchu stosu

	s.swap(stack);	// OK (void) zamienia miejscami kontenery tego samego typu

	s.emplace();	// OK (reference) dodaje element na szczyt stosu, inicjalizuje go pakietem argumentow

	return 0;
}