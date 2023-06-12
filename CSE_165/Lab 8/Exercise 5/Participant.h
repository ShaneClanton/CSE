#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include <string>

#include "Sortable.h"

class Participant : public Sortable {

public:
    std::string name;
    int age;
    double score;

    Participant(std::string m_name, int m_age, double m_score) : name(m_name), age(m_age), score(m_score) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getScore() const { return score; }

    // Declare static member variable pointer to function
    static bool (*comp_cb)(const Participant*, const Participant*);

    // Define comparison function that calls the static comparison function pointer
    virtual bool compare(const Sortable* other) {
        const Participant* otherParticipant = dynamic_cast<const Participant*>(other);
        return comp_cb(otherParticipant, this);
    }

    virtual void print() {
        std::cout << name << "\t" << age << "\t" << score << std::endl;
    }
};

#endif
