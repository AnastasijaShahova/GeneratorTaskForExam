export const getStatisticData = (role) => {
    let customData = {};
    if (role === "ученик") {
        customData.header = "Статистика";
        customData.list = [
            {
                text: "Общий рейтинг",
                url: "/general-rating",
            },
            {
                text: "Статистика по темам",
                url: "/topic-statistic",
            },
            {
                text: "Готовность к сдаче экзаменов",
                url: "/exam-statistic",
            },
        ];
    } else {
        customData.header = "Возможности учителя";
        customData.list = [
            {
                text: "Классный журнал",
                url: "/class-log",
            },
            {
                text: "Индивидуальный профиль знаний",
                url: "/user-profile",
            },
        ];
    }

    return customData;
};

export const getStudentsTableHeadrs = () => {
    return [
        "ФИО",
        "Email",
        "Решенные задания",
        "Процент выполнения",
        "Место в рейтинге",
    ];
};

export const getJournalTableHeaders = () => {
    return ["ФИО", "Email", "Готовность к экзамену"];
};
