#ifndef  HEADER_H
#define _HEADER_H
#include <string>
#include <set>
#include <vector>
using namespace std;

template <typename T>
class Tcontainer {
private:
	vector T* elements;
	int max_size;
	int size:
	int step;
	int pas;
	/*realloc*/
public:
	void set(size_t step, T item);
	T get(size_t step) const;

};
#endif 
