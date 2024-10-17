#include "time_span.h"
#include <cmath> // for rounding
#include <iostream>
using namespace std;

// Constructors
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}
TimeSpan::TimeSpan(int hours) : hours_(hours), minutes_(0), seconds_(0) { normalize(); }
TimeSpan::TimeSpan(int minutes, int seconds) : hours_(0), minutes_(minutes), seconds_(seconds) { normalize(); }
TimeSpan::TimeSpan(int hours, int minutes, int seconds) : hours_(hours), minutes_(minutes), seconds_(seconds) { normalize(); }
TimeSpan::TimeSpan(double seconds) : hours_(0), minutes_(0), seconds_(round(seconds)) { normalize(); }

// Getters
int TimeSpan::hours() const { return hours_; }
int TimeSpan::minutes() const { return minutes_; }
int TimeSpan::seconds() const { return seconds_; }

// Setters
void TimeSpan::set_time(int hours, int minutes, int seconds) {
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
    normalize();
}

// Helper: Normalize time (e.g., 90 seconds -> 1 minute 30 seconds)
void TimeSpan::normalize() {
    if (seconds_ >= 60 || seconds_ < -60) {
        minutes_ += seconds_ / 60;
        seconds_ %= 60;
    }
    if (minutes_ >= 60 || minutes_ < -60) {
        hours_ += minutes_ / 60;
        minutes_ %= 60;
    }
    if (seconds_ < 0 && minutes_ > 0) {
        minutes_--;
        seconds_ += 60;
    }
    if (minutes_ < 0 && hours_ > 0) {
        hours_--;
        minutes_ += 60;
    }
}

// Operators
TimeSpan TimeSpan::operator+(const TimeSpan& other) const {
    return TimeSpan(hours_ + other.hours_, minutes_ + other.minutes_, seconds_ + other.seconds_);
}

TimeSpan TimeSpan::operator-(const TimeSpan& other) const {
    return TimeSpan(hours_ - other.hours_, minutes_ - other.minutes_, seconds_ - other.seconds_);
}

TimeSpan TimeSpan::operator-() const {
    return TimeSpan(-hours_, -minutes_, -seconds_);
}

bool TimeSpan::operator==(const TimeSpan& other) const {
    return (hours_ == other.hours_ && minutes_ == other.minutes_ && seconds_ == other.seconds_);
}

bool TimeSpan::operator!=(const TimeSpan& other) const {
    return !(*this == other);
}

bool TimeSpan::operator<(const TimeSpan& other) const {
    if (hours_ != other.hours_) return hours_ < other.hours_;
    if (minutes_ != other.minutes_) return minutes_ < other.minutes_;
    return seconds_ < other.seconds_;
}

bool TimeSpan::operator<=(const TimeSpan& other) const {
    return (*this < other || *this == other);
}

bool TimeSpan::operator>(const TimeSpan& other) const {
    return !(*this <= other);
}

bool TimeSpan::operator>=(const TimeSpan& other) const {
    return !(*this < other);
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& other) {
    hours_ += other.hours_;
    minutes_ += other.minutes_;
    seconds_ += other.seconds_;
    normalize();
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& other) {
    hours_ -= other.hours_;
    minutes_ -= other.minutes_;
    seconds_ -= other.seconds_;
    normalize();
    return *this;
}

// Stream I/O
ostream& operator<<(ostream& os, const TimeSpan& ts) {
    os << "Hours: " << ts.hours_ << ", Minutes: " << ts.minutes_ << ", Seconds: " << ts.seconds_;
    return os;
}

istream& operator>>(istream& is, TimeSpan& ts) {
    int hours, minutes, seconds;
    is >> hours >> minutes >> seconds;
    ts.set_time(hours, minutes, seconds);
    return is;
}
