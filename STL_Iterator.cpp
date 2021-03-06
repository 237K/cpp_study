//
//  STL_Iterator_Inserter.cpp
//  cpp_study
//
//  Created by 형성모 on 21/01/2019.
//
//  [STL 반복자]
//      1. iterator, const_iterator
//      2. reverse_iterator, const_reverse_iterater
//      3. const <T>::iterator/reverse_iterator, const <T>::const_iterator/const_reverse_iterator
//      4. reverse_iterator<T>, base()
//      *5. insert iterator
//          1) inserter() : insert_iterator 객체 생성. insert함수 호출. 모든 컨테이너 사용 가능
//          2) back_inserter() : back_insert_iterator 객체 생성. push_back함수 호출. 시퀀스 컨테이너(vector, deque, list) 사용 가능
//          3) front_inserter() : front_insert_iterator 객체 생성. push_front함수 호출. deque, list 사용 가능
//      *6. iostream_iterator
//          1) ostream_iterator : copy / transform 등과 활용
//          2) istream_iterator : copy 등과 활용
//      7. 반복자 특성과 보조함수
//          1) advance(p, n) : p 반복자를 p += n 위치로 이동
//          2) distance(p1, p2) : p2 - p1 거리 반환. iterator_traits<vector<int>::iterator>::difference_type n = distance()
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class Integer10
{
private:
    int data;
public:
    Integer10(int init=0) : data(init) {}
    int operator() () { return data += 10; }
};

class PrintV
{
public:
    void operator() (const vector<int>& v)
    {
        for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
            cout<<v[i]<<' ';
        cout<<endl;
    }
};

int main(void)
{
    vector<int> v1(5);
    generate(v1.begin(), v1.end(), Integer10());
    
    //inserter
    vector<int> v2;
    
    copy(v1.begin(), v1.end(), inserter<vector<int> >(v2, v2.begin()));
    //v2.begin()반복자를 v2의 insert()멤버함수를 호출하는 삽입반복자로 변환
    
    cout<<"v1 : "; PrintV()(v1);
    cout<<"v1 copy : "; PrintV()(v2);
    cout<<endl<<endl;;
    
    //back_inserter, front_inserter
    list<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    lt1.push_back(5);
    
    list<int> lt2;
    lt2.push_back(1);
    lt2.push_back(2);
    lt2.push_back(3);
    lt2.push_back(4);
    lt2.push_back(5);
    
    list<int>::iterator liter;
    
    cout<<"lt1 : ";
    for(liter = lt1.begin(); liter != lt1.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl;
    cout<<"lt2 : ";
    for(liter = lt2.begin(); liter != lt2.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    cout<<"vector->list copy(back_inserter)"<<endl;
    copy(v1.begin(), v1.end(), back_inserter<list<int> >(lt1));
    cout<<"lt1 : ";
    for(liter = lt1.begin(); liter != lt1.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    cout<<"vector->list copy(front_inserter)"<<endl;
    copy(v1.begin(), v1.end(), front_inserter<list<int> >(lt2));
    cout<<"lt2 : ";
    for(liter = lt2.begin(); liter != lt2.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    //iostream_iterator
    cout<<"ostream_iterator"<<endl;
    cout<<"v1(ostream_iterator<int>(cout) : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout));
    cout<<endl;
    cout<<"v1(ostream_iterator<int>(cout, " ")";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl<<endl;
    cout<<"transform을 이용하여 vector+list 합을 ostream_iterator로 출력"<<endl;
    cout<<"vector1 + list1 : ";
    transform(v1.begin(), v1.end(), lt1.begin(), ostream_iterator<int>(cout, " "), plus<int>());
    cout<<endl<<endl;
    
    cout<<"istream_iterator"<<endl;
    vector<int> cinv;
    
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int> >(cinv));
    cout<<"벡터 cinv에 저장"<<endl<<endl;
    
    cout<<"cinv : ";
    copy(cinv.begin(), cinv.end(), ostream_iterator<int>(cout, " "));
    cout<<endl<<endl;
    
    copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
    cout<<"입력받아서 바로 출력"<<endl;
    cout<<endl;
    
    //advance
    cout<<"advance"<<endl;
    cout<<"v1 : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    cout<<"lt1 : ";
    copy(lt1.begin(), lt1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl<<endl;
    
    vector<int>::iterator viter1 = v1.begin();
    list<int>::iterator liter1 = lt1.begin();
    
    cout<<"viter : "<<*viter1<<endl;
    cout<<"liter : "<<*liter1<<endl;
    
    advance(viter1, 2);
    advance(liter1, 2);
    cout<<"viter : "<<*viter1<<endl;
    cout<<"liter : "<<*liter1<<endl;
    cout<<endl;
    
    //distance
    cout<<"distance"<<endl;
    cout<<"v1 원소 개수 : "<<v1.end() - v1.begin()<<endl;
    cout<<"lt1 원소 개수 : "<<distance(lt1.begin(), lt1.end())<<endl;
    cout<<endl;
    
    return 0;
}
