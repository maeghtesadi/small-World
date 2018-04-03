#pragma once

template <class T>
class Observer {
	virtual void update(T value) = 0;
};


	