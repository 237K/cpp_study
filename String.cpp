//
//  String.cpp
//  cpp_study
//
//  Created by 형성모 on 22/01/2019.
//
//  [string 컨테이너]
//      1. append(sz) : s에 sz를 붙임
//      2. assign(sz) : s에 sz를 할당
//      3. at(i) : i번째 문자열 참조
//      4. begin() : 첫 문자를 가리키는 반복자 반환
//      5. c_str() : c스타일의 문자열 주소 반환
//      6. capacity() : 할당된 메모리 크기 반환
//      7. clear()
//      8. compare(s2)
//      9. copy(buf, n) : buf로 n개의 문자 복사
//      10. data() : 문자열의 배열주소를 반환
//      11. empty()
//      12. end()
//      13. erase(p)
//      14. erase(b, e)
//      15. find(c) / rfind(c)
//      16. insert(n, sz)
//      17. length()
//      18. max_size()
//      19. push_back(c)
//      20. replace(p, n, sz) : p 위치의 n개 문자를 sz로 바꿈
//      21. reserve(n)
//      22. rsize(n)
//      23. rsize(n, c)
//      24. size()
//      25. s2 = s.substr(p) : s2에 p부터의 s문자열을 대입
//      26. swap(s2)
//      27. getline(in, s) : 스트림에서 s로 한줄 읽음
//

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    //생성자
    cout<<"string 생성자"<<endl;
    string t1("Hello");
    const char* p1 = "Hello";
    const char* p2 = p1 + 6;
    
    string s1;
    string s2("Hello");
    string s3("Hello", 2);
    string s4(5, 'H');
    string s5(t1.begin(), t1.end());
    string s6(p1, p2);
    
    cout<<"s1() : "<<s1<<endl;
    cout<<"s2(sz) : "<<s2<<endl;
    cout<<"s3(sz, n) : "<<s3<<endl;
    cout<<"s4(n, c) : "<<s4<<endl;
    cout<<"s5(iter1, iter2) : "<<s5<<endl;
    cout<<"s6(pointer1, pointer2) : "<<s6<<endl<<endl;
    
    //append
    cout<<"append()"<<endl;
    string t2("World");
    const char* p3 = "World";
    const char* p4 = p3 + 6;
    
    string sa1("Hello");
    string sa2("Hello");
    string sa3("Hello");
    string sa4("Hello");
    string sa5("Hello");
    string sa6("Hello");
    string sa7("Hello");
    string sa8("Hello");
    string sa9("Hello");
    string sa10("Hello");
    
    sa1.append(t2);
    cout<<"s.append(s) : "<<sa1<<endl;
    
    sa2.append(t2, 0, 6);
    cout<<"s.append(s, off, n) : "<<sa2<<endl;
    
    sa3.append("World");
    cout<<"s.append(sz) : "<<sa3<<endl;
    
    sa4.append("World", 6);
    cout<<"s.append(sz, n) : "<<sa4<<endl;
    
    sa5.append(t2.begin(), t2.end());
    cout<<"s.append(iter1, iter2) : "<<sa5<<endl;
    
    sa6.append(p3, p4);
    cout<<"s.append(pointer1, pointer2) : "<<sa6<<endl;
    
    sa7.append(5, 'H');
    cout<<"s.append(n, c) : "<<sa7<<endl;
    
    sa8 += t2;
    cout<<"s += s2 : "<<sa8<<endl;
    
    sa9 += "World";
    cout<<"s += sz : "<<sa9<<endl;
    
    for(string::iterator iter = t2.begin(); iter != t2.end(); ++iter)
        sa10.push_back(*iter);
    cout<<"s.push_back(c) : "<<sa10<<endl<<endl;
    
    //c_str(), data()
    cout<<"c_str(), data()"<<endl;
    
    const char *cstr;
    const char *sdata;
    
    cstr = sa10.c_str();
    sdata = sa10.data();
    
    cout<<"'\\0'문자로 끝나는 문자열(c_str) : "<<cstr<<endl;
    cout<<"'\\0'문자 포함하지 않은 문자열 배열 : ";
    for(int i = 0; i < 10; ++i)
        cout<<sdata[i];
    cout<<endl<<endl;
    
    //compare
    cout<<"compare"<<endl;
    cout<<"s1 > s2 : return (ASC코드 거리)"<<endl;
    cout<<"s1 < s2 : return -(ASC코드 거리)"<<endl;
    cout<<"s1 == s2 : return 0"<<endl;
    cout<<"=====\"==========\"====="<<endl;
    
    string sc1("ABCDE");
    string sc2("AKABC");
    const char* cc = "AKABC";
    
    cout<<"s1.compare(s2) : "<<sc1.compare(sc2)<<endl;
    cout<<"s1.compare(char) : "<<sc1.compare(cc)<<endl<<endl;
    
    cout<<"s1.compare(off, n, s2) : "<<sc1.compare(2, 3, sc2)<<endl;
    cout<<"s1.compare(off, n, char) : "<<sc1.compare(2, 3, cc)<<endl<<endl;
    
    cout<<"s1.compare(off, n, s2, off2, n2) : "<<sc1.compare(0, 3, sc2, 2, 3)<<endl;
    cout<<"s1.compare(off, n, char, off2, n2) : "<<sc1.compare(0, 3, cc, 2, 3)<<endl<<endl;
    
    //copy
    cout<<"copy (끝에 '\\0' 포함하지 않음)"<<endl;
    char buffer[100];
    sa10.copy(buffer, sa10.length());
    buffer[sa10.length()] = '\0';
    cout<<"copy(buffer, s.length) : "<<buffer<<endl;
    
    sa10.copy(buffer, 5, 5);
    buffer[5] = '\0';
    cout<<"copy(buffer, n, off) : "<<buffer<<endl<<endl;;
    
    //find, rfind
    cout<<"find(), rfind()"<<endl;
    
    const char *cc2 = "\"Standard Containers\", \"A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.\", \"The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).\", \"Containers replicate structures very commonly used in programming: dynamic arrays (vector), queues (queue), stacks (stack), heaps (priority_queue), linked lists (list), trees (set), associative arrays (map)...\", \"Many containers have several member functions in common, and share functionalities. The decision of which type of container to use for a specific need does not generally depend only on the functionality offered by the container, but also on the efficiency of some of its members (complexity). This is especially true for sequence containers, which offer different trade-offs in complexity between inserting/removing elements and accessing them.\", \"stack, queue and priority_queue are implemented as container adaptors. Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle the elements. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.\" ";
    
    string find_str("container");
    string sc = cc2;
    
    cout<<sc<<endl<<endl;
    cout<<"s.find('c') : "<<sc.find('c')<<endl;
    cout<<"s.find('c', off) : "<<sc.find('c', 250)<<endl;
    cout<<"s.find(\"container\") : "<<sc.find("container")<<endl;
    cout<<"s.find(\"container\", off) : "<<sc.find("container", 250)<<endl;
    cout<<"s.find(\"container classes\", off, n) : "<<sc.find("container classes", 0, 1)<<endl;
    cout<<"s.find(string s2) : "<<sc.find(find_str)<<endl;
    
    string::size_type pos = sc.find("Not Found");
    cout<<"일치하는 문자열을 발견하지 못한 경우 : "<<(int)pos<<endl;
    cout<<"string::npos : "<<(int)string::npos<<endl;
    
    pos = sc.rfind('c');
    if( string::npos != pos )
        cout<<"s.find('c') : "<<pos<<endl;
    
    
    return 0;
}

