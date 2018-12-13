#include <iostream>
#include <map>

using namespace std;


int main(){
    // Create map
    map<string, int> studentList;
    studentList["ali"] = 150140103;
    studentList["ahmet"] = 150140102;
    studentList["ayse"] = 150140101;

    // Insert an element
    studentList.insert(make_pair("serra", 150170104));
    
    
    // Print values
    for(auto el : studentList) {
        printf("%s %d\n", el.first.c_str(), el.second);
    }
    
    return 0;
}

