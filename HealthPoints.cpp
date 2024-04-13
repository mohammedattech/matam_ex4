#include "HealthPoints.h"
HealthPoints::HealthPoints(int healthPoints):
m_maxHealthPoints(healthPoints),
m_healthPoints(healthPoints)
{
    if(healthPoints<=0)
    {
        throw HealthPoints::InvalidArgument();
    }
}
int HealthPoints::gethealth() const
{
    return m_healthPoints;
}
HealthPoints& HealthPoints::operator+=(int healthPoints)
{
    m_healthPoints+=healthPoints;
    if(m_healthPoints > m_maxHealthPoints)
    {
        m_healthPoints=m_maxHealthPoints;
    }
    if(m_healthPoints < 0)
    {
        m_healthPoints=0;
    }
    return *(this);
}
HealthPoints HealthPoints::operator+(int healthPoints)
{
    HealthPoints result(*(this));
    return (result+=healthPoints);
}
HealthPoints operator+(int heal,HealthPoints& healthPoints)
{
    return healthPoints+heal;
}
HealthPoints& HealthPoints::operator-=(int healthPoints)
{
    return (*this)+= -healthPoints;
}
HealthPoints HealthPoints::operator-(int healthPoints)
{
    return (*this)+ -healthPoints;
}

bool operator==(const HealthPoints&h1,const HealthPoints& h2)
{
    return h1.m_healthPoints==h2.m_healthPoints;
}

bool operator!=(const HealthPoints&h1,const HealthPoints&h2)
{
    return !(h1==h2);
}
bool operator<(const HealthPoints&h1,const HealthPoints& h2)
{
    return h1.m_healthPoints<h2.m_healthPoints;
}
bool operator>=(const HealthPoints&h1,const HealthPoints&h2)
{
    return !(h1<h2);
}
bool operator<=(const HealthPoints&h1,const HealthPoints&h2)
{
    return h2>=h1;
}
bool operator>(const HealthPoints&h1,const HealthPoints&h2)
{
    return h2<h1;
}
std::ostream& operator<<(std::ostream& os,const HealthPoints& healthPoints )
{
    return os<<healthPoints.m_healthPoints<<'('<<healthPoints.m_maxHealthPoints<<')';
}
