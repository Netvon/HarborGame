#pragma once

template<class T>
class SmrtPtr {
public:
	SmrtPtr() :pointer(nullptr) {}
	SmrtPtr(T* pointer) :pointer(pointer) { }

	~SmrtPtr()
	{
		if(pointer != nullptr)
			delete pointer;
	}

	T& value() const {
		return *pointer;
	}

private:
	T* pointer;
};