#pragma once
#include <vector>

template <class T>
struct SmartVector: std::pmr::vector<T> {
    void update() {
        for (auto const& el: this) {
            if (el.should_delete) {
                this->erase(el);
            }
        }
    }
};
