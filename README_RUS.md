# SmartCalc

В данном проекте Вам предстоит реализовать на языке программирования Си с использованием структурного подхода расширенную версию обычного калькулятора, который можно найти в стандартных приложениях каждой операционной системы. Помимо базовых арифметических операций, как плюс-минус и умножить-поделить, Вам необходимо дополнить калькулятор возможностью вычисления арифметических выражений с учетом приоритетов, а так же некоторыми математическими функциями (синус, косинус, логарифм и т.д.). Помимо вычисления выражений калькулятор так же должен поддерживать использование переменной _x_ и построение графика соответствующей функции. В качестве дополнительных улучшений можно будет рассмотреть кредитный и депозитный калькулятор.

### Историческая справка

История развития такого вычислительного механизма как калькулятор начинается в ХVII веке, а первые прообразы этого аппарата существовали в VI столетии до нашей эры. Само слово "калькулятор" происходит от латинского "calculo", что в переводе означает "считаю", "подсчитываю". Но более детальное изучение этимологии этого понятия показывает, что изначально следует говорить о слове "calculus", которое переводится как "камешек". Ведь изначально именно камешки использовались как атрибут для счета.

Историю вычислительных машин, в том числе и калькуляторов, традиционно начинают с суммирующей машины Паскаля, созданной в 1643 году Блезом Паскалем, и арифмометра Лейбница, изобретённого в 1673 году немецким математиком Готфридом Вильгельмом Лейбницем.

Суммирующая машина представляла собой ящик со связанными между собой шестеренками, которые поворачивались специальными колесиками, каждому из которых соответствовал один десятичный разряд. Когда одним из колесиков совершался десятый оборот, происходил сдвиг следующей шестеренки на одну позицию, увеличивавший разряд числа. Ответ после проведения математических действий отображался в окошках над колесиками.

Через 20 лет Лейбниц создал свой вариант калькулятора, принцип работы которого был таким же как и у суммирующей машины Паскаля - шестеренки и колесики. Однако в калькулятор Лейбница были добавлены движущая часть, которая стала прообразом подвижных кареток будущих настольных калькуляторов, и рукоятка, крутившая ступенчатое колесо, которое в дальнейшем было заменено на цилиндр. Данные добавления позволили существенно ускорить повторяющиеся операции - умножение и деление. Использование калькулятора Лейбница хоть и незначительно упростило процесс вычисления, но дало толчок другим изобретателям - движущая часть и цилиндр калькулятора Лейбница использовались в вычислительных машинах до середины XX века.

Затем в 1957 компанией Casio был выпущен один из первых серийных калькуляторов 14-А. Он выполнял четыре действия арифметики над 14-разрядными десятичными числами. Конструкция использовала реле, весила 140 кг и была выполнена в виде стола с тумбой-вычислительным блоком, клавиатурой и дисплеем, при работе потребляла 300 Вт. Однако, калькуляторы быстро развивались и усложнялись, как и прочие вычислительные машины. В 1965 году компания Wang Laboratories выпустила калькулятор Wang LOCI-2, который мог вычислять логарифмы, Casio представила первый калькулятор со встроенной памятью "Casio 001" (размеры 37x48x25 см, вес 17 кг), а Olivetti выпустила "Programma 101" - первый калькулятор, который мог сохранять программу и многократно выполнять вычисления по ней.

Малогабаритные настольные и карманные калькуляторы начали выпускаться с 1970 года, после появления интегральных микросхем, резко сокративших размеры, массу и энергопотребление электронных приборов. В 1970 году Sharp и Canon начали продажи калькуляторов, которые можно было держать в руке (весом порядка 800 г). В 1971 появился первый действительно карманный (131x77x37 мм) калькулятор 901B фирмы Bomwar. Он выполнял 4 арифметические операции, имел дисплей на светодиодах и стоил 240 долларов. В 1973 году в продаже появился калькулятор Sharp EL-805, в котором впервые был использован ЖК-дисплей. А уже в 1979 Hewlett Packard выпустила первый калькулятор с алфавитно-цифровым индикатором, программируемый, с возможностью подключения дополнительных модулей - RAM, ROM, устройства чтения штрих-кодов, кассеты с магнитной лентой, флоппи-дисков, принтеров и др.