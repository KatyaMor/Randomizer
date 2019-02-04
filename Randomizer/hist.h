#pragma once

#include <iostream>
#include <functional>
#include <iomanip>
#include <vector>

using namespace std;

void histogram(function<double()> &f, double &lower, double &higher, int &n);