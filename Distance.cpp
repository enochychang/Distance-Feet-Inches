#include <iostream>
#include <math.h>
#include "Distance.h"

using namespace std;
using std::ostream;

//private
/*
unsigned feet;
double inches;
*/

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
*/
Distance::Distance() : feet(0), inches(0.0) {}

/* Constructs a distance of ft feet and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(unsigned ft, double in) {

  feet = ft;
  inches = in;
  init();
}

/* Constructs a distance of 0 ft and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(double in) {
  feet = 0;
  inches = in;
  init();
}

/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const {
  return feet;
}

/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const {
  return inches;
}

/* Returns the entire distance as the equivalent amount of inches.
    (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const {
  return (feet * 12.0) + inches;
}

/* Returns the entire distance as the equivalent amount of feet.
    (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const {
  return feet + (inches / 12.0);
}

/* Returns the entire distance as the equivalent amount of meters.
    1 inch equals 0.0254 meters.
    (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const {
  return distanceInInches() * 0.0254;
}

/* Returns the sum of 2 Distances.
*/
const Distance Distance::operator+(const Distance &rhs) const {
  unsigned x = this->feet + rhs.getFeet();
  double y = this->inches + rhs.getInches();
  Distance returnVal(x, y);
  return returnVal;
}

/* Returns the difference between 2 Distances.
*/
const Distance Distance::operator-(const Distance &rhs) const {
  /*The reason why we can't do:
    unsigned x = this->feet - rhs.getFeet();
    double y = this->inches - rhs.getInches();
  One of the problems I thought of was potential negative values being entered
  into the unsigned operand. However, according to main.cpp, all Distance objects
  with unsigned operands are initialized with some positive value so there will 
  be no error there in regards to having some potential negative value entered
  into an unsigned var. But, there is a potential problem that occurs when
  subtracting two unsigned variables. That is, if we get a negative value for
  unsigned, that would be bad. So to avoid this, we can do subtraction of the
  distances in inch form and construct the Distance object with the inch value.
  The Distance object has a constructor that takes and handles if only inches
  are passed in.
  */
  Distance returnVal(distanceInInches() - rhs.distanceInInches());
  return returnVal;
}

/* Outputs to the stream out the Distance in the format:
    feet' inches'' (i.e. 3' 3.41'')
*/
ostream& operator<<(ostream &out, const Distance &rhs) {
  out << rhs.feet << "\' " << rhs.inches << "\"";
  return out;
}

//private:

/* Used by the 2 parameterized constructors to convert any negative values
to positive and inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init() {
  inches = fabs(inches);

  if (inches >= 12) {
    feet += static_cast<int>(inches) / 12;
    inches = fmod(inches, 12.0);
  }
}
