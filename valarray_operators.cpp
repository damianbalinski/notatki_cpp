#include <iostream>
#include <valarray>

using namespace	std;

void print(valarray<int> arr)
{
	cout << "INT : ";
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

void print(valarray<bool> arr)
{
	cout << "BOOL: ";
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

int main()
{
	// KONTENERY
	valarray<int> arr = { 1, 2, 3, 4, 5 };
	valarray<int> rarr = { 1, 2, 3, 4, 5 };
	valarray<int> arr1 = { 1, 2, 3, 4, 5 };
	valarray<int> arr2 = { 1, 2, 3, 4, 5 };
	valarray<size_t> ids = { 0, 2 };
	valarray<bool> bools = { true, true, false, false, true };

	// TABLICE POMOCNICZE
	auto my_slice_array = arr[slice(1, 2, 3)];
	auto my_gslice_array = arr[gslice(1, { 2 }, { 3 })];
	auto my_mask_array = arr[arr > 3];
	auto my_indirect_array = arr[ids];

	// SELEKTORY/MASKI
	auto my_slice = slice(1, 2, 3);
	auto my_gslice = gslice(1, { 2 }, { 3 });

	// ZMIENNE
	int n = 2;
	int val = 2;
	bool bol = true;
	int id = 2;
	auto list = { 1, 2, 3, 4 };

	// PRZYPISANIA
	//arr = arr;					// przypisanie lwartosci
	//arr = rarr;					// przypisanie rwartosci
	//arr = val;					// przypisanie kazdemu elementowi wartosci val
	//arr = my_slice_array;		// wynik selektora
	//arr = my_gslice_array;		// wynik seletora uogolnionego
	//arr = my_mask_array;		// maska tablicy
	//arr = my_indirect_array;	// tablica posrednia
	//arr = list;					// lista inicjalizujaca

	// DOSTEPU - zwraca element lub liste indeksowanych elementow
	//arr[id];					// ilczba (zwraca reference do elementu)
	//arr[my_slice];				// selektor (zwraca slice_array)
	//arr[my_gslice];				// selektor uogolniony (zwraca gslice_array)
	//arr[ids];					// tablica wartosci logiczych (zwraca maske tab.)
	//arr[bools];					// talica indeksow (zwraca tab. posrednia)

	// ROZSZERZONEGO PRZYPISANIE - przypisanie kolejno dla kazdego elementu
	// jesli tablie maja rozne rozmiary zachowanie jest niezdefiniowane
	//arr += arr2;	arr += val;
	//arr -= arr2;	arr -= val;
	//arr *= arr2;	arr *= val;
	//arr /= arr2;	arr /= val;
	//arr %= arr2;	arr %= val;
	//
	//arr &= arr2;	arr &= val;
	//arr |= arr2;	arr |= val;
	//arr ^= arr2;	arr ^= val;
	//arr <<= arr2;	arr <<= val;
	//arr >>= arr2;	arr >>= val;

	// ARYTMETYCZNE
	//+arr;		// unarny
	//-arr;		// unarny
	//arr1 + arr2;		arr + val;		val + arr;
	//arr1 - arr2;		arr - val;		val - arr;
	//arr1 * arr2;		arr * val;		val * arr;
	//arr1 / arr2;		arr / val;		val / arr;
	//arr1 % arr2;		arr % val;		val % arr;

	// BITOWE
	//~arr;		// unarny
	//arr1 & arr2;		arr & val;		val & arr;
	//arr1 | arr2;		arr | val;		val | arr;
	//arr1 ^ arr2;		arr ^ val;		val ^ arr;
	//arr1 << arr2;		arr << val;		val << arr;
	//arr1 >> arr2;		arr >> val;		val >> arr;

	// LOGICZNE - tworza tablice wartosci logicznych, pole ma wartosc
	// true jesli odpowiadajacy element spelnia warunek logiczny
	//!arr;		// unarny
	//arr1 && arr2;		arr && bol;		bol && arr;
	//arr1 || arr2;		arr || bol;		bol || arr;

	// POROWNANIA - worzy tablice wartosci logicnzych, pole ma wartosc
	// true, jesli odpowiadajacy element spelnia warunek logiczny
	//arr1 == arr2;		arr == val;		val == arr;
	//arr1 != arr2;		arr != val;		val != arr;
	//arr1 < arr2;		arr < val;		val < arr;
	//arr1 <= arr2;		arr <= val;		val <= arr;
	//arr1 > arr2;		arr > val;		val > arr;
	//arr1 >= arr2;		arr >= val;		val >= arr;


	// TEST
	valarray<int> v1 = { 1, 2, 3, 4, 5 };
	valarray<int> v2 = { 5, 4, 3, 2, 1 };
	auto res = (4 == v1);

	print(res);
	return 0;
}