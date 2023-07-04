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
		std::cout << "�����A"<< std::endl;
	}
	~A() {
		std::cout << "����A" << std::endl;
	}
};

int main() {
	{
		ScopedPtr<A> p(new A());
	}
	std::cout << "�����" << std::endl;

	return 0;
}