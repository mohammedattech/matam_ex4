#ifndef HEALTH_POINTS_EX4
#define HEALTH_POINTS_EX4
#include <iostream>
class HealthPoints
{
public:
    HealthPoints(int healthPoints=DEFULT_HEALTH);
    HealthPoints(const HealthPoints&)=default;
    ~HealthPoints()=default;
    HealthPoints& operator=(const HealthPoints&)=default;
    HealthPoints& operator+=(int healthPoints);
    HealthPoints& operator-=(int healthPoints);
    HealthPoints operator+(int healthPoints);
    HealthPoints operator-(int healthPoints);
    friend bool operator==(const HealthPoints&,const HealthPoints&) ;
    friend bool operator<(const HealthPoints&,const HealthPoints&);
    friend std::ostream& operator<<(std::ostream&,const HealthPoints& healthPoints);
    class InvalidArgument {};
    int gethealth() const;
    static const int DEFULT_HEALTH = 100;

private:
    int m_maxHealthPoints;
    int m_healthPoints;
};
HealthPoints operator+(int heal,HealthPoints& healthPoints);
HealthPoints operator-(int heal,HealthPoints& HealthPoints);
bool operator>(const HealthPoints&,const HealthPoints&);
bool operator>=(const HealthPoints&,const HealthPoints&);
bool operator!=(const HealthPoints&,const HealthPoints&);
bool operator<=(const HealthPoints&,const HealthPoints&);
#endif