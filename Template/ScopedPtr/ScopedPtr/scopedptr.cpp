#include<iostream>

template<typename T>
class ScopedPtr {
private:
	T* ptr_=nullptr;
public:
	ScopedPtr(T* in) :ptr_(in) {};
	ScopedPtr() {};
	~ScopedPtr() {
		delete ptr_;
	}
	void Reset(T* in=nullptr) {
		if (ptr_ != nullptr) {
			delete ptr_;
		}
		ptr_ = in;
	}
};

class A {
public:
	A() {
		std::cout << "作ったA"<< std::endl;
	}
	~A() {
		std::cout << "死んだA" << std::endl;
	}
};

int main() {
	{
		ScopedPtr<A> p(new A());
	}
	std::cout << "おわり" << std::endl;

	return 0;
}