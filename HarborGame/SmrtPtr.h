#pragma once
template<class T>
class SmrtPtr {
public:
	SmrtPtr() : pointer(nullptr) { }
	SmrtPtr(T* pointer) :pointer(pointer) { }

	SmrtPtr(SmrtPtr<T>& other) {
		pointer = other.pointer;
		other.pointer = nullptr;
	}

	SmrtPtr<T> &operator=(SmrtPtr<T> &other) {
		if (&other == this)
			return *this;

		if (pointer != nullptr)
			delete pointer;

		pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}

	~SmrtPtr()
	{
		if (pointer != nullptr)
			delete pointer;
	}

	template<class TValue = T>
	TValue value() const {
		return dynamic_cast<TValue&>(*pointer);;
	}

private:
	T* pointer;
};