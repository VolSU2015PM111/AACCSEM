#include "stdafx.h"
#include "Position.h"

namespace EyeMomentClassification
{
	Position::Position(const int& n, const double &TimeBetweenMeasurements) :
		std::vector<EyePosition>(n + 1), timeBetweenMeasurements(1.0 / TimeBetweenMeasurements)
	{
	}

	Position::Position(const Position &position) : std::vector<EyePosition>(position)
	{
		this->timeBetweenMeasurements = position.timeBetweenMeasurements;
	}
	Position::~Position()
	{
	}
	std::vector<double> Position::speedArray()
	{
		vector<double> Speed(size() - 1);
		for (unsigned int i = 0; i < size() - 1; i++)
			Speed[i] = at(i).distance(at(i + 1)) * timeBetweenMeasurements;
		return Speed;
	}
	double Position::speed(const unsigned int &i)
	{
		return at(i).distance(at(i + 1)) * timeBetweenMeasurements;
	}
	std::vector<double> Position::OX()
	{
		vector<double> PositionX(size());
		for (unsigned int i = 0; i < size(); i++)
			PositionX[i] = at(i).OX;
		return PositionX;
	}
	std::vector<double> Position::OY()
	{
		vector<double> PositionY(size());
		for (unsigned int i = 0; i < size(); i++)
			PositionY[i] = at(i).OY;
		return PositionY;
	}
	void Position::push_back(const EyePosition &value)
	{
		vector<EyePosition>::push_back(value);
		erase(begin());
	}
	const double &Position::TimeBetweenMeasurements()
	{
		return timeBetweenMeasurements;
	}
}