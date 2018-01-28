# MEGAZVON24

### MEGAZVON24  Arduino MEGA2560 программа для автоматического перезвона колоколов по заданному расписанию.

### поддерживает 24 колокола, у каждого колокола своя настройка. одновременно можно ударить до 8 колоколов.
### есть функция отбивания часов колоколом. есть меню с настройками.
### расписание поддерживает 25 разных мелодий.
### в расписании учтены будни и выходные. есть возможность отметить день как праздничный из меню и с кнопки.

#### created by : ss2s
<https://github.com/ss2s>

#### author of idea : Aleksandr K


#### 24 РЕЛЕ
#### RTC DS3231
#### LCD KeyPad Shield


### ВАЖНАЯ ИНФОРМАЦИЯ:

#### ВСЕ НАСТРОЙКИ ВЫНЕСЕНЫ В ОТДЕЛЬНЫЙ ФАЙЛ "config24.h"
#### НАСТРОЙКА ДЛИТЕЛЬНОСТИ КАЖДОЙ НОТЫ В ФАЙЛЕ "config24.h"
#### НАСТРОЙКИ МЕЛОДИЙ В ФАЙЛЕ "melody24.h"

#### все нужные файлы находятся в папке с прошивкой

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

## ПРАВИЛА НАПИСАНИЯ МЕЛОДИЙ ДЛЯ ПЕРЕЗВОНА:

#### мелодии можно создавать при помощи специальных нот, MAX 24 ноты:
#### есть 4 способа

## 1
#### nota(12, 250, 2000);  // это пример ноты расширеными параметрами
#### (номер колокола, время удара в колокол в мс, время до вызова следующей ноты в мс)

## 2
#### nota12(2000);  // это пример ноты с одним параметром. номер ноты задается в названии ноты
#### время удара в колокол в мс берется из файла "config24.h"
#### номер ноты в названии (время до вызова следующей ноты в мс)

## 3
#### combo3(12, 14, 16, 2000);  // это пример комбо ноты. ударит одновременно в три колокола. максимальное комбо 8 нот.
#### в названии количество нот(1 колокол, 2 колокол, 3 колокол, время до вызова следующей ноты в мс)

## 4
#### с помощью Arduino, С/С++ синтаксиса. можно просто в функции мелодия управлять реле с помощю функций Arduino:
#### digitalWrite(номер пина к которому подключен пин, управляющий сигнал 0 или 1);
#### delay(задержка в мс);
#### можно комбинировать ноты и код Arduino.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

## ПРИМЕР МЕЛОДИИ:

```
// мелодия EX1 пример мелодии с 1 набором нот
void melodiaEX1(){
	// здесь писать ноты
	nota(1, 250, 2000);   // 1 нота, реле 22 (время включения реле 250мс, задержка до следующей ноты 2000мс)
	nota(2, 280, 2000);   // 2 нота, реле 23 (время включения реле 280мс, задержка до следующей ноты 2000мс)
	nota(3, 250, 3000);   // 3 нота, реле 24 (время включения реле 250мс, задержка до следующей ноты 3000мс)
	nota(4, 300, 5000);   // 4 нота, реле 25 (время включения реле 300мс, задержка до следующей ноты 5000мс)
	nota(5, 300, 2000);   // 5 нота, реле 26 (время включения реле 300мс, задержка до следующей ноты 2000мс)
	nota(6, 300, 2000);   // 6 нота, реле 27 (время включения реле 300мс, задержка до следующей ноты 2000мс)
	nota(7, 300, 2000);   // 7 нота, реле 28 (время включения реле 300мс, задержка до следующей ноты 2000мс)
	nota(8, 300, 2000);   // 8 нота, реле 29 (время включения реле 300мс, задержка до следующей ноты 2000мс)
	combo2(1, 2, 2000);                    // комбо нота на 2 колокола   задержка до следующей ноты 2000 мс
	combo3(1, 2, 3, 2000);                 // комбо нота на 3 колокола   задержка до следующей ноты 2000 мс
	combo4(1, 2, 3, 4, 2000);              // комбо нота на 4 колокола   задержка до следующей ноты 2000 мс
	combo5(1, 2, 3, 4, 5, 2000);           // комбо нота на 5 колоколов   задержка до следующей ноты 2000 мс
	combo6(1, 2, 3, 4, 5, 6, 2000);        // комбо нота на 6 колоколов   задержка до следующей ноты 2000 мс
	combo7(1, 2, 3, 4, 5, 6, 7, 2000);     // комбо нота на 7 колоколов   задержка до следующей ноты 2000 мс
	combo8(1, 2, 3, 4, 5, 6, 7, 8, 2000);  // комбо нота на 8 колоколов   задержка до следующей ноты 2000 мс
}

// мелодия EX2 пример мелодии со 2 набором нот
// для написания мелодий лучше использовать второй набор нот. первый для настройки колоколов и создания уникальных нот
void melodiaEX2(){
	// здесь писать ноты
	nota1(500);   // 1 нота, реле 22 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota2(500);   // 2 нота, реле 23 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota3(500);   // 3 нота, реле 24 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota4(500);   // 4 нота, реле 25 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota5(500);   // 5 нота, реле 26 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota6(500);   // 6 нота, реле 27 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota7(500);   // 7 нота, реле 28 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	nota8(500);   // 8 нота, реле 29 (время включения реле задано в настройках нот, задержка до следующей ноты 500мс)
	combo2(1, 2, 1000);                    // комбо нота на 2 колокола   задержка до следующей ноты 1000 мс
	combo3(1, 2, 3, 1000);                 // комбо нота на 3 колокола   задержка до следующей ноты 1000 мс
	combo4(1, 2, 3, 4, 1000);              // комбо нота на 4 колокола   задержка до следующей ноты 1000 мс
	combo5(1, 2, 3, 4, 5, 1000);           // комбо нота на 5 колоколов   задержка до следующей ноты 1000 мс
	combo6(1, 2, 3, 4, 5, 6, 1000);        // комбо нота на 6 колоколов   задержка до следующей ноты 1000 мс
	combo7(1, 2, 3, 4, 5, 6, 7, 1000);     // комбо нота на 7 колоколов   задержка до следующей ноты 1000 мс
	combo8(1, 2, 3, 4, 5, 6, 7, 8, 1000);  // комбо нота на 8 колоколов   задержка до следующей ноты 1000 мс
}
```

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

## ФУНКЦИИ МЕНЮ:

#### функция удара в любой колокол с настраиваемыми параметрами.(сервисная функция для подбора конфигурации)++
#### настройка длительности для каждой ноты (не путать с задержкой между нотами)++
#### список всех мелодий, с возможностью прослушать выбранную мелодию.++
#### настройка часов, время и дата.++
#### настройка праздничных дней автоматически в час ночи (ручная праздника настройка с основного экрана кнопками вверх вниз).+