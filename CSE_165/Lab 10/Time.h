#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    ~Time();

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    void print() const;

    Time operator+(const Time& other) const;
    Time& operator++(); // prefix
    Time operator++(int); // postfix

private:
    int hours_;
    int minutes_;
    int seconds_;

    void normalize(); // helper method to ensure valid time format
};

Time::Time(int hours, int minutes, int seconds) :
    hours_(hours), minutes_(minutes), seconds_(seconds)
{
    normalize();
}

Time::~Time()
{
}

int Time::getHours() const
{
    return hours_;
}

int Time::getMinutes() const
{
    return minutes_;
}

int Time::getSeconds() const
{
    return seconds_;
}

void Time::setHours(int hours)
{
    hours_ = hours;
    normalize();
}

void Time::setMinutes(int minutes)
{
    minutes_ = minutes;
    normalize();
}

void Time::setSeconds(int seconds)
{
    seconds_ = seconds;
    normalize();
}

void Time::print() const
{
    std::cout << hours_ << " hours, "
              << minutes_ << " minutes, "
              << seconds_ << " seconds" << std::endl;
}

Time Time::operator+(const Time& other) const
{
    int total_seconds = seconds_ + other.seconds_;
    int extra_minutes = total_seconds / 60;
    int seconds = total_seconds % 60;

    int total_minutes = minutes_ + other.minutes_ + extra_minutes;
    int extra_hours = total_minutes / 60;
    int minutes = total_minutes % 60;

    int hours = hours_ + other.hours_ + extra_hours;

    return Time(hours, minutes, seconds);
}

Time& Time::operator++()
{
    hours_++;
    normalize();
    return *this;
}

Time Time::operator++(int)
{
    Time old(*this);
    operator++();
    return old;
}

void Time::normalize()
{
    while (seconds_ < 0) {
        seconds_ += 60;
        minutes_--;
    }
    while (seconds_ >= 60) {
        seconds_ -= 60;
        minutes_++;
    }

    while (minutes_ < 0) {
        minutes_ += 60;
        hours_--;
    }
    while (minutes_ >= 60) {
        minutes_ -= 60;
        hours_++;
    }

    while (hours_ < 0) {
        hours_ += 24;
    }
    while (hours_ >= 24) {
        hours_ -= 24;
    }
}

#endif
