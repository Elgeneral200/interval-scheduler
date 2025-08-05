#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Interval {
public:
    int start, end;
    Interval(int s, int e);
    void display();
};

class Scheduler {
private:
    std::vector<int> rooms;
public:
    int intervalPartitioning(std::vector<Interval>& intervals);
};