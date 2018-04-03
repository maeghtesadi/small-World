#pragma once
#include "Observer.h"

template <class T>
class Subject{
public:
	virtual void add(Observer<T> o) = 0;
	virtual void remove(Observer<T> o) = 0;
	virtual void notify(T update) = 0;
}