import { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/Questions.scss";

const QuestionsPage = () => {
    // const mock_questions = [
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkdsfsdjfkdshfkhsdhfhsdkhfkkshfkjskdkfjkhdgkfhsdjfhgkjdshkgdhfnfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    // ];

    const auth = useContext(AuthContext)
    const {request} = useHttp(auth.setModal)

    const [questions, setQuestions] = useState([]);

    useEffect(async () => {
        try {
            const data = await request("http://127.0.0.1/questions?page=3&topicId=1");
            setQuestions(data);
        } catch(err) {
            console.log("Question error ", err)
        }
    }, [])

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
