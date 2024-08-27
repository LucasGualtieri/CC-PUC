#include <iostream>

using namespace std;

// https://chatgpt.com/share/64b85aca-6c2d-46ac-bdee-a074188d8fa0
// clear && g++ SmartPointers.cc && ./a.out

template <typename T>
class SharedPointer {

	T* pointer;
	int* referenceCount;
	void* deleterLambda;

	SharedPointer() { }

  public:

	SharedPointer(T* pointer) {
		referenceCount = new int(1);
		this->pointer = pointer;
	}

	// SharedPointer(T* pointer, auto deleterLambda) {
	// 	referenceCount = new int(1);
	// 	this->pointer = pointer;
	// 	this->deleterLambda = deleterLambda;
	// }

	SharedPointer(const SharedPointer& p) {
		this->pointer = p.pointer;
		this->referenceCount = p.referenceCount;
		(*referenceCount)++;
		// cout << "referenceCount: " << to_string(*referenceCount) << endl;
	}

	~SharedPointer() {

		if (--(*referenceCount) == 0) {

			if (deleterLambda); // deleterLambda(pointer);

			else delete pointer;

			delete referenceCount;
		}

		// cout << "referenceCount: " << to_string(*referenceCount) << endl;
	}

	SharedPointer& operator=(const SharedPointer& p) {

		if (this != &p) {

			// Don't undrestand this
			// // Decrement the reference count of the current object
			// if (--(*referenceCount) == 0) {
			// 	delete pointer;
			// 	delete referenceCount;
			// }

			this->pointer		 = p.pointer;
			this->referenceCount = p.referenceCount;
			(*referenceCount)++;
		}

		return *this;
	}


	// T*& operator*() { return pointer; }
	T& operator*() { return *pointer; }
	T& operator[](size_t index) { return pointer[index]; }
};

void foo(SharedPointer<int> p) {

	// for (int i = 5; i < 10; i++) p[i - 5] = 1;
	for (int i = 5; i < 10; i++) cout << p[i - 5] << endl;
	// for (int i = 5; i < 10; i++) cout << (&(*p))[i - 5] << endl; // This works, just fine
	// delete (&(*p)); // how to handle this??? It seems like this is a problem with real smart pointer
}

int main() {

	{
		int* array = new int[5];

		for (int i = 0; i < 5; i++) array[i] = i;

		// SharedPointer<int> smartPointer(array, [](int* array) { delete[] array; });
		SharedPointer<int> smartPointer(array);

		for (int i = 0; i < 5; i++) cout << smartPointer[i] << endl;
		cout << "-----------" << endl;
		foo(smartPointer);
		cout << "-----------" << endl;
		for (int i = 0; i < 5; i++) cout << smartPointer[i] << endl;
		// for (int i = 0; i < 5; i++) cout << (*smartPointer)[i] << endl;
	}

	cout << "end" << endl;
}