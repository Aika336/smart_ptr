#pragma once
#include <iostream>

template<typename T> class smart_ptr {
public:
	T* buffer;

	smart_ptr();
	smart_ptr(T*& value);
	smart_ptr(const T value);

	~smart_ptr();

	void changePTR(T*& value);
	T operator* ();
	T operator= (const T value);
};

template<typename T>
inline smart_ptr<T>::smart_ptr() {
	buffer = nullptr;
}

template<typename T>
inline smart_ptr<T>::smart_ptr(T*& value) {
	if (buffer != nullptr) delete buffer;
	buffer = value;
	value = nullptr;
}

template<typename T>
inline smart_ptr<T>::smart_ptr(const T value) {
	buffer = new T(value);
}

template<typename T>
inline smart_ptr<T>::~smart_ptr() {
	if (buffer != nullptr) delete buffer;
}

template<typename T>
inline void smart_ptr<T>::changePTR(T*& value) {
	if (buffer != nullptr) delete buffer;

	buffer = value;
	value = nullptr;
}

template<typename T>
inline T smart_ptr<T>::operator*()
{
	return *buffer;
}

template<typename T>
inline T smart_ptr<T>::operator= (const T value)
{
	*buffer = value;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const smart_ptr<T>& point)
{
	out << point.buffer;
	return out;
}