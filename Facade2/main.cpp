#include <iostream>
#include <string>
#include <memory>
#include <string_view>
/** Абстрактный музыкант - не является обязательной составляющей паттерна, введен для упрощения кода */
class Musician {

    const char* name;

public:
    Musician(std::string_view name) {
        this->name = name.data();
    }

    virtual ~Musician() =default;

protected:
    void output(std::string_view text) {
        std::cout << this->name << " " << text << "." << std::endl;
    }
};

/** Конкретные музыканты */
class Vocalist: public Musician {

public:
    Vocalist(std::string_view name): Musician(name) {}

    void singCouplet(int coupletNumber) {
        std::string text = "спел куплет №";
        text += std::to_string(coupletNumber);
        output(text);
    }

    void singChorus() {
        output("спел припев");
    }
};

class Guitarist: public Musician {

public:
    Guitarist(std::string_view name): Musician(name) {}

    void playCoolOpening() {
        output("начинает с крутого вступления");
    }

    void playCoolRiffs() {
        output("играет крутые риффы");
    }

    void playAnotherCoolRiffs() {
        output("играет другие крутые риффы");
    }

    void playIncrediblyCoolSolo() {
        output("выдает невероятно крутое соло");
    }

    void playFinalAccord() {
        output("заканчивает песню мощным аккордом");
    }
};

class Bassist: public Musician {

public:
    Bassist(std::string_view name): Musician(name) {}

    void followTheDrums() {
        output("следует за барабанами");
    }

    void changeRhythm(std::string_view type) {
        std::string text = ("перешел на ритм ");
        text += type;
        text += "a";
        output(text);
    }

    void stopPlaying() {
        output("заканчивает играть");
    }
};

class Drummer: public Musician {

public:
    Drummer(std::string_view name): Musician(name) {}

    void startPlaying() {
        output("начинает играть");
    }

    void stopPlaying() {
        output("заканчивает играть");
    }
};

/** Фасад, в данном случае - знаменитая рок-группа */
class BlackSabbath {

    std::unique_ptr<Vocalist> vocalist;
    std::unique_ptr<Guitarist> guitarist;
    std::unique_ptr<Bassist> bassist;
    std::unique_ptr<Drummer> drummer;

public:

    BlackSabbath() {
        vocalist = std::make_unique<Vocalist>("Оззи Осборн");
        guitarist = std::make_unique<Guitarist>("Тони Айомми");
        bassist = std::make_unique<Bassist>("Гизер Батлер");
        drummer = std::make_unique<Drummer>("Билл Уорд");
    }

   void playCoolSong() {
        guitarist->playCoolOpening();
        drummer->startPlaying();
        bassist->followTheDrums();
        guitarist->playCoolRiffs();
        vocalist->singCouplet(1);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playCoolRiffs();
        vocalist->singCouplet(2);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playIncrediblyCoolSolo();
        guitarist->playCoolRiffs();
        vocalist->singCouplet(3);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playCoolRiffs();
        bassist->stopPlaying();
        drummer->stopPlaying();
        guitarist->playFinalAccord();
    }
};

int main() {
    std::cout << "OUTPUT:" << std::endl;
    BlackSabbath band;
    band.playCoolSong();
    return 0;
}

/**
 * OUTPUT:
 * Тони Айомми начинает с крутого вступления.
 * Билл Уорд начинает играть.
 * Гизер Батлер следует за барабанами.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №1.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №2.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми выдает невероятно крутое соло.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №3.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми играет крутые риффы.
 * Гизер Батлер заканчивает играть.
 * Билл Уорд заканчивает играть.
 * Тони Айомми заканчивает песню мощным аккордом.
 */
