#include <iostream>
#include "Foo.h"
#include <memory>
#include <vector>
#include <map>
#include <algorithm>

#include "TestIncludes.h"
using namespace std;

void forEachFunctionality(){

    std::map<std::string, std::vector<int>> map;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    map["one"] = v;

    for(const auto& kvp : map)
    {
      std::cout << kvp.first << std::endl;

      for(auto v : kvp.second)
      {
         std::cout << v << std::endl;
      }
    }

}

void sharedPointerTest(){
    shared_ptr<int> sptr1 = make_shared<int>(100);
    cout<<"Shared ptr value: "<<*sptr1<<endl;

    shared_ptr<Foo> ptr = make_shared<Foo>(32);
    cout<<"Shared foo : "<< ptr->GetFoo()<<endl;
    shared_ptr<Foo> ptr1 = ptr;
    cout<<"Shared foo1 :"<<ptr1->GetFoo()<<endl;

    unique_ptr<Foo> p1 = make_unique<Foo>(87);
    p1->SetFoo(88);
    cout<<"Unique foo :"<<p1->GetFoo()<<endl;
    //unique_ptr<Foo> p2 = p1; //will not work
    unique_ptr<Foo> p2 = move(p1); //will work
    //cout<<"Unique foo :"<<p1->GetFoo();//will get nullptr
    cout<<"Unique foo1 :"<<p2->GetFoo()<<endl;
}


int main()
{
    cout << "Hello world!" << endl;

	//forEachFunctionality();
	//functorExample();
	//sharedPointerTest();
	//rValueReferance();
	//lambdaTest();
	//templateSpecialization();

	runAllRegisteredTestSuits();



    return 0;
}
