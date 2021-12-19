import { useState } from "react";
import "../styles/Questions.scss";

const QuestionsPage = () => {
    const mock_questions = [
        {
            id: 1,
            text: "djnksnfjksnjkdsfsdjfkdshfkhsdhfhsdkhfkkshfkjskdkfjkhdgkfhsdjfhgkjdshkgdhfnfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
            type: 7,
        },
        {
            id: 1,
            text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
            type: 7,
        },
        {
            id: 1,
            text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
            type: 7,
        },
        {
            id: 1,
            text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
            type: 7,
        },
        {
            id: 1,
            text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
            type: 7,
        },
    ];

    const [questions, setQuestions] = useState(mock_questions);

    return (
        <div className="questions">
            {questions.map((question) => (
                <div className="questions__item">
                    <h3>Задание {question.type}</h3>
                    <div style={{whiteSpace: "normal", height: "400px"}}>
                        <p>
                            {question.id}. {question.text}
                        </p>
                    </div>

                    <input placeholder="Введите ответ" />
                </div>
            ))}
        </div>
    );
};

export default QuestionsPage;
