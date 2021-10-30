#include <iostream>
#include <string>
#include "LinkedList.h"


using namespace std;


int main() {
    LinkedList<char> lst;
    try{
        while(true) {
            string cmnd;
            cin >> cmnd;
            if (cmnd == "push_back") {
                char c;
                cin >> c;
                lst.push_back(c);
            } else if (cmnd == "push_front") {
                char c;
                cin >> c;
                lst.push_front(c);
            } else if (cmnd == "pop_back") {
                lst.pop_back();
            } else if (cmnd == "pop_front") {
                lst.pop_front();
            }
            cout << lst << "\n";
        }
    }
    catch(const char *c){
        cout << c << "\n";
    }
    return 0;
}
