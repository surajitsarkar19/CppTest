#ifndef TESTBASICMATH_H
#define TESTBASICMATH_H

#include <iostream>
#include <string>
#include <list>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
//#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include "BasicMath.h"


using namespace CppUnit;
using namespace std;

class TestBasicMath : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST_SUITE_END();

    public:
        TestBasicMath();
        virtual ~TestBasicMath();

        void setUp();
        void tearDown();

        void testAddition();
        void testMultiply();

    protected:

    private:
        BasicMath *m_pBasicMath;
};

#endif // TESTBASICMATH_H
