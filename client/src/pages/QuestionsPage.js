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
            const data = await request("http://127.0.0.1:3001/questions?topicId=11");
            setQuestions(data);
        } catch(err) {
            console.log("Question error ", err)
        }
    }, [])

    return (
        <div className="questions">
            {questions.map((question, index) => (
                <div className="questions__item">
                    <h3>Задание {question.number}</h3>
                    <div style={{whiteSpace: "normal", height: "400px"}}>
                        <p>
                            {index + 1}. {question.text}
                        </p>
                    </div>

                    <input placeholder="Введите ответ" />
                </div>
            ))}
        </div>
    );
};

export default QuestionsPage;
