#include <iostream>

/**
 * Вспомогательный класс, описывающий некоторое преступление
 */
class CriminalAction {

    friend class Policeman;     // Полицейские имеют доступ к материалам следствия

    int complexity;             // Сложность дела

    const char* description;    // Краткое описание преступления

public:
    CriminalAction(int complexity, const char* description): complexity(complexity), description(description) {}

};

/**
 * Абстрактный полицейский, который может заниматься расследованием преступлений
 */
class Policeman {

protected:

    int deduction;      // дедукция (умение распутывать сложные дела) у данного полицейского

    Policeman* next;    // более умелый полицейский, который получит дело, если для текущего оно слишком сложное

    virtual void investigateConcrete(const char* description) {}    // собственно расследование

public:

    Policeman(int deduction) : deduction(deduction), next(nullptr) {}

    virtual ~Policeman() {
        delete next;
    }

    /**
     * Добавляет в цепочку ответственности более опытного полицейского, который сможет принять на себя
     * расследование, если текущий не справится
     */
    Policeman* setNext(Policeman* policeman) {
        next = policeman;
        return next;
    }

    /**
     * Полицейский начинает расследование или, если дело слишком сложное, передает его более опытному коллеге
     */
    void investigate(CriminalAction* criminalAction) {
        if (deduction < criminalAction->complexity) {
            if (next) {
                next->investigate(criminalAction);
            } else {
                std::cout << "Это дело не раскрыть никому." << std::endl;
            }
        } else {
            investigateConcrete(criminalAction->description);
        }
    }
};

class MartinRiggs: public Policeman {

protected:

    void investigateConcrete(const char* description) {
        std::cout << "Расследование по делу \"" << description << "\" ведет сержант Мартин Риггс" << std::endl;
    }

public:

    MartinRiggs(int deduction): Policeman(deduction) {}
};

class JohnMcClane: public Policeman {

protected:

    void investigateConcrete(const char* description) {
        std::cout << "Расследование по делу \"" << description << "\" ведет детектив Джон Макклейн" << std::endl;
    }

public:
    JohnMcClane(int deduction): Policeman(deduction) {}
};

class VincentHanna: public Policeman {

protected:

    void investigateConcrete(const char* description) {
        std::cout << "Расследование по делу \"" << description << "\" ведет лейтенант Винсент Ханна" << std::endl;
    }

public:
    VincentHanna(int deduction): Policeman(deduction) {}
};

int main() {
    std::cout << "OUTPUT:" << std::endl;
    Policeman* policeman = new MartinRiggs(3);  // полицейский с наименьшим навыком ведения расследований
    policeman
            ->setNext(new JohnMcClane(5))
            ->setNext(new VincentHanna(8));     // добавляем ему двух опытных коллег
    policeman->investigate(new CriminalAction(2, "Торговля наркотиками из Вьетнама"));
    policeman->investigate(new CriminalAction(7, "Дерзкое ограбление банка в центре Лос-Анджелеса"));
    policeman->investigate(new CriminalAction(5, "Серия взрывов в центре Нью-Йорка"));
    return 0;
}

/**
 * OUTPUT:
 * Расследование по делу "Торговля наркотиками из Вьетнама" ведет сержант Мартин Риггс
 * Расследование по делу "Дерзкое ограбление банка в центре Лос-Анджелеса" ведет лейтенант Винсент Ханна
 * Расследование по делу "Серия взрывов в центре Нью-Йорка" ведет детектив Джон Макклейн
 */
