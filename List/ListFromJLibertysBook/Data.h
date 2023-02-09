#include <iostream>
#pragma once
using namespace std;

enum { kIsSmaller, kIsLarger, kIsSame };

class Data
{
public:
	Data(int val) :myValue(val) {}
	~Data() {}
	// out in console this value
	void Show() const { cout << myValue << endl; }
	int Compare(const Data& theOtherData) {
		if (myValue < theOtherData.myValue)
			return kIsSmaller;
		else if (myValue > theOtherData.myValue)
			return kIsLarger;
		else
			return kIsSame;
	}
private:
	int myValue;
};