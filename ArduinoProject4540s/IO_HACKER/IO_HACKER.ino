/*
    *** IO_HACKER IN OUT MULTI CONTROLLER v._X4_EX2_AX2_KS ***

for LCD KeySh 16*2
// for LCD I2C 16*2
// for NEXTION HMI

****************************************************************************************************

ПРОГРАММА УПРАВЛЯЕТ НЕСКОЛЬКИМИ ПЕРЕКИДНЫМИ РЕЛЕ В ЗАВИСИМОСТИ ОТ НАСТРОЕК,
НАСТРОЙКИ ЗАДАЮТСЯ В ШАБЛОНАХ
ШАБЛОНЫ ПРЕДСТАВЛЯЮТ НАСТРОЙКИ ФУНКЦИЙ ДЛЯ ПАКЕТА РЕЛЕ,
МОЖНО СОЗДАВАТЬ ПОЛЬЗОВАТЕЛЬСКИЕ ШАБЛОНЫ (И ФУНКЦИИ В ВЕРСИИ _FX).
ДЛЯ КАЖДОГО РЕЛЕ МОЖНО НАСТРОИТЬ СВОЮ НЕЗАВИСИМУЮ ФУНКЦИЮ,
КОЛИЧЕСТВО РЕЛЕ ОГРАНИЧЕНО КОЛИЧЕСТВОМ СВОБОДНЫХ ВЫХОДОВ И КОНФИГУРАЦИЕЙ ОБОРУДОВАНИЯ
ПОЛЬЗОВАТЕЛЬСКИЕ ФУНКЦИИ СТРОЯТСЯ НА ВСТРОЕНЫХ ФАКТОРАХ И ВХОДНЫХ ДАННЫХ

****************************************************************************************************

КОД ВЕРСИИ:
_SX - количество выходов 5в (шим или управление диодами ws2812b)
_X - количечство выходов реле
_EX - количество входов 5в
_AX - количество аналоговых входов
_I _KS _NEXT - дисплей. I KS дисплей 16*2, NEXT сенсорный дисплей nextion
FX-версия разработчика
_FX - версия библиотеки факторов для создания пользовательских функций в разработке...
если FX не указана то входы используются только для встроеных функций (версия разработчика откл.)

PROTOTIPE ВЕРСИИ: +v отмечены доступные версии
I_O_HACKER_X4_KS - 4 реле, дисплей 16*2 LCD Keypad Shield
I_O_HACKER_X4_EX2_KS - 4 реле, 2 входа 5в, дисплей 16*2 LCD Keypad Shield
I_O_HACKER_X4_EX2_AX2_KS - 4 реле, 2 входа 5в, 2 аналоговых входа, дисплей 16*2 LCD Keypad Shield +v
I_O_HACKER_X4_I - 4 реле, дисплей 16*2 I2C
I_O_HACKER_X4_EX2_I - 4 реле, 2 входа 5в, дисплей 16*2 I2C
I_O_HACKER_X4_EX4_I - 4 реле, 4 входа 5в, дисплей 16*2 I2C
I_O_HACKER_X4_EX2_NEXT - 4 реле, 2 входа 5в, дисплей сенсорный nextion
I_O_HACKER_X4_EX4_NEXT - 4 реле, 4 входа 5в, дисплей сенсорный nextion
I_O_HACKER_X8 - 8 реле, дисплей 16*2 I2C
I_O_HACKER_X8_EX2_I - 8 реле, 2 входа 5в, дисплей 16*2 I2C
I_O_HACKER_X8_EX4_I - 8 реле, 4 входа 5в, дисплей 16*2 I2C
I_O_HACKER_X8_EX2_NEXT - 8 реле, 2 входа 5в, дисплей сенсорный nextion
I_O_HACKER_X8_EX4_NEXT - 8 реле, 4 входа 5в, дисплей сенсорный nextion

****************************************************************************************************

ВХОДНЫЕ ДАННЫЕ:
-ВЛАЖНОСТЬ(DHT 11, DHT 22).
-ТЕМПЕРАТУРА
-ОСВЕЩЕННОСТЬ-аналоговый датчик освещенности (встроен в корпус)
-ВРЕМЯ-встроеные часы
-ДАТЧИК ДВИЖЕНИЯ ЧЕРЕЗ ВХОД 5в v._EX*
+2 ВХОДА 5в В ВЕРСИИ _EX2
+4 ВХОДА 5в В ВЕРСИИ _EX4
+АНАЛОГОВЫЕ ВХОДЫ v._AX
В ВЕРСИЯХ НИЖЕ _EX ДАТЧИК ДВИЖЕНИЯ МОЖНО ПОДКЛЮЧИТЬ ЧЕРЕЗ ВЫХОД РЕЛЕ**
**(ДАТЧИК ДВИЖЕНИЯ ЧЕРЕЗ ВЫХОД РЕЛЕ)-ПИТАНИЕ ДАТЧИКА ДВИЖЕНИЯ ПОДКЛЮЧАТЬ ЧЕРЕЗ РЕЛЕ С ФУНКЦИЕЙ:

ПОДДЕРЖКА ДО 4 ТЕМПЕРАТУРНЫХ ДАТЧИКОВ В ВЕРСИИ _X4
ПОДДЕРЖКА ДО 8 ТЕМПЕРАТУРНЫХ ДАТЧИКОВ В ВЕРСИИ _X8

****************************************************************************************************

ВСТРОЕНЫЕ ФАКТОРЫ ДЛЯ ПОЛЬЗОВАТЕЛЬСКИХ ФУНКЦИЙ _FX101  _FXv.1.0.1:
ФАКТОРЫ ДОСТУПНЫ ТОЛЬКО В ВЕРСИИ _FX
PROTOTIPE: FX000
-ПЕРЕКЛЮЧЕНИЕ ФУНКЦИЙ НА РЕЛЕ ПО СОБЫТИЯМ (ФАКТОРАМ)
-ИЗМЕНЕНИЕ НАСТРОЕК ФУНКЦИИ ПО СОБЫТИЯМ
-ВЫСОКИЙ УРОВЕНЬ НА ВЫХОДЕ РЕЛЕ
-ВЫСОКИЙ УРОВЕНЬ НА ВЫХОДЕ ФУНКЦИИ
-ТАЙМЕР // dеlay
-ВХОДЫ 5в В ВЕРСИИ _EX
-ЛОГИЧЕСКИЕ ОПЕРАЦИИ МЕЖДУ ВХОДАМИ 5в: И, ИЛИ _EX
-ЛОГИЧЕСКИЕ ОПЕРАЦИИ С ВЫХОДОМ ФУНКЦИИ: И, ИЛИ
-ЛОГИЧЕСКИЕ ОПЕРАЦИИ С ВЫХОДОМ ФУНКЦИИ И ВХОДОМ 5в: И, ИЛИ _EX

REALISATION: FX100

****************************************************************************************************

ВСТРОЕНЫЕ ШАБЛОНЫ:
РЕАЛИЗУЮТ НАСТРОЙКУ ПАКЕТА РЕЛЕ ПО ЗАРАНЕЕ ЗАДАНЫМ ПАРАМЕТРАМ

*-"GROW CONTROL"
УПРАВЛЕНИЕ МИКРОКЛИМАТОМ ДЛЯ РАСТЕНИЙ
1-ТАЙМЕР СВЕТ, 2-ТЕРМОРЕГУЛЯТОР, 3-РЕГУЛЯТОР ВЛАЖНОСТИ, 4-ТАЙМЕР АВТОПОЛИВ

*-"INCUBATOR"
УПРАВЛЕНИЕ ИНКУБАТОРОМ

*-"AVR"
АВТОЗАПУСК ГЕНЕРАТОРА v._X8_EX4

*-"ECOWAT"
ЭКОНОМИЯ ЭНЕРГИИ ПО ДВУМ ТАРИФАМ

****************************************************************************************************

ВСТРОЕНЫЕ ФУНКЦИИ:
-FX-ПОЛЬЗОВАТЕЛЬСКИЕ ФУНКЦИИ v._FX
-TIMER-ТАЙМЕР
-TIMER_Z-ТАЙМЕР ЗАДЕРЖКИ-через (х) времени переключает выход
-TIMER_I-ТАЙМЕР ИМПУЛЬСНЫЙ-через (х) времени включает выход на (у) времени
-TC-ТАЙМЕР ЦИКЛИЧЕСКИЙ-через (х) времени переключает выход
-TCI-ТАЙМЕР ЦИКЛИЧЕСКИЙ ИМПУЛЬСНЫЙ
-GHL-ТАЙМЕР СВЕТ ЦИКЛ (ИМИТАЦИЯ СВЕТОВОГО ЦИКЛА)-ориентируется по часам
-OL-РЕЛЕ ОСВЕЩЕННОСТИ СВЕТ
-OLD-РЕЛЕ ОСВЕЩЕННОСТИ СВЕТ +(ДАТЧИК ДВИЖЕНИЯ ЧЕРЕЗ ВХОД v._EX)*
-GHT-ТАЙМЕР СВЕТ -ориентируется по часам
-GHTOL-ТАЙМЕР+ОСВЕЩЕННОСТЬ СВЕТ -ориентируется по часам
-GHTOLD-ТАЙМЕР+ОСВЕЩЕННОСТЬ СВЕТ +(ДАТЧИК ДВИЖЕНИЯ ЧЕРЕЗ ВХОД v._EX)*
-ТАЙМЕР АВТОПОЛИВ (АВТОКОРМ)
-ТЕРМОРЕГУЛЯТОР (НАГРЕВ, ОХЛАЖДЕНИЕ)
-РЕГУЛЯТОР ВЛАЖНОСТИ (УВЛАЖНЕНИЕ, СУШКА)
-АВТОПОВОРОТ ЛОТКА (ДЛЯ ИНКУБАТОРА)
-АВР АВТОЗАПУСК ГЕНЕРАТОРА (АВТОМАТИЧЕСКИЙ ВВОД РЕЗЕРВА) с версии _X8_EX4

****************************************************************************************************

НАСТРОЙКИ МЕНЮ:

*/
void menu(){}

void setup(){}

void loop(){}
