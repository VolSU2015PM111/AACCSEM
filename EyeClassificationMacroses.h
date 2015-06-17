#pragma once
#ifdef ALGORITHMCLASSDLL_EXPORTS
#define ALGORITHMCLASSDLL_API __declspec(dllexport) 
#else
#define ALGORITHMCLASSDLL_API __declspec(dllimport) 
#endif


#define SQRT(a) ((a)*(a))