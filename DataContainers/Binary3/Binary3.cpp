
#include <iostream>
using namespace std;

#define tab "\t"

#define DEBUG   
//#define - определить
//#defined - определено


class Tree
{
protected:
    class Element
    {
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
            Data(Data), pLeft(pLeft), pRight(pRight)
        {
#if defined DEBUG
            cout << "EConstruction:\t" << this << endl;
#endif // DEBUG

        }
        ~Element()
        {
           
#ifdef DEBUG
            cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

        }
        friend class Tree;
        friend class UniqueTree;

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

    Tree(const std::initializer_list<int>& il) :Tree()
    {
        for (int const* it = il.begin(); it != il.end(); ++it)
            insert(*it, Root);
        cout << "ILConctructor:\t" << this << endl;
    }

    ~Tree()
    {
        Clear(Root);
        cout << "TDestructor:\t" << this << endl;
    }

    void insert(int Data)
    {
        insert(Data, Root);
        
    }
    void Erase(int Data)
    {
        Erase(Data, Root);
    }
    int minValue()const
    {
        return minValue(Root);
    }

    int maxValue()const
    {
        return maxValue(Root);
    }

    int Summa()const

    {
        return Summa(Root);
    }

    int count()const
    {
        return count(Root);
    }

    void Print()const
    {
        Print(Root);
        cout << endl;
    }
    double Average()const
    {
        return (double)Summa(Root) / count(Root);
    }
private:
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

    int minValue(Element* Root)const
    {
        /*if (Root->pLeft == nullptr)return Root->Data;
        else return minValue(Root->pLeft);*/
        return Root == nullptr ? 0 : Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
    }

    int maxValue(Element* Root)const
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

    int count(Element* Root)const
    {
        return !Root ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
        /*if (Root == nullptr) return 0;
        else return count(Root->pLeft) + count(Root->pRight) + 1;*/
    }

    int Summa(Element* Root)const
    {
        return Root == nullptr ? 0 :Root->Data + Summa(Root->pLeft) + Summa(Root->pRight);

    }

    double Average(Element* Root)
    {
        if (Root==nullptr || count(Root)==0 ) return 0.0;
        return (double) Summa(Root) / count(Root);

    }
  
    /*void Clear()
    {
        Clear(Root);
        Root = nullptr;
    }*/

    void Clear(Element*& Root)
    {
        if (Root == nullptr) return;
        Clear(Root->pLeft);
        Clear(Root->pRight);
        delete Root;
        Root = nullptr;
    }

    void Erase(int Data, Element*& Root)
    {
        if (Root == nullptr)return;
        Erase(Data, Root->pLeft);
        Erase(Data, Root->pRight);
        if (Data == Root->Data)
        {
            //листок
            if (Root->pLeft == Root->pRight)
            {
                delete Root;
                Root = nullptr;
            }
            else
            {
                //Для того чтобы дерево балансировалось при удалении элементов
                //перед удалением его нужно взвесить
                if (count(Root->pLeft) > count(Root->pRight))
                {
                    //и если левая ветка тяжелее, чем правая, то берем из нее максимальное значение
                    //,потому что оно ближе всего к удаляемому значению:
                    Root->Data = maxValue(Root->pLeft);
                    Erase(maxValue(Root->pLeft), Root->pLeft);
                }
                else
                {
                    //в противном случае берем минимальное значение из правой ветки,/
                    //потому что оно ближе всего к удаляемому значению
                    Root->Data = minValue(Root->pRight);
                    Erase(minValue(Root->pRight), Root->pRight);
                }
            }
        }
    }
    
    //void Erase(int Value)
    //{
    //    Root = RecursivelyErase(Value, Root);
    //}

    //Element* RecursivelyErase(int Value, Element*& Root)
    //{
    //    if (Root == nullptr) return nullptr; 

    //    if (Value < Root->Data)
    //        Root->pLeft = RecursivelyErase(Value, Root->pLeft); 
    //    else if (Value > Root->Data)
    //        Root->pRight = RecursivelyErase(Value, Root->pRight); 
    //    else 
    //    {
    //        
    //        if (Root->pLeft == nullptr && Root->pRight == nullptr)
    //        {
    //            delete Root;
    //            return nullptr;
    //        }
    //        
    //        else if (Root->pLeft == nullptr)
    //        {
    //            Element* Temp = Root;
    //            Root = Root->pRight;
    //            delete Temp;
    //            return Root;
    //        }
    //        else if (Root->pRight == nullptr)
    //        {
    //            Element* Temp = Root;
    //            Root = Root->pLeft;
    //            delete Temp;
    //            return Root;
    //        }
    //        
    //        else
    //        {
    //            // Находим наименьший элемент в правом поддереве
    //            Element* Successor = Root->pRight;
    //            while (Successor->pLeft != nullptr)
    //                Successor = Successor->pLeft;

    //            // Копируем значение преемника в удаляемый узел
    //            Root->Data = Successor->Data;

    //            // Удаляем преемника из правого поддерева
    //            Root->pRight = RecursivelyErase(Successor->Data, Root->pRight);
    //        }
    //    }
    //    return Root;
    //}

};
class UniqueTree :public Tree
{
    void insert(int Data, Element* Root)
    {
        if (this->Root == nullptr) this->Root = new Element(Data);
        if (Root == nullptr)return;
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
            else insert(Data, Root->pLeft);
        }
        else if(Data>Root->Data)
        {
            if (Root->pRight == nullptr)Root->pRight = new Element(Data);
            else insert(Data, Root->pRight);
        }
    }
public:
    void insert(int Data)
    {
        insert(Data, Root);
    }
};
//#define BASE_CHECK

int main()
{
    system("chcp 1251> NUL");

#ifdef BASE_CHECK
    int n;

    cout << "Введите количество элементов: "; cin >> n;
    Tree tree;
    // cout << "Минимальное значение в дереве: " << tree.minValue() << endl;

    // cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
    for (int i = 0; i < n; ++i)
    {
        tree.insert(rand() % 100);
    }

    tree.Print();
    cout << endl;
    cout << "Минимальное значение в дереве: " << tree.minValue() << endl;

    cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;

    cout << "Количество элементов дерева: " << tree.count() << endl;
    cout << "Сумма всех элементов бинарного дерева: " << tree.Summa() << endl;
    cout << "Среднее арифметическое элементов бинарного деерва: " << tree.Average() << endl;
    cout << endl;

    UniqueTree u_tree;
    for (int i = 0; i < n; ++i)
    {
        u_tree.insert(rand() % 100);

    }
    u_tree.Print();
    cout << endl;
    cout << "Минимальное значение в дереве: " << u_tree.minValue() << endl;
    cout << "Максимальное значение в дереве: " << u_tree.maxValue() << endl;
    cout << "Количество элементов дерева: " << u_tree.count() << endl;
    cout << "Сумма всех элементов бинарного дерева: " << u_tree.Summa() << endl;
    cout << "Среднее арифметическое элементов бинарного деерва: " << u_tree.Average() << endl;

    //cout << "Дерево до удаления: " << endl;
    //tree.Print();

   // cout << endl;

   /* int value;
    cout << "Введите значение для удаления: " << endl;
    cin >> value;
    tree.Erase(value);
    cout << "Дерево после удаления: " << endl;
    tree.Print();
    cout << endl;
    */

    return 0;
#endif // DEBUG

    Tree tree = {     50,

             25,            75, 

        16,      32,   58,       85
    };
    tree.Print();
    int value;
    //cout << "Введите удаляемое значение:" << endl;
    //cin>>value;
    tree.Erase(25);
    tree.Erase(32);
    tree.Erase(50);
    tree.Erase(75);
    tree.Print();
}

