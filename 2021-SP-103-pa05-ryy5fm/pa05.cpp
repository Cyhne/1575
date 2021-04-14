/* Sample tester (for debugging, add the -g flag if you want to use gdb)
 * We've included std::list below to show you how your types should behave.
 * Test all your MyList functions here or in multiple mains.
 * Hint: Build and test one function at a time!!
 */

// USE THIS TO TEST, BUT REMOVE LATER TO VALIDATE YOUR OWN IMPLEMENTAION
#include <list>
using namespace std;
// Uncomment this to test with your own list implementation
#include "MyList.h"

int main()
{
    // Uncomment this to test with your own list implementation
    MyList<int> l;
    //std::list<int> l;


    l.push_back(100);
    l.printList();
    cout << endl;
    l.push_back(200);
    l.printList();
    cout << endl;
    l.push_back(300);
    l.printList();
    cout << endl;
    l.push_front(90);
    l.printList();
    cout << endl;
    l.push_front(80);
    l.printList();
    cout << endl;
    l.push_front(70);
    l.printList();
    cout << endl;
    cout << endl;

    cout << "ERASE TEST" << endl;
    l.erase(4);
    l.printList();
    cout << endl;

    cout << "INSERT TEST" << endl;
    l.insert(l.begin(), 3);
    l.insert(4, 20);
    l.printList();
    cout << endl;

    cout << "BEGIN ASSIGN TEST" << endl;
    l.assign(10,10);
    l.printList();
    cout << "SIZE: " << l.size() << endl;
    cout << endl;
    cout << "POP" << endl;
    l.pop_front();
    l.printList();
    cout << "PUSHED" << endl;
    l.push_back(800);
    l.printList();
    l.push_front(800);
    l.push_front(800);
    l.printList();
    cout << l.front() << endl;
    cout << l.back() << endl;
    cout << l.size() << endl;
    cout << endl;
    cout << endl;

    cout << "REMOVE" << endl;
    l.remove(1);
    l.printList();
    cout << endl;

    cout << "CLEAR TEST" << endl;
    l.clear();
    l.printList();
    cout << "EMPTY? " << l.empty() << endl; // 1 = Empty , 0 = Not
    cout << endl;
    cout << endl;

    cout << "CLEAR EMPTY ARRAY? " << endl;
    l.clear();

    l.push_front(100);
    l.printList();
    cout << endl;
    l.push_front(200);
    l.printList();
    cout << endl;
    l.push_front(300);
    l.printList();
    cout << endl;
    l.push_front(90);
    l.printList();
    cout << endl;
    l.push_front(80);
    l.printList();
    cout << endl;
    l.push_front(70);
    l.printList();
    cout << endl;
    cout << endl;
    // Uncomment this to test with your own list implementation

    cout << "OPERATOR EQUALS TEST" << endl;
    MyList<int> sink;
    sink = l;
    sink.printList();
    cout << sink.front() << endl;
    cout << sink.back() << endl;

    cout << endl;

    cout << "COPY PUSHBACK TEST" << endl;
    l.push_back(5);
    l.printList();
    cout << endl;
    sink.push_back(10);
    cout << "l list" << endl;
    l.printList();
    cout << "sink list" << endl;
    sink.printList();
    cout << endl;
    cout << endl;

    cout << "COPY CONSTRUCTOR TEST" << endl;
    MyList<int> test(l);
    test.printList();
    cout << test.front() << endl;
    cout << test.back() << endl;
    cout << endl;

    cout << "REVERSE TEST" << endl;
    l.printList();
    l.reverse();
    cout << "REVERSED" << endl;
    l.printList();
    cout << l.front() << " " << l.back() << endl;

/*
    int j = 0;
    for(auto i = 0; i < l.size(); i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }
    cout << j << endl;
*/
   return 0;
}
