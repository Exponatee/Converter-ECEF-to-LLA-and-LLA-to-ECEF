# Converter ECEF to LLA and LLA to ECEF

Этот код позволяет преобразовывать координаты ECEF в LLA и обратно.

## Как установить?

- Нужно иметь gcc компилятор

- Выполняем клонирование моего репозитория через 

```git clone https://github.com/Exponatee/converter_ecef_to_lla_and_lla_to_ecef.git```

- Заходим в него

```./convert_LLA_to_ECEF.exe``` - запуск нашей программы для перевода LLA координат в ECEF координаты

```./convert_ECEF_to_LLA.exe``` - запуск нашей программы для перевода ECEF координат в LLA координаты

## Как скомпилировать?

```gcc convert_ECEF_to_LLA.c -o convert_ECEF_to_LLA.exe -lm```