#include <iostream>
#include <string>

using namespace std;

enum Season
{
    Winter, // 0
    Spring, // 1
    Summer, // 2
    Autumn, // 3
};

class SeasonsBase
{
public:
    virtual void Change() = 0;

    virtual ~SeasonsBase()
    {

    }

    Season get_s()
    {
        return s; // Возвращает исходное s (Winter)
    }

    Season s = Winter; // Season = 0 (Winter)
};

class Seasons : public SeasonsBase // Этот класс переключает времена года
{
public:
    void Change() override
    {
        switch (s) // переключатель
        {
        case Winter: s = Spring;
            break;
        case Spring: s = Summer;
            break;
        case Summer: s = Autumn;
            break;
        case Autumn: s = Winter;
            break;
        }
    }
};

class ReverseSeasons : public SeasonsBase // Тот же класс, что и Seasons, но в обратном порядке
{
public:
    void Change() override
    {
        switch (s)  // начинается с числа 3
        {
        case Winter: s = Autumn;
            break;
        case Autumn: s = Summer;
            break;
        case Summer: s = Spring;
            break;
        case Spring: s = Winter;
            break;
        }
    }
};

int main()
{
    Seasons seas;
    seas.Change();
    cout << seas.get_s() << endl;
    seas.Change();
    cout << seas.get_s() << endl;
    seas.Change();
    cout << seas.get_s() << endl;
    system("pause");
    return 0;
};
