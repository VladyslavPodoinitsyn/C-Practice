#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

#include <iostream>
using namespace std;

class TimeSpan {
public:
    // Constructors
    TimeSpan();
    TimeSpan(int hours);
    TimeSpan(int minutes, int seconds);
    TimeSpan(int hours, int minutes, int seconds);
    TimeSpan(double seconds);
    
    // Getters
    int hours() const;
    int minutes() const;
    int seconds() const;
    
    // Setters
    void set_time(int hours, int minutes, int seconds);

    // Operator Overloads
    TimeSpan operator+(const TimeSpan& other) const; 
    TimeSpan operator-(const TimeSpan& other) const; 
    TimeSpan operator-() const; 

    bool operator==(const TimeSpan& other) const; 
    bool operator!=(const TimeSpan& other) const; 
    bool operator<(const TimeSpan& other) const; 
    bool operator<=(const TimeSpan& other) const; 
    bool operator>(const TimeSpan& other) const; 
    bool operator>=(const TimeSpan& other) const; 

    TimeSpan& operator+=(const TimeSpan& other); 
    TimeSpan& operator-=(const TimeSpan& other); 
    
    // Stream I/O
    friend ostream& operator<<(ostream& os, const TimeSpan& ts);
    friend istream& operator>>(istream& is, TimeSpan& ts);

private:
    // Helper function to normalize the time (carry over minutes and seconds)
    void normalize();

    int hours_;   
    int minutes_; 
    int seconds_; 
};

#endif
