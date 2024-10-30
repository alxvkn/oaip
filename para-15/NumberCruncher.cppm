export module NumberCruncher;

// НИКАКИЕ МАКРОСЫ не будут показаны импортёру модуля
#define CRUNCH_FACTOR 3.14

namespace numbers {
int FAR = 10;

// скрытая функция которая умножает эээ число на крунч фактор
float applyCrunchFactor(float number) {
    return number * CRUNCH_FACTOR;
}

// публичная функция (для пользователя модуля)
export float crunch(float number) {
    if (number <= 10) {
        // если намбер меньше либо равен десяти,
        // то возвращается значение приватной переменной ФАР
        return FAR;
    } else {
        // если намбер больше десяти, то
        // возвращается намбер после применения к нему крунч фактора
        auto crunched = applyCrunchFactor(number);
        return crunched;
    }
}
}

// этот код писал не я (!!!) не обзывайтесь.
