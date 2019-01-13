#include "TestBasicMath.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

TestBasicMath::TestBasicMath()
{
    //ctor
}

TestBasicMath::~TestBasicMath()
{
    //dtor
}
void TestBasicMath::setUp()
{
    m_pBasicMath = new BasicMath();
}

void TestBasicMath::tearDown()
{
    delete m_pBasicMath;
}

void TestBasicMath::testAddition()
{
    CPPUNIT_ASSERT(5 == m_pBasicMath->Addition(2,3));
}

void TestBasicMath::testMultiply()
{
    CPPUNIT_ASSERT(6 == m_pBasicMath->Multiply(2,3));
}
