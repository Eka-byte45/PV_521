
#include <iostream>
using namespace std;

#define tab "\t"
class Tree
{
    class Element
    {
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
            Data(Data), pLeft(pLeft), pRight(pRight)
        {
            cout << "EConstruction:\t" << this << endl;
        }
        ~Element()
        {
            cout << "EDestructor:\t" << this << endl;
        }
        friend class Tree;

    }*Root;
public:
    Element* GetRoot()const
    {
        return Root;
    }
    Tree() :Root(nullptr)
    {
        cout << "TConstructor:\t" << this << endl;

    }
    ~Tree()
    {
        cout << "TDestructor:\t" << this << endl;
    }
    void insert(int Data, Element* Root)
    {
        if (this->Root == nullptr) this->Root = new Element(Data);
        if (Root == nullptr)return;
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
            else insert(Data, Root->pLeft);
        }
        else
        {
            if (Root->pRight == nullptr)Root->pRight = new Element(Data);
            else insert(Data, Root->pRight);
        }
    }

    int minValue(Element* Root)
    {
        /*if (Root->pLeft == nullptr)return Root->Data;
        else return minValue(Root->pLeft);*/
        return Root == nullptr ? 0 : Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
    }

    int maxValue(Element* Root)
    {
        return !Root ? 0 : Root->pRight ? maxValue(Root->pRight) : Root->Data;
        /**if (Root->pRight == nullptr)return Root->Data;
        else return maxValue(Root->pRight);*/
    }

    void Print(Element* Root)const
    {
        if (Root == nullptr)return;
        Print(Root->pLeft);
        cout << Root->Data << tab;
        Print(Root->pRight);
    }

    int count(Element* Root)
    {
        return !Root ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
        /*if (Root == nullptr) return 0;
        else return count(Root->pLeft) + count(Root->pRight) + 1;*/
    }
};
int main()
{
    system("chcp 1251> NUL");
    //std::cout << "Hello Tree!\n";
    int n;
    
    cout << "Введите количество элементов: "; cin >> n;
    Tree tree;
    cout << "Минимальное значение в дереве: " << tree.minValue(tree.GetRoot()) << endl;

    cout << "Максимальное значение в дереве: " << tree.maxValue(tree.GetRoot()) << endl;
    for (int i = 0; i < n; ++i)
    {
        tree.insert(rand() % 100, tree.GetRoot());
    }
    
    tree.Print(tree.GetRoot());
    cout << endl;
    cout << "Минимальное значение в дереве: "<<tree.minValue(tree.GetRoot()) << endl;
    
    cout << "Максимальное значение в дереве: " << tree.maxValue(tree.GetRoot()) << endl;
   
    cout << "Количество элементов дерева: " << tree.count(tree.GetRoot())<<endl;


}

