## Converter ECEF to LLA and LLA to ECEF

> **Этот код позволяет преобразовывать ECEF в LLA координаты и LLA в ECEF координаты**

---

## Как установить?

***ТЫКНИ НА СПОЙЛЕР***
<details>
<summary>УСТАНОВКА</summary>

  ---

**1. У вас должен быть gcc компилятор.**

---

#### Проверить его наличие можно при помощи команды

**```gcc --version```**

**Что должно вывестись**
     
     gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
     Copyright (C) 2022 Free Software Foundation, Inc.
     This is free software; see the source for copying conditions.  There is NO
     warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.```
     
***Если вывелась ошибка или что-то другое - поищите в интернете способы установки компилятора в зависимости от вашей системы.***

---
   
**2. Клонируем репозиторий**

**```git clone https://github.com/Exponatee/Converter-ECEF-to-LLA-and-LLA-to-ECEF.git```**

**3. Заходим в нашу директорию**

**```cd Converter-ECEF-to-LLA-and-LLA-to-ECEF```**

**4. Запускаем нужную программу**

**```./converter_ECEF_to_LLA.exe```** - перевод ECEF в LLA координаты

**```./converter_LLA_to_ECEF.exe```** - перевод LLA в ECEF координаты

**5. Пользуемся**
</details>

---

## Как скомпилировать?

***ТЫКНИ НА СПОЙЛЕР***
<details>
<summary>КОМПИЛЯЦИЯ</summary>

---

**1. Находясь в директории вводим команду**

**```gcc converter_ECEF_to_LLA.c -o converter_ECEF_to_LLA.exe -lm```**

Я думаю у вас возник вопрос: **"Для чего в конце используется ```-lm```?"**

Так вот: таким образом для компилятора мы указываем с какими библиотеками нужно совместно производить компиляцию

В нашем случае это библиотека "**<math.h>**".

**Буду надеяться что дальнейший интерфейс для Вас абсолютно понятен.**                             
**Желаю удачного кодинга, друзья!**
</details>

---



