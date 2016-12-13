// iei

#include <iostream>
using namespace std;

// указател към константа - не можем да променим данните,
// към които сочи, но можем да го пренасочим към други
void doSomething(const int* ptr)
{
    int localX = 20;
    ptr = &localX;
    // *ptr = 30; - забранено
    cout << "*ptr = " << *ptr << endl;
}

// обикновен указател - можем да променяме данните, което е страничен ефект
void doSomethingElse(int* ptr)
{
    *ptr = 20;
}

// размяна през указатели
void swapByPointers(int* ptr1, int* ptr2)
{
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

// размяна с побитови операции
// задължителна е проверка дали x и y са една и съща променлива,
// тоест дали са на едно и също място в паметта <=> еднакви адреси
void specialSwap(int& x, int& y)
{
    if (&x != &y)
    {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

void f(int arr[], int n)
{
    // едно и също
    cout << arr[0] << endl;
    cout << *arr << endl;

    // променяме стойността, към която сочи arr
    (*arr)++;
    // променяме самия указател
    arr++;
    cout << *arr << endl;
}

void printArray(const int arr[], int n)
{
    /*for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;*/
    // рекурсивно отпечатване на масив
    // разчитаме на това, че всеки път предаваме големината като аргумент
    // и спираме когато не останат числа за принтиране.
    if (n == 0)
        cout << endl;
    else
    {
        // отпечатванме в обратен ред става само с размяна на следващите два реда
        cout << arr[0] << " ";
        printArray(arr + 1, n - 1);
    }
}

// да подаваме "<някакъв тип>* arr" е същото като "<някакъв_тип> arr[]"
// и в двата случая ни трябва да знаем големината на масива
int sumArray(const int* arr, int n)
{
    // рекурсивно изчисление на сума на числа в масив
    if (n == 0)
        return 0;
    else
        return *arr + sumArray(arr + 1, n - 1);
}

int min(int a, int b) { return a < b ? a : b; } // lol

int arrayMin(const int* arr, int n)
{
    // най-малкото от числата в целия масив е или първото число,
    // или най-малкото измежду останалите числа
    if (n == 1)
        return arr[0];
    else
        return min(arr[0], arrayMin(arr + 1, n - 1));
}

// задачка от лекции (?)
void zadachka()
{
    int arr[8] = { 1,2,3,4,5,6,7,8 };
    const int n = 8;
    int* ptrs[2] = { &arr[3], &arr[7] }; // <=> { arr + 3, arr + 7 }
    int**q = &ptrs[1]; // <=> ptrs + 1
    int* p = &arr[0];  // <=> arr + 0

    printArray(arr, n);
    // зад.1 - през указателя p промени arr[3];
    //*(p + 3) = 10;

    // ако не знаем точно къде сочи ptrs[0] - изчисляваме го
    int offset = ptrs[0] - p;
    //std::cout << "offset = " << offset << endl;
    *(p + offset) = 10;

    printArray(arr, n);

    // зад.2 - през q промени arr[3];
    // две решения, като за първото пак имаме два варианта
    //*(*q - 4) = 12;
    int offset2 = ptrs[1] - ptrs[0];
    *(*q - offset2) = 12;

    //**(q - 1) = 20;
    printArray(arr, n);
    cout << "sum = " << sumArray(arr, n) << endl;

    // вместо да мислим как функцията arrayMin да се справя с "грешни"
    // данни (или празни масиви) - ние се грижим да не я извикваме с такива!
    if (n == 0)
        cout << "Empty array!\n";
    else
        cout << "min = " << arrayMin(arr, n) << endl;

    // не е позволено да смятаме разлика между указатели към различни неща!
    //int offsetWrong = q - p;
}

int main()
{
    //int t = 12;
    //int x = 34;
    //cin >> x;
    
    //swapByPointers(&t, &x);
    //specialSwap(t, x);
    //cout << "t=" << t << "\nx=" << x << endl;

    //int arrayofInts[] = { 0,2,3,4,5 };
    //f(arrayofInts, 5);
    //cout << "arrayofInts[0] = " << arrayofInts[0] << endl;
    
    //int* ptr = &t;
    //int** dptr = &ptr;

    //(**dptr)++; // двоен указател, значи два пъти дереференцираме
    //cout << "t = " << t << endl;

    zadachka();
}
