# BFPRT Algorithm Implementation

## Описание

Этот проект реализует алгоритм **BFPRT** (также известный как *алгоритм медианы медиан*) для нахождения **k-й порядковой статистики** в неотсортированном массиве.

В отличие от `std::nth_element`, который в худшем случае может работать за `O(n²)`, алгоритм **BFPRT** гарантирует время работы `O(n)` даже в худшем случае.

### Основные возможности

- Нахождение `k`-го наименьшего элемента в массиве
- Гарантированная линейная сложность в худшем случае
- Шаблонная реализация, работающая с любыми типами данных

---

## Использование

### Требования

- Компилятор с поддержкой **C++20**
- **CMake** версии **3.21** или выше
- **Google Test** — для модульных тестов
- **Google Benchmark** — для оценки производительности

### Сборка проекта

```bash
mkdir build && cd build
cmake ..
make
```

### Запуск примера использования:
```bash
cd build && ./example
```

### Запуск тестов:
```bash
cd build && ctest
```

```console
    Start 1: test_bfprt_impl
1/4 Test #1: test_bfprt_impl ..................   Passed    0.63 sec
    Start 2: test_exceptions
2/4 Test #2: test_exceptions ..................   Passed    0.01 sec
    Start 3: test_medianOfMedians
3/4 Test #3: test_medianOfMedians .............   Passed    0.01 sec
    Start 4: test_partition
4/4 Test #4: test_partition ...................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.67 sec
```

### Запуск бенчмарков
```bash
cd build && ./benchmarks/bfprt_benchmarks
```

## Особенности реализации

- **Алгоритмические особенности**:
  - Медиана медиан для выбора оптимального pivot
  - Рекурсивное разбиение массива

- **Интерфейс**:
    - Совместим с STL-итераторами
    - Поддерживает произвольные типы данных
    - Интуитивно понятный интерфейс (более простой, чем у std::nth_element)
    - Шаблонная реализация для работы с любыми типами, поддерживающими сравнение

## Результаты Benchmark'ов

### Результаты для `std::nth_element`

| Benchmark                        | Время       | CPU Время  | Итерации |
|-----------------------------------|-------------|------------|----------|
| `BM_StdNthElement/100/50`         | 12770 ns    | 12749 ns   | 70244    |
| `BM_StdNthElement/1000/500`       | 119973 ns   | 119506 ns  | 9560     |
| `BM_StdNthElement/10000/5000`     | 595929 ns   | 592822 ns  | 1065     |
| `BM_StdNthElement/100000/50000`   | 8333295 ns  | 8329877 ns | 93       |

#### Оценка сложности:
- **Big-O**: 5.01 NlgN
- **RMS**: 2%

`std::nth_element` близок к своей ожидаемой сложности O(N), что подтверждается полученными результатами.

---

### Результаты для алгоритма BFPRT

| Benchmark                        | Время        | CPU Время  | Итерации |
|-----------------------------------|--------------|------------|----------|
| `BM_BFPRT/100/50`                | 43323 ns     | 43220 ns   | 13528    |
| `BM_BFPRT/1000/500`              | 423740 ns    | 423444 ns  | 1559     |
| `BM_BFPRT/10000/5000`            | 4166523 ns   | 4164807 ns | 135      |
| `BM_BFPRT/100000/50000`          | 43408915 ns  | 43399277 ns| 17       |

#### Оценка сложности:
- **Big-O**: 433.92 N
- **RMS**: 1%

Алгоритм BFPRT работает линейно, как и ожидается, но с большим коэффициентом, что делает его медленнее, чем `std::nth_element`, особенно на небольших массивах.

---

### Заключение:
- **Кастомная реализация BFPRT** показывает линейную сложность, как и задумано, но имеет большую константу. Вероятно это делает ее более выгодной в специфических случаях, например, когда требуется гарантированное O(n), несмотря на меньшую скорость на небольших массивах.
