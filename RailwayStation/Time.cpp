#include "Time.h"

Node::Node()
{

	hour = new int(0);
	min = new int(0);

}

Node::Node(int& hour_arg, int& min_arg)
{

	hour = new int(hour_arg);
	min = new int(min_arg);

}

Node::Node(const Node& temp)
{

	hour = new int(*temp.hour);
	min = new int(*temp.min);

}

Node::~Node()
{

	delete hour;
	delete min;

}

Time::Time()
{

	_time = new Node;

}

Time::Time(int& hour_arg, int& min_arg)
{

	_time = new Node(hour_arg, min_arg);

}

Time::Time(const Time& temp)
{

	_time = new Node(*temp._time);

}

Time::~Time()
{

	delete _time;

}

Time& Time::operator=(const Time& tmp)
{

	*_time->hour = *tmp._time->hour;
	*_time->min = *tmp._time->min;

	return *this;

}

bool Time::operator<(const Time& tmp)
{
	return
			*_time->hour > *tmp._time->hour
			||
			*_time->min > *tmp._time->min;

}

bool Time::operator>(const Time& tmp)
{

	return
		*_time->hour < *tmp._time->hour
		||
		*_time->min < *tmp._time->min;

}

bool Time::operator==(const Time& tmp)
{

	return
		*_time->hour < *tmp._time->hour
		&&
		*_time->min < *tmp._time->min;

}

std::istream& operator>>(std::istream& in, Time& time)
{
	in >> *(time._time->hour);
	in >> *(time._time->min);

	return in;

}

std::ostream& operator<<(std::ostream& out, const Time& tmp)
{

	out << " ( " << *(tmp._time->hour) << " : " << *(tmp._time->min) << " ) ";

	return out;

}
