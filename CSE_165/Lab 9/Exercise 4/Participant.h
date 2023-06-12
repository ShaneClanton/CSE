#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include <string>

#include "Sortable.h"

class Participant : public Sortable {
private:
    std::string m_name;
    int m_age;
    double m_score;

public:
    Participant(std::string name, int age, double score) : m_name(name), m_age(age), m_score(score) {}

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
    double getScore() const { return m_score; }

    virtual bool compare(const Sortable* other) {
        const Participant* otherParticipant = dynamic_cast<const Participant*>(other);
        if (otherParticipant != nullptr) {
            if (m_score != otherParticipant->getScore()) {
                return m_score < otherParticipant->getScore();
            } else if (m_age != otherParticipant->getAge()) {
                return m_age > otherParticipant->getAge();
            } else {
                return m_name > otherParticipant->getName();
            }
        } else {
            // other is not a Participant, so it must be a Circle
            return true;
        }
    }

    virtual void print() {
        std::cout << m_name << "\t" << m_age << "\t" << m_score << std::endl;
    }
};

#endif
