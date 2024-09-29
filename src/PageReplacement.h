#ifndef PageReplacement_H
#define PageReplacement_H

#pragma once

#include <vector>
#include <queue>
#include <algorithm>

class PageReplacement
{
public:
    PageReplacement();
    ~PageReplacement();
    int simulateFIFO(const std::vector<int>& pages, unsigned long numFrames);
    int simulateOTM(const std::vector<int>& pages, unsigned long numFrames);
    int simulateLRU(const std::vector<int>& pages, unsigned long numFrames);

private:

};

#endif