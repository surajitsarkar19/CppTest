#include <iostream>
#include "templates.h"
#include "enumFactory.h"
#include "checkMaxFactory.h"

using namespace std;

template <typename T> T checkMaxTemplate(T *a, T b)
{
   T sum = 0;
   int i;
   if (b != 0)
   {
      for (i = 0; i < 100; i++)
      {
         sum += (*a++) * b;
         b++;
      }
   }
   else
   {
      for (i = 0; i < 100; i++)
      {
         sum += (*a++) * b;
         b--;
      }
   }
   return sum;
}

/* Define the data structures you need */
define_list(int)
//define_list(float)


#define SOME_ENUM(XX) \
    XX(FirstValue,) \
    XX(SecondValue,) \
    XX(SomeOtherValue,=50) \
    XX(OneMoreValue,=100) \

DECLARE_ENUM(SomeEnum,SOME_ENUM)
DEFINE_ENUM(SomeEnum,SOME_ENUM)

DECLARE_CHECK_MAX(int)
IMPLEMENT_CHECK_MAX(int)


int main(){
    cout<<"Template test";
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i] = i+1;
    }
    int *p = arr;
    int b=100;
    cout<<"checkMaxTemplate b="<< b <<": "<<checkMaxTemplate<int>(p,b)<<endl;
    b=0;
    cout<<"checkMaxTemplate b="<< b <<": "<<checkMaxTemplate<int>(p,b)<<endl;


    cout<<"-------------------checkMax using #define--------------------------"<<endl;
    b=100;
    cout<<"checkMax#Define b="<< b <<": "<<callCheckMax(int,p,b)<<endl;
    b=0;
    cout<<"checkMax#Define b="<< b <<": "<<callCheckMax(int,p,b)<<endl;


    List(int)* intList = new_list(int);
    List(int)* intList1 = new_list(int);
    push_front(intList, 5);
    push_front(intList, 10);
    push_front(intList, 15);

    push_front(intList1, 25);
    push_front(intList1, 4);
    display_element(intList);
    display_element(intList1);

    cout<<SomeEnum::SomeOtherValue<<endl;
    cout<<GetString(SomeEnum::SomeOtherValue)<<endl;
    cout<<GetSomeEnumValue("SecondValue4");
    
    return 0;
}