const mockData = (type) => {
    let data;
    switch (type) {
        case "variants":
            data = [
                {
                    text: "Анализ информационных моделей",
                    number: 1,
                },
                {
                    text: "Кодирование и декодирование",
                    number: 2,
                },
                {
                    text: "Анализ программ",
                    number: 3,
                },
                {
                    text: "Перебор слов и системы счисления",
                    number: 4,
                },
            ];
            break;
        case "questions":
            data = [
                {
                    number: 1,
                    text: `Сколько секунд потребуется модему, 
                    передающему информацию со скоростью 32000 бит/с, 
                    чтобы передать 24─цветное растровое изображение размером 800 на 600 пикселей, 
                    при условии что цвет кодируется минимально возможным количеством бит.`,
                },
                {
                    number: 1,
                    text: `Пить или не пить, какой ответ верный?`,
                },
                {
                    number: 1,
                    text: `Сколько секунд потребуется модему, 
                    передающему информацию со скоростью 32000 бит/с, 
                    чтобы передать 24─цветное растровое изображение размером 800 на 600 пикселей, 
                    при условии что цвет кодируется минимально возможным количеством бит.`,
                },
                {
                    number: 1,
                    text: `Пить или не пить, какой ответ верный?`,
                },
            ];
            break;
        case "answers":
            data = ["1", "2", "3", "4"];
            break;
        case "students_table":
            data = [
                {
                    fio: "Иванов И И",
                    email: "i.ivanov@yandex.ru",
                    countTasks: 93.9,
                    percent: 64.0,
                    rating: 1,
                },
                {
                    fio: "Петров А В",
                    email: "a.petrov@yandex.ru",
                    countTasks: 40.1,
                    percent: 33.1,
                    rating: 2,
                },
                {
                    fio: "Шахова А Ю",
                    email: "a.shahova@yandex.ru",
                    countTasks: 66.4,
                    percent: 20.2,
                    rating: 3,
                },
                {
                    fio: "Садыков И В",
                    email: "u.sadykov@google.com",
                    countTasks: 47.6,
                    percent: 17.2,
                    rating: 4,
                },
                {
                    fio: "Рыжкова Д А",
                    email: "d.ryzkova@yandex.ru",
                    countTasks: 39.9,
                    percent: 15.0,
                    rating: 5,
                },
            ];
            break;
        default:
            data = [];
    }
    return data;
};

export default mockData;
