import { useContext, useEffect, useState } from "react";
import ResultModal from "../components/ResultModal";
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
    //         id: 2,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 3,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 4,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 5,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    // ];

    const [active, setActive] = useState(false)

    const auth = useContext(AuthContext);
    const { request } = useHttp(auth.setModal);

    const [questions, setQuestions] = useState([]);

    const [answers, setAnswers] = useState([{questionId: "1", answer: "aa"}]);
    let search = window.location.search;
    const topicId = parseInt(search.replace(/\D+/g,""));
    useEffect(async () => {
        try {
            const data = await request(`http://127.0.0.1:3001/questions?topicId=${topicId}`);
            setQuestions(data);
        } catch(err) {
            console.log("Question error ", err)
        }
    }, [])

    const sendResults = () => {
        setActive(true)
    };

    const handleInput = (e) => {
        const { id, value } = e.target;

        const findAnswer = answers.find(
            (answer) => answer.questionId === id,
        );

        console.log(findAnswer)

        if (findAnswer) {
            findAnswer.answer = value;
            // setAnswers(findAnswer)
        } else {
            answers.push({ questionId: id, answer: value });
            console.log(answers)
            setAnswers(answers);
        }
    };

    console.log(answers)
    return (
        <div className="questions">
            {questions.map((question, index) => (
                <div className="questions__item">
                    <h3>Задание {question.number}</h3>
                    <div className="questions__item__text">
                        <p>
                            {question.id}. {question.text}
                        </p>
                    </div>

                    <input
                        id={`${question.id}`}
                        placeholder="Введите ответ"
                        onChange={handleInput}
                    />
                </div>
            ))}

            <div className="questions__sendAns">
                <button onClick={sendResults}>Отправить</button>
            </div>

            <ResultModal active={active} setActive={setActive} trueAnswers={6} falseAnswers={2}/>
        </div>
    );
};

export default QuestionsPage;
