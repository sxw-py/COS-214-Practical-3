#include "Leaf.h"

Leaf::Leaf(int cap) : capacity(cap), isOpen(false) {}

void Leaf::open()
{
	this->isOpen = true;
}

void Leaf::close()
{
	this->isOpen = false;
}

bool Leaf::reportStatus() const
{
	return this->isOpen;
}

int Leaf::getCapacity() const
{
	return this->capacity;
}
