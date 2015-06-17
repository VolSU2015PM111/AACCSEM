#pragma once
#include "Algorithm.h"
#include "EyeClassificationMacroses.h"
#include "functions.h"

namespace EyeMomentClassification
{
	class viterbyPatch
	{
	private:

		std::vector<eyeMomentsClasses>classes[NClasses];
		std::vector<StateProbility> Storage;
		int lastnumber;
	public:
		viterbyPatch(const int& N, const StateProbility& startP);
		viterbyPatch(const viterbyPatch& vps);
		~viterbyPatch();
		void push(const eyeMomentsClasses& Class, const viterbyPatch& Value, const eyeMomentsClasses& state);
		StateProbility& Probability(const int &i);
		const eyeMomentsClasses& operator()(const eyeMomentsClasses &i,const unsigned int &j);
		viterbyPatch &operator=(const viterbyPatch&vps);
	};

}