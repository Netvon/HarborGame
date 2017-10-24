#pragma once
#include <cstddef>
#include <iostream>

template <class T>
class Vector {
	T *_array;
	std::size_t _capacity;
	std::size_t _used;
public:
	Vector() : Vector(16) { };

	Vector(std::size_t cap) : _array{ new T[cap] },
		_capacity{ cap },
		_used{ 0 } { };

	virtual ~Vector()
	{
		if (_array != nullptr)
			delete[] _array;
	}

	Vector(const Vector &v) : _array{ new T[v._capacity] },
		_capacity{ v._capacity },
		_used{ v._used }
	{
		for (std::size_t i = 0; i < _used; ++i) {
			_array[i] = v._array[i];
		}
	}

	Vector<T> &operator=(const Vector<T> &v)
	{
		if (&v == this)
			return *this;

		if (_array != nullptr)
			delete[] _array;

		_array = new T[v._capacity];
		_capacity = v._capacity;
		_used = v._used;

		for (std::size_t i = 0; i < _used; ++i) {
			_array[i] = v._array[i];
		}

		return *this;
	}

	Vector(Vector<T> &&v) : _array{ v._array },
		_capacity{ v._capacity },
		_used{ v._used }
	{
		v._array = nullptr;
		v._used = v._capacity = 0;
	}

	Vector<T> &operator=(Vector<T> &&v)
	{
		if (&v == this)
			return *this;

		if (_array != nullptr)
			delete[] _array;

		_array = v._array;
		_capacity = v._capacity;
		_used = v._used;

		v._array = nullptr;
		v._used = v._capacity = 0;

		return *this;
	}

	std::size_t capacity() const
	{
		return _capacity;
	}

	void push_back(T value)
	{
		if (_used + 1 > _capacity)
			alloc_new();

		_array[_used++] = value;
	}

	std::size_t size() const
	{
		return _used;
	}

	T get(std::size_t index) const
	{
		return _array[index];
	}

	Vector<T>& pop_back() {
		if (_used == 0)
			return *this;

		size_t newSize = _used - 1;
		T* temp = new T[newSize];
		_used = newSize;
		_capacity = newSize;

		for (std::size_t i = 0; i < newSize; i++)
		{
			temp[i] = _array[i];
		}

		delete[] _array;
		_array = temp;

		return *this;
	}

	Vector<T>& pop_index(size_t index)
	{
		if (_used == 0)
			return *this;

		size_t newSize = _used - 1;
		T* temp = new T[newSize];
		_used = newSize;
		_capacity = newSize;

		size_t y = 0;

		for (std::size_t i = 0; i < newSize; i++)
		{
			temp[i] = _array[y];

			if (i + 1 == index)
				y += 2;
			else
				y++;
		}

		delete[] _array;
		_array = temp;

		return *this;
	}

	const T* getArray() const {
		return _array;
	}

	bool contains(const T& item) const {
		;
		for (std::size_t i = 0; i < _used; i++)
		{
			if (_array[i] == item)
				return true;
		}

		return false;
	}

private:
	void alloc_new() {

		if (_used == 0)
			_used = 1;

		_capacity = _used * 2;
		T* temp = new T[_capacity];

		for (std::size_t i = 0; i < _used; i++)
		{
			temp[i] = _array[i];
		}

		delete[] _array;
		_array = temp;
	}
};