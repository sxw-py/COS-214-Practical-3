#include "Observer.h"
#include "Subject.h"

void Observer::addSubject(Subject* subject)
{
	subjects.push_back(subject);
}

void Observer::removeSubject(Subject* subject)
{
	for (auto it = subjects.begin(); it != subjects.end(); )
	{
		if (*it == subject)
			it = subjects.erase(it);
		else
			it++;
	}
}

Observer::~Observer()
{
	for (auto subject : subjects)
		subject->detach(this);
}
