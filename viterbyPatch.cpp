#include "stdafx.h"
#include "viterbyPatch.h"

namespace EyeMomentClassification
{
	viterbyPatch::viterbyPatch(const int& N, const StateProbility& startP) :Storage(N)
	{
		Storage[0] = startP;
		lastnumber = N;
		for (int i = 0; i < NClasses; i++)
		{
			classes[i].push_back((eyeMomentsClasses)i);
		}
	}
	viterbyPatch::viterbyPatch(const viterbyPatch& vps)
	{
		Storage = vps.Storage;
		lastnumber = vps.lastnumber;
		for (int i = 0; i < NClasses; i++)
			classes[i] = vps.classes[i];
	}
	viterbyPatch::~viterbyPatch()
	{
	}
	void viterbyPatch::push(const eyeMomentsClasses& Class, const viterbyPatch& Value, const eyeMomentsClasses& state)
	{
		classes[Class] = Value.classes[state];
		classes[Class].push_back(Class);
	}
	StateProbility& viterbyPatch::Probability(const int &i)
	{
		return Storage[i];
	}
	viterbyPatch &viterbyPatch::operator=(const viterbyPatch&vps)
	{
		if (lastnumber != lastnumber)
		{
			lastnumber = vps.lastnumber;
		}

		Storage = vps.Storage;
		for (int i = 0; i < NClasses; i++)
			classes[i] = vps.classes[i];
		return *this;
	}
	const eyeMomentsClasses& viterbyPatch::operator()(const eyeMomentsClasses &i, const unsigned int &j)
	{
		return classes[i][j];
	}
}