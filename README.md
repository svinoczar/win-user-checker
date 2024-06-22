# Тестовое задание:
 
Необходимо написать простое web-приложение с использованием node.js+node-addon-api (C++)+WinAPI для проверки привилегии пользователя (например, Администратор/Пользователь/Гость) в списке пользователей операционной системы Windows.
 
Приложение должно работать по следующему сценарию
 
1. Пользователь запускает web-сервер из корня проекта:
server.bat
2. Автоматически открывается браузер с начальной web страницей, на которой отображаются
- поле ввода имени пользователя
- кнопка "Проверить"
3. Пользователь вводит любое имя пользователя и нажимает на "проверить"
4. Если введённый пользователь в списке пользователей имеет привилегию Администратор/Пользователь/Гость, отображается страница с надписью "Пользователь имя_введённого_пользователя имеет привилегию привилегия_введённого пользователя", иначе "Пользователя имя_введённого_пользователя нет". Под надписью есть кнопка "Назад", при нажатии на которую происходит возврат на начальную страницу.
5. Проверку привилегий осуществлять через WinAPI.
 
Для самопроверки список пользователей для проверки можно получить через Управление компьютером->Служебные программы->Локальные пользователи и группы->Пользователи.
