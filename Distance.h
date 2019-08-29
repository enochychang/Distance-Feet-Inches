// Distance.h file
#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
// using namespace std;

class Distance
{
  private:
    unsigned feet;
    double inches;
  public:

    Distance();
    Distance(unsigned ft, double in);
    Distance(double in);

    //getters
    unsigned getFeet() const;
    double getInches() const;
    double distanceInInches() const;
    double distanceInFeet() const;
    double distanceInMeters() const;

    const Distance operator+(const Distance &rhs) const;
    const Distance operator-(const Distance &rhs) const;

    friend std::ostream& operator<<(std::ostream &out, const Distance &rhs);

  private:

    void init();
};

#endif
