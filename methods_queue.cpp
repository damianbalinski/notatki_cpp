// metody zdefiniowne dla kolejek
#include <iostream>
#include <queue>
#include <deque>

int main()
{
	/*
	 * OZNACZENIAA
	 * Q queue
	 * P priority_queue
	 * - all
	 */

	std::queue<int, std::deque<int>> q;
	std::queue<int, std::deque<int>> queue;
	std::priority_queue<int, std::vector<int>> p;
	std::priority_queue<int, std::vector<int>> prior_queue;
	int val = 10;
	int rval = 10;
	int args = 10;

	q.size();		// OK - (size_type) liczba elementow
	q.empty();		// OK - (bool) sprawdza, czy kolejka jest pusta

	q.front();		// OK Q (reference) referencja do elementu z poczatku kolejki (dodanego jako pierwszy)
	q.back();		// OK Q (reference) referencja do elementu z konca kolejki (dodanego jako ostatni)
	p.top();		// OK P (const_reference) referencja do niemodyfikowalnego elementu z poczatku kolejki(dodanego jako pierwszy)

	q.swap(queue);	// OK - (void) zamienia miejscami kolejki tego samego typu

	q.push(val);	// OK - (void) dodaje element na koniec kolejki
	q.push(rval);	
	q.pop();		// OK - (void) usuwa element z poczatku kolejki

	q.emplace(args);// OK (reference) dodaje element na koniec kolejki, inicjalizuje go pakietem argumentow
	
	return 0;
}