# Лабораторная работа № 2: библиотека операций над массивами

Проект создан по методическим указаниям МГТУ им. Н. Э. Баумана.
Язык: C++17. Сборка: CMake 3.16+. ОС: WSL Ubuntu/Linux, Windows (MSVC или MinGW).

## Как проверить в WSL Ubuntu

```bash
sudo apt update
sudo apt install -y build-essential cmake git
cmake -S . -B build
cmake --build build -j 2
ctest --test-dir build --output-on-failure
./build/app
./build/variant_07
ldd build/app
```

CMake создает `build/libarraylib.so` и `build/libarraylib.a` на Linux, а также
`build/app`, `build/variant_07` и два тестовых исполняемых файла. На Windows
динамическая библиотека имеет расширение `.dll`, статическая — `.lib`.

## Что делает библиотека

`arr_sum`, `arr_max`, `arr_min`, `arr_average`, `arr_count_positive`,
`arr_count_negative`, `arr_count_zero`, `arr_product`, `arr_median`.

Предусловия: массив не пуст (`n > 0`), указатель действителен. Переполнение
`int` для суммы/произведения не обрабатывается (как в методичке). Медиана
не меняет оригинальный массив.

## Самостоятельные этапы

- `stages/stage1.cpp` — программа из одного исходного файла.
- `main.cpp` + `src/arraylib.cpp` + `include/arraylib.h` — разделение на модули.
- `scripts/check_stages.sh` — воспроизводимая проверка сборки этапов 1–6.
- `examples/variant_07.cpp` — прикладная программа по **варианту 7**.
- `.github/workflows/ci.yml` — GitHub Actions CI.

Вариант 7: оценки `{4, 5, 3, 4, 5, 5, 4, 3, 4, 5}`; средняя 4.20,
минимум 3, максимум 5, четыре пятёрки, две оценки ниже 4, медиана 4.00.

## Публикация на GitHub

История Git и тег `v1.0.0` подготовлены в архиве вместе с проектом.
1. Создай пустой репозиторий `arraylib` на GitHub.
2. В терминале проекта выполни:

```bash
git status
git log --oneline --graph --all
git tag
git remote add origin git@github.com:ВАШ_ЛОГИН/arraylib.git
git push -u origin main
git push origin --all
git push origin --tags
```

Если SSH не настроен, используй HTTPS ссылку репозитория.
Обязательно проверь вкладку **Actions** после push. Никакой push автоматически
не выполнялся.

## Доказательства для отчета

Рекомендуемые реальные скриншоты из **собственной WSL + VS Code**:
1. `g++ --version`, `cmake --version`, `git --version`.
2. Дерево файлов проекта в VS Code с индикатором WSL.
3. `cmake --build build -j 2`, список `.so` и `.a`.
4. `ctest --test-dir build --output-on-failure`.
5. `./build/app`, `./build/variant_07`.
6. `ldd build/app` и наличие `libarraylib.so`.
7. `git log --graph --all`, `git tag`, страница репозитория GitHub и зелёный CI.

Проверка кода в среде подготовки отчёта не является доказательством запуска на
компьютере студента. Замените протоколы в отчёте своими скриншотами при сдаче.
