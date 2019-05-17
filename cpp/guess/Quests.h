#ifndef UNTITLED_QUESTS_H
#define UNTITLED_QUESTS_H

#include <vector>
#include "util.h"

template<typename T>
class Quests {
public:
    typedef typename std::vector<T> array_type;
    typedef typename array_type::iterator iterator;
    typedef typename array_type::const_iterator const_iterator;

    explicit Quests(const int numQuestions) {
        if (numQuestions < 0) throw std::bad_alloc();
        for (int i = 0; i < numQuestions; ++i)
            queue.push_back(generateQuest<T>());
    }

    T size() {
        return queue.size();
    }

    T &operator[](int index) {
        return queue[index];
    }

    void newQuestion() {
        queue.push_back(generateQuest<T>());
    }

    inline iterator begin() noexcept { return queue.begin(); }

    inline const_iterator cbegin() const noexcept { return queue.cbegin(); }

    inline iterator end() noexcept { return queue.end(); }

    inline const_iterator cend() const noexcept { return queue.cend(); }

private:
    std::vector<T> queue;
};


#endif //UNTITLED_QUESTS_H
