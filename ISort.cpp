#include <iostream>
#include <cstdlib>
#include "Sequences.h"
#include <ctime>
#include <chrono>

using namespace std;
/*
template<typename T>
LinkedListSequence<T>* Contact(LinkedListSequence<T>* list1, LinkedListSequence<T>* list2){
        int len, item;
        len = list2 -> GetLength();
        for(int i=0; i<len; ++i){
           item = list2 -> Get(i);
           list1 -> Append(item);
        }
        return list1;
}
*/
template<typename T>
void Replace(LinkedListSequence<T>* seq, int a, int b , char test = 'n')
{
    int elem1, elem2;
    elem1 = seq -> Get(a);
    elem2 = seq -> Get(b);

    seq -> RemoveAt(a);
    seq -> InsertAt(elem2, a);
    seq -> RemoveAt(b);
    seq -> InsertAt(elem1, b);
    if (test == 'y') TestReplace(seq, elem1, elem2, a, b);
}

template<typename T>
void Replace(ArraySequence<T>* seq, int a, int b, char test = 'n')
{
    int tem;
    int elem1 = seq -> Get(a);
    int elem2 = seq -> Get(b);
    tem = seq -> Get(a);
    seq -> Set(seq -> Get(b), a);
    seq -> Set(tem, b);
    if (test == 'y') TestReplace(seq, elem1, elem2, a, b);
}
/*
template<typename T>
LinkedListSequence<T>* FastSortLinkedList(LinkedListSequence<T>* seq) //int st, int ed)
{
    int elem, RefElemNum, len;
    LinkedListSequence<int> leftL;
    LinkedListSequence<int> rightL;
    LinkedListSequence<int>* L;
    leftL = LinkedListSequence<int>();
    rightL = LinkedListSequence<int>();
    len = seq -> GetLength();
    if (len > 1)
    {
        RefElemNum = seq -> Get(len/2);
        for(int i = 0; i<len; ++i)
        {
            elem = seq -> Get(i);
            if (elem > RefElemNum)
            {
                rightL.Append(elem);
            }
            else
            {
                leftL.Append(elem);
            }
        }
        L = Contact(FastSortLinkedList1(&leftL), FastSortLinkedList1(&rightL));

        return L;

    }
    else
    {
        return seq;
    }
}

/*
template<typename T>
Sequence<T>* Sort(Sequence<T>* seq)//,int (*cmp)(T,T));
{



}
 */
/*
template<typename T>
void FastSort(LinkedListSequence<T>* seq, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = seq -> Get((i + j) / 2);
    int temp;

    while (i <= j)
    {
        while (seq -> Get(i) < pivot)
            i++;
        while (seq -> Get(j) > pivot)
            j--;
        if (i <= j)
        {
            Replace(seq, i, j);
            i++;
            j--;
        }
    }
    if (j > low)
        FastSort(seq, low, j);
    if (i < high)
        FastSort(seq, i, high);
}
*/

template<class T>
void TestSort(T* seq, int Start = 0, int End = -1)
{
    int flag = 0;
    if (End == -1) End = seq -> GetLength() - 1;
    for(int i = Start; i < End; i++)
    {
        if(seq -> Get(i) > seq -> Get(i+1))  flag = 1;
    }
    if (flag == 1)
    {
        for(int i = Start; i < End; i++)
        {
            if(seq -> Get(i) < seq -> Get(i+1))  flag = 2;
        }
    }
    if( flag == 0) cout <<"selected part sequence is sorted in ascending order"<<endl;
    if( flag == 1) cout <<"selected part sequence is sorted in descending order"<<endl;
    if( flag == 2) cout <<"selected part sequence is not sorted"<<endl;

}

template<class T>
void TestReplace(T* seq, int a, int b, int indexa, int indexb)
{
    if ((seq -> Get(indexa) == b) && (seq -> Get(indexb) == a))
    {
        cout <<"Ok"<<endl;
    }
    else
    {
        cout <<"No ok"<<endl;
    }

}

template<class T>
void FastSort(T* seq, int Start = 0, int End = -1, bool Reverse = false)
{
    if (End == -1) End = seq -> GetLength() - 1;
    int i = Start;
    int j = End;
    int pivot = seq -> Get((i + j) / 2);

    while (i <= j)
    {
        if (Reverse)
        {
            while (seq -> Get(i) > pivot)
                i++;
            while (seq -> Get(j) < pivot)
                j--;
        }
        else
        {
            while (seq -> Get(i) < pivot)
                i++;
            while (seq -> Get(j) > pivot)
                j--;
        }
        if (i <= j)
        {
            Replace(seq, i, j);
            i++;
            j--;
        }
    }
    if (j > Start)
        FastSort(seq, Start, j, Reverse);
    if (i < End)
        FastSort(seq, i, End, Reverse);
}
 /*
template<typename T>
void ShakerSort(LinkedListSequence<T>* seq, int Start, int End)
{
    int i, Left, Right;
    Left=Start+1;
    Right=End;
    while (Left<=Right)
    {

    for (i=Right; i>=Left; i--)
        if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
    Left++;
    for (i=Left; i<=Right; i++)
        if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
    Right--;
    }
}

template<typename T>
void ShakerSort(ArraySequence<T>* seq, int Start, int End)
{
    int i, Left, Right;
    Left=Start+1;
    Right=End;
    while (Left<=Right)
    {

    for (i=Right; i>=Left; i--)
        if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
    Left++;
    for (i=Left; i<=Right; i++)
        if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
    Right--;
    }
}
*/
template<class T>
void ShakerSort(T* seq, int Start = 0, int End = -1, bool Reverse = false)
{
    int i, Left, Right;
    if (End == -1) End = seq -> GetLength() - 1;
    Left=Start+1;
    Right=End;
    while (Left<=Right)
    {

    for (i=Right; i>=Left; i--)
    {
        if (Reverse)
        {
            if (seq -> Get(i-1) < seq -> Get(i)) Replace(seq, i , i-1);
        }
        else
        {
            if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
        }
    }
    Left++;
    for (i=Left; i<=Right; i++)
    {
        if (Reverse)
        {
            if (seq -> Get(i-1) < seq -> Get(i)) Replace(seq, i , i-1);
        }
        else
        {
            if (seq -> Get(i-1) > seq -> Get(i)) Replace(seq, i , i-1);
        }
    }
    Right--;
    }
}

template<class T>
void ShellSort(T* seq, int Start = 0, int End = -1, bool Reverse = false)
{
    if (End == -1) End = seq -> GetLength() - 1;
    int j, i;
    int d = (End-Start+1)/2;
    while (d > 0)
        {
            for (i=Start; i<=End-d; i++)
            {
                j=i;
                if (Reverse)
                {
                    while (j>=Start && seq -> Get(j) < seq -> Get(j+d))
                    {
                        Replace(seq, j, j+d);
                        j--;
                    }
                }
                else
                {
                    while (j>=Start && seq -> Get(j) > seq -> Get(j+d))
                    {
                        Replace(seq, j, j+d);
                        j--;
                    }
                }
            }
            d=d/2;
        }
}


template<class T>
void Sort(T* seq, int usesorting = 1, int Start = 0, int End = -1, bool Reverse = false, char test = 'n')
{
    if ((Start < 0)||((Start > End)&&(End != -1))||(End > seq -> GetLength()))
    {
        End = seq -> GetLength() - 1;
        Start = 0;
        cout<< "A part of the sequence is incorrectly selected, sorting will be performed for the entire sequence" <<endl;
    }
    if (usesorting < 1 || usesorting > 3) usesorting = 1;

    auto begin = std::chrono::steady_clock::now();
    if(usesorting == 1)
    {
        cout <<"use FastSort"<<endl;
        FastSort(seq, Start, End, Reverse);
    }
    if(usesorting == 2)
    {
        cout <<"use ShakerSort"<<endl;
        ShakerSort(seq, Start, End, Reverse);
    }
    if(usesorting == 3)
    {
        cout <<"use ShellSort"<<endl;
        ShellSort(seq, Start , End, Reverse);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    int seconds = elapsed_ms.count();
    cout <<"The time: "<< seconds <<" milliseconds" <<endl;
    if (test == 'y') TestSort(seq, Start, End);
}

void ISort()
{
    int len, choice, choiceSeq, usesorting, Start, End;
    char test;
    bool Reverse;
    choice = 1;
    cout << "length: "<<endl;
    cin >> len ;
    while(len<=1)
    {
        cout << "Enter the correct length"<<endl;
        cin >> len ;
    }

    cout << "Random data(1), Your data(2)"<<endl;
    cin >> choice;


    int* data =  new int[len];
    for (int i = 0; i < len; ++i)
    {
        if (choice == 1) data[i] = rand() % 1000;
        if (choice == 2) cin >> data[i];
    }
    choice = 1;
    while(choice == 1)
    {
        cout << "Sequence type:"<<endl;
        cout << "ArraySequence(1), LinkedListSequence(2)"<<endl;
        cin >> choiceSeq;
        ArraySequence<int> SeqA(data,len);
        LinkedListSequence<int> SeqL(data,len);

        cout << "automatic test: Yes(y) or No(n)"<<endl;
        cin >> test;

        cout << "Select sorting:"<<endl;
        cout << "FastSort(1), ShakerSort(2), ShellSort(3)"<<endl;
        cin >> usesorting;

        cout << "Reverse: true(1) or false(2)"<<endl;
        cin >> choice;
        if (choice == 1) Reverse = true;
        if (choice == 2) Reverse = false;

        cout << "Print sequence: Yes(1) or No(2)"<<endl;
        cin >> choice;

        if (choice == 1 && choiceSeq == 1) SeqA.Print();
        if (choice == 1 && choiceSeq == 2) SeqL.Print();

        cout << "Select the sortable interval" <<endl;
        cout << "Use the interval 0  -1 to sort the entire sequence." <<endl;
        cin >> Start >> End;

        if (choiceSeq == 1) Sort(&SeqA, usesorting, Start, End, Reverse, test);
        if (choiceSeq == 2) Sort(&SeqL, usesorting, Start, End, Reverse, test);

        cout << "Print sequence: Yes(1) or No(2)"<<endl;
        cin >> choice;
        if (choice == 1 && choiceSeq == 1) SeqA.Print();
        if (choice == 1 && choiceSeq == 2) SeqL.Print();
        cout << "Repeat using the same data: Yes(1) or No(2)"<<endl;
        cin >> choice;
    }
}


int main()
{

    srand(time(NULL));
    ISort();
/*
   // long seconds;
   // srand(time(NULL));
//for (int flag = 1; flag <= 6; flag++)
//{
//    for (int k = 9000; k <= 10000; k=k+1000)
//    {
/*
        int* data =  new int[10];
        for (int i = 0; i < 10; ++i)
        {
            data[i] = rand() % 1000;
        }
        LinkedListSequence<int>a(data,10);
        a.Print();
        ShellSort(&a, 0, -1, true);
        a.Print();
        TestSort(&a);

//        LinkedListSequence<int>a(data,10000);
       // auto begin = std::chrono::steady_clock::now();
       /*
        if (flag == 1) FastSort(&a);
        if (flag == 2) ShellSort(&a);
        if (flag == 3) ShakerSort(&a);
        if (flag == 4) FastSort(&l);
        if (flag == 5) ShellSort(&l);
        if (flag == 6) ShakerSort(&l);

       // a.Print();
        FastSort(&l);
       // l.RemoveAt(9);
        //l.InsertAt(-1, 9);
     //   Sort(&a, 1, -3, 8);
       // TestSort(&a);
       // Replace(&l, 2, 5);
      //  a.Print();
     //   auto end = std::chrono::steady_clock::now();
     //   auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
     //   seconds = elapsed_ms.count();

        if (flag == 1 && k == 1000) cout<< "ArraySequence" <<endl;
        if (flag == 4 && k == 1000) cout<< "LinkedListSequence" <<endl;
        if (flag % 3 == 1 && k == 1000)cout<< "FastSort" <<endl;
        if (flag % 3 == 2 && k == 1000)cout<< "ShellSort" <<endl;
        if (flag % 3 == 0 && k == 1000)cout<< "ShakerSort" <<endl;

     //   cout <<"The time: "<< seconds <<" milliseconds with the number of data ="<< k <<endl;


  //  }
//}
*/
    return 0;
}
