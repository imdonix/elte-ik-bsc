#pragma once

#include "summation.hpp"

class ComposeArray : public Summation<int, std::vector<int> >
{
protected:
    std::vector<int>  func(const int &e) const override {
        std::vector<int> t;
        t.push_back(e);
        return t;
    }
    std::vector<int>  neutral() const override {
        std::vector<int> t;
        return t;
    }
    std::vector<int>  add(const std::vector<int> &a, const std::vector<int> &b) const override {
        std::vector<int> t = a;
        t.push_back(b[0]);
        return t;
    }
};
